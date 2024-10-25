#include "Visualizer.h"
#include "STLReader.h"
#include "StlWriter.h"
#include <QFileDialog>
#include <QGridLayout>


Visualizer::Visualizer(QWidget *parent)
    : QMainWindow(parent)
{
    SetUpUI();
    connect(LoadFile, &QPushButton::clicked , this , &Visualizer::onLoadFileClick);
    connect(TranslateFile, &QPushButton::clicked , this , &Visualizer::onTranslateClick);
}

Visualizer::~Visualizer()
{
}

void Visualizer::SetUpUI()
{
    LoadFile = new QPushButton("Load File", this);
    TranslateFile = new QPushButton("Translate", this);
    LoadEdit = new QTextEdit(this);
    TranslateEdit = new QTextEdit(this);
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(LoadFile, 0, 0);
    layout->addWidget(TranslateFile, 1, 0);
    layout->addWidget(LoadEdit, 0, 1);
    layout->addWidget(TranslateEdit, 1, 1);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
}

void  Visualizer::onLoadFileClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open STL File"), "", tr("STL Files (*.stl)"));

    if (!fileName.isEmpty())
    {
        LoadEdit->clear();

        StlReader reader;
        reader.read(fileName.toStdString(), triangulation);

        LoadEdit->setText("File loaded successfully from - " + fileName);
    }
}

void Visualizer::onTranslateClick()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Data File"), "/data", tr("Data Files (*.dat)"));

    if (!fileName.isEmpty())
    {
        TranslateEdit->clear();

        StlWriter writer;
        writer.Write(fileName.toStdString(), triangulation);

        TranslateEdit->setText("File saved successfully to - " + fileName);

    }
}
