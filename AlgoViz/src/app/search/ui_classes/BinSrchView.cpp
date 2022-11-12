#include "BinSrchView.h"

BinSrchView::BinSrchView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.binSrchAnimArea->setScene(scene);
	ui.binSrchAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.binSrchAnimArea->setAlignment(Qt::AlignVCenter);
	ui.binSrchInsertLineEdit->setPlaceholderText("Search Value");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.binSrchInsertLineEdit->setValidator(intValidator);

	srch = new Search(scene, ui.binSrchPlainTextEdit);
	srch->displayStructure();
}

BinSrchView::~BinSrchView()
{
}

void BinSrchView::on_binSrchHomeBtn_clicked() {
	scene->clear();
	delete(srch);
	srch = new Search(scene, ui.binSrchPlainTextEdit);
	srch->displayStructure();
	emit homeClicked();
}

void BinSrchView::on_binSrchSrchBtn_clicked()
{
	QString insertVal = ui.binSrchInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	srch->binSearch(insertVal.toInt());
}

void BinSrchView::on_binSrchNewValBtn_clicked()
{
}
