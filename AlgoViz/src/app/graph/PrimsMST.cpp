#include "PrimsMST.h"

PrimsMST::PrimsMST()
{
}

PrimsMST::PrimsMST(QGraphicsScene* graphicsScene, QPlainTextEdit* primsMSTConsole)
	:graphicsScene(graphicsScene), primsMSTConsole(primsMSTConsole)
{
	primsMSTGraph = new Graph(graphicsScene, true);
}

PrimsMST::~PrimsMST()
{
}

void PrimsMST::run(int startNodeId)
{

	std::vector<Node*>* nodesInGraph = primsMSTGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = primsMSTGraph->getNodeNeighbours();
	std::vector<std::vector<int>*>* weightMatrix = primsMSTGraph->getWeightMatrix();

	std::vector<int>* parent = new std::vector<int>(nodesInGraph->size(), 0);
	std::vector<int>* key = new std::vector<int>(nodesInGraph->size(), std::numeric_limits<int>::max());
	std::vector<bool>* mstSet = new std::vector<bool>(nodesInGraph->size(), false);

	key->at(0) = 0;
	parent->at(startNodeId) = -1;

	for (int i = 0; i < nodesInGraph->size() - 1; i++)
	{
		int nextNodeWithMinKey = minKey(key, mstSet);
		mstSet->at(nextNodeWithMinKey) = true;

		for (int v = 0; v < nodesInGraph->size(); v++)
		{
			if (weightMatrix->at(nextNodeWithMinKey)->at(v) && mstSet->at(v) == false
				&& weightMatrix->at(nextNodeWithMinKey)->at(v) < key->at(v))
			{
				parent->at(v) = nextNodeWithMinKey;
				key->at(v) = weightMatrix->at(nextNodeWithMinKey)->at(v);
			}
		}
	}
	printMST(parent, weightMatrix);
}

void PrimsMST::displayGraph()
{
	primsMSTGraph->displayGraphNodes();
}

int PrimsMST::minKey(std::vector<int>* key, std::vector<bool>* mstSet)
{
	int min = std::numeric_limits<int>::max();
	int minIndex = -1;

	for (int i = 0; i < primsMSTGraph->getNodesInGraph()->size(); i++)
	{
		if (mstSet->at(i) == false && key->at(i) < min)  {
			min = key->at(i);
			minIndex = i;
		}
	}
	return minIndex;
}

void PrimsMST::printMST(std::vector<int>* parent, std::vector<std::vector<int>*>* weightMatrix)
{
	QString soln = "Edge \tWeight\n";
	int edgeStartID = 0;
	int edgeEndID = 0;

	Node* startNode = nullptr;
	Node* endNode = nullptr;
	Line* connectingLine = nullptr;

	for (int i = 1; i < primsMSTGraph->getNodesInGraph()->size(); i++)
	{
		edgeStartID = parent->at(i);
		edgeEndID = i;

		startNode = primsMSTGraph->getNodesInGraph()->at(edgeStartID);
		endNode = primsMSTGraph->getNodesInGraph()->at(edgeEndID);
		connectingLine = primsMSTGraph->getConnectingLine(startNode, endNode);
		if (connectingLine) {
			soln.append(QString::number(edgeStartID) + " - " + QString::number(edgeEndID) + " \t" + QString::number(weightMatrix->at(edgeStartID)->at(edgeEndID)) + "\n");
			primsMSTConsole->setPlainText(soln);
		}
	}
}
