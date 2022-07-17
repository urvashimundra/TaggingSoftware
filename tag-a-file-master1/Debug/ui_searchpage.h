/********************************************************************************
** Form generated from reading UI file 'searchpage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPAGE_H
#define UI_SEARCHPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "taglineedit.h"
#include "taglistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SearchPage
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    TagLineEdit *tagEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    TagListWidget *tagList;
    QLabel *resultsLabel;
    QTableView *resultView;

    void setupUi(QWidget *SearchPage)
    {
        if (SearchPage->objectName().isEmpty())
            SearchPage->setObjectName(QString::fromUtf8("SearchPage"));
        SearchPage->resize(465, 361);
        verticalLayout_3 = new QVBoxLayout(SearchPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        titleLabel = new QLabel(SearchPage);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        horizontalLayout_2->addWidget(titleLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(SearchPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        tagEdit = new TagLineEdit(groupBox);
        tagEdit->setObjectName(QString::fromUtf8("tagEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tagEdit->sizePolicy().hasHeightForWidth());
        tagEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(tagEdit);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        tagList = new TagListWidget(groupBox);
        tagList->setObjectName(QString::fromUtf8("tagList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tagList->sizePolicy().hasHeightForWidth());
        tagList->setSizePolicy(sizePolicy1);
        tagList->setMaximumSize(QSize(16777215, 21));
        tagList->setFlow(QListView::LeftToRight);

        verticalLayout_2->addWidget(tagList);

        resultsLabel = new QLabel(groupBox);
        resultsLabel->setObjectName(QString::fromUtf8("resultsLabel"));

        verticalLayout_2->addWidget(resultsLabel);

        resultView = new QTableView(groupBox);
        resultView->setObjectName(QString::fromUtf8("resultView"));
        resultView->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_2->addWidget(resultView);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(SearchPage);

        QMetaObject::connectSlotsByName(SearchPage);
    } // setupUi

    void retranslateUi(QWidget *SearchPage)
    {
        SearchPage->setWindowTitle(QCoreApplication::translate("SearchPage", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("SearchPage", "Search for filenames matching one or more tags.", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("SearchPage", "Search tag:", nullptr));
        tagEdit->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("SearchPage", "Tags list:", nullptr));
        resultsLabel->setText(QCoreApplication::translate("SearchPage", "Results:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchPage: public Ui_SearchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPAGE_H
