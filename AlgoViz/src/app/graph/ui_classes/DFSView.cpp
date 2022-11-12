#include "DFSView.h"

DFSView::DFSView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.dfsAnimArea->setScene(scene);
	ui.dfsAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.dfsAnimArea->setAlignment(Qt::AlignTop);
	ui.dfsInsertLineEdit->setPlaceholderText("Starting Node");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.dfsInsertLineEdit->setValidator(intValidator);

	dfs = new DFS(scene, ui.dfsPlainTextEdit);
	dfs->displayGraph();
}

DFSView::~DFSView()
{
}

void DFSView::on_dfsHomeBtn_clicked()
{
	scene->clear();
	delete(dfs);
	dfs = new DFS(scene, ui.dfsPlainTextEdit);
	dfs->displayGraph();
	emit homeClicked();
}

void DFSView::on_dfsInsertBtn_clicked()
{
	QString insertVal = ui.dfsInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	dfs->run(insertVal.toInt());
}

void DFSView::on_dfsNewGraphBtn_clicked()
{
}
