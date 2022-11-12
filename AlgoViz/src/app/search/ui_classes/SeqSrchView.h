#pragma once
#include <Qwidget>
#include "ui_SeqSrchView.h"
#include <QIntValidator>
#include "../Search.h"
class SeqSrchView : public QWidget
{
	Q_OBJECT
private:
	Ui::SeqSrchViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	Search* srch;

public:
	SeqSrchView(QWidget* parent = nullptr);
	~SeqSrchView();

private slots:
	void on_seqSrchHomeBtn_clicked();
	void on_seqSrchSrchBtn_clicked();
	void on_seqSrchNewValBtn_clicked();
signals:
	void homeClicked();
};

