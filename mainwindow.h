#ifndef SOFTTOP_H
#define SOFTTOP_H

#include <QMainWindow>
#include <QMessageBox>
#include "keydata.h"

namespace Ui {
class MainWindow;
}

class UserAssistant;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    UserAssistant *m_userAssistant;

private slots:
    void onUpdateTable();
    void onAboutTriggered();
};

#endif // SOFTTOP_H
