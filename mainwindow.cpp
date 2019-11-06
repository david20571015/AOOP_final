#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_run_clicked()
{
    Data windata;
    building.run();
    windata=building.getData();

    ui->line_testdata1->setText(QString::fromStdString(windata.testdata1));
    ui->line_submitdata1->setText(QString::fromStdString(windata.submit1));
    ui->line_spendtime1->setText(QString::number(windata.spendtime1));
    ui->line_corr1->setText(QString::number(static_cast<int>(windata.correct1)));

    ui->line_testdata2->setText(QString::fromStdString(windata.testdata2));
    ui->line_submitdata2->setText(QString::fromStdString(windata.submit2));
    ui->line_spendtime2->setText(QString::number(windata.spendtime2));
    ui->line_corr2->setText(QString::number(static_cast<int>(windata.correct2)));
}
