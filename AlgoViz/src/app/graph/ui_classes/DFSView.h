#pragma once
#include <Qwidget>
#include "ui_DFSView.h"
#include <QIntValidator>
#include "../DFS.h"
class DFSView : public QWidget
{
	Q_OBJECT
private:
	Ui::DFSViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	DFS* dfs;
public:
	DFSView(QWidget* parent = nullptr);
	~DFSView();

private slots:
	void on_dfsHomeBtn_clicked();
	void on_dfsInsertBtn_clicked();
	void on_dfsNewGraphBtn_clicked();
signals:
	void homeClicked();
};

