#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->spinBoxTimer->setEnabled(ui->checkBoxTimer->isChecked());
  connect(ui->checkBoxTimer, &QCheckBox::checkStateChanged, this, &MainWindow::checkBoxChanged);//Windows
  //connect(ui->checkBoxTimer, &QCheckBox::stateChanged, this, &MainWindow::checkBoxChanged);//Linux
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
  if (receivingString())
  {
    WorkFile workFile;
    workFile.searchInputFiles(m_stringPathInputFiles, m_stringMaskInputFiles);
    std::vector<unsigned long long> variable = workFile.readFile(m_checkBoxDeleteFiles);

    XOR resultXOR(variable, workFile.checkMoreСharacters(m_inputBinaryValue));
    std::vector<std::string> vectorResultXOR = resultXOR.functionXOR();

    workFile.saveFile(vectorResultXOR, m_stringPathOutFiles, m_checkBoxModificOutFiles);

    workFile.clear();
  }
}

void MainWindow::cycleWork()
{
  WorkFile workFile;

  do
  {
    if (receivingString())
    {
      workFile.searchInputFiles(m_stringPathInputFiles, m_stringMaskInputFiles);
      std::vector<unsigned long long> variable = workFile.readFile(m_checkBoxDeleteFiles);

      XOR resultXOR(variable, workFile.checkMoreСharacters(m_inputBinaryValue));
      std::vector<std::string> vectorResultXOR = resultXOR.functionXOR();
      workFile.saveFile(vectorResultXOR, m_stringPathOutFiles, m_checkBoxModificOutFiles);

      QThread::sleep(m_inputSpinTimer);
      DialogConfirmationWindow startDialog(this);
      int resultDialog = startDialog.exec();

      if(resultDialog == QDialog::Rejected)
        break;

      workFile.clear();
    }
  } while(true);
}

bool MainWindow::receivingString()
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

    return true;
  }
  else
    return false;
}
