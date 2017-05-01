#include "polinom.h"
#include "ui_polinom.h"

polinom::polinom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::polinom)
{
    ui->setupUi(this);
}

polinom::~polinom()
{
    delete ui;
}
