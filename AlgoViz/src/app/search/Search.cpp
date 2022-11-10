#include "Search.h"

Search::Search()
{
}

Search::Search(QGraphicsScene* graphicsScene, QPlainTextEdit* linSrchConsole, bool linear)
	:graphicsScene(graphicsScene), linSrchConsole(linSrchConsole), linear(linear)
{
	linearBoxes = new ArrayNode(graphicsScene, MAX_ARR_SIZE);
}

Search::~Search()
{
}

void Search::displayStructure()
{
	linearBoxes->displayGraphNodes();
	if (linear) {
		linearBoxes->displayRandomizedValues();
	}
	else {
		linearBoxes->displayRandomizedValues(true);
	}
	
}


void Search::linSearch(int valToSearchFor) {
	int foundIndex = 0;
	bool notFound = true;
	linSrchConsole->appendPlainText("Searching for: " + QString::number(valToSearchFor));
	std::vector<int>* searchableValues = linearBoxes->getSearchableValues();
	for (int i = 0; i < MAX_ARR_SIZE; i++)
	{
		linearBoxes->displayGlowAnimation(i);
		if (valToSearchFor == searchableValues->at(i)) {
			linearBoxes->setNodeColor(i,Qt::green);
			foundIndex = i;
			linSrchConsole->appendPlainText("Value: " + QString::number(valToSearchFor) + " found at: Index value of " + QString::number(foundIndex));
			notFound = false;
			break;
		}
	}
	if (notFound) {
		linSrchConsole->appendPlainText("Value not found :(");
	}
}

void Search::binSearch(int valToSearchFor) {
	linSrchConsole->appendPlainText("Searching for: " + QString::number(valToSearchFor));
	int searchedVal = binSearcher(0, MAX_ARR_SIZE - 1, valToSearchFor);
	if (searchedVal == -1) {
		linSrchConsole->appendPlainText("Value not found :(");
	}
	else {
		linSrchConsole->appendPlainText("Value: " + QString::number(valToSearchFor) + " found at: Index value of " + QString::number(searchedVal));
		linearBoxes->setNodeColor(searchedVal, Qt::green);
	}
}

int Search::binSearcher(int lo, int hi, int searchVal) {
	std::vector<int>* searchableValues = linearBoxes->getSearchableValues();
	if (hi >= lo && hi > 0)
	{
		int mid = (lo + hi) / 2;
		linearBoxes->displayGlowAnimation(mid);
		if (searchableValues->at(mid) == searchVal) {
			linearBoxes->blackOutNodes(mid - 1, "-l");
			linearBoxes->blackOutNodes(mid + 1, "-r");
			return mid;
		}

		if (searchableValues->at(mid) > searchVal) {
			linearBoxes->blackOutNodes(mid, "-r");
			return binSearcher(lo, mid - 1, searchVal);
		}
		else {
			linearBoxes->blackOutNodes(mid, "-l");
			return binSearcher(mid + 1, hi, searchVal);
		}

		
	}
	return -1;
}

const int Search::MAX_ARR_SIZE = 13;