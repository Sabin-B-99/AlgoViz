#include "BSTView.h"

BSTView::BSTView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	/*scene->setSceneRect(ui.bstAnimArea->rect());*/
	ui.bstAnimArea->setScene(scene);
	ui.bstAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.bstAnimArea->setAlignment(Qt::AlignTop);
	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);

	bst = new BSTNode(scene);
	dfs = new DFS(scene, ui.bstPlainTextEdit);
	dfs->displayGraph();
}

BSTView::~BSTView()
{
}

void BSTView::on_bstInsertBtn_clicked()
{
	QString insertVal = ui.bstInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	dfs->run(insertVal.toInt());
}

void BSTView::on_bstDelBtn_clicked() {
}


void BSTView::on_bstHomeBtn_clicked() {
	scene->clear();
	free(bst);
	bst = new BSTNode(scene);
	emit homeClicked();
}