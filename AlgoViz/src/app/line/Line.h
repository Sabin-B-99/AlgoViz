#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QPen>
#include <cmath>


class Line : public QGraphicsItem {
private:
	QPointF* startCoord;
	QPointF* endCoord;
	QGraphicsItem* parent;
	QGraphicsItem* startNode;
	QGraphicsItem* endNode;
	QPen* lineStrokePen;
	bool hasArrowHead;
	bool hasArrowAtTopOrLeft;
	double arrowSize;
public:
	Line(QGraphicsItem* parent = nullptr);
	Line(QGraphicsItem* startNode, QGraphicsItem* endNode, bool hasArrow, bool hasArrowAtTopOrLeft, QGraphicsItem* parent = nullptr);

	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	void setArrowSize(double arrowSize);

private:
	QPolygonF* buildArrowHead(const QLineF& line);

};