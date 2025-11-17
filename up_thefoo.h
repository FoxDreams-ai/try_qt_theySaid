#ifndef UP_THEFOO_H
#define UP_THEFOO_H

#include <QObject>
#include <QThread>
#include <QScreen>

#include "dialog.h"
class Frame;


class Up_theFoo : public QObject
{
    Q_OBJECT
public:
    explicit Up_theFoo(QObject *parent = nullptr);
    void ScreenGet(Frame *F);
    //Метод сохранения выбраных выриантов

    Dialog* Generate_7(Frame *F,int i);

private:
    QThread For_windows;
    // Frame *Fra;

    Dialog *window;
    //Params
    bool is_even = 0;
    int move_scaleing=1;
    int function_times_action = 7;

    //смена положения окон
    int vertical_pos   = 0;
    int horisontal_pos = 0;

    int start_w_pos;
    int start_h_pos;

protected:
    //<summary> Принимает координаты и перемещает окна последовательно размещая их с правой и левой сторон</summary>
    void Move_Target(Dialog *window , Frame *F);
    QList<Dialog*> dialogs; //Храним созданные окна для дальнейшего доступа здесь.

    //Сохранение центра позиции для оследующего применения его для анимации и координации
    void start_pos_init(){
        start_w_pos = vertical_pos;
        start_h_pos = horisontal_pos;

    };

    void Start_dialog_widgets(Dialog *window){
        window->move(start_h_pos , start_w_pos);
    }

private:
    //Functions

    void Frame_update();


};

#endif // UP_THEFOO_H
