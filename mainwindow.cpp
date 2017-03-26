#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numbertostringconvertor.h"
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,18}")));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty()){
        NumberToStringConvertor n;
        QString s = n.NumberToString(ui->lineEdit->text());
        ui->textBrowser->clear();
        if (!s.startsWith("*")){
            ui->textBrowser->setText(s);
        }
        else{
            ui->textBrowser->setText("error");
        }
    }
}
