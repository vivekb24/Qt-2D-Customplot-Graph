#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QGradient>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void addpoint(double x, double y);
    void clearData();
    void Plot();
private slots:
    void on_btn_add_clicked();
    void on_btn_clear_clicked();
private:
    Ui::MainWindow *ui;
    QVector<double>qv_x,qv_y;
};

#endif // MAINWINDOW_H
