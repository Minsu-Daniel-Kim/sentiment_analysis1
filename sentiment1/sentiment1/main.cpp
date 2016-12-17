//
//  main.cpp
//  sentiment1
//
//  Created by Minsu Kim on 12/16/16.
//  Copyright (c) 2016 Minsu Kim. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include "ReviewCalculator.h"

using namespace std;



int main(int argc, const char * argv[]) {

    string word;
    float totalRating = 0.0;
    int wordCount = 0;
    
    cout << "Enter a word: ";
    cin >> word;
    
    string fileName = "/Users/daniel/Dropbox/sentiment1/sentiment1/sentiment1/movieReviews.txt";
    

    
    ReviewCalculator calculator(fileName);
    calculator.calculate(word);
    totalRating = calculator.getRating();
    wordCount = calculator.getCount();

    cout << word << " appears " << wordCount << " times." << endl;
    cout << "The average score for reviews containing the word " << word << " is " << totalRating/wordCount;
    
    
    
}
