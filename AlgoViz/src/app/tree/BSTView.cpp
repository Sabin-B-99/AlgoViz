#include "BSTView.h"
BSTView::BSTView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	scene->setSceneRect(ui.bstAnimArea->rect());
	ui.bstAnimArea->setScene(scene);
	ui.bstAnimArea->setAlignment(Qt::AlignTop);
	ui.bstAnimArea->setRenderHint(QPainter::Antialiasing);
	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);
	bst = new BSTNode();
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
	bst->insert(insertVal.toInt());
	
	int32_t key = insertVal.toInt();
	
	Node* nodeUI = nullptr;
	Line* lineUI = nullptr;

	bst->getUINode(key, nodeUI);
	//bst->getNodeLine(key, lineUI);
	//if (nodeUI) {
	//	scene->addItem(nodeUI);
	//}
	//if (lineUI) {
	//	scene->addItem(lineUI);
	//}

	BSTNodeAnimator* anim = new BSTNodeAnimator(bst);
	anim->animateNodeOutileColChange();
	scene->addItem(nodeUI);

}

void BSTView::on_bstDelBtn_clicked() {
}


void BSTView::on_bstHomeBtn_clicked() {
	scene->clear();
	free(bst);
	bst = new BSTNode();
	emit homeClicked();
}