/********************************************************************************
** Form generated from reading UI file 'filedownloadgetter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDOWNLOADGETTER_H
#define UI_FILEDOWNLOADGETTER_H

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

class Ui_filedownlaodgetter
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *filedownlaodgetter)
    {
        if (filedownlaodgetter->objectName().isEmpty())
            filedownlaodgetter->setObjectName(QStringLiteral("filedownlaodgetter"));
        filedownlaodgetter->resize(323, 124);
        horizontalLayoutWidget = new QWidget(filedownlaodgetter);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 301, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(filedownlaodgetter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 80, 221, 25));

        retranslateUi(filedownlaodgetter);

        QMetaObject::connectSlotsByName(filedownlaodgetter);
    } // setupUi

    void retranslateUi(QDialog *filedownlaodgetter)
    {
        filedownlaodgetter->setWindowTitle(QApplication::translate("filedownlaodgetter", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("filedownlaodgetter", "File name:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("filedownlaodgetter", "Download", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class filedownlaodgetter: public Ui_filedownlaodgetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDOWNLOADGETTER_H
