/********************************************************************************
** Form generated from reading UI file 'filestodownload.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESTODOWNLOAD_H
#define UI_FILESTODOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_filesToDownload
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *filesToDownload)
    {
        if (filesToDownload->objectName().isEmpty())
            filesToDownload->setObjectName(QStringLiteral("filesToDownload"));
        filesToDownload->resize(254, 336);
        label = new QLabel(filesToDownload);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 191, 291));
        pushButton = new QPushButton(filesToDownload);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 300, 131, 25));

        retranslateUi(filesToDownload);

        QMetaObject::connectSlotsByName(filesToDownload);
    } // setupUi

    void retranslateUi(QDialog *filesToDownload)
    {
        filesToDownload->setWindowTitle(QApplication::translate("filesToDownload", "Dialog", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("filesToDownload", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class filesToDownload: public Ui_filesToDownload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESTODOWNLOAD_H
