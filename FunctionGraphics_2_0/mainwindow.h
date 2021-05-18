#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_DrawButton_clicked();

    void on_TOFComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QLabel *VarcLabel = new QLabel("Variable C");
    QLineEdit *VarcLineEdit = new QLineEdit(this);

    double Get_a_Variable();
    double Get_b_Variable();
    double Get_c_Variable();

    int Check_Function_Type();

    void DrawLinear();
    void DrawRadical();
    void DrawModulus();
    void DrawPower();
    void DrawSinus();
    void DrawCosinus();
    void DrawTangent();
};
#endif // MAINWINDOW_H
