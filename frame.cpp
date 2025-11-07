#include "frame.h"
#include "./ui_frame.h"
#include "up_thefoo.h"

Frame::Frame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Frame)
{
    ui->setupUi(this);
}

Frame::~Frame()
{
    delete ui;
}

int i= 0;

void Frame::Frames_amount(bool l){
    if(l){i++;}
    else {i--;}
}

void Frame::on_commandLinkButton_clicked()
{
    Up_theFoo up;
    up.ScreenGet(this);
    up.Generate_7(this,i);
}



