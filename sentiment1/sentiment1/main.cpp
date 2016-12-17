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
#include "FileCalculator.h"
using namespace std;



int main(int argc, const char * argv[]) {
    struct wordRating {
        string highestWord;
        float highestAvgRating;
        string lowestWord;
        float lowestAvgRating;
    };
    string reviewFile = "/Users/daniel/Dropbox/sentiment1/sentiment1/sentiment1/movieReviews.txt";
    

    
//    string word;
//    float totalRating = 0.0;
//    int wordCount = 0;
//    
//    cout << "Enter a word: ";
//    cin >> word;
//    
//    
//
//
//    
//    ReviewCalculator calculator(reviewFile);
//    calculator.calculate(word);
//    totalRating = calculator.getRating();
//    wordCount = calculator.getCount();
//
//    cout << word << " appears " << wordCount << " times." << endl;
//    cout << "The average score for reviews containing the word " << word << " is " << totalRating/wordCount << endl;
//    
//    string filename;
//    cout << "Enter the name of the file with words you want to score: ";
//    cin >> filename;
//    FileCalculator fileCalculator(filename, reviewFile);
//    fileCalculator.calculate();
////    cout << "count : " << fileCalculator.getTotalCount() << endl;
//    cout << "The average score of words in " << filename << " is " << fileCalculator.getAverage() << endl;
//    cout << "The overall sentiment of " << filename << " is " << fileCalculator.getSentiment() << endl;
//    fileCalculator.findHighestLowest();
//    FileCalculator::WordRating wr = fileCalculator.getWordRating();
//    cout << wr.highestAvgRating << endl;
//    
//    string filename;
//    cout << "Enter the name of the file with words you want to score: ";
//    cin >> filename;
//    FileCalculator fileCalculator(filename, reviewFile);
//    fileCalculator.calculate();
//    fileCalculator.findHighestLowest();
//    FileCalculator::WordRating wr = fileCalculator.getWordRating();
//    cout << "The most positive word, with a score of " << wr.highestAvgRating << " is " << wr.highestWord << endl;
//    cout << "The most negative word, with a score of " << wr.lowestAvgRating << " is " << wr.lowestWord << endl;
//    
    
}
