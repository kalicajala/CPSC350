#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Translator.h"

using namespace std;

class FileProcessor : public Translator {
    public: 
        FileProcessor(); // constructor
        ~FileProcessor(); // destructor
        
        // takes text from input file, translates it, and outputs 
        // both original and translated text in output file
        void processFile(string inputFile, string outputFile);

        // helper function
        // will differentiate between a sentence and singular word by checking if there is whitespace (any spaces)
        bool containsSpace(string check); 
        
    
    private:
    Translator *myTranslator; // pointer object to the Translator class so we can use its functions
};

#endif