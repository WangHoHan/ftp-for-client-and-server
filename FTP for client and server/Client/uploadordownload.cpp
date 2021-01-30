#include "uploadordownload.h"
#include "ui_uploadordownload.h"
#include "fileuploadgetter.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#define IP(H) *((unsigned long*) (H)->h_addr_list[0])
#include <QMessageBox>
#include <QString>
#include <iostream>
UploadOrDownload::UploadOrDownload(QWidget *parent) : QDialog(parent), ui(new Ui::UploadOrDownload)
{
    ui->setupUi(this);
}
UploadOrDownload::~UploadOrDownload()
{
    delete ui;
}
void UploadOrDownload::on_pushButtonDownload_clicked()
{
    long downloadRequest = 1;
    downloadRequest = htonl(downloadRequest);
    if (send(soc, &downloadRequest, sizeof(long), 0) != sizeof(long))
    {
        QMessageBox::warning(this, "Warning", "Download request failed\n");
        ::close(soc);
    }
    char buffer[4096];
    long option;
    QString filelist;
    if (recv(soc, &option, sizeof(long), 0) != sizeof(long))
    {
        printf("Operation not received\n");
    }
    option = ntohl(option);
    char fileNames[128];
    memset(fileNames, 0, 128);
    int i = 0;
    while (i < option)
    {
        if (recv(soc, &fileNames, 128, 0) != 128)
        {
            QMessageBox::warning(this, "Warning", "File list not received\n");
        }
        i++;
        filelist = filelist + QString::fromStdString(fileNames) + "\n";
        memset(fileNames, 0, 128);
    }
    QMessageBox::information(this, "Information", "files to download:\n" + filelist);
    filedownloadgetter = new FileDownloadGetter(this);
    filedownloadgetter->show();
    filedownloadgetter->setSocket(soc);
}
void UploadOrDownload::on_pushButtonUpload_clicked()
{
    long uploadRequest = 0;
    uploadRequest = htonl(uploadRequest);
    if (send(soc, &uploadRequest, sizeof(long), 0) != sizeof(long))
    {
        QMessageBox::warning(this, "Warning", "Upload request failed\n");
        ::close(soc);
    }
    fileUploadGetter = new FileUploadGetter(this);
    fileUploadGetter->setSocket(soc);
    fileUploadGetter->show();
}
void UploadOrDownload::on_pushButtonQuit1_clicked()
{
    exit(0);
}

