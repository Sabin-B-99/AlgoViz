#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(QGraphicsScene* graphicsScene, QPlainTextEdit* stackConsole)
	:graphicsScene(graphicsScene), stackConsole(stackConsole), topIndex(0), pushLabel(nullptr), popLabel(nullptr), pushVal(nullptr), popVal(nullptr)
{
	linearBoxes = new ArrayNode(graphicsScene, MAX_STACK_SIZE, true, false, "TOP");
	stackElements = new std::stack<int>;
	stackElementsInTextForm = new std::stack<QGraphicsTextItem*>;
}

Stack::~Stack()
{
}

void Stack::displayStructure() {
	linearBoxes->displayGraphNodes();
}

void Stack::push(int valToPush) {
	if (topIndex < MAX_STACK_SIZE) {
		stackElements->push(valToPush);
		displayPushAnimation(valToPush);
		topIndex++;
		delete(pushLabel);
	}
	else {
		stackConsole->appendPlainText("Error: Stack Overflow");
	}
}

void Stack::pop() {
	if (topIndex > 0) {
		displayPopAnimation();
		topIndex--;
		PauseAnim::showPauseAnimation(3000);
		delete(popLabel);
		delete(popVal);
	}
	else {
		stackConsole->appendPlainText("Error: Stack Underflow");
	}
	
}

void Stack::displayPushAnimation(int valPushed) {
	pushVal = new QGraphicsTextItem(QString::number(valPushed));
	pushLabel = new QGraphicsTextItem("Pushing: ");

	int initialPushLabelPosX = linearBoxes->getNodeList()->at(0)->pos().x();
	int initialPushLabelPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	pushLabel->setPos(initialPushLabelPosX, initialPushLabelPosY);
	graphicsScene->addItem(pushLabel);

	int initialPushValPosX = initialPushLabelPosX + pushLabel->boundingRect().width() + 5;
	int initialPushValPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	pushVal->setPos(initialPushValPosX, initialPushValPosY);
	graphicsScene->addItem(pushVal);
	
	PauseAnim::showPauseAnimation(1000);

	Node* boxToPushValTo = linearBoxes->getNodeList()->at(topIndex);
	int finalPushValPosX = boxToPushValTo->pos().x() + (boxToPushValTo->boundingRect().width() / 2) - 5;
	int finalPushValPosY = boxToPushValTo->pos().y() + (boxToPushValTo->boundingRect().height() / 2) - 8;
	
	QPropertyAnimation* pushAnim = new QPropertyAnimation(pushVal, "pos");
	pushAnim->setStartValue(pushVal->pos());
	pushAnim->setEndValue(QPointF(finalPushValPosX, finalPushValPosY));
	pushAnim->setDuration(1000);
	pushAnim->start();

	QParallelAnimationGroup* animGroup = linearBoxes->animateArrow("-h", 1);

	QSequentialAnimationGroup* sequentialAnimation = new QSequentialAnimationGroup;
	sequentialAnimation->addAnimation(pushAnim);
	sequentialAnimation->addAnimation(animGroup);
	sequentialAnimation->start();

	stackElementsInTextForm->push(pushVal);

	stackConsole->appendPlainText("Pushing: " + QString::number(valPushed));
	stackConsole->appendPlainText("*********");
}

void Stack::displayPopAnimation() {
	popVal = stackElementsInTextForm->top();
	int popValInt = stackElements->top();
	popLabel = new QGraphicsTextItem("Poping: ");

	int initialPopLabelPosX = linearBoxes->getNodeList()->at(0)->pos().x();
	int initialPopLabelPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;
	popLabel->setPos(initialPopLabelPosX, initialPopLabelPosY);
	graphicsScene->addItem(popLabel);

	int finalPopValPosX = initialPopLabelPosX + popLabel->boundingRect().width() + 5;
	int finalPopValPosY = linearBoxes->getNodeList()->at(0)->pos().y() - 150;

	QPropertyAnimation* popAnim = new QPropertyAnimation(popVal, "pos");
	popAnim->setStartValue(popVal->pos());
	popAnim->setEndValue(QPointF(finalPopValPosX, finalPopValPosY));
	popAnim->setDuration(1000);
	popAnim->start();

	QParallelAnimationGroup* animGroup = linearBoxes->animateArrow("-h", -1);

	QSequentialAnimationGroup* sequentialAnimation = new QSequentialAnimationGroup;
	sequentialAnimation->addAnimation(popAnim);
	sequentialAnimation->addAnimation(animGroup);
	sequentialAnimation->start();

	stackElementsInTextForm->pop();
	stackElements->pop();

	stackConsole->appendPlainText("Poping: " + QString::number(popValInt));
	stackConsole->appendPlainText("*********");

}
const int Stack::MAX_STACK_SIZE = 13;