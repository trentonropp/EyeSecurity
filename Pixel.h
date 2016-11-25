//
// Created by Jad Zeineddine on 11/24/16.
//

#ifndef PROJECT_RGB_H
#define PROJECT_RGB_H
#endif //PROJECT_RGB_H


#include "StanfordCPPLib/graphics/gbufferedimage.h"
#include "StanfordCPPLib/private/init.h"

class Pixel {

private:

    int red;
    int green;
    int blue;

public:


Pixel colorConverter(int hexValue);

    int getRed();

    int getBlue();


    int getGreen();


    Pixel(int r, int g, int b);

    Pixel();

};