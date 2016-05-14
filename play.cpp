#include "play.h"
#include "ui_play.h"

Play::Play(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Play)
{
    time = 30;
    scorenum = 0;
    ui->setupUi(this);
    for(int i=0;i<8;i++)
    {
        pos[i] = (rand() % 511+1)+800;
        for(int j=0;j<8;j++)
        {
            if(i == j)
            {
                continue;
            }
            else if(abs(pos[i] - pos[j]) < 60)
            {
                pos[i] = (rand() % 811+1)+800;
                j--;
            }
        }
    }
        ui->note0->setGeometry(pos[0], 135, 31, 31);
        ui->note1->setGeometry(pos[1], 135, 31, 31);
        ui->note2->setGeometry(pos[2], 135, 31, 31);
        ui->note3->setGeometry(pos[3], 135, 31, 31);
        ui->note4->setGeometry(pos[4], 135, 31, 31);
        ui->note5->setGeometry(pos[5], 135, 31, 31);
        ui->note6->setGeometry(pos[6], 135, 31, 31);
        ui->note7->setGeometry(pos[7], 135, 31, 31);
        ui->note8->setVisible(false);
        ui->note9->setVisible(false);
        ui->note10->setVisible(false);
        ui->note11->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);
}

Play::~Play()
{
    delete ui;
}

void Play::starttime()
{
    timer = new QTimer();
    QApplication::connect(timer, SIGNAL(timeout()), this, SLOT(timeoutEvent()));
    timer->start(10);
}

void Play::timeoutEvent()
{
    mark++;
    for(int i=0;i<8;i++)
    {
        pos[i]-=2;
    }
    for(int i=0;i<8;i++)
    {
        if(pos[i] < 0)
        {
            pos[i] = (rand() % 511+1)+800;
            for(int j=0;j<8;j++)
            {
                if(i == j)
                {
                    continue;
                }
                else if(abs(pos[i] - pos[j]) < 60)
                {
                    pos[i] = (rand() % 811+1)+800;
                    j--;
                }
            }
            if(i == 0)
                ui->note0->setVisible(true);
            else if(i == 1)
                ui->note1->setVisible(true);
            else if(i == 2)
                ui->note2->setVisible(true);
            else if(i == 3)
                ui->note3->setVisible(true);
            else if(i == 4)
                ui->note4->setVisible(true);
            else if(i == 5)
                ui->note5->setVisible(true);
            else if(i == 6)
                ui->note6->setVisible(true);
            else if(i == 7)
                ui->note7->setVisible(true);
        }

    }
    ui->note0->setGeometry(pos[0], 135, 31, 31);
    ui->note1->setGeometry(pos[1], 135, 31, 31);
    ui->note2->setGeometry(pos[2], 135, 31, 31);
    ui->note3->setGeometry(pos[3], 135, 31, 31);
    ui->note4->setGeometry(pos[4], 135, 31, 31);
    ui->note5->setGeometry(pos[5], 135, 31, 31);
    ui->note6->setGeometry(pos[6], 135, 31, 31);
    ui->note7->setGeometry(pos[7], 135, 31, 31);
    if(mark == 100)
    {
        time--;
        ui->timer_label->setNum(time);
        mark = 0;
    }
    if(time == 0)
    {
        QMessageBox::StandardButton abc = QMessageBox::information(NULL, "GameOver!", "Score:" + QString::number(scorenum)  + "\n play again?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
               if(abc == QMessageBox::Yes)
               {
                   time = 30;
                   scorenum = 0;
                   for(int i=0;i<8;i++)
                   {
                       pos[i] = (rand() % 511+1)+800;
                       for(int j=0;j<8;j++)
                       {
                           if(i == j)
                           {
                               continue;
                           }
                           else if(abs(pos[i] - pos[j]) < 60)
                           {
                               pos[i] = (rand() % 811+1)+800;
                               j--;
                           }
                       }
                   }
                   ui->note0->setGeometry(pos[0], 135, 31, 31);
                   ui->note1->setGeometry(pos[1], 135, 31, 31);
                   ui->note2->setGeometry(pos[2], 135, 31, 31);
                   ui->note3->setGeometry(pos[3], 135, 31, 31);
                   ui->note4->setGeometry(pos[4], 135, 31, 31);
                   ui->note5->setGeometry(pos[5], 135, 31, 31);
                   ui->note6->setGeometry(pos[6], 135, 31, 31);
                   ui->note7->setGeometry(pos[7], 135, 31, 31);
                   ui->timer_label->setNum(time);
                   ui->score->setNum(scorenum);
               }

               if(abc == QMessageBox::No)
               {

                   QApplication::quit();
               }
    }
}

void Play::keyPressEvent(QKeyEvent *event)
{
    QSound::play(":/img/dong.wav");
    if(event->key() == Qt::Key_F || event->key() == Qt::Key_J)
    {
        if(pos[0] >= 28 && pos[0] <= 44)
        {
            scorenum++;
            ui->note0->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[1] >= 28 && pos[1] <= 44)
        {
            scorenum++;
            ui->note1->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[2] >= 28 && pos[2] <= 44)
        {
            scorenum++;
            ui->note2->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[3] >= 28 && pos[3] <= 44)
        {
            scorenum++;
            ui->note3->setVisible(false);
            ui->score->setNum(scorenum);
        }
    }
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_K)
    {
        QSound::play(":/img/ka.wav");
        if(pos[4] >= 28 && pos[4] <= 44)
        {
            scorenum++;
            ui->note4->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[5] >= 28 && pos[5] <= 44)
        {
            scorenum++;
            ui->note5->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[6] >= 28 && pos[6] <= 44)
        {
            scorenum++;
            ui->note6->setVisible(false);
            ui->score->setNum(scorenum);
        }
        if(pos[7] >= 28 && pos[7] <= 44)
        {
            scorenum++;
            ui->note7->setVisible(false);
            ui->score->setNum(scorenum);
        }
    }
}
