/********************************************************************************
** Form generated from reading UI file 'softtop.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTTOP_H
#define UI_SOFTTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoftTop
{
public:
    QAction *action_Close;
    QAction *actionAbout;
    QAction *actionUpdate;
    QAction *actionHour;
    QAction *actionDay;
    QAction *actionAll_Time;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *topTable;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *sortByrGrBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *byHour;
    QRadioButton *byDay;
    QRadioButton *byAllTime;
    QPushButton *updateButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *viewAllcheckBox;
    QMenuBar *menuBar;
    QMenu *menu_Program;
    QMenu *menuInfo;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SoftTop)
    {
        if (SoftTop->objectName().isEmpty())
            SoftTop->setObjectName(QStringLiteral("SoftTop"));
        SoftTop->resize(648, 462);
        SoftTop->setMinimumSize(QSize(500, 350));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        SoftTop->setFont(font);
        action_Close = new QAction(SoftTop);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        actionAbout = new QAction(SoftTop);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionUpdate = new QAction(SoftTop);
        actionUpdate->setObjectName(QStringLiteral("actionUpdate"));
        actionHour = new QAction(SoftTop);
        actionHour->setObjectName(QStringLiteral("actionHour"));
        actionDay = new QAction(SoftTop);
        actionDay->setObjectName(QStringLiteral("actionDay"));
        actionAll_Time = new QAction(SoftTop);
        actionAll_Time->setObjectName(QStringLiteral("actionAll_Time"));
        centralWidget = new QWidget(SoftTop);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        topTable = new QTableWidget(centralWidget);
        topTable->setObjectName(QStringLiteral("topTable"));
        topTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        topTable->setColumnCount(0);

        verticalLayout_2->addWidget(topTable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sortByrGrBox = new QGroupBox(centralWidget);
        sortByrGrBox->setObjectName(QStringLiteral("sortByrGrBox"));
        horizontalLayout = new QHBoxLayout(sortByrGrBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        byHour = new QRadioButton(sortByrGrBox);
        byHour->setObjectName(QStringLiteral("byHour"));
        byHour->setChecked(true);

        horizontalLayout->addWidget(byHour);

        byDay = new QRadioButton(sortByrGrBox);
        byDay->setObjectName(QStringLiteral("byDay"));

        horizontalLayout->addWidget(byDay);

        byAllTime = new QRadioButton(sortByrGrBox);
        byAllTime->setObjectName(QStringLiteral("byAllTime"));

        horizontalLayout->addWidget(byAllTime);

        updateButton = new QPushButton(sortByrGrBox);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout->addWidget(updateButton);


        horizontalLayout_3->addWidget(sortByrGrBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        viewAllcheckBox = new QCheckBox(centralWidget);
        viewAllcheckBox->setObjectName(QStringLiteral("viewAllcheckBox"));
        viewAllcheckBox->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(viewAllcheckBox);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        SoftTop->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SoftTop);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 648, 20));
        menu_Program = new QMenu(menuBar);
        menu_Program->setObjectName(QStringLiteral("menu_Program"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        SoftTop->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SoftTop);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SoftTop->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SoftTop);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SoftTop->setStatusBar(statusBar);

        menuBar->addAction(menu_Program->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menu_Program->addAction(action_Close);
        menuInfo->addAction(actionAbout);
        menuOptions->addAction(actionUpdate);
        menuOptions->addSeparator();
        menuOptions->addAction(actionHour);
        menuOptions->addAction(actionDay);
        menuOptions->addAction(actionAll_Time);

        retranslateUi(SoftTop);

        QMetaObject::connectSlotsByName(SoftTop);
    } // setupUi

    void retranslateUi(QMainWindow *SoftTop)
    {
        SoftTop->setWindowTitle(QApplication::translate("SoftTop", "SoftTop - User Assistant", 0));
        action_Close->setText(QApplication::translate("SoftTop", "&Close", 0));
        actionAbout->setText(QApplication::translate("SoftTop", "&About", 0));
        actionUpdate->setText(QApplication::translate("SoftTop", "&Update", 0));
#ifndef QT_NO_STATUSTIP
        actionUpdate->setStatusTip(QApplication::translate("SoftTop", "Update list", 0));
#endif // QT_NO_STATUSTIP
        actionHour->setText(QApplication::translate("SoftTop", "&Hour", 0));
#ifndef QT_NO_STATUSTIP
        actionHour->setStatusTip(QApplication::translate("SoftTop", "Show programs by last hour(date)", 0));
#endif // QT_NO_STATUSTIP
        actionDay->setText(QApplication::translate("SoftTop", "&Day", 0));
#ifndef QT_NO_STATUSTIP
        actionDay->setStatusTip(QApplication::translate("SoftTop", "Show programs by last days", 0));
#endif // QT_NO_STATUSTIP
        actionAll_Time->setText(QApplication::translate("SoftTop", "&All Time", 0));
#ifndef QT_NO_STATUSTIP
        actionAll_Time->setStatusTip(QApplication::translate("SoftTop", "Show most used program", 0));
#endif // QT_NO_STATUSTIP
        sortByrGrBox->setTitle(QApplication::translate("SoftTop", "Sort by", 0));
#ifndef QT_NO_STATUSTIP
        byHour->setStatusTip(QApplication::translate("SoftTop", "Show programs by last hour(date)", 0));
#endif // QT_NO_STATUSTIP
        byHour->setText(QApplication::translate("SoftTop", "Hour", 0));
#ifndef QT_NO_STATUSTIP
        byDay->setStatusTip(QApplication::translate("SoftTop", "Show programs by last days", 0));
#endif // QT_NO_STATUSTIP
        byDay->setText(QApplication::translate("SoftTop", "Day", 0));
#ifndef QT_NO_STATUSTIP
        byAllTime->setStatusTip(QApplication::translate("SoftTop", "Show most used program", 0));
#endif // QT_NO_STATUSTIP
        byAllTime->setText(QApplication::translate("SoftTop", "All Time", 0));
#ifndef QT_NO_STATUSTIP
        updateButton->setStatusTip(QApplication::translate("SoftTop", "Update program list", 0));
#endif // QT_NO_STATUSTIP
        updateButton->setText(QApplication::translate("SoftTop", "Update Top", 0));
        viewAllcheckBox->setText(QApplication::translate("SoftTop", "View all", 0));
        menu_Program->setTitle(QApplication::translate("SoftTop", "&Program", 0));
        menuInfo->setTitle(QApplication::translate("SoftTop", "&Info", 0));
        menuOptions->setTitle(QApplication::translate("SoftTop", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class SoftTop: public Ui_SoftTop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTTOP_H
