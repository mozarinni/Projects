#ifndef POLINOM_H
#define POLINOM_H

#include <QWidget>

namespace Ui {
class polinom;
}

class polinom : public QWidget
{
    Q_OBJECT

public:
    explicit polinom(QWidget *parent = 0);
    ~polinom();

private:
    Ui::polinom *ui;
};

#endif // POLINOM_H
