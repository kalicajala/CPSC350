#ifndef LEVEL_H
#define LEVEL_H

#include "FileProcessor.h"

#include <iostream>
#include <cstdlib> // for random number generation
#include <string>

using namespace std;

class Level {
    public:
        Level(); // default constructor
        ~Level(); // default deconstructor
        Level(int N, bool last, int coinP, int emptyP, int goombaP, int koopaP, int mushroomP); // overloaded constructor

        char **levelArray;
        
        // aux functions
        void buildLevel(); // builds the NxN level grid
        string convertToString(); // converts level to a string to read into the file

    private:
        unsigned int dimension; 
        unsigned int percentCoin; 
        unsigned int percentEmpty; 
        unsigned int percentGoomba;
        unsigned int percentKoopa;
        unsigned int percentMushroom;
        bool isLast;
        int marioRow;
        int marioCol;

        // for buildLevel method
        unsigned int coinBound;
        unsigned int emptyBound;
        unsigned int goombaBound;
        unsigned int koopaBound;
        unsigned int mushroomBound;
        
};

#endif