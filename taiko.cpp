#include "taiko.h"
#include "ui_taiko.h"

#include <QtCore>

Taiko::Taiko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Taiko)
{
    ui->setupUi(this);
}

Taiko::~Taiko()
{
    delete ui;
}

void Taiko::on_playButton_clicked()
{
    close();
    pla.setFixedSize(511, 480);
    pla.show();
    pla.starttime();
}

void Taiko::on_exitButton_clicked()
{
    QApplication::quit();
}
