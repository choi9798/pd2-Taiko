#ifndef PLAY_H
#define PLAY_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QLabel>
#include <QPixmap>
#include <time.h>
#include <QtGlobal>
#include <QMessageBox>
#include <QSound>

namespace Ui {
class Play;
}

class Play : public QMainWindow
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = 0);
    void starttime();
    void keyPressEvent(QKeyEvent *event);
    ~Play();

private slots:
    void timeoutEvent();

private:
    Ui::Play *ui;
    double time = 30;
    int mark = 0;
    QTimer *timer;
    QKeyEvent *event;
    int pos[8];
    int scorenum = 0;
};

#endif // PLAY_H
