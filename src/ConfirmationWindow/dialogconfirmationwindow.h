#ifndef DIALOGCONFIRMATIONWINDOW_H
#define DIALOGCONFIRMATIONWINDOW_H

#include <QDialog>
#include <QPushButton>
namespace Ui
{
class DialogConfirmationWindow;
}

class DialogConfirmationWindow : public QDialog
{
  Q_OBJECT

public:
  explicit DialogConfirmationWindow(QWidget *parent = nullptr);
  ~DialogConfirmationWindow();

private slots:
  void restartProgram();
  void exitFunctionCycle();

private:
  Ui::DialogConfirmationWindow *ui;
  QPushButton *pushButtonRestart, *pushButtonExit;

};

#endif // DIALOGCONFIRMATIONWINDOW_H
