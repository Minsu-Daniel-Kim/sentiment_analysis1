//
//  ReviewCalculator.h
//  sentiment1
//
//  Created by Minsu Kim on 12/16/16.
//  Copyright (c) 2016 Minsu Kim. All rights reserved.
//

#ifndef __sentiment1__ReviewCalculator__
#define __sentiment1__ReviewCalculator__

#include <set>
#include <utility>
#include <stdio.h>
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class ReviewCalculator {
    
    public:
        ReviewCalculator(string file);
        ReviewCalculator();
        int getCount();
        int getRating();
        void findHighestLowest();
    
        void calculate(string word);
    
    private:
        ifstream infile;
        int rating = 0;
        int wordCount = 0;
    
    
};


#endif /* defined(__sentiment1__ReviewCalculator__) */
