#include "filestodownload.h"
#include "ui_filestodownload.h"
FilesToDownload::FilesToDownload(QWidget *parent) : QDialog(parent), ui(new Ui::filesToDownload)
{
    ui->setupUi(this);
}
FilesToDownload::~FilesToDownload()
{
    delete ui;
}
void FilesToDownload::on_pushButton_clicked()
{
    hide();
}
void FilesToDownload::setLabelValue(QString string)
{
    this->ui->label->setText(string);
}
