#include "AlgoViz.h"
#include <qpushbutton.h>

AlgoViz::AlgoViz(QWidget *parent)
    : QMainWindow(parent)
{  
    ui.setupUi(this);
    ui.stackedWidget->addWidget(&bst);
    ui.stackedWidget->addWidget(&bfs);
    ui.stackedWidget->addWidget(&dfs);
    ui.stackedWidget->addWidget(&dijSPF);
    ui.stackedWidget->addWidget(&primMST);
    ui.stackedWidget->addWidget(&kruskalMST);
    ui.stackedWidget->addWidget(&seqSrch);
    ui.stackedWidget->addWidget(&binSrch);
    ui.stackedWidget->addWidget(&stack);
    ui.stackedWidget->addWidget(&q);

    ui.stackedWidget->setCurrentIndex(0);

    connect(&bst, SIGNAL(homeClicked()), this, SLOT(moveHome()));

    connect(&bfs, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&dfs, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&dijSPF, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&primMST, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&kruskalMST, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&seqSrch, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&binSrch, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&stack, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(&q, SIGNAL(homeClicked()), this, SLOT(moveHome()));
}

AlgoViz::~AlgoViz()
{}

void AlgoViz::moveHome()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void AlgoViz::on_bstButton_clicked() {
    ui.stackedWidget->setCurrentIndex(1);
}

void AlgoViz::on_bfsButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(2);
}

void AlgoViz::on_dfsButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(3);
}

void AlgoViz::on_dijkstraButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(4);
}

void AlgoViz::on_primButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(5);
}

void AlgoViz::on_kruskalButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(6);
}

void AlgoViz::on_seqSrchButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(7);
}

void AlgoViz::on_binSrchButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(8);
}

void AlgoViz::on_stackButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(9);
}

void AlgoViz::on_queueButton_clicked()
{
    ui.stackedWidget->setCurrentIndex(10);
}



