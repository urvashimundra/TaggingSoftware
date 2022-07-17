/********************************************************************************
** Form generated from reading UI file 'editpage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPAGE_H
#define UI_EDITPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "taglineedit.h"
#include "taglistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_EditPage
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    TagLineEdit *tagEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    TagListWidget *tagList;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *EditPage)
    {
        if (EditPage->objectName().isEmpty())
            EditPage->setObjectName(QString::fromUtf8("EditPage"));
        EditPage->resize(434, 366);
        verticalLayout_3 = new QVBoxLayout(EditPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        titleLabel = new QLabel(EditPage);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        horizontalLayout_4->addWidget(titleLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(EditPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

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
        tagList->setLayoutDirection(Qt::LeftToRight);
        tagList->setFlow(QListView::LeftToRight);

        verticalLayout_2->addWidget(tagList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(EditPage);

        QMetaObject::connectSlotsByName(EditPage);
    } // setupUi

    void retranslateUi(QWidget *EditPage)
    {
        EditPage->setWindowTitle(QCoreApplication::translate("EditPage", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("EditPage", "Add or edit the tags associated with a filename.", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("EditPage", "Filename:", nullptr));
        lineEdit->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("EditPage", "New tag:", nullptr));
        tagEdit->setPlaceholderText(QCoreApplication::translate("EditPage", "Enter to accept", nullptr));
        label->setText(QCoreApplication::translate("EditPage", "Tags list:", nullptr));
        pushButton->setText(QCoreApplication::translate("EditPage", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPage: public Ui_EditPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPAGE_H
