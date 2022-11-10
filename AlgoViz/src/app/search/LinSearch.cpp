#include "LinSearch.h"

LinSearch::LinSearch()
{
}

LinSearch::LinSearch(QGraphicsScene* graphicsScene, QPlainTextEdit* linSrchConsole)
	:graphicsScene(graphicsScene), linSrchConsole(linSrchConsole)
{
	linearBoxes = new ArrayNode(graphicsScene, MAX_ARR_SIZE);
	searchableValues = new std::vector<int>(MAX_ARR_SIZE, -1);
	searchableValuesInTextForm = new std::vector<QGraphicsTextItem*>;
	generateRandomValues();
}

LinSearch::~LinSearch()
{
}

void LinSearch::displayStructure()
{
	linearBoxes->displayGraphNodes();
	initializeValuesInBoxes();
}

void LinSearch::generateRandomValues()
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < MAX_ARR_SIZE; i++)
	{
		int randomValue = std::rand() % 999;
		searchableValues->at(i)  = randomValue;
	}
}

void LinSearch::initializeValuesInBoxes()
{
	int currentIndex = 0;
	Node* firstBox = linearBoxes->getNodeList()->at(0);
	QGraphicsTextItem* boxVal = nullptr;

	int boxValPosX = firstBox->pos().x() + (firstBox->boundingRect().width() / 2) - 5;
	int boxValPosY = firstBox->pos().y() + (firstBox->boundingRect().height() / 2) - 8;

	for (std::vector<int>::iterator it = searchableValues->begin(); it != searchableValues->end(); it++)
	{
		boxVal = new QGraphicsTextItem(QString::number(*it));
		boxVal->setPos(boxValPosX, boxValPosY);
		searchableValuesInTextForm->emplace_back(boxVal);
		graphicsScene->addItem(boxVal);
		boxValPosX += firstBox->boundingRect().width();
	}
}

void LinSearch::search(int valToSearchFor) {
	int foundIndex = 0;
	for (int i = 0; i < MAX_ARR_SIZE; i++)
	{
		linearBoxes->displayGlowAnimation(i);
		if (valToSearchFor == searchableValues->at(i)) {
			linearBoxes->setNodeColor(i,Qt::green);
			foundIndex = i;
			linSrchConsole->setPlainText("Value: " + QString::number(valToSearchFor) + " found at: Index value of " + QString::number(foundIndex));
			break;
		}
		else {
			linSrchConsole->setPlainText("Value not found :(");
		}
	}
}

const int LinSearch::MAX_ARR_SIZE = 13;