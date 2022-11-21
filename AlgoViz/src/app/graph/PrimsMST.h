#pragma once
#include "Graph.h"
#include <queue>
#include <vector>
#include <QPlainTextEdit>
#include <QLabel>
#include "../animation/PauseAnim.h"
#include <limits>
#include <QTextCodec>
#include <qtextcodec>
class PrimsMST
{
	Graph* primsMSTGraph;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* primsMSTConsole;
public:
	PrimsMST();
	PrimsMST(QGraphicsScene* graphicsScene, QPlainTextEdit* primsMSTConsole);
	~PrimsMST();

	void run();
	void displayGraph();

private:
	int minKey(std::vector<int>* key, std::vector<bool>* mstSet);
	void printMST(std::vector<int>* parent, std::vector<std::vector<int>*>* weightMatrix);
};

