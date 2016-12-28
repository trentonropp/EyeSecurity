//
// Created by Jad Zeineddine on 11/24/16.
//

#ifndef PROJECT_PICTURECONVERT_H
#define PROJECT_PICTURECONVERT_H

#include <vector>
#include <string>
#include "lodepng.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Compare.h"

#include "Pixel.h"


using namespace std;

class pictureConvert {
public:
    pictureConvert();
    vector <vector<Pixel> >decodeOneStep(const char* filename);
    void display(vector<vector<Pixel> > picture );
};


#endif //PROJECT_PICTURECONVERT_H
