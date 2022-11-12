#pragma once
#include <Qwidget>
#include "ui_BinSrchView.h"
#include <QIntValidator>
#include "../Search.h"
class BinSrchView : public QWidget
{
	Q_OBJECT
private:
	Ui::BinSrchViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	Search* srch;

public:
	BinSrchView(QWidget* parent = nullptr);
	~BinSrchView();

private slots:
	void on_binSrchHomeBtn_clicked();
	void on_binSrchSrchBtn_clicked();
	void on_binSrchNewValBtn_clicked();
signals:
	void homeClicked();
};

