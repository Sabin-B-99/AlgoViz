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
	dist->at(startNodeId) = 0;

	Node* currentNode = nullptr;
	Node* nextNode = nullptr;
	Line* nodeConnectingLine = nullptr;

	for (int i = 0; i < nodesInGraph->size() - 1; i++)
	{
		int nextVertexWithMinDist = minDistance(dist, sptSet);
		sptSet->at(nextVertexWithMinDist) = true;

		for (int v = 0; v < nodesInGraph->size(); v++)
		{		
			//Animation Code
			currentNode = nodesInGraph->at(nextVertexWithMinDist);
			nextNode = nodesInGraph->at(v);
			nodeConnectingLine = dspfGraph->getConnectingLine(currentNode, nextNode);
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
			//Animation Code Ends

			if (!sptSet->at(v) && weightMatrix->at(nextVertexWithMinDist)->at(v)
				&& dist->at(nextVertexWithMinDist) != std::numeric_limits<int>::max()
				&& dist->at(nextVertexWithMinDist) + weightMatrix->at(nextVertexWithMinDist)->at(v) < dist->at(v)){

				dist->at(v) = dist->at(nextVertexWithMinDist) + weightMatrix->at(nextVertexWithMinDist)->at(v);
			}
		}
	}
	printSolution(dist, startNodeId);
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

void DijkstraSPF::printSolution(std::vector<int>* dist, int sourceNode)
{
	QString soln = "Vertex \t| Distance from Source: " + QString::number(sourceNode);
	soln.append("\n---------------------------------------------------\n");
	for (int i = 0; i < dspfGraph->getNodesInGraph()->size(); i++)
	{
		if (dist->at(i) == std::numeric_limits<int>::max()) {
			soln.append(QString::number(i) + "\t| " + QString::fromUtf8("\xE2\x88\x9E") + "\n");
		}
		else {
			soln.append(QString::number(i) + "\t| " + QString::number(dist->at(i)) + "\n");
		}
		dspfConsole->setPlainText(soln);
	}

}
