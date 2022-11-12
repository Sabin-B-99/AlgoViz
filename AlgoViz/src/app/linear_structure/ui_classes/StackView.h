#pragma once
#include <Qwidget>
#include "ui_StackView.h"
#include <QIntValidator>
#include "../Stack.h"
class StackView : public QWidget
{
	Q_OBJECT
private:
	Ui::StackViewClass ui;
	QGraphicsScene* scene;
	QIntValidator* intValidator;
	QRegularExpression* regExp;
	QRegularExpressionValidator* regExpValidator;
	Stack* stack;

public:
	StackView(QWidget* parent = nullptr);
	~StackView();

private slots:
	void on_stackHomeBtn_clicked();
	void on_stackPushBtn_clicked();
	void on_stackPopBtn_clicked();
signals:
	void homeClicked();
};

