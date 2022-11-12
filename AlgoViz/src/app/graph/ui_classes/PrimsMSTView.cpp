#include "PrimsMSTView.h"

PrimsMSTView::PrimsMSTView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.primAnimArea->setScene(scene);
	ui.primAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.primAnimArea->setAlignment(Qt::AlignTop);
	ui.primInsertLineEdit->setPlaceholderText("Starting Node");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.primInsertLineEdit->setValidator(intValidator);

	primMST = new PrimsMST(scene, ui.primPlainTextEdit);
	primMST->displayGraph();
}

PrimsMSTView::~PrimsMSTView()
{
}

void PrimsMSTView::on_primHomeBtn_clicked() {
	scene->clear();
	delete(primMST);
	primMST = new PrimsMST(scene, ui.primPlainTextEdit);
	primMST->displayGraph();
	emit homeClicked();
}

void PrimsMSTView::on_primInsertBtn_clicked()
{
	QString insertVal = ui.primInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	primMST->run(insertVal.toInt());
}

void PrimsMSTView::on_primNewGraphBtn_clicked()
{
}
