#include "Model.h"

// default constructor
Model::Model() {
    // doesn't output anything
}

// default destructor
Model::~Model() {
    // doesn't output anything
}

string Model::translateSingleConsonant(char consonant) {
    // takes the given consonant and translates it into the form consonant + o + consonant and returns it
    string output;
    output += consonant;
    output += "o";
    output += tolower(consonant); // in case the character was uppercase
    
    return output;
}

string Model::translateSingleVowel(char vowel) {
    // turns the given vowel into a string value and returns it
    string output;
    output += vowel;

    return output;
}