#ifndef POWERS_H
#define POWERS_H
#include <vector>
using namespace std;
class powers{
    private:
    public:
    int tresure(const vector<vector<int>>& matrix);
    int generatePowers(const vector<vector<int>>& matrix);
    int generatePortals(const vector<vector<int>>& matrix, int size);
    int DOUBLE_PLAY(const vector<vector<int>>& matrix, int size);
    int CONTROL_ENEMY(const vector<vector<int>>& matrix, int size);
    int JUMP_WALL(const vector<vector<int>>& matrix, int size);
    int random(int num);
};


#endif
