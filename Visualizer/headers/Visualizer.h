#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qTextEdit.h>

#include"Triangulation.h"

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWidget *parent = nullptr);
    ~Visualizer();

private:
    void SetUpUI();
private slots:
    void onLoadFileClick();
    void onTranslateClick();


private:
    Triangulation triangulation;
    QPushButton* LoadFile;
    QPushButton* TranslateFile;
    QTextEdit* LoadEdit;
    QTextEdit* TranslateEdit;

};
