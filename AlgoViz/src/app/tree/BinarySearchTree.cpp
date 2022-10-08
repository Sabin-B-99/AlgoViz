#include "BinarySearchTree.h"
#include "BSTNode.h"
BinarySearchTree::BinarySearchTree(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.bstAnimArea->setScene(scene);
	intValidator = new QIntValidator();
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);
	bst = new BSTNode();
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::on_bstInsertBtn_clicked()
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
	bst->getNodeLine(key, lineUI);
	if (nodeUI) {
		scene->addItem(nodeUI);
	}
	if (lineUI) {
		scene->addItem(lineUI);
	}
}

void BinarySearchTree::on_bstDelBtn_clicked() {
}


void BinarySearchTree::on_bstHomeBtn_clicked() {
	emit homeClicked();
}