#ifndef FILESTODOWNLOAD_H
#define FILESTODOWNLOAD_H
#include <QDialog>
namespace Ui
{
class filesToDownload;
}
class FilesToDownload : public QDialog
{
    Q_OBJECT
public:
    Ui::filesToDownload *ui;
    explicit FilesToDownload(QWidget *parent = 0);
    ~FilesToDownload();
    void setLabelValue(QString string);
private slots:
    void on_pushButton_clicked();
private:
};
#endif // FILESTODOWNLOAD_H
