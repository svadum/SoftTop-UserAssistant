#ifndef SOFTTOP_H
#define SOFTTOP_H

#include <QMainWindow>
#include <QMessageBox>
#include "toptenlist.h"
#include "keydata.h"

namespace Ui {
class SoftTop;
}

class SoftTop : public QMainWindow
{
    Q_OBJECT

public:
    explicit SoftTop(QWidget *parent = 0);
    ~SoftTop();

private slots:
    void on_action_Close_triggered();

    void on_actionAbout_triggered();

    void on_viewAllcheckBox_clicked();

    void on_updateButton_clicked();

    void on_byDay_clicked();

    void on_byHour_clicked();

    void on_byAllTime_clicked();

    void on_actionUpdate_triggered();

    void on_actionHour_triggered();

    void on_actionDay_triggered();

    void on_actionAll_Time_triggered();

private:
    // members
    Ui::SoftTop *ui;
    QMessageBox *aboutBox;
    TopTenList *topList;
    QVector<KeyData> topKeyVector;

    // service
    void setTopTable(int rowCount);
    TopTenList::SortType getCurrentSortType();
};

#endif // SOFTTOP_H
