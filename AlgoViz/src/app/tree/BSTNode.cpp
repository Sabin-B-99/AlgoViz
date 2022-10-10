#include "BSTNode.h"

BSTNode::BSTNode(QGraphicsScene* scene)
	:scene(scene), root(nullptr), key(0), left(nullptr), right(nullptr), parent(nullptr), nodeLevel(-1),
	leftChild(false), rightChild(false), finalNodePosInUI(nullptr), UINode(nullptr), nodeLine(nullptr)
{
	initPosBeforeAnim = new QPointF(20, 20);
}

BSTNode::BSTNode(int32_t key, BSTNode* left, BSTNode* right)
	:root(nullptr), key(key), left(left), right(right), parent(nullptr), nodeLevel(-1),
	leftChild(false), rightChild(false), finalNodePosInUI(nullptr), UINode(nullptr), nodeLine(nullptr)
{
	initPosBeforeAnim = new QPointF(20, 20);
}

BSTNode::~BSTNode()
{
}

int32_t BSTNode::getKey()
{
	return this->key;
}

BSTNode* BSTNode::getleft()
{
	return this->left;
}

BSTNode* BSTNode::getRight()
{
	return this->right;
}

BSTNode* BSTNode::getParent()
{
	return this->parent;
}

BSTNode* BSTNode::getRoot()
{
	return this->root;
}

Line* BSTNode::getNodeLine()
{
	return this->nodeLine;
}



int32_t BSTNode::getLevel()
{
	return this->nodeLevel;
}

bool BSTNode::isLeftChild()
{
	return this->leftChild;
}

bool BSTNode::isRightChild()
{
	return this->rightChild;
}

void BSTNode::setLeft(BSTNode* left)
{
	this->left = left;
}

void BSTNode::setRight(BSTNode* right)
{
	this->right = right;
}

void BSTNode::setParent(BSTNode* parent)
{
	this->parent = parent;
}

void BSTNode::setLevel(int32_t nodeLevel)
{
	this->nodeLevel = nodeLevel;
}

void BSTNode::setLeftChild(bool leftChild)
{
	this->leftChild = leftChild;
}

void BSTNode::setRightChild(bool rightChild)
{
	this->rightChild = rightChild;
}



void BSTNode::createUINode()
{
	QString nodeVal = QString::number(this->getKey());
	this->UINode = new Node(*(this->getInitPosBeforeAnim()), nodeVal, Qt::lightGray);
}

void BSTNode::createNodeLine()
{
	BSTNode* parent = this->getParent();
	Node* parentNodeUI = nullptr;
	if (parent) {
		parentNodeUI = parent->getUINode();
		this->nodeLine = new Line(parentNodeUI, this->getUINode(), true, false);
	}
}


QPointF* BSTNode::getInitPosBeforeAnim()
{
	return this->initPosBeforeAnim;
}

QPointF* BSTNode::getFinalNodePosInUI()
{
	return this->finalNodePosInUI;
}

Node* BSTNode::getUINode()
{
	return this->UINode;
}

void BSTNode::getUINode(int32_t key, Node*& node)
{
	getUINode(root, key, node);
}

void BSTNode::getUINode(BSTNode* root, int32_t key, Node*& node)
{
	if (root) {
		if (root->getKey() == key) {
			node = root->getUINode();
		}
		getUINode(root->getleft(), key, node);
		getUINode(root->getRight(), key, node);
	}
	else {
		return;
	}	
}

void BSTNode::getNodeLine(int32_t key, Line*& line)
{
	getNodeLine(root, key, line);
}

void BSTNode::getNodeLine(BSTNode* root, int32_t key, Line*& line)
{

	if (root) {
		if (root->getKey() == key) {
			line = root->getNodeLine();
		}
		getNodeLine(root->getleft(), key, line);
		getNodeLine(root->getRight(), key, line);
	}
	else {
		return;
	}
}

QPointF BSTNode::calculteNodePos()
{
	QPointF finalPos(0, 0);
	int32_t newPosX = rootXPos;
	int32_t newPosY = 0;

	BSTNode* parent = this->getParent();


	if (parent) {
		Node* parentNodeUI = parent->getUINode();
		int32_t midX = parentNodeUI->pos().x() + parentNodeUI->boundingRect().width() / 2;
		int32_t midY = parentNodeUI->pos().y() + parentNodeUI->boundingRect().height();
		if (this->isLeftChild()) {
			newPosX = midX - 50;
			newPosY = midY + 25;
		}
		if (this->isRightChild()) {
			newPosX = midX + 50;
			newPosY = midY + 25;
		}
	}

	finalPos.setX(newPosX);
	finalPos.setY(newPosY);
	this->finalNodePosInUI = new QPointF(finalPos);
	return finalPos;
}

void BSTNode::drawTreeUIElements()
{

	this->createUINode();
	this->getUINode()->setPos(this->calculteNodePos());
}



void BSTNode::showInsertionAnimation()
{	
	if (this->getParent()) {
		QPropertyAnimation* insertionAnim = new QPropertyAnimation(this->UINode, "pos");
		insertionAnim->setStartValue(*(this->getInitPosBeforeAnim()));
		insertionAnim->setEndValue(*(this->getFinalNodePosInUI()));
		insertionAnim->setDuration(2000);
		insertionAnim->start();
	}

}

void BSTNode::showPauseAnimation(int msecs)
{
	QTimer* t = new QTimer();
	t->setSingleShot(true);
	t->start(msecs);//this is the time to sleep in this case 60 seconds 
	QEventLoop pause;
	connect(t, SIGNAL(timeout()), &pause, SLOT(quit()));
	pause.exec();//keeps the program responsive 
}





void BSTNode::insert(int32_t key)
{
	if (root == nullptr) {
		root = new BSTNode(key, nullptr, nullptr);
		root->setParent(nullptr);
		root->setLevel(0);
		root->drawTreeUIElements();
		scene->addItem(root->getUINode());
		scene->addItem(root->getNodeLine());
	}
	else {
		insert(root, key);
	}
}

void BSTNode::insert(BSTNode* root, int32_t key)
{    
	root->getUINode()->setNodeOutlinePen(new QPen(Qt::red));
	scene->update();
	root->showPauseAnimation(800);
	root->getUINode()->setNodeOutlinePen(new QPen(Qt::black));
	scene->update();

	if (key < root->getKey()){
		if (root->getleft() == nullptr) {
			root->setLeft(new BSTNode(key, nullptr, nullptr));
			root->getleft()->setParent(root); 
			root->getleft()->setLevel(root->getLevel() + 1);
			root->getleft()->setLeftChild(true);

			root->getleft()->drawTreeUIElements();
			root->getleft()->showInsertionAnimation();
			scene->addItem(root->getleft()->getUINode());
			scene->addItem(root->getleft()->getNodeLine());	
		}
		else {
			insert(root->getleft(), key);
		}
	}

	if (key >= root->getKey()) {
		if (root->getRight() == nullptr) {
			root->setRight(new BSTNode(key, nullptr, nullptr));
			root->getRight()->setParent(root);
			root->getRight()->setLevel(root->getLevel() + 1);
			root->getRight()->setRightChild(true);

			root->getRight()->drawTreeUIElements();
			root->getRight()->showInsertionAnimation();
	
			scene->addItem(root->getRight()->getUINode());
			scene->addItem(root->getRight()->getNodeLine());
		}
		else {
			insert(root->getRight(), key);
		}
	}
}

int32_t BSTNode::rootXPos = 250;