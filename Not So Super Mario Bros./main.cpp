#include "FileProcessor.h"
#include "World.h"

int main(int argc, char **argv) {
    srand(time(0)); // sets seed for my random numbers
    
    string iFile;
    string oFile;

    iFile = argv[1];

    cout << "Enter the name of the output file: " << endl;
    cin >> oFile;

    FileProcessor *fp = new FileProcessor();
    int numbers[8];
    int *returnArray;
    returnArray = fp->processInput(iFile);
    for (int i = 0; i < 8; i++) {
        numbers[i] = returnArray[i];
    }

    delete fp;

    // assigns the values from the input file to the corresponding number of levels, dimensions, lives, and percents
    int numLevels = numbers[0];
    int dimensions = numbers[1];
    int lives = numbers[2];
    int coinPercent = numbers[3];
    int emptyPercent = numbers[4];
    int goombaPercent = numbers[5];
    int koopaPercent = numbers[6];
    int mushroomPercent = numbers[7];



    World *world = new World(iFile, oFile, numLevels, dimensions, lives, coinPercent, emptyPercent, goombaPercent, koopaPercent, mushroomPercent);

    bool gameOn = true;
    int i = 0;

    for (int i = 0; i < numLevels; i++) {
        gameOn = world->gameplay(i);
        if (!gameOn) {
            break;
        }
    }
    
    world->gameStats();

    delete world;
    delete[] returnArray;
    return 0;
}