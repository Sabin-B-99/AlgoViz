#pragma once
#include "ArrayNode.h"
#include <QGraphicsScene>
#include <QPlainTextEdit>
#include <stack>
#include "../animation/PauseAnim.h"
class Stack
{
private:
	ArrayNode* linearBoxes;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* stackConsole;
	int32_t topIndex;
	std::stack<int>* stackElements;
	std::stack<QGraphicsTextItem*>* stackElementsInTextForm;
	QGraphicsTextItem* pushLabel;
	QGraphicsTextItem* popLabel;
	QGraphicsTextItem* pushVal;
	QGraphicsTextItem* popVal;

	static const int MAX_STACK_SIZE;

public:
	Stack();
	Stack(QGraphicsScene* graphicsScene, QPlainTextEdit* stackConsole);
	~Stack();

	void displayStructure();
	void push(int valToPush);
	void pop();

private:
	void displayPushAnimation(int valPushed);
	void displayPopAnimation();
};

