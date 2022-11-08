#include "ArrayNode.h"

ArrayNode::ArrayNode(QGraphicsScene* graphicsScene)
	:graphicsScene(graphicsScene), size(6)
{
	createLinearStructure();
}

ArrayNode::ArrayNode(QGraphicsScene* graphicsScene, int size, bool hasHeadArrow, bool hasTailArrow)
	:graphicsScene(graphicsScene), size(size), hasHeadArrow(hasHeadArrow) , hasTailArrow(hasTailArrow), headArrow(nullptr), tailArrow(nullptr)
{
	nodeList = new std::vector<Node*>;
	headText = new QGraphicsTextItem("Head");
	tailText = new QGraphicsTextItem("Tail");
	createLinearStructure();

}

ArrayNode::~ArrayNode()
{
}

void ArrayNode::createNodes()
{
	for (int i = 0; i < size; i++)
	{
		nodeList->emplace_back(new Node("", Qt::white, true));
	}
	int headLineStartX = nodeList->at(0)-> pos().x() + nodeList->at(0)->boundingRect().width() / 2;
	int headLineStartY = nodeList->at(0)->pos().y() + nodeList->at(0)->boundingRect().height() - 10;
	int headLineEndX = headLineStartX;
	int headLineEndY = headLineStartY + nodeList->at(0)->boundingRect().height();
	headArrow = new Line(new QPointF(headLineStartX, headLineStartY), new QPointF(headLineEndX, headLineEndY), true, false);
	headText->setPos(headLineStartX - 13, headLineStartY - 20);

	int tailLineStartX = nodeList->at(0)->pos().x() + nodeList->at(0)->boundingRect().width() / 2;
	int tailLineStartY = nodeList->at(0)->pos().y() + nodeList->at(0)->boundingRect().height() * 3 + 10 ;
	int tailLineEndX = tailLineStartX;
	int tailLineEndY = tailLineStartY + nodeList->at(0)->boundingRect().height();
	tailArrow = new Line(new QPointF(tailLineStartX, tailLineStartY), new QPointF(tailLineEndX, tailLineEndY), false, true);
	tailText->setPos(tailLineStartX - 13 , tailLineEndY);
}

void ArrayNode::positionNodes()
{
	int posX = 0;
	int posY = 100;
	Node* nodeToBePositioned = nullptr;
	for (int i = 0; i < nodeList->size(); i++)
	{
		nodeToBePositioned = nodeList->at(i);
		nodeToBePositioned->setPos(posX, posY);
		posX += nodeToBePositioned->boundingRect().width();
	}
}

void ArrayNode::displayGraphNodes()
{
	for (std::vector<Node*>::iterator it = nodeList->begin(); it != nodeList->end(); it++)
	{
		graphicsScene->addItem(*it);
	}

	if (hasHeadArrow) {
		graphicsScene->addItem(headArrow);
		graphicsScene->addItem(headText);
	}
	if (hasTailArrow) {
		graphicsScene->addItem(tailArrow);
		graphicsScene->addItem(tailText);
	}
	
}

void ArrayNode::createLinearStructure() 
{
	createNodes();
	positionNodes();
}

std::vector<Node*>* ArrayNode::getNodeList()
{
	return this->nodeList;
}

QGraphicsTextItem* ArrayNode::getHeadText()
{
	return this->headText;
}

QGraphicsTextItem* ArrayNode::getTailText()
{
	return this->tailText;
}

Line* ArrayNode::getHeadArrow()
{
	return this->headArrow;
}

Line* ArrayNode::getTailArrow()
{
	return this->tailArrow;
}
