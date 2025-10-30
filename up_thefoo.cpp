#include <QThread>
#include "up_thefoo.h"
#include "dialog.h"
#include "frame.h"

Up_theFoo::Up_theFoo(QObject *parent)
    : QObject(parent),
    Fra(nullptr),
    window(nullptr)
{
}

void Up_theFoo::ScreenGet(Frame *F){
    Dialog *window  =new Dialog(F);

    QScreen *screen = QGuiApplication::primaryScreen();
    vertical_pos = (screen->size().height())/2;
    vertical_pos -=(window->size().height())/2;

    horisontal_pos = (screen->size().width())/2;
    horisontal_pos -=(window->size().width())/2;
}

Dialog* Up_theFoo::Generate_7(Frame *F) {

    for(int i = 0;i<7;i++)
    {
        Dialog *window = new Dialog(F);
        window->show();
        Move_Target(window);
        QThread::sleep(1);
    }
    return window;
}

void Up_theFoo::Move_Target(Dialog *window){
    window->move(0,0);
    window->move(horisontal_pos,vertical_pos);
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
