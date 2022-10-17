#include "BSTView.h"
#include "../graph/Graph.h"
BSTView::BSTView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	/*scene->setSceneRect(ui.bstAnimArea->rect());*/
	ui.bstAnimArea->setScene(scene);
	ui.bstAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.bstAnimArea->setAlignment(Qt::AlignTop);
	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);
	bst = new BSTNode(scene);
}

BSTView::~BSTView()
{
}

void BSTView::on_bstInsertBtn_clicked()
{
	Graph* g = new Graph(scene);
	g->displayGraphNodes();
}

void BSTView::on_bstDelBtn_clicked() {
}


void BSTView::on_bstHomeBtn_clicked() {
	scene->clear();
	free(bst);
	bst = new BSTNode(scene);
	emit homeClicked();
}