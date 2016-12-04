//
// Created by Jad Zeineddine on 11/24/16.
//


#include "pictureConvert.h"
#include <fstream>
#include <stdio.h>
#include "parser.h"


using namespace std;

    pictureConvert::pictureConvert() {


    }


vector <vector<Pixel> >pictureConvert::decodeOneStep(const char* filename)
{
    
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;
    
    
    cout<< "started Initial Decode"<< endl;
    //decode
    unsigned error = lodepng::decode(image, width, height, filename);
    
    const int x= width;
    const int y= height;

    //vector to hold Pixels before combining into a 2d array.
    vector<Pixel> tempArray;
    tempArray.resize(x*y,Pixel());
    
    //vector to be returned
    vector <vector<Pixel> >  array;
    
    //make the right size
    array.resize(y,vector<Pixel>(x,Pixel()));
    
    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    
    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
    clock_t t1,t2;
    t1=clock();
    
    
    for (int i = 0; i< (width*height); i++) {
        //cout<< image[i] << endl;
        //cout << "brightness at  "<< i << " = " << tempArray[i].getBrightness() << endl;
    }
 
    cout<< "started RGBH to Pixel"<< endl;
    //takes the rgb and buts it into Pixel Pixel Pixel array
    for(unsigned long int i = 0, j = 0; i < (width*height*4) && j < width*height; j++, i++){
        
        if((i+1)%4==1){
            tempArray[j].setRed(image[i]);
            
            i++;
        }
        if((i+1)%4==2){
            
            tempArray[j].setGreen(image[i]);
            i++;
            
        }
        if((i+1)%4==3){
            
            tempArray[j].setBlue(image[i]);
            i++;
            
        }
        
    }
    
    cout<< "width is " << width << " and the height is " << height<< " so the product is "<< width*height <<endl;
    for (int i = 0; i< (width*height); i++) {
        //cout << "brightness at  "<< i << " = " << tempArray[i].getBlue() << endl;
    }
    
    cout<< "started Pixel to 2dPixel"<< endl;
    
    //debug
    //this method puts the 1d vector into 2d
    for (int i = 0, j = 0; i< width*height && j < height; i++) {
        array[j][i%width] = tempArray[i];
        
        if((i+1)%width==0){
            j++;
        }
    }
    
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    std::cout<<"Time Taken to decode: "<<diff/CLOCKS_PER_SEC<< " seconds" <<std::endl;
    
    return array;
    
    
}

void pictureConvert::display(vector<vector<Pixel> > picture ){
    int height  = picture.size();
    int width = picture[0].size();
    
    
    ofstream img ("pic.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;
    
    for (int y = 0; y< height; y++) {
        for (int x = 0; x < width; x++) {
            int r = picture[y][x].getRed();
            int g = picture[y][x].getGreen();
            int b = picture[y][x].getBlue();
            
            img << r << " " << g << " " << b <<endl;
        }
    }
    
    system("open pic.ppm");
    return;
    
}


int main(){
    
    cout<< "Running..."<< endl;
    const char* filename = "/Users/Jado/Pictures/Jad.png";
    
    pictureConvert a;
    vector <vector<Pixel> > dog = a.decodeOneStep(filename);
    
    Parser pa(dog);
    cout<< "here" << endl;
    vector<Pixel> irisArray = pa.getIrisArray();
    for (int i = 0; i < irisArray.size(); i++) {
        for (int j = 0; j < 20; j++) {
            pa.BWArray[i][j]=irisArray[i];
        }
        
    }
    
    for (int m = 660; m<850; m++) {
    
    cout<<"[" << m << "]   "<< "red is " <<  pa.picture[540][m].getRed()<< " Green is "<< pa.picture[540][m].getGreen() <<"  blue is "<<pa.picture[540][m].getBlue() << " and brightness is " << pa.picture[540][m].getBrightness() << endl;
    }
    a.display(pa.BWArray);
}

