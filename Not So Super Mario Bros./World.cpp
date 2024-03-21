#include "World.h"

World::World() {
    input = "";
    output = "";
    
    levels = 1;
    dim = 0;
    mLives = 0;
    coinPer = 0;
    emptyPer = 0;
    goombaPer = 0;
    koopaPer = 0;
    mushroomPer = 0;
    marioRow = 0;
    marioCol = 0;
    mario = new Mario(0);
    enemy = new Enemy();
    fp = new FileProcessor();

    moves = 0;
    result = true;
}

World::~World() {
    delete mario;
    if (enemy != nullptr) {
        delete enemy;
    }
    delete fp;
}

World::World(string i, string o, int L, int N, int V, int coinP, int emptyP, int goombaP, int koopaP, int mushroomP) {
    input = i;
    output = o;
    levels = L;
    dim = N;
    mLives = V;

    coinPer = coinP;
    emptyPer = emptyP;
    goombaPer = goombaP;
    koopaPer = koopaP;
    mushroomPer = mushroomP;
    marioRow = 0;
    marioCol = 0;

    mario = new Mario(V);
    enemy = new Enemy();
    fp = new FileProcessor(input, output);

    moves = 0;
    result = true;
}

bool World::gameplay(int levelNum) {
    // will be false if Mario dies or he moves onto the next level
    bool continueLevel = true;
    
    // variable used to decide what item will occupy a spot
    int randNum;
    char temp;
    bool last = false;
    
    
    if (levelNum == levels - 1) {
        last = true;
    }
    Level *currLevel = new Level(dim, last, coinPer, emptyPer, goombaPer, koopaPer, mushroomPer);
    currLevel->buildLevel();
    fp->border();
    fp->displayLevel(currLevel->convertToString()); // shows the level before Mario is placed
        
    // places mario in a random place on the grid
    marioRow = rand() % dim;
    marioCol = rand() % dim;
        
    fp->marioStartPos(marioRow, marioCol); // prints Mario's starting position
    temp = currLevel->levelArray[marioRow][marioCol]; // sets temp to the item in the spot Mario will land
    currLevel->levelArray[marioRow][marioCol] = 'H'; // temporarily replaces the item with Mario's position
    fp->displayLevel(currLevel->convertToString()); // prints the level with Mario's position shown
    currLevel->levelArray[marioRow][marioCol] = temp; // set the item back where Mario is to prep for the while loop

    // while loop will run until the level is over or until Mario has no more lives
    while (continueLevel) {
        moves += 1;
        fp->displayStatsBefore(levelNum, marioRow, marioCol, mario->getPowerLevel());
        randNum = 1 + rand() % 4;
        
        if (randNum == 1) {
            continueLevel = interact(currLevel, temp, 'u'); 

            marioRow--; // Mario moves up
            if (marioRow < 0) { // if Mario reaches the upper border, he will instead go to the bottom border of the map (wraps)
                marioRow = dim - 1;
            }
        }
        else if (randNum == 2) {
            continueLevel = interact(currLevel, temp, 'r');

            marioCol++; // Mario moves right
            if (marioCol == dim) { // if Mario reaches the right border, he will instead go to the left border (wraps)
                marioCol = 0;
            }
        }
        else if (randNum == 3) {
            continueLevel = interact(currLevel, temp, 'd');

            marioRow++; // Mario moves down
            if (marioRow == dim) { // if Mario reaches the bottom border, he will instead go to the upper border (wraps)
                marioRow = 0;
            }
        }
        else if (randNum == 4) {
            continueLevel = interact(currLevel, temp, 'l');

            marioCol--; // Mario moves left
            if (marioCol < 0) { // if Mario reaches the left border, he will instead go to the right border (wraps)
                marioCol = dim - 1;
            }
        }
        temp = currLevel->levelArray[marioRow][marioCol]; // takes the item where Mario currently stands after moving
        currLevel->levelArray[marioRow][marioCol] = 'H'; // sets Mario's next position
        fp->border();
        fp->displayLevel(currLevel->convertToString());
        currLevel->levelArray[marioRow][marioCol] = temp;
    }
    delete currLevel;
    if (levelNum != dim - 1) {
        currLevel == nullptr;
    }
    return result;
}

bool World::interact(Level *level, char item, char direction) {
    switch (item) { // based on the item in the spot Mario lands on
        case 'c': 
            mario->collectCoin();
            if (mario->getCoins() >= 20) {
                mario->coinsToLife();
            }
            fp->interact('c');
            level->levelArray[marioRow][marioCol] = 'x';
            fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            return true;
        case 'x':
            fp->interact('x');
            fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            return true;
        case 'g':
            if (enemy->goomba()) {
                fp->interact('G');
                level->levelArray[marioRow][marioCol] = 'x';
                if (enemy->winStreak()) {
                    mario->addLife();
                }
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            }
            else {
                fp->interact('g');
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;
                    return false;
                }
                // goomba remains
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            }
            return true;
        case 'k':
            if (enemy->koopa()) {
                fp->interact('K');
                level->levelArray[marioRow][marioCol] = 'x';
                if (enemy->winStreak()) {
                    mario->addLife();
                }
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            }
            else {
                fp->interact('k');
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;
                    return false;
                }
                // koopa remains
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            }
            return true;
        case 'm':
            if (mario->getPowerLevel() < 2) {
                mario->increasePowerLevel();
            }
            fp->interact('m');
            level->levelArray[marioRow][marioCol] = 'x';
            fp->displayStatsAfter(mario->getLives(), mario->getCoins(), direction);
            return true;
        case 'b': // for the level (not final) boss
            if (enemy->regBoss()) {
                fp->interact('B');
                level->levelArray[marioRow][marioCol] = 'x';
                if (enemy->winStreak()) {
                    mario->addLife();
                }
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                result = true;
                return false;
            }
            else {
                fp->interact('b');
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;
                    return false;
                }
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;;
                    return false;
                }
                // boss remains
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                return true;
            }
        case 'B': // for the final level boss
            if (enemy->finalBoss()) {
                fp->interact('B');
                level->levelArray[marioRow][marioCol] = 'x';
                if (enemy->winStreak()) {
                    mario->addLife();
                }
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                result = true;
                return false;
            }
            else {
                fp->interact('b');
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;
                    fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                    return false;
                }
                mario->decreasePowerLevel();
                if (mario->getLives() == 0) {
                    result = false;
                    fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                    return false;
                }
                // boss remains
                fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 's');
                return true;
            }
        case 'w':
            fp->interact('w');
            level->levelArray[marioRow][marioCol] = 'x';
            fp->displayStatsAfter(mario->getLives(), mario->getCoins(), 'w');
            return false;
        default:
            cout << item << endl;
            cout << "something went wrong" << endl;
            return false;
    }
}

void World::gameStats() {
    fp->displayTotalMoves(result, moves);
}