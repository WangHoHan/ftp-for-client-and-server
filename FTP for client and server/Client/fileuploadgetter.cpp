#include "fileuploadgetter.h"
#include "ui_fileuploadgetter.h"
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
#include <cstring>
#include <libgen.h>
FileUploadGetter::FileUploadGetter(QWidget *parent) : QDialog(parent), ui(new Ui::fileUploadGetter)
{
    ui->setupUi(this);
}
FileUploadGetter::~FileUploadGetter()
{
    delete ui;
}
void FileUploadGetter::on_pushButton_clicked()
{
    QString filePath = ui->fileNameLabel->text();
    std::string str = filePath.toStdString();
    const char* pathToFile = str.c_str();
    char pathToFileChar[128] = "";
    strcat(pathToFileChar, pathToFile);
    char *base;
    base = basename(pathToFileChar);
    char buffer[4096];
    long fileSize, _send, sendTotal, _read;
    struct stat fileinfo;
    FILE* file;
    if (stat(pathToFileChar, &fileinfo) < 0 || str.empty())
    {
        QMessageBox::warning(this, "Warning","Cannot get information about file\n");
        return;
    }
    if (send(soc, base, 128, 0) != 128)
    {
        QMessageBox::warning(this, "Warning", "Error while sending file name\n");
        hide();
        return;
    }
    fileSize = htonl((long) fileinfo.st_size);
    if (send(soc, &fileSize, sizeof(long), 0) != sizeof(long))
    {
        QMessageBox::warning(this, "Warning","Cannot send information about file size\n");
        hide();
        return;
    }
    fileSize = fileinfo.st_size;
    sendTotal = 0;
    file = fopen(pathToFileChar, "rb");
    if (file == NULL)
    {
        QMessageBox::warning(this, "Warning", "Cannot open file\n");
        hide();
        return;
    }
    while (sendTotal < fileSize)
    {
        _read = fread(buffer, 1, 4096, file);
        _send = send(soc, buffer, _read, 0);
        if (_read != _send)
        {
            break;
        }
        sendTotal += _send;
    }
    if (sendTotal == fileSize)
    {
        QMessageBox::information(this, "Information","File sent correctly\n");
        hide();
    }
    else
    {
        QMessageBox::warning(this, "Warning","Sending file failed\n");
        hide();
    }
    fclose(file);
    return;
}
