#include "powers.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int powers::random(int num){
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = rand();
    return 1 + rand() % num;
}

int powers::generatePowers(const vector<vector<int>>& matrix){

    // generatePortals(matrix, size);
    // DOUBLE_PLAY(matrix, size);
    // CONTROL_ENEMY(matrix, size);
    // JUMP_WALL(matrix, size);
}

int powers::generatePortals(const vector<vector<int>>& matrix, int size){
    int can = random(2);
    int input=0;
    int output=0;
    for(int i=0; i<can; i++){
        input = matrix[random(size)][random(size)];
        output = matrix[random(size)][random(size)];
        //ingresar y botar
    }
    return input, output;
}

int powers::DOUBLE_PLAY(const vector<vector<int>>& matrix, int size){

}

int powers::CONTROL_ENEMY(const vector<vector<int>>& matrix, int size){

}

int powers::JUMP_WALL(const vector<vector<int>>& matrix, int size){

}

