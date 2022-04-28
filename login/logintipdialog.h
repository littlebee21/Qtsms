#ifndef LOGINTIPDIALOG_H
#define LOGINTIPDIALOG_H

#include <QDialog>

namespace Ui {
class LoginTipDialog;
}

class LoginTipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginTipDialog(QWidget *parent = nullptr);
    ~LoginTipDialog();

public slots:
    void showLoginResult(int result);
private:
    Ui::LoginTipDialog *ui;
};

#endif // LOGINTIPDIALOG_H
