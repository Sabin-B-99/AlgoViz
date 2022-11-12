#pragma once
#include <Qwidget>
#include "ui_BFSView.h"
#include <QIntValidator>
#include "../BFS.h"
class BFSView : public QWidget
{
	Q_OBJECT
private:
	Ui::BFSViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	BFS* bfs;

public:
	BFSView(QWidget* parent = nullptr);
	~BFSView();

private slots:
	void on_bfsHomeBtn_clicked();
	void on_bfsInsertBtn_clicked();
	void on_bfsNewGraphBtn_clicked();
signals:
	void homeClicked();
};

