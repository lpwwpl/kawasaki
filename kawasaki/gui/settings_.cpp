/*
 * This file is part of QssEditor.
 *
 * QssEditor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QssEditor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QssEditor. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDir>

#include "settings_.h"

/*******************************************************/

class SettingsPrivate
{
public:
    SettingsPrivate()
        : translationsFilled(false)
    {}

    QSettings *settings;
    QMap<QString, QString> translations;
    bool translationsFilled;
    QHash<QString, QVariant> defaultValues;
};

/*******************************************************/

Settings_::Settings_()
{
    d = new SettingsPrivate;

    d->settings = new QSettings(QSettings::IniFormat,
                                QSettings::UserScope,
                                QCoreApplication::organizationName(),
                                QCoreApplication::applicationName());

    d->settings->setFallbacksEnabled(false);

    // save version for future changes
    d->settings->setValue("version", 1.0);
}

Settings_::~Settings_()
{
    delete d->settings;
    delete d;
}

void Settings_::addDefaultValues(const QHash<QString, QVariant> &defaultValues)
{
    QHash<QString, QVariant>::const_iterator itEnd = defaultValues.end();

    for(QHash<QString, QVariant>::const_iterator it = defaultValues.begin();it != itEnd;++it)
    {
        d->defaultValues.insert(it.key(), it.value());
    }
}

QVariant Settings_::defaultValue(const QString &key) const
{
    return d->defaultValues.value(key);
}

void Settings_::sync()
{
    d->settings->sync();
}

Settings_* Settings_::instance()
{
    static Settings_ *inst = new Settings_;

    return inst;
}

void Settings_::fillTranslations()
{
    QFile translations(
            #ifdef Q_OS_UNIX
                QString("/usr/share/" TARGET_STRING).toLower()
            #else
                QCoreApplication::applicationDirPath()
            #endif
                + QDir::separator()
                + "translations"
                + QDir::separator()
                + "translations.conf");

    d->translationsFilled = true;

    if(!translations.open(QFile::ReadOnly))
    {
        qWarning("Cannot open translations' configuration: %s", qPrintable(translations.errorString()));
        return;
    }

    QTextStream in(&translations);

    in.setCodec("UTF-8");

    while(!in.atEnd())
    {
        QString line = in.readLine().trimmed();

        if(line.startsWith("#"))
            continue;

        int index = line.indexOf(QChar('='));

        if(index < 0)
            continue;

        QString code = line.mid(index+1);

        if(code.isEmpty())
            continue;

        d->translations.insert(code, line.left(index));
    }
}

QHash<QString, QVariant>& Settings_::defaultValues()
{
    return d->defaultValues;
}

QSettings *Settings_::settings()
{
    return d->settings;
}

bool Settings_::contains(const QString &key) const
{
    return d->settings->contains(key.startsWith('/') ? ("settings" + key) : key);
}

void Settings_::remove(const QString &key, Settings_::SyncType sync)
{
    QSettings *s = settings();

    s->beginGroup("settings");
    s->remove(key);
    s->endGroup();

    if(sync == Sync)
        s->sync();
}

QMap<QString, QString> Settings_::translations()
{
    if(d->translations.isEmpty())
        fillTranslations();

    return d->translations;
}
