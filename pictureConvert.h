//
// Created by Jad Zeineddine on 11/24/16.
//

#ifndef PROJECT_PICTURECONVERT_H
#define PROJECT_PICTURECONVERT_H

#include <vector>
#include "StanfordCPPLib/graphics/gbufferedimage.h"
#include "StanfordCPPLib/private/init.h"

class pictureConvert {

    pictureConvert();

    vector<vector<rgb> > PixelArray(string filename);

};


#endif //PROJECT_PICTURECONVERT_H
