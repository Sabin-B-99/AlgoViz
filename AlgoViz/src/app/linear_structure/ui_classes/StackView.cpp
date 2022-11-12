#include "StackView.h"

StackView::StackView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.stackAnimArea->setScene(scene);
	ui.stackAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.stackAnimArea->setAlignment(Qt::AlignVCenter);
	ui.stackInsertLineEdit->setPlaceholderText("Push Value");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.stackInsertLineEdit->setValidator(intValidator);

	stack = new Stack(scene, ui.stackPlainTextEdit);
	stack->displayStructure();
}

StackView::~StackView()
{
}

void::StackView::on_stackHomeBtn_clicked() {
	scene->clear();
	delete(stack);
	stack = new Stack(scene, ui.stackPlainTextEdit);
	stack->displayStructure();
	emit homeClicked();
}

void StackView::on_stackPushBtn_clicked()
{
	QString insertVal = ui.stackInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	stack->push(insertVal.toInt());
}

void StackView::on_stackPopBtn_clicked()
{
	stack->pop();
}
