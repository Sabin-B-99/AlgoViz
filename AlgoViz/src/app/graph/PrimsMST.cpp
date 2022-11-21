#include "PrimsMST.h"

PrimsMST::PrimsMST()
{
}

PrimsMST::PrimsMST(QGraphicsScene* graphicsScene, QPlainTextEdit* primsMSTConsole)
	:graphicsScene(graphicsScene), primsMSTConsole(primsMSTConsole)
{
	primsMSTGraph = new Graph(graphicsScene, true);
	primsMSTConsole->clear();
}

PrimsMST::~PrimsMST()
{
}

void PrimsMST::run()
{

	std::vector<Node*>* nodesInGraph = primsMSTGraph->getNodesInGraph();
	std::map<int, std::vector<int>*>* nodeNeighbours = primsMSTGraph->getNodeNeighbours();
	std::vector<std::vector<int>*>* weightMatrix = primsMSTGraph->getWeightMatrix();

	std::vector<int>* parent = new std::vector<int>(nodesInGraph->size(), 0);
	std::vector<int>* key = new std::vector<int>(nodesInGraph->size(), std::numeric_limits<int>::max());
	std::vector<bool>* mstSet = new std::vector<bool>(nodesInGraph->size(), false);

	key->at(0) = 0;
	parent->at(0) = -1;

	Node* currentNode = nullptr;
	Node* nextNode = nullptr;
	Line* nodeConnectingLine = nullptr;

	for (int i = 0; i < nodesInGraph->size() - 1; i++)
	{
		int nextNodeWithMinKey = minKey(key, mstSet);
		if (nextNodeWithMinKey == -1) {
			nextNodeWithMinKey = 1;
			/*break;*/
		}
		/*else {*/
		mstSet->at(nextNodeWithMinKey) = true;
		/*}*/
		
		for (int v = 0; v < nodesInGraph->size(); v++)
		{
			//Animation Code
			currentNode = nodesInGraph->at(nextNodeWithMinKey);
			nextNode = nodesInGraph->at(v);
			nodeConnectingLine = primsMSTGraph->getConnectingLine(currentNode, nextNode);
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

	int weightSum = 0;
	int currentWeight = 0;

	for (int i = 1; i < primsMSTGraph->getNodesInGraph()->size(); i++)
	{
		edgeStartID = parent->at(i);
		edgeEndID = i;

		if (edgeStartID >= 0) {
			startNode = primsMSTGraph->getNodesInGraph()->at(edgeStartID);
			endNode = primsMSTGraph->getNodesInGraph()->at(edgeEndID);
			connectingLine = primsMSTGraph->getConnectingLine(startNode, endNode);
			if (connectingLine) {
				currentWeight = weightMatrix->at(edgeStartID)->at(edgeEndID);
				weightSum += currentWeight;
				soln.append(QString::number(edgeStartID) + " - " + QString::number(edgeEndID) + " \t" + QString::number(currentWeight) + "\n");
				primsMSTConsole->setPlainText(soln);
				connectingLine->setLineStrokePen(new QPen(Qt::red, 2));
			}
		}
	}
	soln.append("\n************************\n Total weigth = " + QString::number(weightSum) + "\n");
	primsMSTConsole->setPlainText(soln);
}
