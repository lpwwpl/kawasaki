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

#ifndef SETTINGS__H
#define SETTINGS__H

#include <QStringList>
#include <QDataStream>
#include <QByteArray>
#include <QDateTime>
#include <QSettings>
#include <QVariant>
#include <QString>
#include <QPoint>
#include <QList>
#include <QHash>
#include <QMap>

#define SETTINGS_GET_BOOL Settings_::instance()->value<bool>
#define SETTINGS_SET_BOOL Settings_::instance()->setValue<bool>

#define SETTINGS_GET_INT Settings_::instance()->value<int>
#define SETTINGS_SET_INT Settings_::instance()->setValue<int>

#define SETTINGS_GET_UINT Settings_::instance()->value<uint>
#define SETTINGS_SET_UINT Settings_::instance()->setValue<uint>

#define SETTINGS_GET_LONG Settings_::instance()->value<long>
#define SETTINGS_SET_LONG Settings_::instance()->setValue<long>

#define SETTINGS_GET_ULONG Settings_::instance()->value<unsigned long>
#define SETTINGS_SET_ULONG Settings_::instance()->setValue<unsigned long>

#define SETTINGS_GET_LONG_LONG Settings_::instance()->value<qlonglong>
#define SETTINGS_SET_LONG_LONG Settings_::instance()->setValue<qlonglong>

#define SETTINGS_GET_ULONG_LONG Settings_::instance()->value<qulonglong>
#define SETTINGS_SET_ULONG_LONG Settings_::instance()->setValue<qulonglong>

#define SETTINGS_GET_FLOAT Settings_::instance()->value<float>
#define SETTINGS_SET_FLOAT Settings_::instance()->setValue<float>

#define SETTINGS_GET_DOUBLE Settings_::instance()->value<double>
#define SETTINGS_SET_DOUBLE Settings_::instance()->setValue<double>

#define SETTINGS_GET_DATE Settings_::instance()->value<QDate>
#define SETTINGS_SET_DATE Settings_::instance()->setValue<QDate>

#define SETTINGS_GET_TIME Settings_::instance()->value<QTime>
#define SETTINGS_SET_TIME Settings_::instance()->setValue<QTime>

#define SETTINGS_GET_DATE_TIME Settings_::instance()->value<QDateTime>
#define SETTINGS_SET_DATE_TIME Settings_::instance()->setValue<QDateTime>

#define SETTINGS_GET_BYTE_ARRAY Settings_::instance()->value<QByteArray>
#define SETTINGS_SET_BYTE_ARRAY Settings_::instance()->setValue<QByteArray>

#define SETTINGS_GET_BIT_ARRAY Settings_::instance()->value<QBitArray>
#define SETTINGS_SET_BIT_ARRAY Settings_::instance()->setValue<QBitArray>

#define SETTINGS_GET_CHAR Settings_::instance()->value<QChar>
#define SETTINGS_SET_CHAR Settings_::instance()->setValue<QChar>

#define SETTINGS_GET_STRING Settings_::instance()->value<QString>
#define SETTINGS_SET_STRING Settings_::instance()->setValue<QString>

#define SETTINGS_GET_STRING_LIST Settings_::instance()->value<QStringList>
#define SETTINGS_SET_STRING_LIST Settings_::instance()->setValue<QStringList>

#define SETTINGS_GET_COLOR Settings_::instance()->value<QColor>
#define SETTINGS_SET_COLOR Settings_::instance()->setValue<QColor>

#define SETTINGS_GET_SIZE Settings_::instance()->value<QSize>
#define SETTINGS_SET_SIZE Settings_::instance()->setValue<QSize>

#define SETTINGS_GET_SIZEF Settings_::instance()->value<QSizeF>
#define SETTINGS_SET_SIZEF Settings_::instance()->setValue<QSizeF>

#define SETTINGS_GET_POINT Settings_::instance()->value<QPoint>
#define SETTINGS_SET_POINT Settings_::instance()->setValue<QPoint>

#define SETTINGS_GET_POINTF Settings_::instance()->value<QPointF>
#define SETTINGS_SET_POINTF Settings_::instance()->setValue<QPointF>

#define SETTINGS_GET_RECT Settings_::instance()->value<QRect>
#define SETTINGS_SET_RECT Settings_::instance()->setValue<QRect>

#define SETTINGS_GET_RECTF Settings_::instance()->value<QRectF>
#define SETTINGS_SET_RECTF Settings_::instance()->setValue<QRectF>

#define SETTINGS_GET_LINE Settings_::instance()->value<QLine>
#define SETTINGS_SET_LINE Settings_::instance()->setValue<QLine>

#define SETTINGS_GET_LINEF Settings_::instance()->value<QLineF>
#define SETTINGS_SET_LINEF Settings_::instance()->setValue<QLineF>

#define SETTINGS_GET_URL Settings_::instance()->value<QUrl>
#define SETTINGS_SET_URL Settings_::instance()->setValue<QUrl>

#define SETTINGS_REMOVE Settings_::instance()->remove

#define SETTING_TRANSLATION                  "translation"
#define SETTING_OPEN_LAST_FILE               "open-last-file"
#define SETTING_PREVIEW_DELAY                "preview-delay"
#define SETTING_LAST_FILE                    "last-file"
#define SETTING_LAST_FILES                   "last-files"
#define SETTING_FIND_REPLACE_FIND_TEXT       "fr-find-text"
#define SETTING_FIND_REPLACE_REPLACE         "fr-replace"
#define SETTING_FIND_REPLACE_REPLAC_TEXT     "fr-replace-text"
#define SETTING_FIND_REPLACE_FORWARD         "fr-forward"
#define SETTING_FIND_REPLACE_CASE_SENSITIVE  "fr-case-sensitive"
#define SETTING_FIND_REPLACE_WHOLE_WORDS     "fr-whole-words"
#define SETTING_FIND_REPLACE_REGEXP          "fr-regexp"

class SettingsPrivate;

/*
 *  Class to query the application settings. You can use
 *  the macroses above to query the appropriate values
 *  like that:
 *
 *      qDebug() << SETTINGS_GET_STRING(SETTING_TRANSLATION);
 */
class Settings_
{
public:
    static Settings_* instance();

    ~Settings_();

    enum SyncType { NoSync, Sync };

    /*
     *  Get the key value. If the value is not found, then
     *  the appropriate value from the known default values
     *  is returned. If the default value for the key is unknown,
     *  the C++ default value is returned ('0' for 'int', 'false' for 'bool' etc.)
     */
    template <typename T>
    T value(const QString &key);

    /*
     *  Get the key value. Return 'def' if the key is not found
     */
    template <typename T>
    T value(const QString &key, const T &def);

    /*
     *  Set the value of the key. If 'sync' is 'Sync', then call sync()
     */
    template <typename T>
    void setValue(const QString &key, const T &value, SyncType sync = Sync);

    /*
     *  Add your default values for your settings
     */
    void addDefaultValues(const QHash<QString, QVariant> &defaultValues);

    /*
     *  Returns the default value of the setting 'key'. Returns
     *  an invalid QVariant if the settings is not found in the
     *  default values
     */
    QVariant defaultValue(const QString &key) const;

    /*
     *  Returns 'true' if the setting 'key' exists. If 'key' starts with '/'
     *  the setting is returned from "settings" group (almost all settings are stored there).
     *
     *  For example:
     *
     *  contains("list")  - will look for the "list" key in the global section
     *  contains("/list") - will look for the "list" key in the "settings" section
     */
    bool contains(const QString &key) const;

    /*
     *  Remove the specified key from the section "settings"
     */
    void remove(const QString &key, SyncType sync = Sync);

    /*
     *  Sync with the storage
     */
    void sync();

    /*
     *  Available translations, hardcoded
     */
    QMap<QString, QString> translations();

private:
    Settings_();

    void fillTranslations();

    QHash<QString, QVariant> &defaultValues();

    QSettings *settings();

private:
    SettingsPrivate *d;
};

/**********************************/

template <typename T>
T Settings_::value(const QString &key)
{
    T def = T();
    QHash<QString, QVariant>::iterator it = defaultValues().find(key);

    if(it != defaultValues().end())
        def = it.value().value<T>();

    return value<T>(key, def);
}

template <typename T>
T Settings_::value(const QString &key, const T &def)
{
    QSettings *s = settings();

    s->beginGroup("settings");
    QVariant value = s->value(key, QVariant::fromValue(def));
    s->endGroup();

    return value.value<T>();
}

template <typename T>
void Settings_::setValue(const QString &key, const T &value, Settings_::SyncType sync)
{
    QSettings *s = settings();

    s->beginGroup("settings");
    s->setValue(key, QVariant::fromValue(value));
    s->endGroup();

    if(sync == Sync)
        s->sync();
}

#endif // SETTINGS_H
