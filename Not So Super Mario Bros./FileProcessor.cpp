#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    inputFileName = "input.txt";
    outputFileName = "output.txt";

    inFS.open(inputFileName); // creates and opens a new input stream

    // checks if the input stream can open
    if (!inFS.is_open()) {
        cerr << "input file could not open" << endl;
    }

    outFS.open(outputFileName); // output file stream

    // checks if the output stream can open
    if (!outFS.is_open()) {
        cerr << "output file could not open" << endl;
    }
}

FileProcessor::~FileProcessor() {
    // closes the file streams when the FileProcessor object is done being used
    inFS.close();
    outFS.close();
}

FileProcessor::FileProcessor(string inputFile, string outputFile) {
    inputFileName = inputFile;
    outputFileName = outputFile;
    
    // opening the input and output file stream because the things are constantly
    // being read and written from and to the input and output files
    inFS.open(inputFileName); // creates and opens a new input stream

    // checks if the input stream can open
    if (!inFS.is_open()) {
        cerr << "input file could not open" << endl;
    }

    outFS.open(outputFileName); // output file stream

    // checks if the output stream can open
    if (!outFS.is_open()) {
        cerr << "output file could not open" << endl;
    }

}

int* FileProcessor::processInput(string inputFile) {
    // reads the input file contents and assigns them to the array
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cout << "output file could not open" << endl;
        return nullptr;
    }
    int *values = new int[8];
    int count = 0;
    while (count < 8 && inFile >> values[count]) {
        count++;
    }

    inFile.close();
    // since this will only be called in the main method, we will delete
    // the array in the main method instead of here
    return values; 
}

void FileProcessor::displayLevel(string levelInput) {
    if (outFS.is_open()) {
        outFS << levelInput;
    }
    else {
        cout << "outFS is not open" << endl;
    }
    border();
}

void FileProcessor::interact(char item) {
    switch(item) {
        case 'c' : // Mario lands on a coin
            outFS << "Mario collected a coin" << endl;
            break;
        case 'x' : // Mario lands on an empty space
            outFS << "Mario lands on an empty spot" << endl;
            break;
        case 'g' : // Mario runs into a Goomba and lost
            outFS << "Mario fought a Goomba and lost" << endl;
            break;
        case 'G' : // Mario runs into a Goomba and won
            outFS << "Mario fought a Goomba and won" << endl;
            break;
        case 'k' : // Mario runs into a Koopa and lost
            outFS << "Mario fought a Koopa and lost" << endl;
            break;
        case 'K' : // Mario runs into a Koopa and won
            outFS << "Mario fought a Koopa and won" << endl;
            break;
        case 'm' : // Mario lands on a mushroom
            outFS << "Mario ate a mushroom" << endl;
            break;
        case 'w' : // Mario lands on a warp pipe
            outFS << "Mario found a warp pipe" << endl;
            break;
        case 'b' : // Mario runs into the boss and lost
            outFS << "Mario fought the level boss and lost" <<  endl;
            break;
        case 'B' : // Mario runs into the boss and won
            outFS << "Mario fought the level boss and won" <<  endl;
            break;
    }
}


void FileProcessor::displayStatsBefore(int levelNum, int row, int col, int PL) {
    outFS << "Level: " << levelNum << endl; // displays current level
    outFS << "Mario is at Position: (" << row << ", " << col << ")" << endl; // displays Mario's position
    outFS << "Mario is at power level: " << PL << endl; // displays Mario's current powel level (before item interaction)
}


void FileProcessor::displayStatsAfter(int currLives, int currCoins, char direction) {
    outFS << "Mario has " << currLives << " lives left" << endl; // displays Mario's current number of lives
    outFS << "Mario has " << currCoins << " coins" << endl; // displays Mario's current number of coins
    switch (direction) {
        case 'u':
            outFS << "Mario will move UP" << endl;
            break;
        case 'r':
            outFS << "Mario will move RIGHT" << endl;
            break;
        case 'd':
            outFS << "Mario will move DOWN" << endl;
            break;
        case 'l':
            outFS << "Mario will move LEFT" << endl;
            break;
        case 'w':
            outFS << "Mario will WARP" << endl;
            break;
        case 's':
            outFS << "Mario STAYS PUT" << endl;
            break;
    }
}

void FileProcessor::border() {
    outFS << "===============" << endl;
}

void FileProcessor::marioStartPos(int row, int col) {
    outFS << "Mario is at starting position (" << row << ", " << col << ")" << endl;
    border();
}

void FileProcessor::displayTotalMoves(bool result, int total) {
    if (result) {
        outFS << "Mario won in " << total << " moves!";
    }
    else {
        outFS << "Mario lost in " << total << " moves.";
    }
}