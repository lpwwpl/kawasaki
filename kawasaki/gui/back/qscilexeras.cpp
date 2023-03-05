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

#include <QEventLoop>
#include <QRegExp>
#include <qsettings.h>
#include "Qsci/qsciapis.h"

#include "Qsci/qscilexeras.h"

QsciLexerAs::QsciLexerAs(QObject* parent)
    : QsciLexer(parent), nocase(false), fold_comments(false)
{
    QsciAPIs* api = new QsciAPIs(this);

    const QString stringKeywords = QString(keywords(1)) + keywords(2);

    QStringList listKeywords = stringKeywords.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    // Qt classes
    listKeywords
        << "QAbstractScrollArea"
        << "QCheckBox"
        << "QColumnView"
        << "QComboBox"
        << "QDateEdit"
        << "QDateTimeEdit"
        << "QDialog"
        << "QDialogButtonBox"
        << "QDockWidget"
        << "QDoubleSpinBox"
        << "QFrame"
        << "QGroupBox"
        << "QHeaderView"
        << "QLabel"
        << "QLineEdit"
        << "QListView"
        << "QListWidget"
        << "QMainWindow"
        << "QMenu"
        << "QMenuBar"
        << "QMessageBox"
        << "QProgressBar"
        << "QPushButton"
        << "QRadioButton"
        << "QScrollBar"
        << "QSizeGrip"
        << "QSlider"
        << "QSpinBox"
        << "QSplitter"
        << "QStatusBar"
        << "QTabBar"
        << "QTabWidget"
        << "QTableView"
        << "QTableWidget"
        << "QTextEdit"
        << "QTimeEdit"
        << "QToolBar"
        << "QToolButton"
        << "QToolBox"
        << "QToolTip"
        << "QTreeView"
        << "QTreeWidget"
        << "QWidget"

        // alignment
        << "top"
        << "bottom"
        << "left"
        << "right"
        << "center"

        // attachment
        << "scroll"
        << "fixed"

        // border image
        << "none"
        << "stretch"
        << "repeat"

        // border style
        << "dashed"
        << "dot-dash"
        << "dot-dot-dash"
        << "dotted"
        << "double"
        << "inset"
        << "outset"
        << "ridge"
        << "solid"
        << "none"

        // font
        << "normal"
        << "italic"
        << "oblique"
        << "bold"

        // gradients
        << "qlineargradient"
        << "qradialgradient"
        << "qconicalgradient"

        // origin
        << "margin"
        << "border"
        << "padding"
        << "content"

        // palette role
        << "alternate-base"
        << "base"
        << "bright-text"
        << "button"
        << "button-text"
        << "dark"
        << "highlight"
        << "highlighted-text"
        << "light"
        << "link"
        << "link-visited"
        << "mid"
        << "midlight"
        << "shadow"
        << "text"
        << "window"
        << "window-text"

        // repeat
        << "repeat"
        << "repeat-x"
        << "repeat-y"
        << "no-repeat"
        ;

    listKeywords.removeDuplicates();

    foreach(const QString & word, listKeywords)
    {
        api->add(word);
    }

    QEventLoop loop;

    connect(api, SIGNAL(apiPreparationFinished()), &loop, SLOT(quit()));

    api->prepare();

    loop.exec();

    setAPIs(api);
}

QsciLexerAs::~QsciLexerAs()
{

}

QColor QsciLexerAs::defaultColor(int style) const
{
    switch (style)
    {
    case Default:
        return QColor(0x80, 0x80, 0x80);

    case Comment:
    case CommentLine:
        return QColor(0x00, 0x7f, 0x00);

    case CommentDoc:
        return QColor(0x3f, 0x70, 0x3f);

    case Number:
        return QColor(0x00, 0x7f, 0x7f);

    case Keyword:
        return QColor(0x00, 0x00, 0x7f);

    case DoubleQuotedString:
        return QColor(0x7f, 0x00, 0x7f);

        //case PreProcessor:
        //    return QColor(0x7f, 0x7f, 0x00);

    case Operator:
        return QColor(0x00, 0x00, 0x00);
    }

    return QsciLexer::defaultColor(style);
}
const char* QsciLexerAs::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return
            ".PROGRAM .END .TRANS .JOINTS .REALS .STRINGS "
            "IF ELSE CASE VALUE BITS "
            ;

    case 2:
        return
            "TWAIT SIGNAL SIG SWAIT PRINT "
            "POINT POINT/OAT "
            ;
    }

    return 0;
}

QFont QsciLexerAs::defaultFont(int style) const
{
    QFont f;

    switch (style)
    {
    case Comment:
    case CommentLine:
    case CommentDoc:
#if defined(Q_OS_WIN)
        f = QFont("Comic Sans MS", 9);
#elif defined(Q_OS_MAC)
        f = QFont("Comic Sans MS", 12);
#else
        f = QFont("Bitstream Vera Serif", 9);
#endif
        break;

    case Keyword:
    case Operator:
        f = QsciLexer::defaultFont(style);
        f.setBold(true);
        break;

    case DoubleQuotedString:
#if defined(Q_OS_WIN)
        f = QFont("Courier New", 10);
#elif defined(Q_OS_MAC)
        f = QFont("Courier", 12);
#else
        f = QFont("Bitstream Vera Sans Mono", 9);
#endif
        break;

    default:
        f = QsciLexer::defaultFont(style);
    }

    return f;
}

const char* QsciLexerAs::language() const
{
    return "AS";
}
QString QsciLexerAs::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");

    case Comment:
        return tr("C comment");

    case CommentLine:
        return tr("C++ comment");

    case CommentDoc:
        return tr("JavaDoc style C comment");

    case Number:
        return tr("Number");

    case Keyword:
        return tr("Keyword");

    case DoubleQuotedString:
        return tr("Double-quoted string");


    case Operator:
        return tr("Operator");



    case Identifier:
        return tr("Identifier");


    }

    return QString();
}

const char* QsciLexerAs::blockStart(int* style) const
{
    if (style)
        *style = Operator;

    return "";
}


// Return the list of characters that can end a block.
//const char* QsciLexerAs::blockEnd(int* style) const
//{
//    if (style)
//        *style = Operator;

//    return ".END";
//}

const char* QsciLexerAs::lexer() const
{
    return (nocase ? "asnocase" : "as");
}

// Set if comments can be folded.
void QsciLexerAs::setFoldComments(bool fold)
{
    fold_comments = fold;

    setCommentProp();
}

void QsciLexerAs::setCommentProp()
{
    emit propertyChanged("fold.comment", (fold_comments ? "1" : "0"));
}


//const char* QsciLexerAs::blockStartKeyword(int* style ) const
//{
//    if (style)
//        *style = Keyword;

//    return ".PROGRAM .TRANS .JOINTS .REALS .STRINGS "
//        ".STRINGS";
//}

const char* QsciLexerAs::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#$";
}



// Refresh all properties.
void QsciLexerAs::refreshProperties()
{
    setCompactProp();
}


// Read properties from the settings.
bool QsciLexerAs::readProperties(QSettings& qs, const QString& prefix)
{
    int rc = true;

    fold_compact = qs.value(prefix + "foldcompact", true).toBool();

    return rc;
}


// Write properties to the settings.
bool QsciLexerAs::writeProperties(QSettings& qs, const QString& prefix) const
{
    int rc = true;

    qs.setValue(prefix + "foldcompact", fold_compact);

    return rc;
}


// Return true if folds are compact.
bool QsciLexerAs::foldCompact() const
{
    return fold_compact;
}


// Set if folds are compact.
void QsciLexerAs::setFoldCompact(bool fold)
{
    fold_compact = fold;

    setCompactProp();
}


// Set the "fold.compact" property.
void QsciLexerAs::setCompactProp()
{
    emit propertyChanged("fold.compact", (fold_compact ? "1" : "0"));
}
