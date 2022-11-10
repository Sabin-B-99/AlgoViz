#pragma once
#include "../linear_structure/ArrayNode.h"
#include <QGraphicsItem>
#include <QPlainTextEdit>
#include <QGraphicsTextItem>
class Search
{
private:
	ArrayNode* linearBoxes;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* linSrchConsole;
	bool linear;
	
	static const int MAX_ARR_SIZE;

public:
	Search();
	Search(QGraphicsScene* graphicsScene, QPlainTextEdit* linSrchConsole, bool linear = false);
	~Search();

	void displayStructure();
	void linSearch(int valToSearchFor);
	void binSearch(int valToSearchFor);

private:
	int binSearcher(int lo, int hi, int searchVal);
};
