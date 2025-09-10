#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->oneTimeLaunchButton, &QPushButton::clicked, this, &MainWindow::workOneTineLaunch);
    connect(ui->cycleWorkButton, &QPushButton::clicked, this, &MainWindow::cycleWork);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::workOneTineLaunch()
{
    receivingString();

    WorkFile workFile(m_stringMaskInputFiles, m_stringPathInputFiles, m_stringPathOutFiles, m_extens);
    workFile.searchInputFiles();
    workFile.readFile();
}

void MainWindow::cycleWork()
{
    while (true)
    {
        receivingString();

        WorkFile workFile(m_stringMaskInputFiles, m_stringPathInputFiles, m_stringPathOutFiles, m_extens);
        workFile.searchInputFiles();
        workFile.readFile();
    }
}

void MainWindow::receivingString()
{
    QString stringPathInputFiles = ui->pathInputFiles->text();
    QString stringMaskInputFiles = ui->maskInputFiles->text();
    QString stringPathOutFiles = ui->pathOutFiles->text();
    QString extens = ui->nameOutFiles->text();

    if (!stringPathInputFiles.isEmpty() && !stringMaskInputFiles.isEmpty() && !stringPathOutFiles.isEmpty() && !extens.isEmpty())
    {
        this->m_stringPathInputFiles = stringPathInputFiles.toStdString();
        this->m_stringMaskInputFiles = stringMaskInputFiles.toStdString();
        this->m_stringPathOutFiles = stringPathOutFiles.toStdString();
        this->m_extens = extens.toStdString();
    }
    else
    {
        qDebug() << "Error";
    }
}
