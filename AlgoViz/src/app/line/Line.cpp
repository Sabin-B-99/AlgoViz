#include "Line.h"

Line::Line(QGraphicsItem* parent)
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

Line::Line(QGraphicsItem* startNode, QGraphicsItem* endNode, bool hasArrow, bool hasArrowAtTopOrLeft, QGraphicsItem* parent)
	:startNode(startNode), endNode(endNode), hasArrowHead(hasArrow), hasArrowAtTopOrLeft(hasArrowAtTopOrLeft), parent(parent)
{
	lineStrokePen = new QPen(Qt::black);
	lineStrokePen->setWidth(2);
	arrowSize = 9;
}



QRectF Line::boundingRect() const
{
	return QRectF();
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(*lineStrokePen);

	int32_t lineStartX = startNode->boundingRect().x() + startNode->boundingRect().width() / 2;
	int32_t lineStartY = startNode->boundingRect().y() + startNode->boundingRect().height();

	int32_t lineEndX = endNode->boundingRect().x() + endNode->boundingRect().width() / 2;
	int32_t lineEndY = endNode->boundingRect().y();

	startCoord = new QPointF(lineStartX, lineStartY);
	endCoord = new QPointF(lineEndX, lineEndY);
	painter->drawLine(*startCoord, *endCoord);

	
	if (hasArrowHead) {
		QPolygonF* arrowHeadBottomOrRight = buildArrowHead(QLineF(*endCoord, *startCoord));
		painter->setBrush(Qt::black);
		painter->drawPolygon(*arrowHeadBottomOrRight);
	}

	if (hasArrowAtTopOrLeft) {
		QPolygonF* arrowHeadTopOrLeft = buildArrowHead(QLineF(*startCoord, *endCoord));
		painter->setBrush(Qt::black);
		painter->drawPolygon(*arrowHeadTopOrLeft);
	}

}

void Line::setArrowSize(double arrowSize)
{
	this->arrowSize = arrowSize;
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

