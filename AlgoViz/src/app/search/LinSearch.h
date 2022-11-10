#pragma once
#include "../linear_structure/ArrayNode.h"
#include <QGraphicsItem>
#include <QPlainTextEdit>
#include <cstdlib>
#include <QGraphicsTextItem>
class LinSearch
{
private:
	ArrayNode* linearBoxes;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* linSrchConsole;

	std::vector<int>* searchableValues;
	std::vector<QGraphicsTextItem*>* searchableValuesInTextForm;
	
	static const int MAX_ARR_SIZE;

public:
	LinSearch();
	LinSearch(QGraphicsScene* graphicsScene, QPlainTextEdit* linSrchConsole);
	~LinSearch();

	void displayStructure();
	void search(int valToSearchFor);

private:
	void generateRandomValues();
	void initializeValuesInBoxes();
};
