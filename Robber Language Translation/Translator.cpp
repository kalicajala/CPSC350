#include "Translator.h"
#include "Model.h"

Translator::Translator() {
    myModel = new Model(); // myModel created in h file
}

Translator::~Translator() {
    delete myModel; // deallocates memory from this object
}

string Translator::translateEnglishWord(string word) {
    string output;
    string addition;
    // goes through every letter in the word and translates based on if that character is a vowel or consonant
    for (char letter : word) {
        if (isVowel(letter)) {
            addition = myModel->translateSingleVowel(letter);
            output.append(addition);
        }
        else {
            addition = myModel->translateSingleConsonant(letter);
            output.append(addition);
        }
    }
    // returns the fully translated word
    return output;
}

string Translator::translateEnglishSentence(string sentence) {
    string output;
    string addition;
    // iterates through every character in the sentence
    for (char letter : sentence) {
        // checks if there is a space, punctuation, or if character was a number, does not change in the translation
        if (letter == ' ' || isNumber(letter) || isPunctuation(letter)) {
            addition = letter;
            output.append(addition);
        }
        // then checks whether the character is a vowel or consonant
        else if (isVowel(letter)) {
            addition = myModel->translateSingleVowel(letter);
            output.append(addition);
        }
        else {
            addition = myModel->translateSingleConsonant(letter);
            output.append(addition);
        }
    }
    return output;
}

// returns true if the character is a vowel (upper or lowercase)
bool Translator::isVowel(char c) {
    if (c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U') {
            return true;
    }
    return false;
}

// checks if the character was a number, does not change in translation
bool Translator::isNumber(char n) {
    if (n == '0' || n == '1' || n == '2' || n == '3' || n == '4' ||
        n == '5' || n == '6' || n == '7' || n == '8' || n == '9') {
            return true;
    }
    return false;
}

// checks if the character was punctuation, does not change in translation
bool Translator::isPunctuation(char p) {
    if (p == '.' || p == ',' || p == '!' || p == '$' || p == '&' ||
        p == '(' || p == ')' || p == '%' || p == '-' || p == '/' ||
        p == ';' || p == ':') {
            return true;
    }
    return false;
}