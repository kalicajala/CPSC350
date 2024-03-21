#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Enemy {
    public:
        Enemy();
        ~Enemy();

        // goomba or koopa functions
        bool goomba();
        bool koopa();
        bool regBoss();
        bool finalBoss();

        // win streak tracker
        bool winStreak();

    private:
        int wins;
};

#endif