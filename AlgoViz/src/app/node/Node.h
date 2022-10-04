#pragma once
#include <QGraphicsItemGroup>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <cmath>

class Node : public QGraphicsItem{
private:
	int32_t x;
	int32_t y;
	int32_t boundRectWidth;
	int32_t boundRectHeight;
	QString nodeVal;
	QGraphicsEllipseItem* nodeEllip;
	QBrush* nodeFillBrush;
	QPen* nodeOutilePen;
	QGraphicsItem* parent;

public:
	Node(QGraphicsItem *parent = nullptr);
	Node(int32_t x, int32_t y, const QString& nodeVal, const QColor& fillColor, QGraphicsItem* parent = nullptr);
	Node(const QPointF& pos, const QString& nodeVal, const QColor& fillColor, QGraphicsItem* parent = nullptr);
	~Node();

	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	QGraphicsItem* getParent();

};