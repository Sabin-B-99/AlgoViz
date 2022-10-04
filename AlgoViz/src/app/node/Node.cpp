#include "Node.h"

Node::Node(QGraphicsItem* parent)
{
}

Node::Node(int32_t x, int32_t y, const QString& nodeVal, const QColor& fillColor, QGraphicsItem* parent)
	:x(x), y(y), nodeVal(nodeVal), parent(parent)
{
	boundRectWidth = 50 + std::pow(nodeVal.length(), 1.5);
	boundRectHeight = 50 + std::pow(nodeVal.length(), 1.5);
	nodeOutilePen = new QPen(Qt::black);
	nodeFillBrush = new QBrush(fillColor);
	nodeEllip = new QGraphicsEllipseItem();
}

Node::Node(const QPointF& pos, const QString& nodeVal, const QColor& fillColor, QGraphicsItem* parent)
	:x(pos.x()), y(pos.y()), nodeVal(nodeVal), parent(parent)
{
	boundRectWidth = 50 + std::pow(nodeVal.length(), 1.5);
	boundRectHeight = 50 + std::pow(nodeVal.length(), 1.5);
	nodeOutilePen = new QPen(Qt::black);
	nodeFillBrush = new QBrush(fillColor);
	nodeEllip = new QGraphicsEllipseItem();
}

Node::~Node()
{
}

QRectF Node::boundingRect() const
{
	return QRectF(x,y,boundRectWidth, boundRectHeight);
}

void Node::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QRectF rect = boundingRect();
	painter->setPen(*nodeOutilePen);
	painter->setBrush(*nodeFillBrush);
	painter->drawEllipse(rect);

	QPointF boundRectCenter = rect.center();


	int32_t textStartX = ((boundRectCenter.x() + x) / 2) + ((boundRectCenter.x() - x) / 4);
	int32_t textStartY = boundRectCenter.y();
	QPoint textStartPos(textStartX, textStartY);



	painter->drawText(textStartPos, nodeVal);
}

QGraphicsItem* Node::getParent()
{
	return this->parent;
}



