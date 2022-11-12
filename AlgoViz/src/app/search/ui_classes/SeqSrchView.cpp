#include "SeqSrchView.h"

SeqSrchView::SeqSrchView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.seqSrchAnimArea->setScene(scene);
	ui.seqSrchAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.seqSrchAnimArea->setAlignment(Qt::AlignVCenter);
	ui.seqSrchInsertLineEdit->setPlaceholderText("Search Value");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.seqSrchInsertLineEdit->setValidator(intValidator);

	srch = new Search(scene, ui.seqSrchPlainTextEdit);
	srch->displayStructure();
}

SeqSrchView::~SeqSrchView()
{
}

void SeqSrchView::on_seqSrchHomeBtn_clicked() {
	scene->clear();
	delete(srch);
	srch = new Search(scene, ui.seqSrchPlainTextEdit);
	srch->displayStructure();
	emit homeClicked();
}

void SeqSrchView::on_seqSrchSrchBtn_clicked()
{
	QString insertVal = ui.seqSrchInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	srch->linSearch(insertVal.toInt());
}

void SeqSrchView::on_seqSrchNewValBtn_clicked()
{
}
