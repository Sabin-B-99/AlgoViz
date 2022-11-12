#include "BFSView.h"

BFSView::BFSView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.bfsAnimArea->setScene(scene);
	ui.bfsAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.bfsAnimArea->setAlignment(Qt::AlignTop);
	ui.bfsInsertLineEdit->setPlaceholderText("Starting Node");

	intValidator = new QIntValidator();	
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bfsInsertLineEdit->setValidator(intValidator);

	bfs = new BFS(scene, ui.bfsPlainTextEdit);
	bfs->displayGraph();
}

BFSView::~BFSView()
{
}

void BFSView::on_bfsHomeBtn_clicked() {
	scene->clear();
	delete(bfs);
	bfs = new BFS(scene, ui.bfsPlainTextEdit);
	bfs->displayGraph();
	emit homeClicked();
}

void BFSView::on_bfsInsertBtn_clicked() {
	QString insertVal = ui.bfsInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	bfs->run(insertVal.toInt());
}

void BFSView::on_bfsNewGraphBtn_clicked()
{
}

