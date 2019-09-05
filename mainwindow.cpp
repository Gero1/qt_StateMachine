#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStateMachine"
#include "QEventTransition"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stateA->setEnabled(false);
    ui->stateB->setEnabled(false);

    QStateMachine *machine = new QStateMachine(this);
    QState *s1 = new QState();
    QState *s2 = new QState();

    s1->assignProperty(ui->stateA,"text","StateA:Here");
    s1->assignProperty(ui->stateB,"text","StateB");

    s2->assignProperty(ui->stateA,"text","StateA");
    s2->assignProperty(ui->stateB,"text","StateB:Here");


    s1->addTransition(ui->changeButton,SIGNAL(clicked()),s2);
    s2->addTransition(ui->changeButton,SIGNAL(clicked()),s1);

     machine ->addState(s1);
     machine ->addState(s2);
     machine->setInitialState(s1);
     machine->start();

}


MainWindow::~MainWindow()
{
    delete ui;
}
