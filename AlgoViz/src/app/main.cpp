#include "AlgoViz.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <iostream>
#include <QDebug>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AlgoViz w;

    QRect mainWIndowSize = QApplication::desktop()->screenGeometry();
    w.setMinimumSize(mainWIndowSize.width(), mainWIndowSize.height());

    QFile file(":/styles/main_window.css");
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "File not open" << file.error();
    }
    else {
        qDebug() << "File open";
        QString styleSheet = QLatin1String(file.readAll());
        w.setStyleSheet(styleSheet);
    }
    w.show();
    return a.exec();
}
