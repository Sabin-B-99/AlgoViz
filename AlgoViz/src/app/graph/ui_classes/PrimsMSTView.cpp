#include "PrimsMSTView.h"

PrimsMSTView::PrimsMSTView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.primAnimArea->setScene(scene);
	ui.primAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.primAnimArea->setAlignment(Qt::AlignTop);


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
	primMST->run();
}

void PrimsMSTView::on_primNewGraphBtn_clicked()
{
}
