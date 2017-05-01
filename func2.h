#ifndef FUNC2_H
#define FUNC2_H

#include "vector"
#include "iterator"
#include "iostream"
#include "QtAlgorithms"
#include "iomanip"
#include "math.h"
#include <QtCore>
#include <QTableWidget>
#include <QSpinBox>
#include <QLabel>
#include "algorithm"
#include "QVector"


using namespace std;

namespace Ui {
class func2;
}

class func2 : public QWidget
{
    Q_OBJECT

public:
    explicit func2(QWidget *parent = 0);

    void make_tuples_polynom(QVector<int> , back_insert_iterator<QVector<QVector<int>>>);

    void make_tuples(QVector<int>, back_insert_iterator<QVector<QVector<int>>>);

    int RowCount(int **, int , int , int );

    int** Combination(int **, int , int );

    int** Combination_polynom(int **, int , int );

    int RowCheck(int **, int , int );

    int MatrixCompare_1(int **, int **, int , int ,  int);

    int MatrixCompare_2(int **, int **, int , int, int);

    int undefMatrix (int **,int **, int **, int, int ,int, int);

    string polynom(int **, int, int);

    int MatrixCheck(int **,int, int);

    ~func2();
private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_spinBox_1_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::func2 *ui;
};

#endif // FUNC2_H
