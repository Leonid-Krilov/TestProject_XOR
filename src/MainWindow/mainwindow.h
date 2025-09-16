#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <string>
#include <vector>
#include <cstdint>
#include <QThread>
#include <optional>

#include "WorkFile.h"
#include "XOR.h"
#include "dialogconfirmationwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void checkBoxChanged();
  void workOneTineLaunch();
  void cycleWork();

private:
  bool receivingString();

private:
  int m_inputSpinTimer;
  bool m_checkBoxTimer, m_checkBoxDeleteFiles, m_checkBoxModificOutFiles;

  Ui::MainWindow *ui;
  QSpinBox *spinBoxTimer;
  QPushButton *oneTimeLaunchButton, *cycleWorkButton;
  QCheckBox *checkBoxTimer, *checkBoxDeleteFiles, *checkBoxModificOutFiles;
  QLineEdit *pathInputFiles, *maskInputFiles, *pathOutFiles, *binaryValue;

  std::string m_stringPathInputFiles, m_stringPathOutFiles;
  std::string m_stringMaskInputFiles, m_inputBinaryValue;
};
#endif // MAINWINDOW_H
