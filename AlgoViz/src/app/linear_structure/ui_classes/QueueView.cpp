#include "QueueView.h"

QueueView::QueueView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.queueAnimArea->setScene(scene);
	ui.queueAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.queueAnimArea->setAlignment(Qt::AlignVCenter);
	ui.queueInsertLineEdit->setPlaceholderText("Push Value");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.queueInsertLineEdit->setValidator(intValidator);

	q = new Queue(scene, ui.queuePlainTextEdit);
	q->displayStructure();
}

QueueView::~QueueView()
{
}

void QueueView::on_queueHomeBtn_clicked() {
	scene->clear();
	delete(q);
	q = new Queue(scene, ui.queuePlainTextEdit);
	q->displayStructure();
	emit homeClicked();
}

void QueueView::on_queueEnqBtn_clicked()
{
	QString insertVal = ui.queueInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	q->enqueue(insertVal.toInt());
}

void QueueView::on_queueDeqBtn_clicked()
{
	q->dequeue();
}
