#pragma once
#include "../node/Node.h"
#include "../line/Line.h"
#include <QPropertyAnimation>
#include <QPauseAnimation>
#include <vector>
#include <QTimer>
#include <QEventLoop>
class BSTNode : public Node{
private:
	int32_t key;
	BSTNode* left;
	BSTNode* right;

	BSTNode* root;
	BSTNode* parent;

	bool leftChild;
	bool rightChild;

	int32_t nodeLevel;
	
	QPointF* initPosBeforeAnim;
	QPointF* finalNodePosInUI;

	Node* UINode;
	Line* nodeLine;

	QGraphicsScene* scene;
	static int32_t rootXPos;

public:
	BSTNode(QGraphicsScene* scene);
	BSTNode(int32_t key, BSTNode* left, BSTNode* right);
	~BSTNode();

	void insert(int32_t key);
	void insert(BSTNode* root, int32_t key);
	int32_t getKey();
	BSTNode* getleft();
	BSTNode* getRight();
	BSTNode* getParent();
	BSTNode* getRoot();
	int32_t getLevel();
	bool isLeftChild();
	bool isRightChild();

	QPointF* getInitPosBeforeAnim();
	QPointF* getFinalNodePosInUI();

	void setLeft(BSTNode* left);
	void setRight(BSTNode* right);
	void setParent(BSTNode* parent);
	void setLevel(int32_t nodeLevel);
	void setLeftChild(bool leftChild);
	void setRightChild(bool rightChild);
	
	
	void createUINode();
	void createNodeLine();
	Node* getUINode();
	void getUINode(int32_t key, Node*& node);
	void getUINode(BSTNode* root, int32_t key, Node*& node);
	Line* getNodeLine();
	void getNodeLine(int32_t key, Line*& line);
	void getNodeLine(BSTNode* root, int32_t key, Line*& line);

	
	QPointF calculteNodePos();

private:
	void drawTreeUIElements();
	void showInsertionAnimation();
	void showPauseAnimation(int msecs);


};