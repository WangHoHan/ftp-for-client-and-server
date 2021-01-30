#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
long ls(char **fileList)
{
    DIR * dp = opendir("./files/");
    long i = 0;
    struct dirent * ep;
    while((ep = readdir(dp)))
    if(strncmp(ep->d_name, ".", 1) && ep->d_type != DT_DIR)
    {
        fileList[i] = ep->d_name;
            i++;
    }
    closedir(dp);
    return i;
}
void clientUploadFileRequest(int soc)
{
    char fileName[128];
    char path[128] = "./files/";
    long sizeofFile, write, received, allReceived;
    FILE *file;
    char bufor[4096];
    printf("Client upload request\n");
    printf("Getting file name\n");
    memset(fileName, 0, 128);
    if (recv(soc, fileName, 128, 0) <= 0)
    {
        printf("File name not received\n");
        return;
    }
    printf("Getting size of file\n");
    if(recv(soc, &sizeofFile, sizeof(long), 0) != sizeof(long))
    {
        printf("Getting file size failed\n");
        return;
    }
    sizeofFile = ntohl(sizeofFile);
    strcat(path, fileName);
    file = fopen(path, "wb");
    printf("Size of file: %d\n", sizeofFile);
    allReceived = 0;
    while (allReceived < sizeofFile)
    {
        memset(bufor, 0, 4096);
        received = recv(soc, bufor, 4096, 0);
        if (received < 0)
        {
            break;
        }
        allReceived += received;
        fwrite(bufor, 1, received, file);
    }
    close(file);
    close(soc);
    if (allReceived != sizeofFile)
    {
        printf("File receive failed\n");
    }
    else
    {
        printf("File received successfully\n");
    }
}
void clientDownloadFileRequest(int soc)
{
    char fileName[128];
    long fileSize, aSend, allSend, read;
    int i = 0;
    struct stat fileinfo;
    char pathToFile[128] = "./files/";
    FILE* file;
    unsigned char bufor[4096];
    char *fileList[100];
    long j = ls(fileList);
    printf("Client download request\n");
    printf("Sending size of file list: %ld\n", j);
    long jOut = htonl(j);
    if(send(soc, &jOut, sizeof(long), 0) != sizeof(long))
    {
        printf("Send file list failed\n");
        return;
    }
    for(long i = 0; i < j; i++)
    {
        printf("Sending: %s\n", fileList[i]);
        if(send(soc, fileList[i], 128, 0) != 128)
        {
            printf("File list send failed\n");
            return;
        }
    }
    memset(fileName, 0, 128);
    if (recv(soc, fileName, 128, 0) <= 0)
    {
        printf("File name not received\n");
        return;
    }
    printf("Converting file path\n");
    strcat(pathToFile, fileName);
    printf("Sending: %s\n", pathToFile);
    if (stat(pathToFile, &fileinfo) < 0)
    {
        printf("Cannot get information about file\n");
        return;
    }
    printf("Size of file: %d\n", fileinfo.st_size);
    fileSize = htonl((long) fileinfo.st_size);
    if (send(soc, &fileSize, sizeof(long), 0) != sizeof(long))
    {
        printf("Cannot send information about file size\n");
        return;
    }
    fileSize = fileinfo.st_size;
    allSend = 0;
    file = fopen(pathToFile, "rb");
    if (file == NULL)
    {
        printf("Cannot open file\n");
        return;
    }
    while (allSend < fileSize)
    {
        memset(bufor, 0, 4096);
        read = fread(bufor, 1, 4096, file);
        aSend = send(soc, bufor, read, 0);
        if (read != aSend)
            break;
        allSend += aSend;
        printf("Sending: Send %d bytes\n", allSend);
    }
    if (allSend == fileSize)
    {
        printf("File send correctly\n");
    }
    else
    {
        printf("Sending file failed\n");
    }
    fclose(file);
    return;
}
void clientConnector(int soc)
{
    long option;
    printf("Waiting for client request\n");
    if(recv(soc, &option, sizeof(long), 0) != sizeof(long))
    {
        printf("Operation not received \n");
    }
    option = ntohl(option);
    if(option == 1)
    {
        clientDownloadFileRequest(soc);
    }
    else if(option == 0)
    {
        clientUploadFileRequest(soc);
    }
    else
    {
        printf("Illegal argument for taskInfo\n");
    }
    close(soc);
    return;
}
int main()
{
    int soc_listen, soc_client;
    struct sockaddr_in adr;
    socklen_t adr_size = sizeof(struct sockaddr_in);
    soc_listen = socket(PF_INET, SOCK_STREAM, 0);
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);
    adr.sin_addr.s_addr = INADDR_ANY;
    memset(adr.sin_zero, 0, sizeof(adr.sin_zero));
    if (bind(soc_listen, (struct sockaddr*) &adr, adr_size) < 0)
    {
        printf("Bind() failed\n");
        return 1;
    }
    listen(soc_listen, 10);
    while(1)
    {
        adr_size = sizeof(struct sockaddr_in);
        soc_client = accept(soc_listen, (struct sockaddr*) &adr, &adr_size);
        if (soc_client < 0)
        {
            printf("Cannot accept connection with client\n");
            continue;
        }
        printf("Connected with: %s:%u\n", inet_ntoa(adr.sin_addr), ntohs(adr.sin_port));
        if (fork() == 0)
        {
            clientConnector(soc_client);
            close(soc_client);
            exit(0);
        }
        else
        {
            continue;
        }
    }
    return 0;
}
