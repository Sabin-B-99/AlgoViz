#include "AlgoViz.h"
#include <qpushbutton.h>

AlgoViz::AlgoViz(QWidget *parent)
    : QMainWindow(parent)
{  
    ui.setupUi(this);
    ui.stackedWidget->addWidget(&bst);

    ui.stackedWidget->setCurrentIndex(0);

    connect(&bst, SIGNAL(homeClicked()), this, SLOT(moveHome()));
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
