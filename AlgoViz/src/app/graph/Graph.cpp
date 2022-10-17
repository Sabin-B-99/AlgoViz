#include "Graph.h"

Graph::Graph()
	:graphicsScene(nullptr), nodesInGraph(nullptr), nodeNeighbours(nullptr)
{
}

Graph::Graph(QGraphicsScene* graphicsScene)
	:graphicsScene(graphicsScene)
{
	this->nodesInGraph = new std::vector<Node*>;
	this->nodeNeighbours = new std::map<int, std::vector<Node*>*>;
	this->nodePairByLevel = new std::map<int, std::pair<Node*, Node*>*>;
}

Graph::~Graph()
{
}

void Graph::displayGraphNodes()
{
	createGraphNode();
	pairNodesByLevel();
	positionGraphNodes();
	for (std::vector<Node*>::iterator it = this->nodesInGraph->begin(); it != this->nodesInGraph->end(); it++)
	{
		this->graphicsScene->addItem(*it);
	}
}

void Graph::createGraphNode()
{
	Node* graphNode = nullptr;
	for (int i = 0; i < totalNodesInGraph; i++)
	{
		QString nodeVal = QString::number(i);
		graphNode = new Node(nodeVal, Qt::lightGray);
		this->nodesInGraph->emplace_back(graphNode);
	}
}

/// <summary>
/// TODO: Reftactor later
///Function needs refractorig later
/// </summary>
void Graph::positionGraphNodes(){
	
	Node* firstNode = nullptr;
	Node* nodeToBePositionedLeft = nullptr;
	Node* nodeToBePositionedRight = nullptr;
	QPointF nodePos(0, 0);
	QPointF nodePosRight(0, 0);

	int newPosXLeft = 0;
	int newPosYLeft = 0;
	int newPosXRight = 0;
	int newPosYRight = 0;

	int maxWidthPoint = totalNodesInGraph / 4;
	int totalLevels = maxWidthPoint * 2;

	int midPointX = 0;
	int midPointY = 0;

	std::map<int, std::pair<Node*, Node*>*>::iterator it;
	std::pair<Node*, Node*>* nodePair = nullptr;

	for (int i = 0; i <= totalLevels; i++)
	{
		it = nodePairByLevel->find(i);
		nodePair = it->second;

		if (i <= maxWidthPoint) {
			if (i == 0) {
				firstNode = nodePair->first;
				firstNode->setPos(nodePos);
				midPointX = firstNode->pos().x() + firstNode->boundingRect().width() / 2;
				midPointY = firstNode->pos().y() + firstNode->boundingRect().height();
			}
			else {
				nodeToBePositionedLeft = nodePair->first;
				nodeToBePositionedRight = nodePair->second;
				
				newPosXLeft += (midPointX - 50);
				newPosYLeft += (midPointY + 35);
				nodePos.setX(newPosXLeft);
				nodePos.setY(newPosYLeft);
				nodeToBePositionedLeft->setPos(nodePos);

				newPosXRight += (midPointX + 50);
				newPosYRight += (midPointY + 35);
				nodePosRight.setX(newPosXRight);
				nodePosRight.setY(newPosYRight);
				nodeToBePositionedRight->setPos(nodePosRight);
			}
		}
		else {
			if (i == totalLevels) {
				nodeToBePositionedLeft = nodePair->first;
				nodeToBePositionedRight = nullptr;
				newPosXLeft += (midPointX + 50);
				newPosYLeft += (midPointY + 35);
				nodePos.setX(newPosXLeft);
				nodePos.setY(newPosYLeft);
				nodeToBePositionedLeft->setPos(nodePos);
			}
			else {
				nodeToBePositionedLeft = nodePair->first;
				nodeToBePositionedRight = nodePair->second;

				newPosXLeft += (midPointX + 50);
				newPosYLeft += (midPointY + 35);
				nodePos.setX(newPosXLeft);
				nodePos.setY(newPosYLeft);
				nodeToBePositionedLeft->setPos(nodePos);

				newPosXRight += (midPointX - 50);
				newPosYRight += (midPointY + 35);
				nodePosRight.setX(newPosXRight);
				nodePosRight.setY(newPosYRight);
				nodeToBePositionedRight->setPos(nodePosRight);
			}
		}
	}
}

void Graph::pairNodesByLevel()
{
	int maxWidthPoint = totalNodesInGraph / 4;
	int totalLevels = maxWidthPoint * 2;

	Node* nodeLeft = nullptr;
	Node* nodeRight = nullptr;
	std::pair<Node*, Node*>* nodePairs = nullptr;
	int nodeNo = 0;
	for (int i = 0; i <= totalLevels; i++)
	{
		if (i == 0) {
			nodeLeft = nodesInGraph->at(nodeNo);
			nodeRight = nullptr;
		}
		else if (i == totalLevels) {
			nodeLeft = nodesInGraph->at(totalNodesInGraph - 1);
			nodeRight = nullptr;
		}
		else {
			nodeLeft = nodesInGraph->at(nodeNo - 1);
			nodeRight = nodesInGraph->at(nodeNo);
		}
		nodePairs = new std::pair<Node*, Node*>;
		nodePairs->first = nodeLeft;
		nodePairs->second = nodeRight;
		nodePairByLevel->emplace(i, nodePairs);
		nodeNo += 2;
	}
}

const int Graph::totalNodesInGraph = 8;
