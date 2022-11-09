#pragma once
#include "../node/Node.h"
#include "../line/Line.h"
#include <QGraphicsTextItem>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
class ArrayNode
{
private:
	int size;
	std::vector<Node*>* nodeList;
	QGraphicsScene* graphicsScene;
	QGraphicsTextItem* headText;
	QGraphicsTextItem* tailText;
	bool hasHeadArrow;
	bool hasTailArrow;
	Line* headArrow;
	Line* tailArrow;
public:
	ArrayNode(QGraphicsScene* graphicsScene);
	ArrayNode(QGraphicsScene* graphicsScene, int size, bool hasHeadArrow = false, bool hasTailArrow = false, const QString& headArrowText = "", const QString& tailArrowText = "");
	~ArrayNode();

	void createNodes();
	void positionNodes();
	void displayGraphNodes();
	void createLinearStructure();
	QParallelAnimationGroup* animateArrow(std::string arrowFlag, int index);

	std::vector<Node*>* getNodeList();
	QGraphicsTextItem* getHeadText();
	QGraphicsTextItem* getTailText();
	Line* getHeadArrow();
	Line* getTailArrow();

};

