#ifndef MARIO_H
#define MARIO_H

#include <iostream>

using namespace std;

class Mario {
    public:
        Mario(); // default constructor
        ~Mario(); // default destructor
        Mario(int V); // overloaded constructor with number of lives (inputted from user)
        
        // helper methods, descriptions in .cpp file
        void collectCoin(); 
        void coinsToLife(); 
        void increasePowerLevel();
        void decreasePowerLevel();
        bool hasLife();
        void addLife();

        // methods to help access attributes from outside the class
        int getLives();
        int getCoins();
        int getPowerLevel();

    private:
        int lives; // Mario's lives remaining
        int numCoins; // number of coins Mario has
        int powerLevel; // power level of Mario (0, 1, 2)

};

#endif