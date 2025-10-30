#ifndef SOLVE_R_H
#define SOLVE_R_H

#include <QWidget>

namespace Ui {
class Solve_r;
}

class Solve_r : public QWidget
{
    Q_OBJECT

public:
    explicit Solve_r(QWidget *parent = nullptr);
    ~Solve_r();

private:
    Ui::Solve_r *ui;
};

#endif // SOLVE_R_H
