#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&building,SIGNAL(updateGUI()),this,SLOT(slot_update_data()));
}

MainWindow::~MainWindow()
{
    building.~Building();
    delete ui;
}

void MainWindow::on_run_clicked()
{
    Data windata;
    building.run(ui->comboBox->currentIndex());
    windata = building.getData();

    ui->line_testdata1->setText(QString::fromStdString(windata.testdata));
    ui->line_submitdata1->setText(QString::fromStdString(windata.submit));
    ui->line_spendtime1->setText(QString::number(windata.spendtime));
    ui->line_corr1->setText(QString::number(static_cast<int>(windata.correct)));
}

void MainWindow::on_start_clicked()
{
    ui->finish->setVisible(0);
    building.startSimulation();
}

void MainWindow::slot_update_data()
{
    Data windata;
    windata = building.getData();

    if(windata.nowfloor)
    {
        ui->line_testdata1->setText(QString::fromStdString(windata.testdata));
        ui->line_submitdata1->setText(QString::fromStdString(windata.submit));
        ui->line_spendtime1->setText(QString::number(windata.spendtime));
        ui->line_corr1->setText(QString::number(static_cast<int>(windata.correct)));
        ui->line_score->setText(QString::number(windata.score));
        ui->comboBox->setCurrentIndex(windata.nowfloor);
    }
    else
        ui->finish->setVisible(1);
}
