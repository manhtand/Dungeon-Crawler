#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
namespace Ui { class StartScreen; }

class GraphicalUI;

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(GraphicalUI*, QWidget* parent = nullptr);
    ~StartScreen();

private:
    GraphicalUI* graphicalui;
    Ui::StartScreen* ui;
};

#endif // STARTSCREEN_H
