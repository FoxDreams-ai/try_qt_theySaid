#ifndef FRAME_H
#define FRAME_H

#include <QMainWindow>
#include "up_thefoo.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Frame;
}
QT_END_NAMESPACE

class Frame : public QMainWindow
{
    Q_OBJECT

public:
    Frame(QWidget *parent = nullptr);
    ~Frame();


private slots:
    void on_commandLinkButton_clicked();
    void Frames_amount(bool l);
private:
    Ui::Frame *ui;

};
#endif // FRAME_H
