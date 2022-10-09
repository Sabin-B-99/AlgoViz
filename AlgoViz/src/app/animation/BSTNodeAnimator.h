#pragma once
#include <QPropertyAnimation>
#include "../tree/BSTNode.h"
class BSTNodeAnimator 
{
private:
	BSTNode* root;
	QPropertyAnimation* posAnim;

public:
	BSTNodeAnimator();
	BSTNodeAnimator(BSTNode* root);

	void animateNodeOutileColChange();
	void animateNodePos();
};

