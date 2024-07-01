#ifndef POWERS_H
#define POWERS_H
#include <vector>
using namespace std;
class powers
{
    private:
    public:
    int tresure(const vector<vector<int>>& matrix);
    void generatePowers(const vector<vector<int>>& matrix);
    void generatePortals(const vector<vector<int>>& matrix, int size);
    void DOUBLE_PLAY(const vector<vector<int>>& matrix, int size);
    void CONTROL_ENEMY(const vector<vector<int>>& matrix, int size);
    void JUMP_WALL(const vector<vector<int>>& matrix, int size);
};


#endif
