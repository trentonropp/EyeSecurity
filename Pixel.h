//
// Created by Jad Zeineddine on 11/24/16.
//

#include <cmath>
#include <iostream>
#include "stdlib.h"
#pragma once

class Pixel {

private:

    int red=0;
    int green;
    int blue;

public:


Pixel colorConverter(int hexValue);

    void setRed(int x){
        red=x;
    }
    
    
    void setGreen(int x){
        green=x;
    }
    
    void setBlue(int x){
        blue=x;
    }
    
    bool isPrettyBlack();
    
    bool isPrettySclera();
    
    bool isActuallyBlack();
    
    
    bool isPrettyWhite();
    
    void makeBlack();
    void makeWhite();
    
    int getRed();

    int getBlue();


    int getGreen();

    int getBrightness();

    void brighten(Pixel &x, double factor);

    Pixel(int r, int g, int b);

    Pixel();

};
