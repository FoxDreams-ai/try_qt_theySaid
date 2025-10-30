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
    Dialog* Generate_7(Frame *F);
    int vertical_pos   = 0;
    int horisontal_pos = 0;
private:
    Frame *Fra;

    Dialog *window;
    bool is_even = 0;
    int move_scaleing=1;
protected:
    //<summary> Принимает координаты и перемещает окна последовательно размещая их с правой и левой сторон</summary>
    void Move_Target(Dialog *window);

};

#endif // UP_THEFOO_H
