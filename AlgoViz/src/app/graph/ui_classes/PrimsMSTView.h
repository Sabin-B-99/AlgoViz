#pragma once
#include <Qwidget>
#include "ui_PrimView.h"
#include <QIntValidator>
#include "../PrimsMST.h"
class PrimsMSTView : public QWidget
{
	Q_OBJECT
private:
	Ui::PrimViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	PrimsMST* primMST;

public:
	PrimsMSTView(QWidget* parent = nullptr);
	~PrimsMSTView();

private slots:
	void on_primHomeBtn_clicked();
	void on_primInsertBtn_clicked();
	void on_primNewGraphBtn_clicked();
signals:
	void homeClicked();
};

