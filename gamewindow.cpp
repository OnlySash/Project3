#include "gamewindow.h"
#include "build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ui_gamewindow.h"
#include "Matrix.h"
#include "powers.h"
#include <QMessageBox>
Matrix *m;

gamewindow::gamewindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gamewindow){
    ui->setupUi(this);
    initializeNodeMatrix();
    loadBackground();
    buildLaberynth();
    generateWalls();
    wayMaker();
    loadHunters();
    initializePowers();
    initializeTresure();
}

gamewindow::~gamewindow(){
    delete ui;
}

void gamewindow::initializeNodeMatrix(){
    m = new Matrix(laberynthHeightSize, laberynthWidthSize);
    m->printMatrix();
    printf("\n");
    m->connectNodes();
    m->applySearchAlgorithm();
    m->connectAdjNodes();
    m->connectAdjNodes();
}

void gamewindow::loadBackground(){
    this->resize(windowWidth, windowHeigth);
    QPixmap pix(":/Images/background.png");
    ui->label->resize(windowWidth, windowHeigth);
    ui->label->setPixmap(pix.scaled(windowWidth,windowHeigth));
}

void gamewindow::initializeBoxArray(){
    for (int i = 0; i<laberynthHeightSize; i++)
    {
        boxArray[i] = new QLabel*[laberynthWidthSize];
    }
}

void gamewindow::buildLaberynth(){
    initializeBoxArray();
    int heightGap = 0;
    for (int i = 0; i<laberynthHeightSize; i++)
    {
        int widthGap = 0;
        for (int j = 0; j<laberynthWidthSize; j++)
        {
            boxArray[i][j] = new QLabel("", this);
            int marginWidthCenter = laberynthWidthSize/2;
            int marginHeigthCenter = laberynthHeightSize/2;
            int posX = (this->width() / 2-boxSize*marginWidthCenter) + widthGap;
            int posY = (this->height() / 2-boxSize*marginHeigthCenter) + heightGap;
            boxArray[i][j]->setGeometry(posX, posY, boxSize, boxSize);
            QPixmap pix1(":/Images/Wall.png");

            QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(boxArray[i][j]);
            effect->setOpacity(0.7);
            boxArray[i][j]->setGraphicsEffect(effect);

            boxArray[i][j]->setPixmap(pix1.scaled(boxSize,boxSize));
            widthGap+=boxSize;
        }
        heightGap+=boxSize;
    }
}

void gamewindow::initializeWallArray(){
    for (int i = 0; i<laberynthHeightSize; i++)
    {
        wallArray[i] = new QLabel**[laberynthWidthSize];
        for (int j = 0; j<laberynthWidthSize; j++)
        {
            wallArray[i][j] = new QLabel*[4];
        }
    }
}

void gamewindow::initializePixArray(){
    pixArray[0] = QPixmap(":/Images/Above_Block.png");
    pixArray[1] = QPixmap(":/Images/Right_Block.png");
    pixArray[2] = QPixmap(":/Images/Below_Block.png");
    pixArray[3] = QPixmap(":/Images/Left_Block.png");
}

void gamewindow::generateWalls(){
    initializeWallArray();
    initializePixArray();

    int heightGap = 0;
    for (int i = 0; i<laberynthHeightSize; i++){
        int widthGap = 0;
        for (int j = 0; j<laberynthWidthSize; j++){
            for (int k = 0; k<4; k++){
                wallArray[i][j][k] = new QLabel("", this);
                int marginWidthCenter = laberynthWidthSize/2;
                int marginHeigthCenter = laberynthHeightSize/2;
                int posX = (this->width() / 2-boxSize*marginWidthCenter) + widthGap;
                int posY = (this->height() / 2-boxSize*marginHeigthCenter) + heightGap;
                wallArray[i][j][k]->setGeometry(posX, posY, boxSize, boxSize);
                wallArray[i][j][k]->setPixmap(pixArray[k].scaled(boxSize,boxSize));
            }
            widthGap+=boxSize;
        }
        heightGap+=boxSize;
    }
}

void gamewindow::wayMaker(){
    int openedPath = -1;
    for (int i=0; i<laberynthHeightSize; i++){
        for (int j=0; j<laberynthWidthSize; j++){
            m->updateCurrentNode(i, j);
            for (int k=0; k<4; k++){
                openedPath = m->getNodePath(i,j);
                if (openedPath != -1){
                    if (wallArray[i][j][openedPath] != nullptr){
                        wallArray[i][j][openedPath]->setPixmap(QPixmap());
                    }
                }
                else{
                    break;
                }
            }
        }
    }
}

void gamewindow::loadHunters(){
    //Hunter #1
    QPoint position1 = boxArray[0][0]->pos();
    leftLimit = position1.x();
    aboveLimit = position1.y();
    QPixmap pix2(":/Images/Hunter.png");

    ui->label_2->resize(boxSize, boxSize);
    ui->label_2->setPixmap(pix2.scaled(boxSize,boxSize));
    ui->label_2->move(leftLimit, aboveLimit);
    ui->label_2->raise();

    //Hunter #2
    QPoint position2 = boxArray[laberynthHeightSize-1][laberynthWidthSize-1]->pos();
    rightLimit = position2.x();
    belowLimit = position2.y();
    QPixmap pix3(":/Images/Huntera.png");

    ui->label_3->resize(boxSize, boxSize);
    ui->label_3->setPixmap(pix3.scaled(boxSize,boxSize));
    ui->label_3->move(rightLimit, belowLimit);
    ui->label_3->raise();
}

void gamewindow::keyPressEvent(QKeyEvent *event){
    int step = boxSize;
    int x1 = ui->label_2->x();
    int y1 = ui->label_2->y();
    int x2 = ui->label_3->x();
    int y2 = ui->label_3->y();

    if (turn == false){
        if (event->key() == Qt::Key_Left && x1>leftLimit){
            QPixmap pixmap = wallArray[currentRowPlayer1][currentColumnPlayer1][3]->pixmap();
            if (pixmap.isNull() == 1){
                x1 -= step;
                currentColumnPlayer1 -= 1;
                winValidation(false, x1, y1);
                turn = true;
            }
        }
        else if (event->key() == Qt::Key_Right && x1<rightLimit){
            QPixmap pixmap = wallArray[currentRowPlayer1][currentColumnPlayer1][1]->pixmap();
            if (pixmap.isNull() == 1){
                x1 += step;
                currentColumnPlayer1 += 1;
                winValidation(false, x1, y1);
                turn = true;
            }
        }
        else if (event->key() == Qt::Key_Up && y1>aboveLimit){
            QPixmap pixmap = wallArray[currentRowPlayer1][currentColumnPlayer1][0]->pixmap();
            if (pixmap.isNull() == 1){
                y1 -= step;
                currentRowPlayer1 -= 1;
                winValidation(false, x1, y1);
                turn = true;
            }
        }
        else if(event->key() == Qt::Key_Down && y1<belowLimit){
            QPixmap pixmap = wallArray[currentRowPlayer1][currentColumnPlayer1][2]->pixmap();
            if (pixmap.isNull() == 1){
                y1 += step;
                currentRowPlayer1 += 1;
                winValidation(false, x1, y1);
                turn = true;
            }
        }
        ui->label_2->move(x1, y1);
        //turn = true;
    }
    if (turn == true){
        if (event->key() == Qt::Key_A && x2>leftLimit){
            QPixmap pixmap = wallArray[currentRowPlayer2][currentColumnPlayer2][3]->pixmap();
            if (pixmap.isNull() == 1)
            {
                x2 -= step;
                currentColumnPlayer2 -= 1;
                winValidation(true, x2, y2);
                turn = false;
            }
        }
        else if (event->key() == Qt::Key_D && x2<rightLimit){
            QPixmap pixmap = wallArray[currentRowPlayer2][currentColumnPlayer2][1]->pixmap();
            if (pixmap.isNull() == 1){
                x2 += step;
                currentColumnPlayer2 += 1;
                winValidation(true, x2, y2);
                turn = false;
            }
        }
        else if (event->key() == Qt::Key_W && y2>aboveLimit){
            QPixmap pixmap = wallArray[currentRowPlayer2][currentColumnPlayer2][0]->pixmap();
            if (pixmap.isNull() == 1){
                y2 -= step;
                currentRowPlayer2 -= 1;
                winValidation(true, x2, y2);
                turn = false;
            }
        }
        else if(event->key() == Qt::Key_S && y2<belowLimit){
            QPixmap pixmap = wallArray[currentRowPlayer2][currentColumnPlayer2][2]->pixmap();
            if (pixmap.isNull() == 1){
                y2 += step;
                currentRowPlayer2 += 1;
                winValidation(true, x2, y2);
                turn = false;
            }
        }
        ui->label_3->move(x2, y2);
        //turn = false;
    }
}

void gamewindow::initializeTresure(){
    QLabel *label = new QLabel(this);
    QPixmap pixmap(":/Images/Bounty Chest.png");
    label->setPixmap(pixmap.scaled(boxSize, boxSize));
    winx = (this->width() / 2);
    winy = (this->height() / 2);
    label->setGeometry(winx, winy, boxSize, boxSize);
    label->show();
}

void gamewindow::generateImages(QPixmap pixmap, int posx, int posy)
{
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap.scaled(boxSize, boxSize));
    label->setGeometry(posx, posy, boxSize, boxSize);
    label->show();
}

/*
void initializePowers(){
    powers pow;
    int posx;
    int posy;
    for(int i=0; i<6; i++){
        posx =pow.random(10);
        posy =pow.random(10);
        //DOUBLE_PLAY
        if(i<=2){
            QPixmap pixmap(":/Images/Black-Circle-Fade-Sphere-PNG-Transparent-Images.png");
            generateImages(pixmap, posx, posy);
        }
        //CONTROL_ENEMY
        else if(i>2 &&i<=4){

        }
        //JUMP_WALL
        else{

        }
    }
}
*/

void gamewindow::winValidation(bool turn, int posx, int posy){
    QString winner ="";
    if(turn == false){
        winner = "You're the winner Player 1";
    }
    else{
        winner = "You're the winner Player 2";
    }
    if(posx == winx && posy == winy){
        QMessageBox msgBox;
        msgBox.setText(winner);
        msgBox.exec();
    }
}



