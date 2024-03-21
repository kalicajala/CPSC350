#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileProcessor {
    public:
        ifstream inFS;
        ofstream outFS;
        
        FileProcessor();
        ~FileProcessor();
        FileProcessor(string inputFile, string outputFile);

        // function that will read in the levels, dimensions, lives, and percent values,  
        // then return it as an array to be used in the level class
        int* processInput(string inputFile);
        
        // functions that will write to the console log 
        // void displayLevel(char** levelGrid, int numRows);
        void displayLevel(string levelInput);
        void interact(char item);
        void displayStatsBefore(int levelNum, int row, int col, int PL);
        void displayStatsAfter(int currLives, int currCoins, char direction);
        void border();
        void marioStartPos(int row, int col);
        void displayTotalMoves(bool result, int total);

    private:
        string inputFileName;
        string outputFileName;
};

#endif