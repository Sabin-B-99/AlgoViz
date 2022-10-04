#pragma once

#include <QWidget>
#include "ui_BinarySearchTree.h"
#include "../node/Node.h"
#include "../line/Line.h"
#include <vector>
#include <map>
#include <QIntValidator>

class BinarySearchTree : public QWidget
{
	Q_OBJECT

private:
	Ui::BinarySearchTreeClass ui;
	QGraphicsScene* scene;
	static int32_t totalNode;
	std::vector<Node*>* nodeList;
	std::map <Node*, int32_t>* nodeLevel;
	QIntValidator* validator;
	int32_t totalLevel;

public:
	BinarySearchTree(QWidget *parent = nullptr);
	~BinarySearchTree();

private:
	QPointF calculateNewNodePos(Node* parent, int32_t currentLevel);

private slots:
	void on_bstHomeBtn_clicked();
	void on_bstInsertBtn_clicked();
	void on_bstDelBtn_clicked();

signals:
	void homeClicked();


};
