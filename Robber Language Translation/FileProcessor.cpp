#include "Model.h"
#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    myTranslator = new Translator(); // myTranslator created in h file
}

FileProcessor::~FileProcessor() {
    delete myTranslator; // deallocates memory memory from this object
}

void FileProcessor::processFile(string inputFile, string outputFile) {
    
    ifstream inFS; // creates a new input stream
    inFS.open(inputFile); // opens the input stream
    
    // checks if the input stream can open
    if (!inFS.is_open()) {
        cout << "input file could not open" << endl;
        return;
    }

    ofstream outFS; // output file stream
    outFS.open(outputFile); // open output file stream

    // checks if the output stream can open
    if (!outFS.is_open()) {
        cout << "output file could not open" << endl;
        return;
    }

    // writes the beginning part of the HTML file to the output file
    outFS << "<!DOCTYPE html>" << endl;
    outFS << "<html>" << endl;
    outFS << "<head>" << endl;
    outFS << "<title>English to Robber Translation</title>" << endl;
    outFS << "</head>" << endl;
    outFS << "<body>" << endl;

    // reads the input file contents and writes it to the output file in bold
    string line;
    string translatedText;
    while (getline(inFS, line)) {
        outFS << "<p><b>" << line << "</b><br></p>" << endl;
        // checks if there is a space in the line (if there is its a sentence, if not its a word)
        if (containsSpace(line)) {
            translatedText += "<p><i>" + myTranslator->translateEnglishSentence(line) + "</i><br></p>" + "\n";
        }
        else {
            translatedText += "<p><i>" + myTranslator->translateEnglishWord(line) + "</i><br></p>" + "\n";
        }
    }


    // breaks the line between the original text and the translated text
    outFS << "<p><b></b><br></p>" << endl;

    // outputs the translated text after the original text
    outFS << translatedText;


    // finishes the HTML code
    outFS << "<p><i></i><br></p>" << endl;
    outFS << "</body>" << endl;
    outFS << "</html>" << endl;

    // closes the input and output file streams
    inFS.close();
    outFS.close();


}

bool FileProcessor::containsSpace(string check) {
    // iterates through the line in the file and checks if it is a sentence or a single word based on if it contains a space of not
    for (char c : check) {
        if (c == ' ') {
            return true;
        }
    }
    return false;
}
