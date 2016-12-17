//
//  FileCalculator.cpp
//  sentiment1
//
//  Created by Minsu Kim on 12/16/16.
//  Copyright (c) 2016 Minsu Kim. All rights reserved.
//

#include "FileCalculator.h"

FileCalculator::FileCalculator(string file, string reviewfile) {
    
    infile = ifstream("/Users/daniel/Dropbox/sentiment1/sentiment1/sentiment1/" + file);
    reviewFile = reviewfile;
    map <string, float> wordRating;
    wordRatingMap = wordRating;
    

}

void FileCalculator::calculate() {
    
    string line;
    
    float totalRating = 0.0;
    int totalWordCount = 0;
    
    while (getline(infile, line)) {
     

        ReviewCalculator calculator(reviewFile);
        calculator.calculate(line);
        totalWordCount = calculator.getCount();
        totalRating = calculator.getRating();
        
        wordRatingMap[line] += totalRating / totalWordCount;
    }
    
}
FileCalculator::WordRating FileCalculator::getWordRating() {
    return wordRating;
}


void FileCalculator::findHighestLowest() {
    
    WordRating wr;
    wr.highestAvgRating = 0;
    wr.lowestAvgRating = INT_MAX;
    
    map<string, float>::iterator it;
    
    for (auto const& x : wordRatingMap)
    {
        string key = x.first;
        float value = x.second;
        if (value > (wr.highestAvgRating)) {
            wr.highestAvgRating = value;
            wr.highestWord = key;
        }
        
        if (value < (wr.lowestAvgRating)) {
            wr.lowestAvgRating = value;
            wr.lowestWord = key;
        }
    }
    
    wordRating = wr;
}

int FileCalculator::getTotalCount() {
    return wordRatingMap.size();
}

float FileCalculator::getTotalRating() {
    totalRating = 0;
    map<string, float>::iterator it;
    
    for (auto const& x : wordRatingMap)
    {

        totalRating += x.second;
    }
    
    
    return totalRating;
}

string FileCalculator::getSentiment() {
    
    float average = getAverage();
    if (average > 2.01) {
        return "positive";
    } else if (average < 1.99) {
        return "negative";
    } else {
        return "neutral";
    }
    
    
    
}

float FileCalculator::getAverage() {
    return getTotalRating() / getTotalCount();
}
