#include "KruskalMSTView.h"

KruskalMSTView::KruskalMSTView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.kruskalAnimArea->setScene(scene);
	ui.kruskalAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.kruskalAnimArea->setAlignment(Qt::AlignTop);
	

	kruskalMST = new KruskalMST(scene, ui.kruskalPlainTextEdit);
	kruskalMST->displayGraph();
}

KruskalMSTView::~KruskalMSTView()
{
}

void KruskalMSTView::on_kruskalHomeBtn_clicked() {
	scene->clear();
	delete(kruskalMST);
	kruskalMST = new KruskalMST(scene, ui.kruskalPlainTextEdit);
	kruskalMST->displayGraph();
	emit homeClicked();
}

void KruskalMSTView::on_kruskalRunBtn_clicked()
{
	kruskalMST->run();
}

void KruskalMSTView::on_kruskalNewGraphBtn_clicked()
{
}
