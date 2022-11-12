#include "BSTView.h"

BSTView::BSTView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	/*scene->setSceneRect(ui.bstAnimArea->rect());*/
	ui.bstAnimArea->setScene(scene);
	ui.bstAnimArea->setRenderHint(QPainter::Antialiasing);
	/*ui.bstAnimArea->setAlignment(Qt::AlignTop);*/ //for graphs
	ui.bstAnimArea->setAlignment(Qt::AlignVCenter); //for linearStructures
	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);

	/*bst = new BSTNode(scene);*/


}

BSTView::~BSTView()
{
}

void BSTView::on_bstInsertBtn_clicked()
{
	QString insertVal = ui.bstInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	/*ui.bstPlainTextEdit->appendPlainText("Inset Button Pressed");*/
	/*dfs->run(insertVal.toInt());*/
	/*dijkstraSP->run(insertVal.toInt());*/
	/*primMST->run(insertVal.toInt());*/
	/*kruskalMST->run();*/


	/* Node* n = arrNode->getNodeList()->at(5);*/
	 
	 /*QPolygonF* arrowHead = l->getArrowHeadAtBottomOrRight();*/

	//QPropertyAnimation* insertionAnim = new QPropertyAnimation(arrowHead, "pos");
	//insertionAnim->setStartValue(QPointF(50,50));
	//insertionAnim->setEndValue(QPointF(150, 150));
	//insertionAnim->setDuration(2000);
	//insertionAnim->start();


}

void BSTView::on_bstDelBtn_clicked() {
}


void BSTView::on_bstHomeBtn_clicked() {
	scene->clear();
	free(bst);
	bst = new BSTNode(scene);
	emit homeClicked();
}