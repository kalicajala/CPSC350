#include "Level.h"

// default constructor
// sets variables to default values
// won't be actually implementing this during runtime
Level::Level() {
    dimension = 1;
    percentCoin = 0;
    percentEmpty = 0;
    percentGoomba = 0;
    percentKoopa = 0;
    percentMushroom = 0;
    levelArray = nullptr;
    isLast = false;
    marioRow = 0;
    marioCol = 0;

    coinBound = 0;
    emptyBound = 0;
    goombaBound = 0;
    koopaBound = 0;
    mushroomBound = 0;
}

// default destructor
// deallocates memory from 2d array pointer, File Processor pointer, and Mario pointer
Level::~Level() {
    for (int i = 0; i < dimension; i++) {
        delete[] levelArray[i];
    }
    delete[] levelArray;
}

// overloaded constructor
// takes in row and column dimensions, along with 
// percentages of how often different items occupy 
// a spot in the level
Level::Level(int N, bool last, int coinP, int emptyP, int goombaP, int koopaP, int mushroomP) {
    dimension = N;
    isLast = last;
    percentCoin = coinP;
    percentEmpty = emptyP;
    percentGoomba = goombaP;
    percentKoopa = koopaP;
    percentMushroom = mushroomP;
    levelArray = nullptr;
    marioRow = 0;
    marioCol = 0;

    coinBound = coinP - 1;
    emptyBound = coinP + emptyP - 1;
    goombaBound = coinP + emptyP + goombaP - 1;
    koopaBound = coinP + emptyP + goombaP + koopaP - 1;
    mushroomBound = coinP + emptyP + goombaP + koopaP + mushroomP - 1;

    // allocate memory for the level array
    levelArray = new char*[dimension];
    for (int i = 0; i < dimension; i++) {
        levelArray[i] = new char[dimension];
    }
}

// method to set up the level layout using the percentages from
// the constructor
void Level::buildLevel() {
    levelArray = new char*[dimension];

    // to ensure the random numbers being generated aren't repeated
    // in a constant order
    // variable used to decide what item will occupy a spot
    int randNum;

    for (int row = 0; row < dimension; row++) {
        levelArray[row] = new char[dimension]; // allocate emory for each row
        for (int col = 0; col < dimension; col++) {
            randNum = rand() % 99;

            if (randNum <= coinBound) {
                levelArray[row][col] = 'c';
            }
            else if (randNum <= emptyBound) {
                levelArray[row][col] = 'x';
            }
            else if (randNum <= goombaBound) {
                levelArray[row][col] = 'g';
            }
            else if (randNum <= koopaBound) {
                levelArray[row][col] = 'k';
            }
            else if (randNum <= mushroomBound) {
                levelArray[row][col] = 'm';
            }
        }
    }


    // randomly assigns the level boss position
    int randRow = rand() % dimension;
    int randCol = rand() % dimension;
    if (isLast) {
        levelArray[randRow][randCol] = 'B'; // final boss for last level
    }
    else {
        levelArray[randRow][randCol] = 'b';
    }

    // if the current level isn't the last level, then a warp pipe
    // will be generated. if Mario lands on this, he automatically 
    // transports to the next level
    if (!(isLast)) {
        randRow = rand() % dimension;
        randCol = rand() % dimension;
        levelArray[randRow][randCol] = 'w';
    }
}

string Level::convertToString() {
    string s;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            s += levelArray[row][col];
            s += " ";
        }
        s += "\n";
    }
    return s;
}