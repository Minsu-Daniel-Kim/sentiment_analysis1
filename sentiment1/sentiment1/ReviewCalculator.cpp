//
//  ReviewCalculator.cpp
//  sentiment1
//
//  Created by Minsu Kim on 12/16/16.
//  Copyright (c) 2016 Minsu Kim. All rights reserved.
//

#include "ReviewCalculator.h"

using namespace std;


ReviewCalculator::ReviewCalculator(string file) {
    
    infile = ifstream(file);
    
}
int ReviewCalculator::getRating() {
    return rating;
}

int ReviewCalculator::getCount() {
    return wordCount;
}

void ReviewCalculator::calculate(string word) {
    
    
    string line;

    while (getline(infile, line)) {
        std::set<string> myset;
        int tokenCount = 0;
        int rate = 0;
        bool isContain = false;
        istringstream iss(line);
        string token;

        while(iss >> token) {
    
            if (tokenCount == 0) {
                rate = stoi(token);
            } else {
//                std::transform(token.begin(), token.end(), token.begin(), ::tolower);
                if (token.find(word) != string::npos) {
                    myset.insert(word);
                    isContain = true;

                }
        
            }
            

        
            tokenCount++;
                
        }
        if (isContain) {
            rating += rate;
        }
        wordCount += myset.size();

        
    }


    
}