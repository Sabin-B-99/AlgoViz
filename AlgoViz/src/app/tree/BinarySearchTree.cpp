#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.bstAnimArea->setScene(scene);
	nodeList = new std::vector<Node*>();
	nodeLevel = new std::map<Node*, int32_t>();
	validator = new QIntValidator();
	ui.bstInsertLineEdit->setValidator(validator);
}

BinarySearchTree::~BinarySearchTree()
{}

void BinarySearchTree::on_bstInsertBtn_clicked()
{
	QString insertVal = ui.bstInsertLineEdit->text();
	Node* nodeToInset = new Node(10, 10, insertVal, Qt::lightGray);
}

void BinarySearchTree::on_bstDelBtn_clicked() {
}

QPointF BinarySearchTree::calculateNewNodePos(Node* node, int32_t currentLevel)
{
	QPointF parentPos = node->getParent()->pos();
	return QPointF();
}

void BinarySearchTree::on_bstHomeBtn_clicked() {
	emit homeClicked();
}

int32_t BinarySearchTree::totalNode = 0;