#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,18}")));//validator to prevent wrong input
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty()){//check to prevent null reference exception
        QString s = n.NumberToString(ui->lineEdit->text());
        ui->textBrowser->clear();//clearing text browser for new output
        if (!s.startsWith("*")){//function returning '*' is custom exception call
            ui->textBrowser->setText(s);
        }
        else{
            ui->textBrowser->setText("error");
        }
    }
}
