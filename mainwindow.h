#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include <QRegExp>
#include "numbertostringconvertor.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_pushButton_clicked();

private:
  NumberToStringConvertor n;
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
