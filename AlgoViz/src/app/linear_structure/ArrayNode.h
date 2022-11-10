#pragma once
#include "../node/Node.h"
#include "../line/Line.h"
#include "../animation/PauseAnim.h"
#include <QGraphicsTextItem>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <cstdlib>
#include <algorithm>
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

	std::vector<int>* searchableValues;
	std::vector<QGraphicsTextItem*>* searchableValuesInTextForm;
public:
	ArrayNode(QGraphicsScene* graphicsScene);
	ArrayNode(QGraphicsScene* graphicsScene, int size, bool hasHeadArrow = false, bool hasTailArrow = false, const QString& headArrowText = "", const QString& tailArrowText = "");
	~ArrayNode();

	void createNodes();
	void positionNodes();
	void displayGraphNodes();
	void createLinearStructure();
	QParallelAnimationGroup* animateArrow(std::string arrowFlag, int index);
	void displayGlowAnimation(int nodeIndex);
	void setNodeColor(int nodeIndex,const QColor& col);
	void blackOutNodes(int index, const QString& flag);
	void displayRandomizedValues(bool sorted = false);

	std::vector<Node*>* getNodeList();
	QGraphicsTextItem* getHeadText();
	QGraphicsTextItem* getTailText();
	Line* getHeadArrow();
	Line* getTailArrow();
	std::vector<int>* getSearchableValues();

private:
	void generateRandomValues(bool sorted = false);
	void initializeValuesInBoxes();
	void setHeadArrowLabel(const QString& text);
	void setTailTailLabel(const QString& text);
};

