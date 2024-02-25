#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char **argv) {
    // instantiates a FileProcessor
    FileProcessor *fp = new FileProcessor();

    // the names of the input and output files
    string iFile = "original.txt";
    string oFile = "translation.html";
    
    // calls the processFile method to process the file and
    // output an new file with original and translated text
    fp->processFile(iFile, oFile);

    // deallocates memory from FileProcessor object
    delete fp;

    // ends program
    return 0;

}