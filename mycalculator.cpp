#include "mycalculator.h"
#include "./ui_mycalculator.h"


MyCalculator::MyCalculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyCalculator)
{
    ui->setupUi(this);
    this->setMaximumSize(300,410);
    this->setMinimumSize(300,410);
    this->setWindowTitle("Qt简易计算器");
    //放图标到按键上
    QIcon con("D:\\CoderLife\\QtEx02\\myQtEx05\\backIcon.png");
    ui->delhButton->setIcon(con);
    //改变按键背景色
    ui->equalButton->setStyleSheet("background:lightblue");
    ui->ShowEdit->setStyleSheet("background:lightskyblue");
}

MyCalculator::~MyCalculator()
{
    delete ui;
}


void MyCalculator::on_oneButton_clicked()
{
    showText += "1";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_twoButton_clicked()
{
    showText += "2";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_threeButton_clicked()
{
    showText += "3";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_fourButton_clicked()
{
    showText += "4";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_fivehButton_clicked()
{
    showText += "5";
    ui->ShowEdit->setText(showText);

}

void MyCalculator::on_sixButton_clicked()
{
    showText += "6";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_sevenButton_clicked()
{
    showText += "7";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_eightButton_clicked()
{
    showText += "8";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_nineButton_clicked()
{
    showText += "9";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_zeroButton_clicked()
{
    showText += "0";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_leftButton_clicked()
{
    showText += "(";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_rightButton_clicked()
{
    showText += ")";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_clearButton_clicked()
{
    showText.clear();
    ui->ShowEdit->clear();
}

void MyCalculator::on_addButton_clicked()
{
    showText += "+";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_subButton_clicked()
{
    showText += "-";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_mulButton_clicked()
{
    showText += "*";
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_delhButton_clicked()
{
    showText.chop(1);
    ui->ShowEdit->setText(showText);
}

void MyCalculator::on_divhButton_clicked()
{
    showText += "/";
    ui->ShowEdit->setText(showText);
}


void MyCalculator::on_equalButton_clicked()
{
    QStack<int> s_num,s_opt;
    char opt[128] = {0};
    int i = 0, tmp = 0, num1 = 0, num2 = 0;

    //把QString 转换成 char *
    ///////////////////////////////
    QByteArray ba = showText.toLatin1();
    strcpy(opt,ba.data());

    while(opt[i] != '\0' || s_opt.empty() != true)
    {
        if(opt[i] >= '0' && opt[i] <= '9')//判断是否为数值
        {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if(opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;

            }
        }
        else  //判断是否为运算符号
        {
            if(s_opt.empty() == true || Priority(opt[i]) > Priority (s_opt.top()) || (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }
            if(s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }

            if(Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(') || (opt[i] == '\0' && s_opt.empty() != true))
            {

                char ch  = s_opt.top();
                s_opt.pop();
                switch(ch)
                {
                    case '+':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 + num2);
                        break;
                    case '-'://栈是先进后出，要交换位置
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2 - num1);
                        break;
                    case '*':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 * num2);
                        break;
                    case '/'://栈是先进后出，要交换位置
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2 / num1);
                        break;

                }

            }

        }


    }
    ui->ShowEdit->setText(QString::number(s_num.top()));
    showText.clear();

}

int MyCalculator::Priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;

    }

}



