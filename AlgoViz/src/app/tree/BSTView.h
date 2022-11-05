#pragma once

#include <QWidget>
#include "ui_BSTView.h"
#include "../line/Line.h"
#include <vector>
#include <map>
#include <QIntValidator>
#include "BSTNode.h"
#include "../graph/BFS.h"
#include "../graph/DFS.h"
#include <iostream>


class BSTView : public QWidget
{
	Q_OBJECT

private:
	Ui::BSTViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	int32_t totalLevel;
	BSTNode* bst; BFS* bfs; DFS* dfs;
	
public:
	BSTView(QWidget *parent = nullptr);
	~BSTView();

private:

private slots:
	void on_bstHomeBtn_clicked();
	void on_bstInsertBtn_clicked();
	void on_bstDelBtn_clicked();

signals:
	void homeClicked();


};
