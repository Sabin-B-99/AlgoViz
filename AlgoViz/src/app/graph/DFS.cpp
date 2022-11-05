#include "DFS.h"

DFS::DFS()
{
}

DFS::DFS(QGraphicsScene* graphicsScene, QPlainTextEdit* dfsConsole)
	:graphicsScene(graphicsScene), dfsConsole(dfsConsole)
{
	dfsGraph = new Graph(graphicsScene);
	dfsConsoleText = "DFS Traversal:\n\n";
	dfsConsole->setPlainText(dfsConsoleText);

	recursionStackCount = 0;
}

DFS::~DFS()
{
}

void DFS::run(int startNodeId)
{
	std::vector<Node*>* nodesInGraph = dfsGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = dfsGraph->getNodeNeighbours();

	Node* currentNode = nodesInGraph->at(startNodeId);
	dfsVisited[startNodeId] = true;

	currentNode->setNodeOutlinePen(new QPen(Qt::red));
	graphicsScene->update();
	PauseAnim::showPauseAnimation(2000);
	dfsConsoleText.append(QString::number(startNodeId) + " -> ");
	dfsConsole->setPlainText(dfsConsoleText);
	currentNode->setNodeOutlinePen(new QPen(Qt::blue));
	graphicsScene->update();

	for(std::vector<int>::iterator it = nodeNeighbours->at(startNodeId)->begin(); it != nodeNeighbours->at(startNodeId)->end(); it++)
	{
		if (!dfsVisited[*it]) {
			recursionStackCount++;
			run(*it);
		}
	}
	recursionStackCount--;
	if (recursionStackCount == 0 || recursionStackCount == -1) {
		dfsConsoleText.append(" X\n DFS Traversal Complete!!\n");
		dfsConsole->setPlainText(dfsConsoleText);
	}
}

void DFS::displayGraph()
{
	dfsGraph->displayGraphNodes();
}
