#include "Enemy.h"

Enemy::Enemy() {
    wins = 0;
}

Enemy::~Enemy() {
    // nothing to do
}

bool Enemy::goomba() {
    // to ensure the random numbers being generated aren't repeated
    // in a constant order
    int x = time(0);
    srand(x);
    // variable used to decide if Mario wins or not
    int randNum = 1 + rand() % 5;
    // runs if Mario lost
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    // runs if Mario won
    else {
        // spot now empty
        wins += 1;
        return true;
    }
}

bool Enemy::koopa() {
    // to ensure the random numbers being generated aren't repeated
    // in a constant order
    int x = time(0);
    srand(x);
    // variable used to decide if Mario wins or not
    int randNum = 1 + rand() % 20;
    // runs if Mario lost
    if (randNum <= 7) {
        wins = 0;
        return false;
    }
    // runs if Mario won
    else {
        // spot now empty
        wins += 1;
        return true;
    }
}

bool Enemy::regBoss() {
    // to ensure the random numbers being generated aren't repeated
    // in a constant order
    int x = time(0);
    srand(x);
    // variable used to decide if Mario wins or not
    int randNum = 1 + rand() % 5;
    // runs if Mario lost
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    // runs if Mario won
    else {
        // spot now empty
        wins += 1;
        return true;
    }
}

bool Enemy::finalBoss() {
    // to ensure the random numbers being generated aren't repeated
    // in a constant order
    int x = time(0);
    srand(x);
    // variable used to decide if Mario wins or not
    int randNum = 1 + rand() % 5;
    // runs if Mario lost
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    // runs if Mario won
    else {
        // spot now empty
        wins += 1;
        return true;
    }
} 

bool Enemy::winStreak() {
    if (wins >= 7) {
        wins -= 7;
        return true;
    }
    return false;
}