//
// Created by Jad Zeineddine on 11/24/16.
//


class Pixel {

private:

    int red;
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
    
    
    
    int getRed();

    int getBlue();


    int getGreen();


    Pixel(int r, int g, int b);

    Pixel();

};
