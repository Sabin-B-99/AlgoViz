#include "Queue.h"

Queue::Queue() {

}

Queue::Queue(QGraphicsScene* graphicsScene, QPlainTextEdit* queueConsole) 
	:graphicsScene(graphicsScene), queueConsole(queueConsole), headIndex(0), tailIndex(0),
	enqueueLabel(nullptr), dequeueLabel(nullptr), enqueueVal(nullptr), dequeueVal(nullptr)
{
	linearBoxes = new ArrayNode(graphicsScene, MAX_QUEUE_SIZE, true, true, "HEAD", "TAIL");
	queueElements = new std::queue<int>;
	queueElementsInTextForm = new std::queue<QGraphicsTextItem*>;
}

Queue::~Queue()
{
}

void Queue::displayStructure()
{
	linearBoxes->displayGraphNodes();
}

void Queue::enqueue(int enqueud)
{
	if (tailIndex < MAX_QUEUE_SIZE) {
		queueElements->push(enqueud);
		displayEnqueueAnim(enqueud);
		tailIndex++;
		delete(enqueueLabel);
	}
	else {
		queueConsole->appendPlainText("Error: Overflow");
	}
}

void Queue::dequeue()
{
	if (queueElements->size() > 0) {
		displayDequeueAnim();
		headIndex++;
		PauseAnim::showPauseAnimation(3000);
		delete(dequeueLabel);
		delete(dequeueVal);
	}
	else {
		queueConsole->appendPlainText("Error: Underflow");
	}
	
}

void Queue::displayEnqueueAnim(int enqueued)
{
	enqueueVal = new QGraphicsTextItem(QString::number(enqueued));
	enqueueLabel = new QGraphicsTextItem("Enqueuing: ");

	int initialEnqLabelPosX = linearBoxes->getNodeList()->at(0)->pos().x();
	int initialEnqLabelPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	enqueueLabel->setPos(initialEnqLabelPosX, initialEnqLabelPosY);
	graphicsScene->addItem(enqueueLabel);

	int initialEnqValPosX = initialEnqLabelPosX + enqueueLabel->boundingRect().width() + 5;
	int initialEnqValPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	enqueueVal->setPos(initialEnqValPosX, initialEnqValPosY);
	graphicsScene->addItem(enqueueVal);

	Node* boxToPushValTo = linearBoxes->getNodeList()->at(tailIndex);
	int finalPushValPosX = boxToPushValTo->pos().x() + (boxToPushValTo->boundingRect().width() / 2) - 5;
	int finalPushValPosY = boxToPushValTo->pos().y() + (boxToPushValTo->boundingRect().height() / 2) - 8;

	QPropertyAnimation* pushAnim = new QPropertyAnimation(enqueueVal, "pos");
	pushAnim->setStartValue(enqueueVal->pos());
	pushAnim->setEndValue(QPointF(finalPushValPosX, finalPushValPosY));
	pushAnim->setDuration(1000);
	pushAnim->start();

	QParallelAnimationGroup* animGroup = linearBoxes->animateArrow("-t", 1);

	QSequentialAnimationGroup* sequentialAnimation = new QSequentialAnimationGroup;
	sequentialAnimation->addAnimation(pushAnim);
	sequentialAnimation->addAnimation(animGroup);
	sequentialAnimation->start();

	queueElementsInTextForm->push(enqueueVal);

	queueConsole->appendPlainText("Pushing: " + QString::number(enqueued));
	queueConsole->appendPlainText("*********");
	PauseAnim::showPauseAnimation(1000);

}

void Queue::displayDequeueAnim()
{
	dequeueVal = queueElementsInTextForm->front();
	int dequeuedValInt = queueElements->front();
	dequeueLabel = new QGraphicsTextItem("Dequeuing: ");

	int initialDeqLabelPosX = linearBoxes->getNodeList()->at(0)->pos().x();
	int initialDeqLabelPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;
	dequeueLabel->setPos(initialDeqLabelPosX, initialDeqLabelPosY);
	graphicsScene->addItem(dequeueLabel);

	int finalDeqValPosX = initialDeqLabelPosX + dequeueLabel->boundingRect().width() + 5;
	int finalDeqValPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	QPropertyAnimation* deqAnim = new QPropertyAnimation(dequeueVal, "pos");
	deqAnim->setStartValue(dequeueVal->pos());
	deqAnim->setEndValue(QPointF(finalDeqValPosX, finalDeqValPosY));
	deqAnim->setDuration(1000);
	deqAnim->start();

	QParallelAnimationGroup* animGroup = linearBoxes->animateArrow("-h", 1);

	QSequentialAnimationGroup* sequentialAnimation = new QSequentialAnimationGroup;
	sequentialAnimation->addAnimation(deqAnim);
	sequentialAnimation->addAnimation(animGroup);
	sequentialAnimation->start();

	queueElementsInTextForm->pop();
	queueElements->pop();

	queueConsole->appendPlainText("Dequeuing: " + QString::number(dequeuedValInt));
	queueConsole->appendPlainText("*********");
}

const int Queue::MAX_QUEUE_SIZE = 13;