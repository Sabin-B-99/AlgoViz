#pragma once
#include "../node/Node.h"
#include "../line/Line.h"
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
	
	QPointF* nodePosInUI;
	Node* UINode;
	Line* nodeLine;

public:
	BSTNode();
	BSTNode(int32_t key, BSTNode* left, BSTNode* right);
	~BSTNode();

	void insert(int32_t key);
	void insert(BSTNode* root, int32_t key);
	int32_t getKey();
	BSTNode* getleft();
	BSTNode* getRight();
	BSTNode* getParent();
	BSTNode* getRoot();
	Line* getNodeLine();
	QPointF* getUINodePos();
	int32_t getLevel();
	bool isLeftChild();
	bool isRightChild();

	void setLeft(BSTNode* left);
	void setRight(BSTNode* right);
	void setParent(BSTNode* parent);
	void setLevel(int32_t nodeLevel);
	void setLeftChild(bool leftChild);
	void setRightChild(bool rightChild);
	void setUINodePos(QPointF* uiNodePos);
	void setUINode(Node* node);
	void setNodeLine(Line* nodeLine);
	void createUINode(BSTNode* root, QPointF* pos);
	void createNodeLine(BSTNode* root);

	Node* getUINode();
	void getUINode(int32_t key, Node*& node);
	void getUINode(BSTNode* root, int32_t key, Node*& node);
	void getNodeLine(int32_t key, Line*& line);
	void getNodeLine(BSTNode* root, int32_t key, Line*& line);
	void calculatePositionInScene(BSTNode* root);

};