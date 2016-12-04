

#include "Pixel.h"

using namespace std;
Pixel Pixel::colorConverter(int hexValue)
{
    Pixel trenton;

    trenton.red = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
    trenton.green = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG bytez
    trenton.blue = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

    return trenton;
}



int Pixel::getRed(){
    //cout<< "returned red" << endl;
return red;
}

int Pixel::getBlue(){
return blue;
}

int Pixel::getGreen(){
return green;
}

//if the Pixel is nearly black but not entirely
bool Pixel::isPrettyBlack(){
    int variance = 20;

    Pixel p=*this;
    if (    abs(  p.getGreen() - p.getBlue()  )<variance    &&   abs(  p.getBlue() - p.getRed()  )<variance  &&  abs(  p.getGreen() - p.getRed()  )<variance   && ( p.getBrightness()<45 )    ) {
    return true;
    }
    else
        return false;
}


//if the pixel is entirely black
bool Pixel::isActuallyBlack(){
    //Pixel p = *this;
    if(getBrightness()<3){
        //cout<< "works"<< endl;

    return true;
    }

    else {
        return false;
    }
}

bool Pixel::isPrettyWhite(){
    int variance = 50;

    Pixel p=*this;
    if (    abs(  p.getGreen() - p.getBlue()  )<variance    &&   abs(  p.getBlue() - p.getRed()  )<variance  &&  abs(  p.getGreen() - p.getRed()  )<variance   && ( p.getBrightness()>70)    ) {
        return true;
    }
    else
        return false;
}

bool Pixel::isPrettySclera(){
    int variance = 5;

    Pixel p=*this;
    if (    (p.getRed()-p.getGreen())> variance && (p.getRed()-p.getBlue()) >variance && ( p.getBrightness()>65)    ) {
        return true;
    }
    else
        return false;
}

void Pixel::makeBlack(){
    Pixel p=*this;
    p.setBlue(0);
    p.setGreen(0);
    p.setBlue(0);
}

void Pixel::makeWhite(){

    this->red=255;
    this->blue=255;
    this->green=255;
}


void Pixel::brighten(Pixel &x, double factor){

    factor = 1/factor;
    x.red=(int)((double)x.red*factor);
    x.blue=(int)((double)x.blue*factor);
    x.green= (int)((double)x.green*factor);

    return;
}

int Pixel::getBrightness(){
    int i = (int)(((double)getRed()+(double)getGreen()+(double)getBlue())/3);
    return i;
}

Pixel::Pixel(int r, int g, int b) {
    red=r;
    green=g;
    blue=b;
}


Pixel::Pixel() {

    red= 0;
    green= 0;
    blue=0;

}
