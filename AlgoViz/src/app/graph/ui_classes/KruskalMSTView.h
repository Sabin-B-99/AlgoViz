#pragma once
#include <Qwidget>
#include "ui_KruskalView.h"
#include "../KruskalMST.h"
class KruskalMSTView : public QWidget
{
	Q_OBJECT
private:
	Ui::KruskalViewClass ui;
	QGraphicsScene* scene;
	KruskalMST* kruskalMST;

public:
	KruskalMSTView(QWidget* parent = nullptr);
	~KruskalMSTView();

private slots:
	void on_kruskalHomeBtn_clicked();
	void on_kruskalRunBtn_clicked();
	void on_kruskalNewGraphBtn_clicked();
signals:
	void homeClicked();
};

