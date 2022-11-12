#pragma once
#include <Qwidget>
#include "ui_QueueView.h"
#include <QIntValidator>
#include "../Queue.h"
class QueueView : public QWidget
{
	Q_OBJECT
private:
	Ui::QueueViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	Queue* q;

public:
	QueueView(QWidget* parent = nullptr);
	~QueueView();

private slots:
	void on_queueHomeBtn_clicked();
	void on_queueEnqBtn_clicked();
	void on_queueDeqBtn_clicked();
signals:
	void homeClicked();
};

