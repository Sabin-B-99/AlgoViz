#pragma once
#include "Graph.h"
#include <queue>
#include <vector>
#include <QPlainTextEdit>
#include <QLabel>
#include "../animation/PauseAnim.h"
class BFS
{
private:
	Graph* bfsGraph;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* bfsConsole;
	QLabel* bfsCurrentRootValLabel;

	std::queue<int>* bfsQueue;
	std::vector<bool> bfsVisited;
public:
	BFS();
	BFS(QGraphicsScene* graphicsScene, QPlainTextEdit* bfsConsole);
	~BFS();

	void run(int startNodeId);
	void displayGraph();
};