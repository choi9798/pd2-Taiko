#ifndef TAIKO_H
#define TAIKO_H

#include <QMainWindow>
#include <QtCore>
#include <QLabel>
#include <QPushButton>
#include "play.h"

namespace Ui {
class Taiko;
}

class Taiko : public QMainWindow
{
    Q_OBJECT

public:
    explicit Taiko(QWidget *parent = 0);
    ~Taiko();

private slots:
    void on_playButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::Taiko *ui;
    Play pla;
};

#endif // TAIKO_H
