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
    Dialog* Generate_7(Frame *F,int i);
    int vertical_pos   = 0;
    int horisontal_pos = 0;
private:
    QThread For_windows;
    Frame *Fra;

    Dialog *window;
    bool is_even = 0;
    int move_scaleing=1;

    int function_times_action = 7;
    int start_w_pos;
    int start_h_pos;
protected:
    //<summary> Принимает координаты и перемещает окна последовательно размещая их с правой и левой сторон</summary>
    void Move_Target(Dialog *window , Frame *F);

    void start_pos_init(){
        start_w_pos = vertical_pos;
        start_h_pos = horisontal_pos;

    };

    void Start_dialog_widgets(Dialog *window){
        window->move(start_h_pos , start_w_pos);
    }


};

#endif // UP_THEFOO_H
