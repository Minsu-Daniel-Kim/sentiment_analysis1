//
//  FileCalculator.h
//  sentiment1
//
//  Created by Minsu Kim on 12/16/16.
//  Copyright (c) 2016 Minsu Kim. All rights reserved.
//

#ifndef __sentiment1__FileCalculator__
#define __sentiment1__FileCalculator__

#include "ReviewCalculator.h"
#include <stdio.h>
#include <set>
#include <map>
#include <utility>
#include <stdio.h>
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;


class FileCalculator {
    
    public:
        struct WordRating {
            string highestWord;
            float highestAvgRating;
            string lowestWord;
            float lowestAvgRating;
        };
    
    public:

        FileCalculator(string file, string reviewFile);
        int getTotalCount();
        float getTotalRating();
        void calculate();
        string getSentiment(float ratings);
        float getAverage();
        WordRating getWordRating();
        void sortWordsBySentiment();
        void findHighestLowest();
        void writeFile();
    
    private:
        WordRating wordRating;
        float highestAvgRating = 0;
        float lowestAvgRating = INT_MAX;
        string highestWord;
        string lowestWord;
        ifstream infile;
    
        float totalRating = 0;
        int totalWordCount = 0;
        string reviewFile;
        map <string, float> wordRatingMap;

    

    
};

#endif /* defined(__sentiment1__FileCalculator__) */
