#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

using namespace std;

class Model {
    public:
        Model(); // constructor
        ~Model(); // destructor
        
        // takes in consonant/vowel and returns the corrosponding encoding
        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);
    
    private:
};

#endif