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

void scoreOfWord(string reviewFile);
void averageScoreOfWord(string reviewFile);
void findHighestLowest(string reviewFile);
void sortWords(string reviewFile);

int main(int argc, const char * argv[]) {
    struct wordRating {
        string highestWord;
        float highestAvgRating;
        string lowestWord;
        float lowestAvgRating;
    };
    string reviewFile = "/Users/daniel/Dropbox/sentiment1/sentiment1/sentiment1/movieReviews.txt";
    

    while (true) {
        
        int selectedNum = 0;
        
        cout << "What would yo like to do?" << endl;
        cout << "1: Get the score of a word" << endl;
        cout << "2: Get the average score of words in a file (one word per line)" << endl;
        cout << "3: Find the highest/lowest scoring words in a file" << endl;
        cout << "4: Sort words from a file into positive.txt and negative.txt" << endl;
        cout << "5: Exit the program" << endl;
        cout << "Enter a number 1-5: ";
        cin >> selectedNum;
        
        
        switch (selectedNum) {
            case 1:
                scoreOfWord(reviewFile);
                cout << endl;
                break;
            case 2:
                averageScoreOfWord(reviewFile);
                cout << endl;
                break;
            case 3:                
                findHighestLowest(reviewFile);
                cout << endl;
                break;
            case 4:
                sortWords(reviewFile);
                cout << endl;
                break;
            case 5:
                cout << "Program ended." << endl;
                return 0;
            default:
                break;
        }
    }

}

void scoreOfWord(string reviewFile) {
    string word;
    float totalRating = 0.0;
    int wordCount = 0;
    
    cout << "Enter a word: ";
    cin >> word;
    
    ReviewCalculator calculator(reviewFile);
    calculator.calculate(word);
    totalRating = calculator.getRating();
    wordCount = calculator.getCount();
    
    cout << word << " appears " << wordCount << " times." << endl;
    cout << "The average score for reviews containing the word " << word << " is " << totalRating/wordCount << endl;
    
    
}

void averageScoreOfWord(string reviewFile) {
    string filename;
    cout << "Enter the name of the file with words to find the average score for: ";
    cin >> filename;
    FileCalculator fileCalculator(filename, reviewFile);
    fileCalculator.calculate();
    //    cout << "count : " << fileCalculator.getTotalCount() << endl;
    float avg = fileCalculator.getAverage();
    cout << "The average score of words in " << filename << " is " << avg << endl;
    cout << "The overall sentiment of " << filename << " is " << fileCalculator.getSentiment(avg) << endl;

    
}

void findHighestLowest(string reviewFile) {
    string filename;
    cout << "Enter the name of the file with words to score: ";
    cin >> filename;
    FileCalculator fileCalculator(filename, reviewFile);
    fileCalculator.calculate();
    fileCalculator.findHighestLowest();
    FileCalculator::WordRating wr = fileCalculator.getWordRating();
    cout << "The most positive word, with a score of " << wr.highestAvgRating << " is " << wr.highestWord << endl;
    cout << "The most negative word, with a score of " << wr.lowestAvgRating << " is " << wr.lowestWord << endl;
};
void sortWords(string reviewFile) {
    string filename;
    cout << "Enter the name of the file with words to score: ";
    cin >> filename;
    FileCalculator fileCalculator(filename, reviewFile);
    fileCalculator.calculate();
    fileCalculator.sortWordsBySentiment();
};
