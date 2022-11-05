#include "BFS.h"

BFS::BFS()
{
}

BFS::BFS(QGraphicsScene* graphicsScene, QPlainTextEdit* bfsConsole)
	:graphicsScene(graphicsScene), bfsConsole(bfsConsole)
{
	bfsGraph = new Graph(graphicsScene);
	bfsQueue = new std::queue<int>;
}

BFS::~BFS()
{
}

void BFS::run(int startNodeId)
{
	
	std::vector<Node*>* nodesInGraph = bfsGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = bfsGraph->getNodeNeighbours();

	bfsVisited.resize(nodesInGraph->size());
	for (int i = 0; i < bfsVisited.size(); i++)
	{
		bfsVisited[i] = false;
	}

	bfsQueue->emplace(startNodeId);
	bfsVisited[startNodeId] = true;

	int currrentNodeId = -1;
	Node* currentNode = nullptr;
	
	std::vector<int>* neighbourList = nullptr;

	QString bfsQueueText = "BFS Traversal:\n\n";
	
	while (!bfsQueue->empty())
	{
		currrentNodeId = bfsQueue->front();
		currentNode = nodesInGraph->at(currrentNodeId);
		neighbourList = nodeNeighbours->at(currrentNodeId);
		
		currentNode->setNodeOutlinePen(new QPen(Qt::red));
		graphicsScene->update();
		PauseAnim::showPauseAnimation(2000);
		bfsQueueText.append(QString::number(currrentNodeId) + " -> ");
		bfsConsole->setPlainText(bfsQueueText);
		currentNode->setNodeOutlinePen(new QPen(Qt::blue));
		graphicsScene->update();

		bfsQueue->pop();

		for (std::vector<int>::iterator it = neighbourList->begin(); it != neighbourList->end(); it++)
		{
			if (!bfsVisited.at(*it)) {
				bfsVisited[*it] = true;
				bfsQueue->emplace(*it);
			}
		}
	}
	bfsQueueText.append(" X\n BFS Traversal Complete!!\n");
	bfsConsole->setPlainText(bfsQueueText);
}

void BFS::displayGraph()
{
	bfsGraph->displayGraphNodes();
}


