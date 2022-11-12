#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AlgoViz.h"
#include "tree/ui_classes/BSTView.h"
#include "graph/ui_classes/BFSView.h"
#include "graph/ui_classes/DFSView.h"
#include "graph/ui_classes/DijkstraSPFView.h"
#include "graph/ui_classes/KruskalMSTView.h"
#include "graph/ui_classes/PrimsMSTView.h"
#include "linear_structure/ui_classes/StackView.h"
#include "linear_structure/ui_classes/QueueView.h"
#include "search/ui_classes/SeqSrchView.h"
#include "search/ui_classes/BinSrchView.h"

class AlgoViz : public QMainWindow
{
    Q_OBJECT

public:
    AlgoViz(QWidget *parent = nullptr);
    ~AlgoViz();

private slots:
    void on_bstButton_clicked();
    void on_bfsButton_clicked();
    void on_dfsButton_clicked();
    void on_dijkstraButton_clicked();
    void on_primButton_clicked();
    void on_kruskalButton_clicked();
    void on_seqSrchButton_clicked();
    void on_binSrchButton_clicked();
    void on_stackButton_clicked();
    void on_queueButton_clicked();
    void moveHome();

private:
    Ui::AlgoVizClass ui;
    BSTView bst;

    BFSView bfs;
    DFSView dfs;
    DijkstraSPFView dijSPF;
    PrimsMSTView primMST;
    KruskalMSTView kruskalMST;
    StackView stack;
    QueueView q;
    SeqSrchView seqSrch;
    BinSrchView binSrch;
};
