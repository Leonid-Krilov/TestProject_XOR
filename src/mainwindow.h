#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <string>

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
    QLineEdit *pathInputFiles, *maskInputFiles, *pathOutFiles, *nameOutFiles;

    std::string m_stringPathInputFiles, m_stringPathOutFiles;
    std::string m_stringMaskInputFiles, m_stringNameOutFiles;

};
#endif // MAINWINDOW_H
