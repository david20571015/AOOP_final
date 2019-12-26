#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "building.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_run_clicked();

    void on_start_clicked();

    void slot_update_data();

    void on_upload_clicked();

private:
    Building building;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
