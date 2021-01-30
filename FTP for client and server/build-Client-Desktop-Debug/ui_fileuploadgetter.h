/********************************************************************************
** Form generated from reading UI file 'fileuploadgetter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEUPLOADGETTER_H
#define UI_FILEUPLOADGETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileUploadGetter
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fileNameLabel;
    QPushButton *pushButton;

    void setupUi(QDialog *fileUploadGetter)
    {
        if (fileUploadGetter->objectName().isEmpty())
            fileUploadGetter->setObjectName(QStringLiteral("fileUploadGetter"));
        fileUploadGetter->resize(340, 101);
        horizontalLayoutWidget = new QWidget(fileUploadGetter);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 301, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        fileNameLabel = new QLineEdit(horizontalLayoutWidget);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));

        horizontalLayout->addWidget(fileNameLabel);

        pushButton = new QPushButton(fileUploadGetter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 60, 221, 25));

        retranslateUi(fileUploadGetter);

        QMetaObject::connectSlotsByName(fileUploadGetter);
    } // setupUi

    void retranslateUi(QDialog *fileUploadGetter)
    {
        fileUploadGetter->setWindowTitle(QApplication::translate("fileUploadGetter", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("fileUploadGetter", "File Name:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("fileUploadGetter", "Upload", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fileUploadGetter: public Ui_fileUploadGetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEUPLOADGETTER_H
