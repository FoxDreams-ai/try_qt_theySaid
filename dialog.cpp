#include <QTimer>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setLineEditText(const QString &text)
{
    this->ui->lineEdit->setMaxLength(50);
    Loading.clear();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() mutable {

        if (Loading.size() >= ui->lineEdit->maxLength()) {
            if(ui->lineEdit->isVisible()){
                ui->lineEdit->hide();
            }
            timer->stop();
            timer->deleteLater();
        }
        else{

            Loading.append(text);
            ui->lineEdit->setText(Loading);
}
        });

    timer->start(15);
}
