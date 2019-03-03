#include <QTableWidget>
#include <QCalendarWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userassistant.h"

#define DEFAULT_ROW_COUNT 10

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_userAssistant(new UserAssistant)
{
    ui->setupUi(this);

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

    // set columns labels(names)
    ui->topTable->setHorizontalHeaderLabels({tr("Name"), tr("Last Run Date"), tr("Run count"), tr("Focus time")});
    onUpdateTable();

    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateTable);
    connect(ui->viewAllcheckBox, &QCheckBox::clicked, this, &MainWindow::onUpdateTable);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAboutTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_userAssistant;
}

void MainWindow::onAboutTriggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setAttribute(Qt::WA_DeleteOnClose);
    msgBox->setText("Created by Senkiv Vadym");
    msgBox->exec();
}

void MainWindow::onUpdateTable()
{
    const QVector<KeyData> &values = m_userAssistant->values();
    bool isViewAll = ui->viewAllcheckBox->isChecked();
    if (isViewAll || values.size() < DEFAULT_ROW_COUNT) {
        ui->topTable->setRowCount(values.size());
    } else {
        ui->topTable->setRowCount(DEFAULT_ROW_COUNT);
    }

    ui->topTable->clearContents();
    for(int i = 0; i < ui->topTable->rowCount(); i++)
    {
        QTableWidgetItem *nameItm = new QTableWidgetItem();
        QTableWidgetItem *dateItm = new QTableWidgetItem();
        QTableWidgetItem *countItm = new QTableWidgetItem();
        QTableWidgetItem *focusTimeItm = new QTableWidgetItem();

        dateItm->setTextAlignment(Qt::AlignHCenter);
        countItm->setTextAlignment(Qt::AlignHCenter);
        focusTimeItm->setTextAlignment(Qt::AlignHCenter);

        const KeyData &value = values[i];
        nameItm->setText(value.getName());
        dateItm->setText(value.getLastDateTime().toString("yyyy/MM/dd hh:mm:ss"));
        countItm->setText(QString::number(value.getRunCount()));
        focusTimeItm->setText(QString::number(value.getFocusTime()));

        ui->topTable->setItem(i, 0, nameItm);
        ui->topTable->setItem(i, 1, dateItm);
        ui->topTable->setItem(i, 2, countItm);
        ui->topTable->setItem(i, 3, focusTimeItm);
    }
}
