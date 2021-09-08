#include "mainwindow.h"
#include "./ui_mainwindow.h"

double firstnum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));


    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus_minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sub,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sq,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_log,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_log_10,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sqrt,SIGNAL(released()),this,SLOT(binary_operation_pressed()));



    ui->pushButton_add->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_sq->setCheckable(true);
    ui->pushButton_sqrt->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
    ui->pushButton_log_10->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if((ui->pushButton_add->isChecked() || ui->pushButton_sqrt->isChecked() || ui->pushButton_log_10->isChecked() || ui->pushButton_log->isChecked() || ui->pushButton_sub->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains(".") && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text()+ ".");
}

void MainWindow::unary_operation_pressed()
{
    double labelNumber;
    QString newLabel;
    QPushButton * button = (QPushButton*) sender();
    if(button->text() =="+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel =QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if(button->text() =="%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel =QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }



}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_sub->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_sq->setChecked(false);
    ui->pushButton_sqrt->setChecked(false);
    ui->pushButton_log->setChecked(false);
    ui->pushButton_log_10->setChecked(false);

    userIsTypingSecondNumber =false;

    ui->label->setText("0");
}


void MainWindow::on_pushButton_equal_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked()){
        labelNumber =firstnum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_sub->isChecked()){
        labelNumber =firstnum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_sub->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()){
        labelNumber =firstnum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()){
        labelNumber =firstnum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    else if(ui->pushButton_sq->isChecked()){
        labelNumber =firstnum * firstnum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_sq->setChecked(false);
    }
    else if(ui->pushButton_log->isChecked()){
        labelNumber = log(firstnum);
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_log->setChecked(false);
    }
    else if(ui->pushButton_log_10->isChecked()){
        labelNumber = log10(firstnum);
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_log_10->setChecked(false);
    }
    else if(ui->pushButton_sqrt->isChecked()){
        labelNumber = sqrt(firstnum);
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_sqrt->setChecked(false);
    }
    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstnum = ui->label->text().toDouble();
    button->setChecked(true);
}

