#include "powers.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int num){
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = rand();
    return 1 + rand() % num;
}

void powers::generatePowers(const vector<vector<int>>& matrix)
{
    int size= matrix.size();
    generatePortals(matrix, size);
    DOUBLE_PLAY(matrix, size);
    CONTROL_ENEMY(matrix, size);
    JUMP_WALL(matrix, size);
}

void powers::generatePortals(const vector<vector<int>>& matrix, int size){
    int can = random(2);
    for(int i=0; i<can; i++){
        int input = matrix[random(size)][random(size)];
        int output = matrix[random(size)][random(size)];
        //ingresar y botar
    }

}

void powers::DOUBLE_PLAY(const vector<vector<int>>& matrix, int size){
    int can = random(2);
    for(int i=0; i<can; i++){
        //desviar matrix[random(size)][random(size)]
    }
}

void powers::CONTROL_ENEMY(const vector<vector<int>>& matrix, int size){
    int can = random(2);
    for(int i=0; i<can; i++){
        //desviar matrix[random(size)][random(size)]
    }
}

void powers::JUMP_WALL(const vector<vector<int>>& matrix, int size){
    int can = random(2);
    for(int i=0; i<can; i++){
        //desviar matrix[random(size)][random(size)]
    }
}

