#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


const int FONT_SIZE = 30;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , FONT("Arial", FONT_SIZE, QFont::Bold)
{
    clock_ = new Clock(this);
    date_ = new Date(this);
    auto timer = new QTimer(this);

    ui->setupUi(this);
    ui->ui_time->setFont(FONT);
    ui->ui_date->setFont(FONT);

    connect(timer, SIGNAL(timeout()), SLOT(ShowTime()));
    connect(timer, SIGNAL(timeout()), SLOT(ShowDate()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ShowTime()
{
    ui->ui_time->setText(clock_->GetCurrentTime());
}


void MainWindow::ShowDate()
{
    ui->ui_date->setText(date_->GetCurrentDate());
}
