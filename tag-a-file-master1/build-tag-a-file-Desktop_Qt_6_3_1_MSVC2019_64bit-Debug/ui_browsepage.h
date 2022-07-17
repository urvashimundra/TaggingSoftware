/********************************************************************************
** Form generated from reading UI file 'browsepage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEPAGE_H
#define UI_BROWSEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrowsePage
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *filesButton;
    QPushButton *tagsButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QTableView *tableView;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *BrowsePage)
    {
        if (BrowsePage->objectName().isEmpty())
            BrowsePage->setObjectName(QString::fromUtf8("BrowsePage"));
        BrowsePage->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(BrowsePage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        titleLabel = new QLabel(BrowsePage);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        horizontalLayout_3->addWidget(titleLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(BrowsePage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filesButton = new QPushButton(groupBox);
        buttonGroup = new QButtonGroup(BrowsePage);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(filesButton);
        filesButton->setObjectName(QString::fromUtf8("filesButton"));

        horizontalLayout->addWidget(filesButton);

        tagsButton = new QPushButton(groupBox);
        buttonGroup->addButton(tagsButton);
        tagsButton->setObjectName(QString::fromUtf8("tagsButton"));

        horizontalLayout->addWidget(tagsButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(BrowsePage);

        QMetaObject::connectSlotsByName(BrowsePage);
    } // setupUi

    void retranslateUi(QWidget *BrowsePage)
    {
        BrowsePage->setWindowTitle(QCoreApplication::translate("BrowsePage", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("BrowsePage", "Browse the database of filenames and tags.", nullptr));
        groupBox->setTitle(QString());
        filesButton->setText(QCoreApplication::translate("BrowsePage", "Files", nullptr));
        tagsButton->setText(QCoreApplication::translate("BrowsePage", "Tags", nullptr));
        label->setText(QCoreApplication::translate("BrowsePage", "All files:", nullptr));
        label_2->setText(QCoreApplication::translate("BrowsePage", "(right-click has options)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrowsePage: public Ui_BrowsePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEPAGE_H
