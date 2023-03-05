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

#ifndef QSCILEXERAS_H
#define QSCILEXERAS_H

#include <QObject>

#include <Qsci/qsciglobal.h>
#include <Qsci/qscilexer.h>


class  QSCINTILLA_EXPORT QsciLexerAs : public QsciLexer
{
    //Q_OBJECT

public:
    enum {
        //! The default.
        Default = 0,
        //! An identifier
        Identifier = 1,
        //! A '{ ... }' style comment.
        Comment = 2,

        CommentDoc = 3,
        //! A comment line.
        CommentLine = 4,
        //! A keyword.
        Keyword = 5,
        //! A number.
        Number = 6,
        Operator = 7,
        DoubleQuotedString = 8,
    };

    QsciLexerAs(QObject *parent = 0);
    virtual ~QsciLexerAs();
    virtual const char *keywords(int set) const;
    virtual QFont defaultFont(int style) const;
    QColor defaultColor(int style) const;
    const char* /*QsciLexerAs::*/language() const;
    QString description(int style) const;

    const char* blockStart(int* style) const;
    const char* lexer() const;
//    const char* blockStartKeyword(int* style = 0) const;
    // Return the list of characters that can end a block.
//    const char* blockEnd(int* style) const;
    const char* wordCharacters() const;
    bool foldComments() const { return fold_comments; }


    //! Causes all properties to be refreshed by emitting the
    //! propertyChanged() signal as required.
    void refreshProperties();

    //! Returns true if trailing blank lines are included in a fold block.
    //!
    //! \sa setFoldCompact()
    bool foldCompact() const;

public slots:
    //! If \a fold is true then trailing blank lines are included in a fold
    //! block. The default is true.
    //!
    //! \sa foldCompact()
    virtual void setFoldCompact(bool fold);
    virtual void setFoldComments(bool fold);
protected:
    //! The lexer's properties are read from the settings \a qs.  \a prefix
    //! (which has a trailing '/') should be used as a prefix to the key of
    //! each setting.  true is returned if there is no error.
    //!
    bool readProperties(QSettings &qs,const QString &prefix);

    //! The lexer's properties are written to the settings \a qs.
    //! \a prefix (which has a trailing '/') should be used as a prefix to
    //! the key of each setting.  true is returned if there is no error.
    //!
    bool writeProperties(QSettings &qs,const QString &prefix) const;

private:
    void setCompactProp();
    void setCommentProp();

    QsciLexerAs(const QsciLexerAs&);
    QsciLexerAs& operator=(const QsciLexerAs&);
        bool fold_compact;
        bool fold_comments;
        bool nocase;
};

#endif // QSCILEXERQSS_H
