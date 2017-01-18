#include <QTableWidget>
#include <QCalendarWidget>
#include "softtop.h"
#include "ui_softtop.h"

static const int kRowDefaultSize = 10;

SoftTop::SoftTop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SoftTop),
    aboutBox(new QMessageBox),
    topList(new TopTenList)
{
    ui->setupUi(this);

    // init. components
    topKeyVector = topList->getTopListVector();

    aboutBox->setText("Created by Senkiv Vadym");

    // set first day of week and
    // current DateTime for dtEdit
    ui->dateEdit->setDate(QDate::currentDate());


    // set columns and sizes
    ui->topTable->setColumnCount(4);

    ui->topTable->setColumnWidth(0, 250);
    ui->topTable->setColumnWidth(1, 170);
    ui->topTable->setColumnWidth(2, 70);
    ui->topTable->setColumnWidth(3, 80);

    ui->topTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->topTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->topTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->topTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->topTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->topTable->sortByColumn(1, Qt::AscendingOrder);
    ui->topTable->sortByColumn(2, Qt::AscendingOrder);
    ui->topTable->sortByColumn(3, Qt::AscendingOrder);

    // set columns labels(names)
    ui->topTable->setHorizontalHeaderLabels(
                QStringList() << "Name" << "Last Run Date" << "Run count" << "Focus time");

    // ouput top
    setTopTable(kRowDefaultSize);
}

SoftTop::~SoftTop()
{
    delete ui;
    delete aboutBox;
    delete topList;
}

void SoftTop::on_action_Close_triggered()
{
    this->close();
}

void SoftTop::on_actionAbout_triggered()
{
    aboutBox->show();
    aboutBox->exec();
}

void SoftTop::on_viewAllcheckBox_clicked()
{
    if(ui->viewAllcheckBox->isChecked())
        setTopTable(topKeyVector.size());
    else
        setTopTable(kRowDefaultSize);
}

void SoftTop::setTopTable(int rowCount)
{
    ui->topTable->setRowCount(rowCount);

    for(int i = 0, j = 0; i < rowCount; i++)
    {
        QTableWidgetItem *nameItm = new QTableWidgetItem();
        QTableWidgetItem *dateItm = new QTableWidgetItem();
        QTableWidgetItem *countItm = new QTableWidgetItem();
        QTableWidgetItem *focusTimeItm = new QTableWidgetItem();

        dateItm->setTextAlignment(Qt::AlignHCenter);
        countItm->setTextAlignment(Qt::AlignHCenter);
        focusTimeItm->setTextAlignment(Qt::AlignHCenter);

        nameItm->setText(topKeyVector.at(i).getName());
        dateItm->setText(topKeyVector.at(i).getLastDateTime().toString("yyyy/MM/dd hh:mm:ss"));
        countItm->setText(QString::number(topKeyVector.at(i).getRunCount()));
        focusTimeItm->setText(QString::number(topKeyVector.at(i).getFocusTime()));

        ui->topTable->setItem(i, j, nameItm);
        ui->topTable->setItem(i, j + 1, dateItm);
        ui->topTable->setItem(i, j + 2, countItm);
        ui->topTable->setItem(i, j + 3, focusTimeItm);
    }
}

TopTenList::SortType SoftTop::getCurrentSortType()
{
    if(ui->byHour->isChecked())
        return TopTenList::ByHour;
    else if(ui->byDay->isChecked())
        return TopTenList::ByDays;

    return TopTenList::ByAllTime;
}

void SoftTop::on_updateButton_clicked()
{
    topList->updateList(getCurrentSortType());
    topKeyVector = topList->getTopListVector();

    on_viewAllcheckBox_clicked();
}

void SoftTop::on_byHour_clicked()
{
    on_updateButton_clicked();
}

void SoftTop::on_byDay_clicked()
{
    on_updateButton_clicked();
}
void SoftTop::on_byAllTime_clicked()
{
    on_updateButton_clicked();
}

void SoftTop::on_actionUpdate_triggered()
{
    on_updateButton_clicked();
}

void SoftTop::on_actionHour_triggered()
{
    on_byHour_clicked();
}

void SoftTop::on_actionDay_triggered()
{
    on_byDay_clicked();
}

void SoftTop::on_actionAll_Time_triggered()
{
    on_byAllTime_clicked();
}
