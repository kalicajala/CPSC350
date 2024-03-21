#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Mario.h"
#include "Enemy.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class World {
    public:
        World(); // default constructor
        ~World(); // default destructor
        World(string i, string o, int L, int N, int V, int coinP, int emptyP, int goombaP, int koopaP, int mushroomP); // overloaded constructor 

        // other functions
        bool gameplay(int levelNum); // takes in the number of the current level and returns a bool (used for whether the game continues or not)
        bool interact(Level *level, char item, char direction); // used as a helper function for when Mario interacts with a spot (empty or not)
        void gameStats(); // displays the game stats (whether Mario won or not, how many moves Mario made in the game)
    
    private:
        string input;
        string output;
        
        int levels;
        int dim;
        int mLives;
        Mario *mario;
        Enemy *enemy;
        FileProcessor *fp;
        int marioRow;
        int marioCol;
        int coinPer;
        int emptyPer;
        int goombaPer;
        int koopaPer;
        int mushroomPer;

        unsigned int moves;
        bool result;
};

#endif