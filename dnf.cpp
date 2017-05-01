#include "dnf.h"
#include "ui_dnf.h"
#include "func2.h"
#include "stdlib.h"
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
#include <QString>
#include <QMessageBox>

using namespace std;

Dnf::Dnf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dnf)
{

    ui->setupUi(this);
}

Dnf::~Dnf()
{
    delete ui;
}
/*
void polynom_1(int **m, int row, int col) {
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
     ui->label_2->setText(str);
}
*/
void Dnf::on_spinBox_valueChanged(int arg1)
{
    int n = ui->spinBox->value();
    ui->tableWidget2->setRowCount(0);
    ui->tableWidget1->setColumnCount(ui->spinBox->value());
    ui->tableWidget2->setColumnCount(ui->spinBox->value());
ui->tableWidget1->setRowCount(pow(2,n));
ui->spinBox_1->setMaximum(pow(2,n));
}

void Dnf::on_spinBox_1_valueChanged(int arg1)
{
    int n = pow(2,ui->spinBox->value());
    ui->tableWidget2->setRowCount(n-(ui->spinBox_1->value()));
    ui->tableWidget1->setRowCount(ui->spinBox_1->value());
}


void Dnf::on_pushButton_clicked()
{
    ui->pushButton_2->setEnabled(false);
    int n =ui->spinBox->value();
    func2 object;
    int row0_1=ui->spinBox_1->value();
    int row1_1=pow(2,n)-row0_1;
    double row0_2,row1_2;
    int row0_3,row1_3;

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
     for (int i = 0; i < row1_1; i++)
     {
         for (int j = 0; j < n; j++)
         {
             matrix1_1[i][j]=(ui->tableWidget2->item(i,j)->text()).toInt();
         }

     }
    if ((object.MatrixCompare_1(matrix0_1,matrix1_1,row0_1,row1_1,n)==1)||(object.MatrixCheck(matrix0_1,row0_1,n)==1)||(object.MatrixCheck(matrix1_1,row1_1,n)==1))
    {

        ui->label_5->setText("Error! \nRedefine function");
    }
    else
    {
        ui->label_5->setText("OK");
        ui->pushButton_2->setEnabled(true);
    }
}

void Dnf::on_pushButton_2_clicked()
{    func2 obj;
    int n =ui->spinBox->value();

    int row0_1=ui->spinBox_1->value();
    int row0_2,row0_3;

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

    int** matrix0_2 = obj.Combination_polynom(matrix0_1,row0_1,n);
    row0_2 = obj.RowCount(matrix0_1,row0_1,n,0);
    row0_3 = obj.RowCheck(matrix0_2,row0_2,n);
    char polynom[100] = "P(x) = ";
    int notone = 0;

    for (int i = 0; i < row0_3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char index[2] = "";
            char x[3] = "X";
            if (matrix0_2[i][j] == 1)
            {
                _itoa_s((j + 1), index, 10);
                strcat_s(x, index);
                strcat_s(polynom, x);
            }
            else notone++;

            if ((j == (n - 1)) && (i != (row0_3 - 1)) && (notone != n))
            {
                strcat_s(polynom, "^");
            }

        }
        notone = 0;
    } // string str=polynom;
     ui->label_2->setText(polynom);
}

void Dnf::on_tableWidget1_cellClicked(int row, int column)
{
    QTableWidgetItem *itab = new QTableWidgetItem;
    itab->setText("1");
    ui->tableWidget1->setItem(row,column,itab);
    if(ui->tableWidget1->item(row,column)->text()=="1"){
        // QTableWidgetItem *itab = new QTableWidgetItem;
        itab->setText("0");
        ui->tableWidget1->setItem(row,column,itab);
}
}
