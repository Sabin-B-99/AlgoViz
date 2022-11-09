#include "Line.h"

Line::Line(QGraphicsItem* parent)
	:arrowHeadBottomOrRight(nullptr), arrowHeadTopOrLeft(nullptr)
{
	startCoord = new QPointF();
	endCoord = new QPointF();
	lineStrokePen = new QPen(Qt::black);
	lineStrokePen->setWidth(2);
	hasArrowHead = false;
	hasArrowAtTopOrLeft = false;
	startNode = nullptr;
	endNode = nullptr;
	arrowSize = 9;
}

Line::Line(QPointF* startCoord, QPointF* endCoord, bool hasArrow, bool hasArrowAtTopOrLeft, const QString& lineText, Node* parent) 
	:startCoord(startCoord), endCoord(endCoord), hasArrowHead(hasArrow), hasArrowAtTopOrLeft(hasArrowAtTopOrLeft), lineText(lineText), parent(parent), 
	arrowHeadBottomOrRight(nullptr), arrowHeadTopOrLeft(nullptr)
{
	lineStrokePen = new QPen(Qt::black);
	lineStrokePen->setWidth(2);
	arrowSize = 9;
	startNode = nullptr;
	endNode = nullptr;
}

Line::Line(Node* startNode, Node* endNode, bool hasArrow, bool hasArrowAtTopOrLeft, const QString& lineText, Node* parent)
	:startNode(startNode), endNode(endNode), hasArrowHead(hasArrow), hasArrowAtTopOrLeft(hasArrowAtTopOrLeft), lineText(lineText), parent(parent),
	arrowHeadBottomOrRight(nullptr), arrowHeadTopOrLeft(nullptr)
{
	lineStrokePen = new QPen(Qt::black);
	lineStrokePen->setWidth(2);
	arrowSize = 9;
	startCoord = nullptr;
	endCoord = nullptr;
}



QRectF Line::boundingRect() const
{
	if (startNode) {
		return QRectF(startNode->boundingRect());
	}
	return QRectF(startCoord->x(), startCoord->y(), lineStrokePen->widthF() + 5, endCoord->y() - startCoord->y());
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(*lineStrokePen);

	int32_t lineStartX = 0;
	int32_t lineStartY = 0;
	int32_t lineEndX = 0;
	int32_t lineEndY = 0;
	if (startNode && endNode) {
		lineStartX = startNode->pos().x() + startNode->boundingRect().width() / 2;
		lineStartY = startNode->pos().y() + startNode->boundingRect().height();

		lineEndX = endNode->pos().x() + endNode->boundingRect().width() / 2;
		lineEndY = endNode->pos().y();

		startCoord = new QPointF(lineStartX, lineStartY);
		endCoord = new QPointF(lineEndX, lineEndY);
	}
	else {
		lineStartX = startCoord->x();
		lineStartY = startCoord->y();
		lineEndX = endCoord->x();
		lineEndY = endCoord->y();
	}


	painter->drawLine(*startCoord, *endCoord);

	int32_t textStartX = ((lineEndX + lineStartX) / 2) - 2;
	int32_t textStartY = ((lineEndY + lineStartY) / 2) - 8;

	painter->drawText(QPointF(textStartX, textStartY), lineText);
	
	if (hasArrowHead) {
		arrowHeadBottomOrRight = buildArrowHead(QLineF(*endCoord, *startCoord)); 
		painter->setBrush(Qt::black);
		painter->drawPolygon(*arrowHeadBottomOrRight);
	}

	if (hasArrowAtTopOrLeft) {
		arrowHeadTopOrLeft = buildArrowHead(QLineF(*startCoord, *endCoord));
		painter->setBrush(Qt::black);
		painter->drawPolygon(*arrowHeadTopOrLeft);
	}
}

void Line::setArrowSize(double arrowSize)
{
	this->arrowSize = arrowSize;
}

QGraphicsItem* Line::getStartNode()
{
	return this->startNode;
}

QGraphicsItem* Line::getEndNode()
{
	return this->endNode;
}

QString Line::getLineText()
{
	return this->lineText;
}

void Line::setLineStrokePen(QPen* lineStrokePen)
{
	this->lineStrokePen = lineStrokePen;
}

QPolygonF* Line::getArrowHeadAtTopOrLeft()
{
	return this->arrowHeadTopOrLeft;
}

QPolygonF* Line::getArrowHeadAtBottomOrRight()
{
	return this->arrowHeadBottomOrRight;
}


QPolygonF* Line::buildArrowHead(const QLineF& line)
{
	//copied from qt forum
	double angle = std::atan2(-line.dy(), line.dx());

	QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
	QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);
	
	QPolygonF* arrowHead = new QPolygonF();

	arrowHead->clear();
	*arrowHead << line.p1() << arrowP1 << arrowP2;

	return arrowHead;

}

