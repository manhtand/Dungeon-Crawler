#include "startscreen.h"
#include "ui_startscreen.h"
#include "GUI/graphicalui.h"

StartScreen::StartScreen(GraphicalUI* p_graphicalui, QWidget *parent) : QDialog(parent), graphicalui(p_graphicalui), ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    ui->btnNewGame->setIcon(*graphicalui->getTexture("tex_new_game_button"));
    ui->startScreenTexture->setPixmap( *graphicalui->getTexture("tex_startscreen") );
    connect(ui->btnNewGame, SIGNAL(clicked()), graphicalui, SLOT(btnNewGame()));
}

StartScreen::~StartScreen() {
    delete ui;
}

