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
#include "DSU.h"
#include <algorithm>
class KruskalMST
{
private:
	Graph* kruskalMSTGraph;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* kruskalMSTConsole;
public:
	KruskalMST();
	KruskalMST(QGraphicsScene* graphicsScene, QPlainTextEdit* kruskalMSTConsole);
	~KruskalMST();

	void run();
	void displayGraph();

};
