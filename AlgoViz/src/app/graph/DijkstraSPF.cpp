#include "DijkstraSPF.h"

DijkstraSPF::DijkstraSPF()
{
}

DijkstraSPF::DijkstraSPF(QGraphicsScene* graphicsScene, QPlainTextEdit* dspfConsole)
	:graphicsScene(graphicsScene), dspfConsole(dspfConsole)
{
	dspfGraph = new Graph(graphicsScene, true);
}

DijkstraSPF::~DijkstraSPF()
{
}

void DijkstraSPF::run(int startNodeId)
{
	std::vector<Node*>* nodesInGraph = dspfGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = dspfGraph->getNodeNeighbours();
	std::vector<std::vector<int>*>* weightMatrix = dspfGraph->getWeightMatrix();

	std::vector<int>* dist = new std::vector<int>(nodesInGraph->size(), std::numeric_limits<int>::max());


	std::vector<bool>* sptSet = new std::vector<bool>(nodesInGraph->size(), false);

	//for (int i = 0; i < nodesInGraph->size(); i++)
	//{
	//	dist.at(i) = std::numeric_limits<int>::max();
	//	sptSet.at(i) = false;
	//}

	dist->at(startNodeId) = 0;

	for (int i = 0; i < nodesInGraph->size() - 1; i++)
	{
		int nextVertexWithMinDist = minDistance(dist, sptSet);
		sptSet->at(nextVertexWithMinDist) = true;

		for (int v = 0; v < nodesInGraph->size(); v++)
		{
			if (!sptSet->at(v) && weightMatrix->at(nextVertexWithMinDist)->at(v)
				&& dist->at(nextVertexWithMinDist) != std::numeric_limits<int>::max()
				&& dist->at(nextVertexWithMinDist) + weightMatrix->at(nextVertexWithMinDist)->at(v) < dist->at(v)){

				dist->at(v) = dist->at(nextVertexWithMinDist) + weightMatrix->at(nextVertexWithMinDist)->at(v);
			}

		}
	}
	printSolution(dist);
}

void DijkstraSPF::displayGraph()
{
	dspfGraph->displayGraphNodes();
}

int DijkstraSPF::minDistance(std::vector<int>* dist, std::vector<bool>* sptSet)
{
	int min = std::numeric_limits<int>::max();
	int min_index = 0;

	for (int i = 0; i < dspfGraph->getNodesInGraph()->size(); i++)
	{
		if(sptSet->at(i) == false && dist->at(i) <= min){
			min = dist->at(i);
			min_index = i;
		}
	}

	return min_index;
}

void DijkstraSPF::printSolution(std::vector<int>* dist)
{
	QString soln = "Vertex \t Distance from Source\n";
	for (int i = 0; i < dspfGraph->getNodesInGraph()->size(); i++)
	{
		soln.append(QString::number(i) + " \t" + QString::number(dist->at(i)) + "\n");
		dspfConsole->setPlainText(soln);
	}
}
