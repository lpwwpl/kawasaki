/*===========================================================================
    CLIPSEditor, editor for CLIPS (C Language Integrated Production System)
    Copyright (C) 2012-2018 Artem G. Novikov

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
===========================================================================*/



#include <QApplication>


#include <QMap>
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "grammar/translator.hpp"
#include <QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include "WndMain.h"
#include "Exceptions.h"


#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QCommandLineParser>
int main(int argc, /*const*/ char** argv)
{

    //QCommandLineParser parser;
    //parser.setApplicationDescription(QGuiApplication::translate("main", "Qt"));  // 设置应用程序描述信息
    //parser.addHelpOption();  // 添加帮助选项 （"-h" 或 "--help"）
    //parser.addVersionOption();  // 添加版本选项 ("-v" 或 "--version") 

    //parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    //QCommandLineOption srcOption(QStringList() << "s" <<"src",
    //    QGuiApplication::translate("main", "source of As code."),
    //    QGuiApplication::translate("main", "source"), "");
    //parser.addOption(srcOption);

    //QApplication app(argc, argv);
    //parser.process(app);
    QString src = "D:/code.txt";//parser.value(srcOption);
     Language::Translator translator;
     return(translator.parse(src));

     ////Language::Translator translator;
     ////return(translator.parse(argc, argv));
     /*
    try
    {
        QApplication a(argc, argv);
        a.setOrganizationName("beltoforion");
        a.setOrganizationDomain("beltoforion.de");
        a.setApplicationName("As");
        a.setApplicationVersion("1.0");

        QSplashScreen* splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/images/res/splash.png"));
        splash->show();

        WndMain w;
        QTimer::singleShot(2500, splash, SLOT(close()));
        QTimer::singleShot(2500, &w, SLOT(show()));

        return a.exec();
    }
    catch (Exception& exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.getMessage());
        msgBox.exec();
    }
    catch (std::exception& exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.what());
        msgBox.exec();
    }
    catch (...)
    {
        QMessageBox msgBox;
        msgBox.setText("Program aborted due to an unexpected exception");
        msgBox.exec();
    }

    return -1;
    */
     //QApplication app(argc, argv);

     //Config config;

     //qApp->setStyleSheet(config.style);

     //QStringList arguments = QCoreApplication::arguments();
     //arguments.removeFirst();
     //config.openFiles += arguments;

     //QString locale = config.languages.value(config.language);

     //QTranslator trans1;
     //trans1.load(":/lang/clipseditor_" + locale);
     //app.installTranslator(&trans1);

     //QTranslator trans2;
     //trans2.load(":/lang/qtbase_" + locale);
     //app.installTranslator(&trans2);

     //app.setWindowIcon(QPixmap(":/rc/icon.png"));

     //MainWindow window(&config);
     //window.show();

     //return app.exec();
}


