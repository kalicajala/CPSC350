#include "Mario.h"

Mario::Mario() {
    lives = 0;
    numCoins = 0;
    powerLevel = 0;
}

Mario::~Mario() {
    // doesn't need to delete or deallocate anything
}

Mario::Mario(int V) {
    lives = V;
    numCoins = 0;
    powerLevel = 0;
}

// adds a coin the Mario's wallet and returns the new amount of coins he has
void Mario::collectCoin() {
    numCoins += 1;
    if (numCoins >= 20) {
        coinsToLife();
    }
}

// exchanges 20 coins for an extra life, returns the new number of lives Mario has
void Mario::coinsToLife() {
    numCoins -= 20;
    lives += 1;
}

// decreases Mario's power level by 1 and returns his new power level
void Mario::decreasePowerLevel() {
    powerLevel -= 1;
    if (powerLevel < 0) {
        powerLevel = 0;
        lives -= 1;
        if (hasLife()) {
            // TODO: see if we implement an end game method here
        }
    }
}

void Mario::increasePowerLevel() {
    powerLevel += 1;
}

bool Mario::hasLife() {
    if (lives == 0) {
        return false;
    }
    return true;
}

int Mario::getLives() {
    return lives;
}

int Mario::getCoins() {
    return numCoins;
}

int Mario::getPowerLevel() {
    return powerLevel;
}

void Mario::addLife() {
    lives++;
}