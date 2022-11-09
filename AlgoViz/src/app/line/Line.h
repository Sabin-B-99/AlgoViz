#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <QGraphicsObject>
#include <QObject>
#include <QPen>
#include <QPainter>
#include <QPen>
#include <cmath>
#include "../node/Node.h"



class Line : public QGraphicsObject {
private:
	QPointF* startCoord;
	QPointF* endCoord;
	Node* parent;
	Node* startNode;
	Node* endNode;
	QPen* lineStrokePen;
	bool hasArrowHead;
	bool hasArrowAtTopOrLeft;
	double arrowSize;
	QString lineText;

	QPolygonF* arrowHeadTopOrLeft;
	QPolygonF* arrowHeadBottomOrRight;

public:
	Line(QGraphicsItem* parent = nullptr);
	Line(QPointF* startCoord, QPointF* endCoord, bool hasArrow, bool hasArrowAtTopOrLeft, const QString& lineText = " ", Node* parent = nullptr);
	Line(Node* startNode, Node* endNode, bool hasArrow, bool hasArrowAtTopOrLeft, const QString& lineText = " ", Node* parent = nullptr);

	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	void setArrowSize(double arrowSize);

	QGraphicsItem* getStartNode();
	QGraphicsItem* getEndNode();
	QString getLineText();

	void setLineStrokePen(QPen* lineStrokePen);

	QPolygonF* getArrowHeadAtTopOrLeft();
	QPolygonF* getArrowHeadAtBottomOrRight();

private:
	QPolygonF* buildArrowHead(const QLineF& line);

};