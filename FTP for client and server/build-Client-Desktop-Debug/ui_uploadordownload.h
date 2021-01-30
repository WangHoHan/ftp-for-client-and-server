/********************************************************************************
** Form generated from reading UI file 'uploadordownload.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADORDOWNLOAD_H
#define UI_UPLOADORDOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadOrDownload
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonDownload;
    QPushButton *pushButtonUpload;
    QPushButton *pushButtonQuit1;

    void setupUi(QDialog *UploadOrDownload)
    {
        if (UploadOrDownload->objectName().isEmpty())
            UploadOrDownload->setObjectName(QStringLiteral("UploadOrDownload"));
        UploadOrDownload->resize(634, 354);
        groupBox = new QGroupBox(UploadOrDownload);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(49, 9, 531, 331));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 40, 391, 271));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonDownload = new QPushButton(widget);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));

        verticalLayout->addWidget(pushButtonDownload);

        pushButtonUpload = new QPushButton(widget);
        pushButtonUpload->setObjectName(QStringLiteral("pushButtonUpload"));

        verticalLayout->addWidget(pushButtonUpload);

        pushButtonQuit1 = new QPushButton(widget);
        pushButtonQuit1->setObjectName(QStringLiteral("pushButtonQuit1"));

        verticalLayout->addWidget(pushButtonQuit1);


        retranslateUi(UploadOrDownload);

        QMetaObject::connectSlotsByName(UploadOrDownload);
    } // setupUi

    void retranslateUi(QDialog *UploadOrDownload)
    {
        UploadOrDownload->setWindowTitle(QApplication::translate("UploadOrDownload", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UploadOrDownload", "Download from File Server / upload to File Server", Q_NULLPTR));
        pushButtonDownload->setText(QApplication::translate("UploadOrDownload", "Download", Q_NULLPTR));
        pushButtonUpload->setText(QApplication::translate("UploadOrDownload", "Upload", Q_NULLPTR));
        pushButtonQuit1->setText(QApplication::translate("UploadOrDownload", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UploadOrDownload: public Ui_UploadOrDownload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADORDOWNLOAD_H
