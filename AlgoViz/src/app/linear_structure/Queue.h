#pragma once
#include "ArrayNode.h"
#include <QGraphicsScene>
#include <QPlainTextEdit>
#include <queue>
#include "../animation/PauseAnim.h"
class Queue
{
private:
	ArrayNode* linearBoxes;
	QGraphicsScene* graphicsScene;
	QPlainTextEdit* queueConsole;
	int32_t headIndex;
	int32_t tailIndex;
	std::queue<int>* queueElements;
	std::queue<QGraphicsTextItem*>* queueElementsInTextForm;
	QGraphicsTextItem* enqueueLabel;
	QGraphicsTextItem* dequeueLabel;
	QGraphicsTextItem* enqueueVal;
	QGraphicsTextItem* dequeueVal;

	static const int MAX_QUEUE_SIZE;
public:
	Queue();
	Queue(QGraphicsScene* graphicsScene, QPlainTextEdit* queueConsole);
	~Queue();

	void displayStructure();
	void enqueue(int enqueueVal);
	void dequeue();

private:
	void displayEnqueueAnim(int enqueud);
	void displayDequeueAnim();

};