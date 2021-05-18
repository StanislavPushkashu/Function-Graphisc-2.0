#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Graph->xAxis->setLabel("x");
    ui->Graph->yAxis->setLabel("y");

    VarcLabel->setVisible(false);
    VarcLineEdit->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TOFComboBox_currentIndexChanged(int index)
{
    if (index == 3) {
        VarcLabel->setVisible(true);
        VarcLineEdit->setVisible(true);

        VarcLineEdit->setPlaceholderText("Enter variable c");
        VarcLineEdit->setText("1");

        ui->gridLayout->addWidget(VarcLabel, 0, 3);
        ui->gridLayout->addWidget(VarcLineEdit, 1, 3);
    }
    else {
        ui->gridLayout->removeWidget(VarcLabel);
        ui->gridLayout->removeWidget(VarcLineEdit);

        VarcLabel->setVisible(false);
        VarcLineEdit->setVisible(false);
    }
}

void MainWindow::on_DrawButton_clicked()
{
    if (Check_Function_Type() == 0)
        DrawLinear();
    else if (Check_Function_Type() == 1)
        DrawRadical();
    else if (Check_Function_Type() == 2)
        DrawModulus();
    else if (Check_Function_Type() == 3)
        DrawPower();
    else if (Check_Function_Type() == 4)
        DrawSinus();
    else if (Check_Function_Type() == 5)
        DrawCosinus();
    else if (Check_Function_Type() == 6)
        DrawTangent();
}

void MainWindow::DrawLinear() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(50), y(50);

    x[0] = -20;
    y[0] = Get_a_Variable() * x[0] + Get_b_Variable();

    for (int i = 1; i < 50; i++) {
        x[i] = x[i - 1] + 1;
        y[i] = Get_a_Variable() * x[i] + Get_b_Variable();
    }


    ui->Graph->addGraph();
    ui->Graph->xAxis->setRange(-20, 20);
    ui->Graph->yAxis->setRange(-20, 20);
    ui->Graph->graph(0)->addData(x, y);
    ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
    ui->Graph->replot();
}

void MainWindow::DrawRadical() {

    if (ui->Graph->graphCount() > 0)
            ui->Graph->clearGraphs();

   QVector <double> x1(201), x2(201), y1(200), y2(200);

   ui->Graph->addGraph();
   ui->Graph->addGraph();

   ui->Graph->xAxis->setRange(-20, 20);
   ui->Graph->yAxis->setRange(-10, 10);

   x1[0] = -20;
   y1[0] = Get_a_Variable() / x1[0] + Get_b_Variable();

   for (int i = 1; i < 200; i++)
       x1[i] = x1[i - 1] + 0.1;

   for (int i = 1; i < 200; i++) {
       y1[i] = Get_a_Variable() / x1[i] + Get_b_Variable();
   }

   x2[0] = 0;
   y2[0] = y1[199] * (-1);

   for(int i = 1; i < 200; i++) {
       x2[i] = x2[i - 1] + 0.1;
   }

   x2[0] = 0.1;

   for(int i = 1; i < 200; i++) {
       y2[i] = Get_a_Variable() / x2[i] + Get_b_Variable();
   }

   ui->Graph->graph(0)->addData(x1, y1);
   ui->Graph->graph(1)->addData(x2, y2);

   ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
   ui->Graph->graph(1)->setPen(QPen(Qt::green, 3));

   ui->Graph->replot();

}

void MainWindow::DrawModulus() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(50), y(50);

    x[0] = -20;
    y[0] = Get_a_Variable() * abs(x[0]) + Get_b_Variable();

    for (int i = 1; i < 50; i++) {
        x[i] = x[i - 1] + 1;
        y[i] = Get_a_Variable() * abs(x[i]) + Get_b_Variable();
    }

    ui->Graph->addGraph();
    ui->Graph->xAxis->setRange(-20, 20);
    ui->Graph->yAxis->setRange(0, 20);
    ui->Graph->graph(0)->addData(x, y);
    ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
    ui->Graph->replot();
}

void MainWindow::DrawPower() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(200), y(200);

    x[0] = -20;
    y[0] = Get_a_Variable() * pow(x[0], Get_c_Variable()) + Get_b_Variable();

    for (int i = 1; i < 200; i++) {
        x[i] = x[i - 1] + 0.25;
        y[i] = Get_a_Variable() * pow(x[i], Get_c_Variable()) + Get_b_Variable();
    }

    ui->Graph->addGraph();
    ui->Graph->xAxis->setRange(-20, 20);
    ui->Graph->yAxis->setRange(-20, 20);
    ui->Graph->graph(0)->addData(x, y);
    ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
    ui->Graph->replot();

}

void MainWindow::DrawSinus() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(200), y(200);

    x[0] = -20;
    y[0] = Get_a_Variable() * qSin(x[0]) + Get_b_Variable();

    for (int i = 1; i < 200; i++) {
        x[i] = x[i - 1] + 0.25;
        y[i] = Get_a_Variable() * qSin(x[i]) + Get_b_Variable();
    }

    ui->Graph->addGraph();
    ui->Graph->xAxis->setRange(-20, 20);
    ui->Graph->yAxis->setRange(-1.5, 1.5);
    ui->Graph->graph(0)->addData(x, y);
    ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
    ui->Graph->replot();
}

void MainWindow::DrawCosinus() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(200), y(200);

    x[0] = -20;
    y[0] = Get_a_Variable() * qCos(x[0]) + Get_b_Variable();

    for (int i = 1; i < 200; i++) {
        x[i] = x[i - 1] + 0.25;
        y[i] = Get_a_Variable() * qCos(x[i]) + Get_b_Variable();
    }

    ui->Graph->addGraph();
    ui->Graph->xAxis->setRange(-20, 20);
    ui->Graph->yAxis->setRange(1.5, 1.5);
    ui->Graph->graph(0)->addData(x, y);
    ui->Graph->graph(0)->setPen(QPen(Qt::green, 3));
    ui->Graph->replot();
}

void MainWindow::DrawTangent() {
    if (ui->Graph->graphCount() > 0)
        ui->Graph->clearGraphs();

    QVector <double> x(32), y(32);

    ui->Graph->xAxis->setRange(-10.99, 1.57);
    ui->Graph->yAxis->setRange(-10, 10);

    int k = -1;

    for (int j = -7; j < 13; j += 2) {

        x[0] = 1.57 * j;
        y[0] = Get_a_Variable() * qTan(x[0]) + Get_b_Variable();

        for(int i = 1; i < 32; i++) {
            x[i] = x[i - 1] + 0.1;
            y[i] = Get_a_Variable() * qTan(x[i]) + Get_b_Variable();
        }

        k++;

        ui->Graph->addGraph();
        ui->Graph->graph(k)->addData(x, y);
        ui->Graph->graph(k)->setPen(QPen(Qt::green, 3));
    }

    ui->Graph->replot();
}


int MainWindow::Check_Function_Type() {
    if (ui->TOFComboBox->currentIndex() == 0)
        return 0;
    else if (ui->TOFComboBox->currentIndex() == 1)
        return 1;
    else if (ui->TOFComboBox->currentIndex() == 2)
        return 2;
    else if (ui->TOFComboBox->currentIndex() == 3)
        return 3;
    else if (ui->TOFComboBox->currentIndex() == 4)
        return 4;
    else if (ui->TOFComboBox->currentIndex() == 5)
        return 5;
    else if (ui->TOFComboBox->currentIndex() == 6)
        return 6;
    else if (ui->TOFComboBox->currentIndex() == 7)
        return 7;
    return 8;
}

double MainWindow::Get_a_Variable() {
    return ui->VaraLineEdit->text().toDouble();
}

double MainWindow::Get_b_Variable() {
    return ui->VarbLineEdit->text().toDouble();
}

double MainWindow::Get_c_Variable(){
    return VarcLineEdit->text().toDouble();
}
