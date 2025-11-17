#include <QThread>
#include <QTimer>
#include <QPropertyAnimation>
#include "up_thefoo.h"
#include "dialog.h"
#include "frame.h"

Up_theFoo::Up_theFoo(QObject *parent)
    : QObject(parent),
    //Fra(nullptr),
    window(nullptr)
{
}


void Up_theFoo::ScreenGet(Frame *F){
    window  =new Dialog(F);
    QScreen *screen = QGuiApplication::primaryScreen();

    vertical_pos = (screen->size().height())/2;
    vertical_pos -=(window->size().height())/2;
    horisontal_pos = (screen->size().width())/2;
    horisontal_pos -=(window->size().width())/2;

    start_pos_init();
}


Dialog* Up_theFoo::Generate_7(Frame *F,int i) {
    for(int j = 0;j<i;j++)
    {
        Dialog *window = new Dialog(F);
        window->show();
        Start_dialog_widgets(window);
        dialogs.append(window);
            Move_Target(window, F);
}
    Frame_update();
    return window;
}


void Up_theFoo::Move_Target(Dialog *window, Frame *F){
        QPropertyAnimation *animation = new QPropertyAnimation(window, "pos");

    QScreen *screen = QGuiApplication::primaryScreen();
    horisontal_pos = std::clamp(horisontal_pos, 0, screen->size().width() - window->width());
    vertical_pos   = std::clamp(vertical_pos, 0, screen->size().height() - window->height());

        animation->setDuration(700);
        animation->setStartValue(QPoint(start_h_pos , start_w_pos));
        animation->setEndValue(QPoint(horisontal_pos, vertical_pos));
        animation->setEasingCurve(QEasingCurve::InBack);
        animation->start(QAbstractAnimation::DeleteWhenStopped);


        if(is_even){
            horisontal_pos += (window->size().width() * move_scaleing);
            is_even = !is_even;
            move_scaleing++;
        }
        else {
            horisontal_pos -= (window->size().width() * move_scaleing);
            vertical_pos -= 20;
            is_even = !is_even;
            move_scaleing++;
        }
}



void Up_theFoo::Frame_update(){
    for (Dialog* dlg : dialogs) {
        if (dlg && dlg->isVisible()) {
            dlg->setLineEditText("///////////////");
        dlg->repaint();
        }
    }
}
