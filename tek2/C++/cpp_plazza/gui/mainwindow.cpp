#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sended(false),
    correctFile(false)
{
    types = {"PHONE_NUMBER", "EMAIL_ADDRESS", "IP_ADDRESS"};
    ui->setupUi(this);
    this->setFixedSize(QSize(744, 355));
    this->ui->tableWidget->setRowCount(0);
    this->ui->tableWidget->setColumnCount(3);
    QStringList header;
    header << "Process ID" << "actives workers" << "Tasks in queue";
    this->ui->tableWidget->setHorizontalHeaderLabels(header);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("open file"),
                qgetenv("PWD"));

    if (filename.length() > 0) {
        this->correctFile = true;
        this->ui->label->setText(filename);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (correctFile)
        this->sended = true;
    this->filename = this->ui->label->text().toStdString();
}
