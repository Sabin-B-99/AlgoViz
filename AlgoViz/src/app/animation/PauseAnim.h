#pragma once
#include <QTimer>
#include <QEventLoop>
#include <QPropertyAnimation>
#include <QPauseAnimation>
class PauseAnim : public QAbstractAnimation {
public:
	static void showPauseAnimation(int msecs);
};