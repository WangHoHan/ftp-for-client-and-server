#include "filedownloadgetter.h"
#include "ui_filedownloadgetter.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#define IP(H) *((unsigned long*) (H)->h_addr_list[0])
#include <QMessageBox>
FileDownloadGetter::FileDownloadGetter(QWidget *parent) : QDialog(parent), ui(new Ui::filedownlaodgetter)
{
    ui->setupUi(this);
}
FileDownloadGetter::~FileDownloadGetter()
{
    delete ui;
}
void FileDownloadGetter::on_pushButton_clicked()
{
    QString lFile = ui->lineEdit->text();
    std::string str = lFile.toStdString();
    const char* fileName = str.c_str();
    char buffer[4096];
    long fileSize, received, receivedTotal;
    FILE *file;
    if (send(soc, fileName, strlen(fileName), 0) != strlen(fileName))
    {
        QMessageBox::warning(this, "Warning","Error while sending the path\n");
        ::close(soc);
        return;
    }
    if (recv(soc, &fileSize, sizeof(long), 0) != sizeof(long))
    {
        QMessageBox::warning(this, "Warning","Error while receiving file length\n");
        ::close(soc);
        return;
    }
    fileSize = ntohl(fileSize);
    receivedTotal = 0;
    char pathToFile[128] = "./files/";
    strcat(pathToFile, fileName);
    file = fopen(pathToFile, "wb");
    while (receivedTotal < fileSize)
    {
        memset(buffer, 0, 4096);
        received = recv(soc, buffer, 4096, 0);
        if (received < 0)
        {
            break;
        }
        receivedTotal += received;
        fwrite(buffer, 1, received, file);
    }
    fclose(file);
    hide();
}
