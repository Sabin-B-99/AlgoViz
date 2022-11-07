#pragma once
#include <map>
#include <algorithm>
#include <vector>
#include "../node/Node.h"
#include <cmath>
#include <utility>
#include "../line/Line.h"
#include <cstdlib>
#include <chrono>


class Graph
{
private:
	std::vector<Node*>* nodesInGraph;
	std::vector<Line*>* linesInGraph;
	std::map<int, std::pair<Node*, Node*>*>* nodePairByLevel;
	std::map<int, std::vector<int>*>* nodeNeighbours;
	std::vector<std::vector<int>*>* weightMatrix;
	QGraphicsScene* graphicsScene;
	const static int totalNodesInGraph;
	bool weighted;

public:
	Graph();
	Graph(QGraphicsScene* graphicsScene, bool wieghted = false);
	~Graph();

	void displayGraphNodes();

	std::vector<Node*>* getNodesInGraph();
	std::vector<Line*>* getLinesInGraph();
	std::map<int, std::pair<Node*, Node*>*>* getNodePairByLevel();
	std::map<int, std::vector<int>*>* getNodeNeighbours();
	std::vector<std::vector<int>*>* getWeightMatrix();

private:
	void createGraphNode();
	void createConnections();
	bool hasConnection(Node* start, Node* end);
	void positionGraphNodes();
	void createNeighbours();
	void pairNodesByLevel();
	void createStaticGraph();
	void createWeightedStaticGraph();
	void initializeWeightMatrix();
	void setWeightMatrixVal(Node* startNode, Node* neighbourNode, int weight);
};

