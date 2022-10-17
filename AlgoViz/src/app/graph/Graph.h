#pragma once
#include <map>
#include <algorithm>
#include <vector>
#include "../node/Node.h"
#include <cmath>
#include <utility>

class Graph
{
private:
	std::vector<Node*>* nodesInGraph;
	std::map<int, std::pair<Node*, Node*>*>* nodePairByLevel;
	std::map<int, std::vector<Node*>*>* nodeNeighbours;
	QGraphicsScene* graphicsScene;
	const static int totalNodesInGraph;

public:
	Graph();
	Graph(QGraphicsScene* graphicsScene);
	~Graph();

	void displayGraphNodes();

private:
	void createGraphNode();
	void positionGraphNodes();
	void pairNodesByLevel();
};

