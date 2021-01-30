#ifndef FILEUPLOADGETTER_H
#define FILEUPLOADGETTER_H
#include <QDialog>
namespace Ui
{
class fileUploadGetter;
}
class FileUploadGetter : public QDialog
{
    Q_OBJECT
public:
    int soc;
    explicit FileUploadGetter(QWidget *parent = 0);
    void setSocket(int socket)
    {
        this -> soc = socket;
    }
    ~FileUploadGetter();
private slots:
    void on_pushButton_clicked();
private:
    Ui::fileUploadGetter *ui;
};
#endif // FILEUPLOADGETTER_H
