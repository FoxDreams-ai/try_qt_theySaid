#include "solve_r.h"
#include "ui_solve_r.h"

Solve_r::Solve_r(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Solve_r)
{
    ui->setupUi(this);
}

Solve_r::~Solve_r()
{
    delete ui;
}
