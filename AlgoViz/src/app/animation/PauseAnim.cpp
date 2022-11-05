#include "PauseAnim.h"

void PauseAnim::showPauseAnimation(int msecs)
{
	QTimer* t = new QTimer();
	t->setSingleShot(true);
	t->start(msecs);//this is the time to sleep in this case 60 seconds 
	QEventLoop pause;
	connect(t, SIGNAL(timeout()), &pause, SLOT(quit()));
	pause.exec();//keeps the program responsive 
}
