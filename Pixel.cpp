

#include "Pixel.h"


Pixel Pixel::colorConverter(int hexValue)
{
    Pixel trenton;

    trenton.red = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
    trenton.green = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG bytez
    trenton.blue = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

    return trenton;
}



int Pixel::getRed(){
return red;
}

int Pixel::getBlue(){
return blue;
}

int Pixel::getGreen(){
return green;
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

int main(){
  return 0;
}
