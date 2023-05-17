#include <QApplication>
#include <iostream>
using namespace std;

#include <dungeoncrawler.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DungeonCrawler dc;
    return a.exec();
}
