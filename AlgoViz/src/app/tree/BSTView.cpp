#include "BSTView.h"

BSTView::BSTView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	/*scene->setSceneRect(ui.bstAnimArea->rect());*/
	ui.bstAnimArea->setScene(scene);
	ui.bstAnimArea->setRenderHint(QPainter::Antialiasing);
	/*ui.bstAnimArea->setAlignment(Qt::AlignTop);*/ //for graphs
	ui.bstAnimArea->setAlignment(Qt::AlignVCenter); //for linearStructures
	intValidator = new QIntValidator();
	intValidator->setRange(-9999, 9999);
	regExp = new QRegularExpression();
	regExp->setPattern("^$");
	regExpValidator = new QRegularExpressionValidator(*regExp);
	ui.bstInsertLineEdit->setValidator(intValidator);

	/*bst = new BSTNode(scene);*/
	/*bfs = new BFS(scene, ui.bstPlainTextEdit);
	bfs->displayGraph();*/

	/*dfs = new DFS(scene, ui.bstPlainTextEdit);
	dfs->displayGraph();*/
	//dijkstraSP = new DijkstraSPF(scene, ui.bstPlainTextEdit);
	//dijkstraSP->displayGraph();

	//primMST = new PrimsMST(scene, ui.bstPlainTextEdit);
	//primMST->displayGraph();

	/*kruskalMST = new KruskalMST(scene, ui.bstPlainTextEdit);
	kruskalMST->displayGraph();*/

	//stack = new Stack(scene, ui.bstPlainTextEdit);
	//stack->displayStructure();

	//q = new Queue(scene, ui.bstPlainTextEdit);
	//q->displayStructure();

	srch = new Search(scene, ui.bstPlainTextEdit);
	srch->displayStructure();
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
	/*ui.bstPlainTextEdit->appendPlainText("Inset Button Pressed");*/
	/*dfs->run(insertVal.toInt());*/
	/*dijkstraSP->run(insertVal.toInt());*/
	/*primMST->run(insertVal.toInt());*/
	/*kruskalMST->run();*/


	/* Node* n = arrNode->getNodeList()->at(5);*/
	 
	 /*QPolygonF* arrowHead = l->getArrowHeadAtBottomOrRight();*/

	//QPropertyAnimation* insertionAnim = new QPropertyAnimation(arrowHead, "pos");
	//insertionAnim->setStartValue(QPointF(50,50));
	//insertionAnim->setEndValue(QPointF(150, 150));
	//insertionAnim->setDuration(2000);
	//insertionAnim->start();

	//stack->push(insertVal.toInt());
	/*q->enqueue(insertVal.toInt());*/
	
	srch->binSearch(insertVal.toInt());
}

void BSTView::on_bstDelBtn_clicked() {
	/*stack->pop();*/
	/*q->dequeue();*/
}


void BSTView::on_bstHomeBtn_clicked() {
	scene->clear();
	free(bst);
	bst = new BSTNode(scene);
	emit homeClicked();
}