#pragma once
#include <map>
#include <algorithm>
#include <vector>
#include "../node/Node.h"
#include <cmath>
#include <utility>
#include "../line/Line.h"

class Graph
{
private:
	std::vector<Node*>* nodesInGraph;
	std::vector<Line*>* linesInGraph;
	std::map<int, std::pair<Node*, Node*>*>* nodePairByLevel;
	std::map<int, std::vector<int>*>* nodeNeighbours;
	QGraphicsScene* graphicsScene;
	const static int totalNodesInGraph;

public:
	Graph();
	Graph(QGraphicsScene* graphicsScene);
	~Graph();

	void displayGraphNodes();

	std::vector<Node*>* getNodesInGraph();
	std::vector<Line*>* getLinesInGraph();
	std::map<int, std::pair<Node*, Node*>*>* getNodePairByLevel();
	std::map<int, std::vector<int>*>* getNodeNeighbours();

private:
	void createGraphNode();
	void createConnections();
	bool hasConnection(Node* start, Node* end);
	void positionGraphNodes();
	void createNeighbours();
	void pairNodesByLevel();
	void createStaticGraph();
};

