#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QWidget>
#include <QStack>
#include <string.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MyCalculator; }
QT_END_NAMESPACE

class MyCalculator : public QWidget
{
    Q_OBJECT

public:
    MyCalculator(QWidget *parent = nullptr);
    ~MyCalculator();

private slots:
    void on_oneButton_clicked();
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fivehButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();
    void on_zeroButton_clicked();
    void on_addButton_clicked();
    void on_subButton_clicked();
    void on_mulButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_clearButton_clicked();
    void on_equalButton_clicked();

    void on_delhButton_clicked();
    void on_divhButton_clicked();



private:
    Ui::MyCalculator *ui;
    QString showText;
    int Priority(char ch);
};
#endif // MYCALCULATOR_H
