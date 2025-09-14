#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->spinBoxTimer->setEnabled(ui->checkBoxTimer->isChecked());
  connect(ui->checkBoxTimer, &QCheckBox::stateChanged, this, &MainWindow::checkBoxChanged);

  connect(ui->oneTimeLaunchButton, &QPushButton::clicked, this, &MainWindow::workOneTineLaunch);
  connect(ui->cycleWorkButton, &QPushButton::clicked, this, &MainWindow::cycleWork);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::checkBoxChanged()
{
  ui->spinBoxTimer->setEnabled(ui->checkBoxTimer->isChecked());
}

void MainWindow::workOneTineLaunch()
{
  receivingString();

  WorkFile workFile;
  workFile.searchInputFiles(m_stringPathInputFiles, m_stringMaskInputFiles);
  std::vector<uint64_t> variable = workFile.readFile(m_checkBoxDeleteFiles);

  XOR resultXOR(variable, std::stoi(m_inputBinaryValue));
  workFile.saveFile(resultXOR.functionXOR(), m_stringPathOutFiles, m_checkBoxModificOutFiles);

  workFile.clear();
}

void MainWindow::cycleWork()
{
  WorkFile workFile;

  do
  {
    receivingString();

    workFile.searchInputFiles(m_stringPathInputFiles, m_stringMaskInputFiles);
    std::vector<uint64_t> variable = workFile.readFile(m_checkBoxDeleteFiles);

    XOR resultXOR(variable, std::stoi(m_inputBinaryValue));
    workFile.saveFile(resultXOR.functionXOR(), m_stringPathOutFiles, m_checkBoxModificOutFiles);

    QThread::sleep(m_inputSpinTimer);
    DialogConfirmationWindow startDialog(this);
    int resultDialog = startDialog.exec();

    if(resultDialog == QDialog::Rejected)
      break;
  } while(true);

  workFile.clear();
}

void MainWindow::receivingString()
{
  if (!ui->pathInputFiles->text().isEmpty() && !ui->maskInputFiles->text().isEmpty() && !ui->pathOutFiles->text().isEmpty() && !ui->binaryValue->text().isEmpty())
  {
    this->m_stringPathInputFiles = ui->pathInputFiles->text().toStdString();
    this->m_stringMaskInputFiles = ui->maskInputFiles->text().toStdString();
    this->m_stringPathOutFiles = ui->pathOutFiles->text().toStdString();
    this->m_inputBinaryValue = ui->binaryValue->text().toStdString();

    this->m_checkBoxDeleteFiles = ui->checkBoxDeleteFiles->isChecked();
    this->m_checkBoxModificOutFiles = ui->checkBoxModificOutFiles->isChecked();

    this->m_inputSpinTimer = ui->spinBoxTimer->text().toInt();
  }
  else
    qDebug() << "Error";
}
