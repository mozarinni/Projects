#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dnf.h"
#include "func2.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ if(ui->radioButton1->isChecked())
    {
    Dnf *d = new Dnf;
        d->show();
    }
    else if (ui->radioButton2->isChecked())
    {
        func2 *f = new func2;
        f->show();
    }
}
