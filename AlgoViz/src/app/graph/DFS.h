#pragma once
#include "Graph.h"
#include <queue>
#include <vector>
#include <QPlainTextEdit>
#include <QLabel>
#include "../animation/PauseAnim.h"
class DFS
{
private:
	Graph* dfsGraph;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* dfsConsole;
	QLabel* dfsCurrentRootValLabel;

	std::map<int, bool> dfsVisited;

	QString dfsConsoleText;
	int recursionStackCount;
public:
	DFS();
	DFS(QGraphicsScene* graphicsScene, QPlainTextEdit* dfsConsole);
	~DFS();

	void run(int startNodeId);
	void displayGraph();
};

