#include "BSTNode.h"
#include <iostream>

BSTNode::BSTNode()
	:root(nullptr), key(0), left(nullptr), right(nullptr), parent(nullptr), nodeLevel(-1), 
	leftChild(false), rightChild(false), nodePosInUI(nullptr), UINode(nullptr), nodeLine(nullptr)
{
}

BSTNode::BSTNode(int32_t key, BSTNode* left, BSTNode* right)
	:root(nullptr), key(key), left(left), right(right), parent(nullptr), nodeLevel(-1),
	leftChild(false), rightChild(false), nodePosInUI(nullptr), UINode(nullptr), nodeLine(nullptr)
{
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

QPointF* BSTNode::getUINodePos()
{
	return this->nodePosInUI;
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

void BSTNode::setUINodePos(QPointF* uiNodePos)
{
	this->nodePosInUI = uiNodePos;
}

void BSTNode::setUINode(Node* node)
{
	this->UINode = node;
}

void BSTNode::setNodeLine(Line* nodeLine)
{
	this->nodeLine = nodeLine;
}

void BSTNode::createUINode(BSTNode* root, QPointF* pos)
{
	QString nodeVal = QString::number(root->getKey());
	UINode = new Node(*pos,nodeVal, Qt::lightGray);
	root->setUINode(UINode);
}

void BSTNode::createNodeLine(BSTNode* root)
{
	BSTNode* parent = root->getParent();
	Node* parentNodeUI = nullptr;
	if (parent) {
		parentNodeUI = parent->getUINode();
		root->setNodeLine(new Line(parentNodeUI, root->getUINode(), true, false));
	}
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


void BSTNode::calculatePositionInScene(BSTNode* root)
{
	QPointF* pos = new QPointF(0,0);
	int32_t newPosX = 0;
	int32_t newPosY = 0;

	

	BSTNode* parent = root->getParent();
	
	if (parent) {
		Node* parentNode = parent->getUINode();
		int32_t midX = 0;
		int32_t midY = 0;

		if (parentNode) {
			midX = parentNode->boundingRect().x() + (parentNode->boundingRect().width() / 2);
			midY = parentNode->boundingRect().y() + parentNode->boundingRect().height();

			if (root->isLeftChild()) {
				newPosX = midX - parentNode->boundingRect().width();
				newPosY = midY + parentNode->boundingRect().height();
				pos->setX(newPosX);
				pos->setY(newPosY);
			}

			if (root->isRightChild()) {
				newPosX = midX + parentNode->boundingRect().width();
				newPosY = midY + parentNode->boundingRect().height();
				pos->setX(newPosX);
				pos->setY(newPosY);
			}
		}
	}
	root->setUINodePos(pos);
}



void BSTNode::insert(int32_t key)
{
	if (root == nullptr) {
		root = new BSTNode(key, nullptr, nullptr);
		root->setParent(nullptr);
		root->setLevel(0);
		calculatePositionInScene(root);
		createUINode(root, root->getUINodePos());
		createNodeLine(root);
	}
	else {
		insert(root, key);
	}
}

void BSTNode::insert(BSTNode* root, int32_t key)
{    
	if (key < root->getKey()){
		if (root->getleft() == nullptr) {
			root->setLeft(new BSTNode(key, nullptr, nullptr));
			root->getleft()->setParent(root); 
			root->getleft()->setLevel(root->getLevel() + 1);
			root->getleft()->setLeftChild(true);
			calculatePositionInScene(root->getleft());
			createUINode(root->getleft(), root->getleft()->getUINodePos());
			createNodeLine(root->getleft());
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
			calculatePositionInScene(root->getRight());
			createUINode(root->getRight(), root->getRight()->getUINodePos());
			createNodeLine(root->getRight());
		}
		else {
			insert(root->getRight(), key);
		}
	}
}


