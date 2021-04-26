#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QFile>

#include "newspaper.h"
#include "reader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Newspaper newspaper("Newspaper A");
        Reader reader;
        QObject::connect(&newspaper, &Newspaper::newPaper,
                         &reader,    &Reader::receiveNewspaper);
        newspaper.send();

    QFile files("worldappriciate.txt");
    files.open(QIODevice::WriteOnly);
    QTextStream stream(&files);
    stream << QString("abcdefg");
    if(files.exists())
    {
        qDebug() << "文件存在";
    }
    else
    {
        qDebug() <<"文件不存在";

    }
    files.close();

    return a.exec();
}
