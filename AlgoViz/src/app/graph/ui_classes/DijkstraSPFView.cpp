#include "DijkstraSPFView.h"

DijkstraSPFView::DijkstraSPFView(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.dijkstraAnimArea->setScene(scene);
	ui.dijkstraAnimArea->setRenderHint(QPainter::Antialiasing);
	ui.dijkstraAnimArea->setAlignment(Qt::AlignTop);
	ui.dijkstraInsertLineEdit->setPlaceholderText("Starting Node");

	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.dijkstraInsertLineEdit->setValidator(intValidator);

	dijkstraSPF = new DijkstraSPF(scene, ui.dijkstraPlainTextEdit);
	dijkstraSPF->displayGraph();
}

DijkstraSPFView::~DijkstraSPFView()
{
}
void DijkstraSPFView::on_dijkstraHomeBtn_clicked() {
	scene->clear();
	delete(dijkstraSPF);
	dijkstraSPF = new DijkstraSPF(scene, ui.dijkstraPlainTextEdit);
	dijkstraSPF->displayGraph();
	emit homeClicked();
}

void DijkstraSPFView::on_dijkstraInsertBtn_clicked()
{
	QString insertVal = ui.dijkstraInsertLineEdit->text();
	int pos = 0;
	if (regExpValidator->validate(insertVal, pos) == QValidator::State::Acceptable) {
		insertVal = "0";
	}
	dijkstraSPF->run(insertVal.toInt());
}

void DijkstraSPFView::on_dijkstraNewGraphBtn_clicked()
{
}
