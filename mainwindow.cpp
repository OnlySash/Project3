#include "mainwindow.h"
#include "build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ui_mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameWindow(nullptr)
{
    ui->setupUi(this);
    QPixmap pix(":/Images/Maze_Knights_Background.png");
    ui->label->setPixmap(pix.scaled(1280,720));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!gameWindow) {
        gameWindow = new gamewindow; // Crea una nueva instancia solo si no existe
    }
    gameWindow->show();
    this->close();
}

