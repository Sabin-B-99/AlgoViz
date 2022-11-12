#pragma once
#include <Qwidget>
#include "ui_DijkstraView.h"
#include <QIntValidator>
#include "../DijkstraSPF.h"
class DijkstraSPFView : public QWidget
{
	Q_OBJECT
private:
	Ui::DijkstraViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	DijkstraSPF* dijkstraSPF;
public:
	DijkstraSPFView(QWidget* parent = nullptr);
	~DijkstraSPFView();

private slots:
	void on_dijkstraHomeBtn_clicked();
	void on_dijkstraInsertBtn_clicked();
	void on_dijkstraNewGraphBtn_clicked();
signals:
	void homeClicked();
};

