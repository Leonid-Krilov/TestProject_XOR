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

#include "WorkFile.h"
#include "XOR.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void workOneTineLaunch();
    void cycleWork();

private:
    void receivingString();

private:
    Ui::MainWindow *ui;
    QSpinBox *spinBoxTimer;
    QPushButton *oneTimeLaunchButton, *cycleWorkButton;
    QCheckBox *checkBoxTimer, *checkBoxDeleteFiles, *checkBoxModificOutFiles;
    QLineEdit *pathInputFiles, *maskInputFiles, *pathOutFiles, *binaryValue;

    std::string m_stringPathInputFiles, m_stringPathOutFiles;
    std::string m_stringMaskInputFiles, m_inputBinaryValue;

    std::vector<uint64_t> variableInput;
    std::vector<uint64_t> saveVariable;
};
#endif // MAINWINDOW_H
