#include "ArrayNode.h"

ArrayNode::ArrayNode(QGraphicsScene* graphicsScene)
	:graphicsScene(graphicsScene), size(6)
{
	createLinearStructure();
}

ArrayNode::ArrayNode(QGraphicsScene* graphicsScene, int size, bool hasHeadArrow, bool hasTailArrow, const QString& headArrowText, const QString& tailArrowText)
	:graphicsScene(graphicsScene), size(size), hasHeadArrow(hasHeadArrow) , hasTailArrow(hasTailArrow), headArrow(nullptr), tailArrow(nullptr)
{
	nodeList = new std::vector<Node*>;
	headText = new QGraphicsTextItem(headArrowText);
	tailText = new QGraphicsTextItem(tailArrowText);
	searchableValues = new std::vector<int>(size, -1);
	searchableValuesInTextForm = new std::vector<QGraphicsTextItem*>;
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
	int headLineStartY = nodeList->at(0)->pos().y() + nodeList->at(0)->boundingRect().height();
	int headLineEndX = headLineStartX;
	int headLineEndY = headLineStartY + nodeList->at(0)->boundingRect().height();
	headArrow = new Line(new QPointF(headLineStartX, headLineStartY), new QPointF(headLineEndX, headLineEndY), false, false);
	headText->setPos(headLineStartX - 13, headLineStartY - 20);

	int tailLineStartX = nodeList->at(0)->pos().x() + nodeList->at(0)->boundingRect().width() / 2;
	int tailLineStartY = nodeList->at(0)->pos().y() + nodeList->at(0)->boundingRect().height() * 3;
	int tailLineEndX = tailLineStartX;
	int tailLineEndY = tailLineStartY + nodeList->at(0)->boundingRect().height();
	tailArrow = new Line(new QPointF(tailLineStartX, tailLineStartY), new QPointF(tailLineEndX, tailLineEndY), false, false);
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

QParallelAnimationGroup* ArrayNode::animateArrow(std::string arrowFlag, int index)
{
	Line* arrow = nullptr;
	QGraphicsTextItem* text = nullptr;
	if (arrowFlag.compare("-h") == 0) {
		arrow = headArrow;
		text = headText;
	}
	else {
		arrow = tailArrow;
		text = tailText;
	}
	int nodeWidth = nodeList->at(0)->boundingRect().width();
	int newPosX = arrow->pos().x() + index * nodeWidth;
	int newPosY = arrow->pos().y();

	QPropertyAnimation* insertionAnim = new QPropertyAnimation(arrow, "pos");
	insertionAnim->setStartValue(arrow->pos());
	insertionAnim->setEndValue(QPointF(newPosX, newPosY));
	insertionAnim->setDuration(1500);

	int newPosXForText = text->pos().x() + index * nodeWidth;
	int newPosYForText = text->pos().y();

	QPropertyAnimation* insertionAnimForText = new QPropertyAnimation(text, "pos");
	insertionAnimForText->setStartValue(text->pos());
	insertionAnimForText->setEndValue(QPointF(newPosXForText, newPosYForText));
	insertionAnimForText->setDuration(1500);

	QParallelAnimationGroup* animGrp = new QParallelAnimationGroup;
	animGrp->addAnimation(insertionAnim);
	animGrp->addAnimation(insertionAnimForText);
	return animGrp;
}

void ArrayNode::displayGlowAnimation(int nodeIndex) {
	Node* nodeToAnimate = nodeList->at(nodeIndex);
	nodeToAnimate->setNodeOutlinePen(new QPen(Qt::red, 4));
	graphicsScene->update();
	PauseAnim::showPauseAnimation(1500);
	nodeToAnimate->setNodeOutlinePen(new QPen(Qt::black));
	graphicsScene->update();
}

void ArrayNode::blackOutNodes(int index, const QString& flag) {
	Node* blackOutNode = nullptr;
	PauseAnim::showPauseAnimation(700);
	if (flag.compare("-l") == 0) {
		for (int i = 0; i <= index; i++)
		{
			nodeList->at(i)->setNodeFillBrush(new QBrush(Qt::black));
		}
	}
	else {
		for (int i = index; i < nodeList->size(); i++)
		{
			nodeList->at(i)->setNodeFillBrush(new QBrush(Qt::black));
		}
	}
}

void ArrayNode::setNodeColor(int nodeIndex, const QColor& color) {
	Node* nodeToAnimate = nodeList->at(nodeIndex);
	nodeToAnimate->setNodeOutlinePen(new QPen(color, 3));
	graphicsScene->update();
}

void ArrayNode::generateRandomValues(bool sorted) {
	std::srand(std::time(nullptr));
	for (int i = 0; i < size; i++)
	{
		int randomValue = std::rand() % 999;
		searchableValues->at(i) = randomValue;
	}

	if (sorted) {
		std::sort(searchableValues->begin(), searchableValues->end());
	}
}

void ArrayNode::initializeValuesInBoxes() {
	int currentIndex = 0;
	Node* firstBox = nodeList->at(0);
	QGraphicsTextItem* boxVal = nullptr;

	int boxValPosX = firstBox->pos().x() + (firstBox->boundingRect().width() / 2) - 5;
	int boxValPosY = firstBox->pos().y() + (firstBox->boundingRect().height() / 2) - 8;

	for (std::vector<int>::iterator it = searchableValues->begin(); it != searchableValues->end(); it++)
	{
		boxVal = new QGraphicsTextItem(QString::number(*it));
		boxVal->setPos(boxValPosX, boxValPosY);
		searchableValuesInTextForm->emplace_back(boxVal);
		graphicsScene->addItem(boxVal);
		boxValPosX += firstBox->boundingRect().width();
	}
}

void ArrayNode::displayRandomizedValues(bool sorted) {
	generateRandomValues(sorted);
	initializeValuesInBoxes();
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


std::vector<int>* ArrayNode::getSearchableValues() {
	return this->searchableValues;
}

void ArrayNode::setHeadArrowLabel(const QString& text) {
	this->headText->setPlainText(text);
}

void ArrayNode::setTailTailLabel(const QString& text) {
	this->tailText->setPlainText(text);
}