#include "KruskalMST.h"

KruskalMST::KruskalMST()
{
}

KruskalMST::KruskalMST(QGraphicsScene* graphicsScene, QPlainTextEdit* kruskalMSTConsole)
	:graphicsScene(graphicsScene), kruskalMSTConsole(kruskalMSTConsole)
{
	this->kruskalMSTGraph = new Graph(graphicsScene, true);
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



	for (std::vector<std::vector<int>>::iterator it = edgeList.begin(); it != edgeList.end(); it++)
	{
		int x = (*it).at(0);
		int y = (*it).at(1);
		int w = (*it).at(2);

		if (s->find(x) != s->find(y)) {
			s->unite(x, y);
			ans += w;
			soln.append(QString::number(x) + " -- " + QString::number(y) + " == " + QString::number(w) + "\n");
			kruskalMSTConsole->setPlainText(soln);
		}
	}
}

void KruskalMST::displayGraph()
{
	kruskalMSTGraph->displayGraphNodes();
}
