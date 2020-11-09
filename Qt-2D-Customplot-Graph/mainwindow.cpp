#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->xAxis->setLabel("X-AXIS");
    ui->customPlot->yAxis->setLabel("Y-AXIS");
    ui->customPlot->xAxis->setRange(0,6);
    ui->customPlot->yAxis->setRange(0,50);

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(170, 100,100));
    gradient.setColorAt(0.38, QColor(240, 0, 0));
    gradient.setColorAt(1, QColor(150, 150, 30));

    ui->customPlot->setBackground(QBrush(gradient));
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->rescaleAxes();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addpoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}
void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}
void MainWindow::Plot()
{
    ui->customPlot->graph(0)->setData(qv_x,qv_y);
    ui->customPlot->replot();
    ui->customPlot->update();
}

void MainWindow::on_btn_add_clicked()
{
    addpoint(ui->bx_x->value(),ui->bx_y->value());
    Plot();
}
void MainWindow::on_btn_clear_clicked()
{
    ui->bx_x->clear();
    ui->bx_y->clear();
    clearData();
    Plot();
}
