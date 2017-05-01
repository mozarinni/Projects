#ifndef DNF_H
#define DNF_H

#include <QWidget>

namespace Ui {
class Dnf;
}

class Dnf : public QWidget
{
    Q_OBJECT

public:
    explicit Dnf(QWidget *parent = 0);
    ~Dnf();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_1_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget1_cellClicked(int row, int column);

private:
    Ui::Dnf *ui;
};

#endif // DNF_H
