#ifndef MINIMAP_H
#define MINIMAP_H

#include <Qsci/qsciscintilla.h>

class MiniMap : public QsciScintilla /*,ISettingsProvider*/
{
    //Q_OBJECT

public:
    explicit MiniMap(QWidget * parent = nullptr);
    void setStyleSheet(QString t_filename);

    //virtual void writeSettings(QSettings& settings);
    //virtual void readSettings(QSettings& settings);
    //virtual void updateFromSettings();
};

#endif // MINIMAP_H
