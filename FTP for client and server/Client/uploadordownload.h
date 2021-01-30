#ifndef UPLOADORDOWNLOAD_H
#define UPLOADORDOWNLOAD_H
#include <QDialog>
#include "fileuploadgetter.h"
#include "filestodownload.h"
#include "filedownloadgetter.h"
namespace Ui
{
class UploadOrDownload;
}
class UploadOrDownload : public QDialog
{
    Q_OBJECT
public:
    int soc;
    explicit UploadOrDownload(QWidget *parent = 0);
    void setSocket(int socket)
    {
        this -> soc = socket;
    }
    ~UploadOrDownload();
private slots:
    void on_pushButtonDownload_clicked();
    void on_pushButtonUpload_clicked();
    void on_pushButtonQuit1_clicked();
private:
    Ui::UploadOrDownload *ui;
    FileUploadGetter *fileUploadGetter;
    FilesToDownload *filesToDownload;
    FileDownloadGetter *filedownloadgetter;
};
#endif // UPLOADORDOWNLOAD_H
