#ifndef FILEDOWNLAODGETTER_H
#define FILEDOWNLAODGETTER_H
#include <QDialog>
namespace Ui
{
class filedownlaodgetter;
}
class FileDownloadGetter : public QDialog
{
    Q_OBJECT
public:
    int soc;
    void setSocket(int socket)
    {
        this -> soc = socket;
    }
    explicit FileDownloadGetter(QWidget *parent = 0);
    ~FileDownloadGetter();
private slots:
    void on_pushButton_clicked();
private:
    Ui::filedownlaodgetter *ui;
};
#endif // FILEDOWNLAODGETTER_H
