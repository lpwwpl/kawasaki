#include <cctype>
#include <fstream>
#include <cassert>

#include <sstream>
#include "translator.hpp"
#include "ast.h"
#include "symboltable.h"
#include "errors.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
int lineNumber = 1;

namespace Language
{

Translator::Translator()
{
}

void Translator::PrepareCommandLineArguments(const int argc, char **argv)
{
    int expectedArgumentCount = SymbolTable::Instance().EntryPoint()->Arguments()->size();

    if (expectedArgumentCount != argc-2)
    {
        std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "script entry point\n";
        exit(EXIT_FAILURE);
    }

    SymbolTable::Instance().PushCommandLineArguments(argc-2, &argv[2]);
}

int Translator::parse(const QString& codestr)
{    
    QFileInfo fileInfo(codestr);
    if (!fileInfo.exists())
        return -1;
    std::cout << codestr.toStdString() << endl;
    std::ifstream in_file(codestr.toStdString().c_str());
    if (!in_file.good())
    {
        std::cerr << BAD_SCRIPT_FILE << std::endl;
        exit(EXIT_FAILURE);
    }
    Lexer lexer(&in_file);
    Parser parser(lexer);

    if (parser.parse() != 0)
    {
        std::cerr << "Parse failed!!\n";
    }

    /////PrepareCommandLineArguments(argc, argv);
    //std::cout << "------compile Info:------" << std::endl;
    //QString str = SymbolTable::Instance().EntryPoint()->toString();
    //std::cout << str.toStdString() << std::endl;
    std::cout << "------RunTime Info:------" << std::endl;
    //return SymbolTable::Instance().EntryPoint()->Execute().toInt();
    QString str = SymbolTable::Instance().toString();
    QString baseName = fileInfo.baseName();
    QDir dir=fileInfo.absoluteDir();
    QString dst = QString("%1/%2.py").arg(dir.absolutePath()).arg(baseName);
    QFile file(dst);
    bool isOK = file.open(QIODevice::WriteOnly);
    file.write(str.toStdString().data());
    file.flush();
    file.close();
    return 1;
}
int Translator::parse(int argc, char **argv)
{

   const char* filename = "D:/code.txt";// argv[1];

   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       std::cerr << BAD_SCRIPT_FILE << std::endl;
       exit( EXIT_FAILURE );
   }

   Lexer lexer(&in_file);
   Parser parser(lexer);

   if( parser.parse() != 0 )
   {
      std::cerr << "Parse failed!!\n";
   }

   PrepareCommandLineArguments(argc, argv);
   //std::cout << "------compile Info:------" << std::endl;
   //QString str = SymbolTable::Instance().EntryPoint()->toString();
   //std::cout << str.toStdString() << std::endl;
   std::cout << "------RunTime Info:------" << std::endl;
   QString str = SymbolTable::Instance().toString();
   QFile file("D:/testlpw.txt");
   bool isOK = file.open(QIODevice::WriteOnly);
   file.write(str.toStdString().data());
   file.flush();
   file.close();
   return 1;

   //return SymbolTable::Instance().EntryPoint()->Execute().toInt();
}
}
