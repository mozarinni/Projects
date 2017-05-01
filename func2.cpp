#include "func2.h"
#include "ui_func2.h"
#include "QVector"
#include "iterator"
#include "iostream"
#include "QtAlgorithms"
#include "iomanip"
#include "math.h"
#include <QtCore>
#include <QTableWidget>
#include <QSpinBox>
#include <QLabel>
#include <QString>


QVector<QVector<int>> src;
QVector<QVector<int>> dest;
QVector<QVector<int>> undef;

using namespace std;

func2::func2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::func2)
{
    ui->setupUi(this);

}

func2::~func2()
{
    delete ui;
}


void func2::make_tuples_polynom(QVector<int> s, back_insert_iterator<QVector<QVector<int>>> d)
{
    auto i = qFind(s.begin(), s.end(), 0);
    if (i == s.end())
    {
        d = s;
        return;
    }
    *i = -1;
    make_tuples_polynom(s, d);
    *i = 1;
    make_tuples_polynom(s, d);
}

void func2::make_tuples(QVector<int> s, back_insert_iterator<QVector<QVector<int>>> d)
{
    auto i = qFind(s.begin(), s.end(), -1);
    if (i == s.end())
    {
        d = s;
        return;
    }
    *i = 0;
    make_tuples(s, d);
    *i = 1;
    make_tuples(s, d);
}

int func2::RowCount(int **m, int row, int col, int num) {
    double numOfPositiveRows = 0, tempIndex = 0;
    int row1 = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == num) {
                tempIndex += 1;
            }
            if (j == (col - 1) && (tempIndex == 0)) {
                numOfPositiveRows += 1;
            }
        }
        if (tempIndex != 0)
            row1 += pow(2, tempIndex);
        tempIndex = 0;
    }
    row1 += numOfPositiveRows;
    return row1;
}

int** func2::Combination(int **m, int row, int col) {
    src.clear();
    dest.clear();
    double row1 = RowCount(m,row,col,-1);
        src.resize(row);
        for (int i = 0; i < row; ++i)
            src[i].resize(col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                src[i][j] = m[i][j];
                }
        }

        for (int i = 0; i < src.size(); ++i)
        {
            if (std::any_of(src[i].begin(), src[i].end(), [](int j) { return j == -1; }))
            {
                make_tuples(src[i], back_inserter(dest));
            }
            else
                dest.push_back(src[i]);
        }


        int **newMatr = new int *[row1];
        for (int i = 0; i < row1; i++) {
            newMatr[i] = new int[col];
        }
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col; j++) {
                newMatr[i][j] = dest[i][j];
            }
        }
        return newMatr;
}

int** func2::Combination_polynom(int **m, int row, int col) {
    int row1 = RowCount(m, row, col,0);
    src.clear();
    dest.clear();
    src.resize(row);
    for (int i = 0; i < row; ++i) {
        src[i].resize(col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            src[i][j] = m[i][j];
        }
    }

    for (int i = 0; i < src.size(); ++i)
    {
        if (any_of(src[i].begin(), src[i].end(), [](int j) { return j == 0; }))
        {
            make_tuples_polynom(src[i], back_inserter(dest));
        }
        else
            dest.push_back(src[i]);
    }

    int **newMatr = new int *[row1];
    for (int i = 0; i < row1; i++) {
        newMatr[i] = new int[col];
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col; j++) {
            newMatr[i][j] = dest[i][j];
        }
    }

    return newMatr;
}

int func2::RowCheck(int **m, int row, int col) {
    int similar;
    int h = 0;
    do {
        for (int i = 0; i < row; i++) {
            for (int k = i + 1; k < row; k++) {
                similar = 0;
                for (int j = 0; j < col; j++)
                {
                    if (m[i][j] == m[k][j]) { similar++; }
                    if (similar == col) {
                        delete[] m[k];
                        for (int l = k; l < row; l++) {
                            m[l] = m[l + 1];
                        }
                        row -= 1;
                    }
                }
            }
        }
        h++;
    } while (h < 2);
    return row;
}

int func2::MatrixCompare_1(int **m1, int **m2, int row1, int row2,  int col)
{
    int index = 0;
    for (int i = 0; i < row1; ++i) {
        for (int k = 0; k < row2; ++k) {
            int similar = 0;
            for (int j = 0; j < col; j++)
            {
                if (m1[i][j] == m2[k][j]) { similar++; }
                if (similar == col) { index++; }
            }
        }
    }
    if (index)
        return 1;
    else return 0;
}

int func2::MatrixCompare_2(int **m1, int **m2, int row1, int row2, int col)
{
    int index = 0;
    for (int i = 0; i < row1; ++i) {
        for (int k = 0; k < row2; ++k) {
            int similar = 0;
            for (int j = 0; j < col; j++)
            {
                if (m1[i][j] == m2[k][j]) { similar++; }
                if (similar == col) { index++; }
            }
        }
    }
    if (index == row1)
        return 1;
    else return 0;
}

int func2::undefMatrix (int **m1,int **m2, int **result, int row1, int row2,int row, int col) {

    for (int i = 0; i < row1; i++) {
        for (int k = 0; k < row; k++) {
            int similar = 0;
            for (int j = 0; j < col; j++)
            {
                if (m1[i][j] == result[k][j]) { similar++; }
                if (similar == col) {
                    delete[] result[k];
                    for (int l = k; l < row; l++) {
                        result[l] = result[l + 1];
                    }
                    row -= 1;
                }
            }
        }
    }
    for (int i = 0; i < row2; i++) {
        for (int k = 0; k < row; k++) {
            int similar = 0;
            for (int j = 0; j < col; j++)
            {
                if (m2[i][j] == result[k][j]) { similar++; }
                if (similar == col) {
                    delete[] result[k];
                    for (int l = k; l < row; l++) {
                        result[l] = result[l + 1];
                    }
                    row -= 1;
                }
            }
        }
    }
    return row;
}

string func2::polynom(int **m, int row, int col) {
    char polynom[100] = "P(x) = ";
    int notone = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char index[2] = "";
            char x[3] = "X";
            if (m[i][j] == 1)
            {
                _itoa_s((j + 1), index, 10);
                strcat_s(x, index);
                strcat_s(polynom, x);
            }
            else notone++;

            if ((j == (col - 1)) && (i != (row - 1)) && (notone != col))
            {
                strcat_s(polynom, "^");
            }

        }
        notone = 0;
    }  string str=polynom;
    return str;
}

int func2::MatrixCheck(int **m, int row, int col) {
    int similar;
    int index = 0;
        for (int i = 0; i < row; i++) {
            for (int k = i + 1; k < row; k++) {
                similar = 0;
                for (int j = 0; j < col; j++)
                {
                    if (m[i][j] == m[k][j]) { similar++; }
                    if (similar == col) {
                        index++;
                        }
                    }
                }
            }
        if (index)
            return 1;
        else return 0;
}

void func2::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget1->setColumnCount(ui->spinBox->value());
    ui->tableWidget2->setColumnCount(ui->spinBox->value());
}

void func2::on_spinBox_1_valueChanged(int arg1)
{

    ui->tableWidget1->setRowCount(ui->spinBox_1->value());
}

void func2::on_spinBox_2_valueChanged(int arg1)
{

    ui->tableWidget2->setRowCount(ui->spinBox_2->value());
}

void func2::on_pushButton_clicked()
{
    int row0_1=ui->spinBox_1->value();
    int row1_1=ui->spinBox_2->value();
    double row0_2,row1_2;
    int row0_3,row1_3;
    int n =ui->spinBox->value();

    int **matrix0_1 = new int*[row0_1];
     for (int i = 0; i < row0_1; i++)
         matrix0_1[i] = new int[n];

     int **matrix1_1 = new int*[row1_1];
      for (int i = 0; i < row1_1; i++)
          matrix1_1[i] = new int[n];


     for (int i = 0; i < row0_1; i++)
     {
         for (int j = 0; j < n; j++)
         {
             matrix0_1[i][j]=(ui->tableWidget1->item(i,j)->text()).toInt();
         }

     }
     int** matrix0_2 = Combination(matrix0_1,row0_1,n);
     row0_2 = RowCount(matrix0_1,row0_1,n,-1);
     row0_3 = RowCheck(matrix0_2,row0_2,n);

     for (int i = 0; i < row1_1; i++)
     {
         for (int j = 0; j < n; j++)
         {
             matrix1_1[i][j]=(ui->tableWidget2->item(i,j)->text()).toInt();
         }

     }
     int** matrix1_2 = Combination(matrix1_1,row1_1,n);
     row1_2 = RowCount(matrix1_1,row1_1,n,-1);
     row1_3 = RowCheck(matrix1_2,row1_2,n);
     if (!(MatrixCompare_1(matrix0_2,matrix1_2,row0_3,row1_3,n)))
             ui->label_5->setText("Orthogonal");
             else ui->label_5->setText("Non-orthogonal");
}


void func2::on_pushButton_2_clicked()
{
    QString a = ui->tableWidget1->item(0,0)->text();
    ui->label_6->setText(a);
            /*int row0_1=ui->spinBox_1->value();
     int n =ui->spinBox->value();

     int **matrix0_1 = new int*[row0_1];
      for (int i = 0; i < row0_1; i++)
          matrix0_1[i] = new int[n];

    for (int i = 0; i < row0_1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix0_1[i][j]=(ui->tableWidget1->item(i,j)->text()).toInt();
        }

    }
    ui->label_6->setText(QString::number(matrix0_1[0][0]));
    ui->label_7->setText(QString::number(matrix0_1[0][1]));
    ui->label_8->setText(QString::number(matrix0_1[0][2]));
    for (int i=0; i< ui->spinBox->value(); i++){
        for (int j = 0; j< ui->spinBox_1->value(); j++){
            QSpinBox* SpinBox_01 = new QSpinBox;
            ui->tableWidget1->setCellWidget(j, i, SpinBox_01);
           SpinBox_01->setRange(-1, 1);
        }
    }
    for (int i=0; i<ui->spinBox->value(); i++){
        for (int j = 0; j<ui->spinBox_2->value(); j++){
            QSpinBox* SpinBox_11 = new QSpinBox;
            ui->tableWidget1->setCellWidget(j, i, SpinBox_11);
           SpinBox_11->setRange(-1, 1);
        }
    }*/
}
