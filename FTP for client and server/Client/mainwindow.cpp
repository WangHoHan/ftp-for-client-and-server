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
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonConnect_clicked()
{
    QString ip = ui->lineEditIp->text();
    QString po = ui->lineEditPort->text();
    std::string str = ip.toStdString();
    const char* ip_char = str.c_str();
    int soc;
    struct sockaddr_in adr;
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);
    adr.sin_addr.s_addr = inet_addr(ip_char);
    soc = socket(PF_INET, SOCK_STREAM, 0);
    if (::connect(soc, (struct sockaddr*) &adr, sizeof(adr))<0)
    {
        QMessageBox::warning(this, "Warning", "Cannot establish connection with file server\n");
        ::close(soc);
    }
    else
    {
        QMessageBox::information(this, "Information", "Connection with file server is established\n");
        hide();
        uploadOrDownload = new UploadOrDownload(this);
        uploadOrDownload->show();
        uploadOrDownload->setSocket(soc);
    }
}
void MainWindow::on_pushButtonQuit_clicked()
{
    exit(0);
}
