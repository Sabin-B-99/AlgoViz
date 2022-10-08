#pragma once

#include <QWidget>
#include "ui_BinarySearchTree.h"
#include "../line/Line.h"
#include <vector>
#include <map>
#include <QIntValidator>
#include "BSTNode.h"
#include <iostream>

class BinarySearchTree : public QWidget
{
	Q_OBJECT

private:
	Ui::BinarySearchTreeClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	int32_t totalLevel;
	BSTNode* bst;

public:
	BinarySearchTree(QWidget *parent = nullptr);
	~BinarySearchTree();

private:

private slots:
	void on_bstHomeBtn_clicked();
	void on_bstInsertBtn_clicked();
	void on_bstDelBtn_clicked();

signals:
	void homeClicked();


};
