#include "dialogconfirmationwindow.h"
#include "ui_dialogconfirmationwindow.h"

DialogConfirmationWindow::DialogConfirmationWindow(QWidget *parent) : QDialog(parent), ui(new Ui::DialogConfirmationWindow)
{
  ui->setupUi(this);

  connect(ui->pushButtonRestart, &QPushButton::clicked, this, &DialogConfirmationWindow::restartProgram);
  connect(ui->pushButtonExit, &QPushButton::clicked, this, &DialogConfirmationWindow::exitFunctionCycle);
}

DialogConfirmationWindow::~DialogConfirmationWindow()
{
    delete ui;
}

void DialogConfirmationWindow::restartProgram()
{
  accept();
}

void DialogConfirmationWindow::exitFunctionCycle()
{
  reject();
}
