#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
// #include <QMediaPlayer>
// #include <QAudioOutput>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class gamewindow;
}
QT_END_NAMESPACE

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    gamewindow(QWidget *parent = nullptr);
    ~gamewindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::gamewindow *ui;

    // QMediaPlayer *mMediaPlayer;
    // QAudioOutput *mAudioOutput;

    // QMediaPlayer *bMediaPlayer;
    // QMediaPlayer *bAudioOutput;

    //Compilation constants
    const int windowWidth = 1280;
    const int windowHeigth = 720;
    const int boxSize = 50;
    const int laberynthHeightSize = 10;
    const int laberynthWidthSize = 10;

    //Instances


    //Methods
    void initializeNodeMatrix();
    void loadBackground();
    void initializeBoxArray();
    void initializeWallArray();
    void buildLaberynth();
    void initializePixArray();
    void generateWalls();
    void wayMaker();
    void loadHunters();

    //Global variables from the class
    QLabel ***boxArray = new QLabel**[laberynthHeightSize];
    QLabel ****wallArray = new QLabel***[laberynthHeightSize];
    QPixmap *pixArray = new QPixmap[4];
    bool turn = false;
    int leftLimit = 0;
    int rightLimit = 0;
    int aboveLimit = 0;
    int belowLimit = 0;
    int currentColumnPlayer1 = 0;
    int currentRowPlayer1 = 0;
    int currentColumnPlayer2 = laberynthWidthSize-1;
    int currentRowPlayer2 = laberynthHeightSize-1;
};

#endif // GAMEWINDOW_H
