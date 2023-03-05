#ifndef QCOMMAND_PROMPT_H
#define QCOMMAND_PROMPT_H

#include <QPlainTextEdit>
#include <QStringList>
#include <QQueue>
#include <QMutex>

#include "IConsole.h"


class QTimer;


//-------------------------------------------------------------------------------------------------
class QCommandPrompt : public QPlainTextEdit,
                       public IConsole
{
    Q_OBJECT

public:

    explicit QCommandPrompt(QWidget *parent = 0);
    virtual ~QCommandPrompt();

    void setPrompt(QString sPrompt, QString sPromptChar);
    QString getPrompt() const;

    void setMaxLines(int nLines);
    void setMaxHistSize(int nSize);
    void setFontSize(int nSize);
    void setOutputInterval(int nInterval);
    void setOutputBlockSize(int nLines);

    void mute(bool bStat);

    void clear();
    void clearHistory();
    QString getLastInput() const;

    // IConsole Interface
    virtual void addLine(QString sText, QColor col);
    virtual void addLine(QString sText);
    virtual void clearQueue();

signals:
    void commandInput(const QString &sCmd);

public slots:
    void writeQueue();

private:

    QString m_sPrompt;          ///< Der Konsolenprompt
    QString m_sPromptChar;
    QString m_sLastInput;       ///< Der letzte user input, wird mit RETURN zurückgesetzt
    QStringList m_vHistory;
    QQueue< QPair<QString, QColor> > m_vLineQueue;
    QTimer *m_pTimerQueue;
    QFont m_font;
    QMutex m_mtxLineQueue;
    const QColor m_colDefault;

    int m_nHistPos;
    int m_nMaxLines;
    int m_nMaxHist;
    int m_nPromptPos;

    int m_nTimerInterval;
    int m_nBlockSize;

    bool m_bIsMuted;

    void write(QString sText, QColor col = Qt::black);
    void clearLineExceptPrompt();
    void keyPressEvent(QKeyEvent *event);
};

#endif // CONSOLE_H
