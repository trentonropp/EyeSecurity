//
// Created by Jad Zeineddine on 11/24/16.
//

#ifndef PROJECT_PICTURECONVERT_H
#define PROJECT_PICTURECONVERT_H

#include <vector>
#include "Pixel.h"
#include <string>
#include "lodepng.h"
#include <iostream>

using namespace std;

class pictureConvert {

    pictureConvert();
    vector <vector<Pixel> >decodeOneStep(const char* filename);

};


#endif //PROJECT_PICTURECONVERT_H
