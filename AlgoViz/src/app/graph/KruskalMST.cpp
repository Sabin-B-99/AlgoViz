#include "KruskalMST.h"

KruskalMST::KruskalMST()
{
}

KruskalMST::KruskalMST(QGraphicsScene* graphicsScene, QPlainTextEdit* kruskalMSTConsole)
	:graphicsScene(graphicsScene), kruskalMSTConsole(kruskalMSTConsole)
{
	this->kruskalMSTGraph = new Graph(graphicsScene, true);
	kruskalMSTConsole->clear();
}

KruskalMST::~KruskalMST()
{
}

void KruskalMST::run()
{
	std::vector<Node*>* nodesInGraph = kruskalMSTGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = kruskalMSTGraph->getNodeNeighbours();
	std::vector<std::vector<int>*>* weightMatrix = kruskalMSTGraph->getWeightMatrix(); 

	std::vector<std::vector<int>> edgeList = kruskalMSTGraph->getEdgeList();
	
	QString soln = "Following edges are constructed in the MST\n";

		
	std::sort(edgeList.begin(), edgeList.end());
	DSU* s = new DSU(edgeList.size());
	int ans = 0;
	kruskalMSTConsole->setPlainText(soln);

	Node* currentNode = nullptr;
	Node* nextNode = nullptr;
	Line* nodeConnectingLine = nullptr;
	std::vector<std::pair<int, int>*>* mstSolnEdges = new std::vector<std::pair<int, int>*>;

	for (std::vector<std::vector<int>>::iterator it = edgeList.begin(); it != edgeList.end(); it++)
	{
		int x = (*it).at(0);
		int y = (*it).at(1);
		int w = (*it).at(2);

		currentNode = nodesInGraph->at(x);
		nextNode = nodesInGraph->at(y);
		nodeConnectingLine = kruskalMSTGraph->getConnectingLine(currentNode, nextNode);
		if (nodeConnectingLine) {
			currentNode->setNodeOutlinePen(new QPen(Qt::blue));
			nextNode->setNodeOutlinePen(new QPen(Qt::red));
			nodeConnectingLine->setLineStrokePen(new QPen(Qt::red));
			graphicsScene->update();
			PauseAnim::showPauseAnimation(1200);
			currentNode->setNodeOutlinePen(new QPen(Qt::black));
			nextNode->setNodeOutlinePen(new QPen(Qt::black));
			nodeConnectingLine->setLineStrokePen(new QPen(Qt::black));
			graphicsScene->update();
		}

		if (s->find(x) != s->find(y)) {
			s->unite(x, y);
			ans += w;

			soln.append(QString::number(x) + " -- " + QString::number(y) + " == " + QString::number(w) +  "\n");
			kruskalMSTConsole->setPlainText(soln);
			mstSolnEdges->emplace_back(new std::pair<int, int>(x,y));
		}
	}

	for (std::vector<std::pair<int,int>*>::iterator it = mstSolnEdges->begin(); it != mstSolnEdges->end(); it++)
	{
		currentNode = nodesInGraph->at((**it).first);
		nextNode = nodesInGraph->at((**it).second);
		nodeConnectingLine = kruskalMSTGraph->getConnectingLine(currentNode, nextNode);
		nodeConnectingLine->setLineStrokePen(new QPen(Qt::red, 2));
	}

	soln.append("\n************************\n Total weigth = " + QString::number(ans) + "\n");
	kruskalMSTConsole->setPlainText(soln);

}

void KruskalMST::displayGraph()
{
	kruskalMSTGraph->displayGraphNodes();
}
