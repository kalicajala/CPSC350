#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include "Model.h"


// add pointer to model in here and in cpp file
using namespace std;

class Translator : public Model{
    public: 
        Translator(); // constructor
        ~Translator(); // destructor
       
        // translates given word/sentence
        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);

        // helper functions
        bool isVowel(char c); // checks if a character is a vowel
        bool isNumber(char n); // checks if a character is a number, won't be translated if so
        bool isPunctuation(char p); // checks if a character is punctuation, won't be translated if so

    private:
        Model *myModel; // pointer object to the Model class so we can use it's functions
};

#endif