#include "BSTNodeAnimator.h"

BSTNodeAnimator::BSTNodeAnimator()
	:root(nullptr), posAnim(nullptr)
{
}

BSTNodeAnimator::BSTNodeAnimator(BSTNode* root)
	:root(root)
{
	posAnim = new QPropertyAnimation(root->getUINode(), "pos");
}

void BSTNodeAnimator::animateNodeOutileColChange()
{
}

void BSTNodeAnimator::animateNodePos()
{
	posAnim->setStartValue(root->getUINode()->pos());
	posAnim->setEndValue(QPointF(200,200));
	posAnim->setDuration(5000);
	posAnim->start();
}



