//
// Created by Jad Zeineddine on 11/24/16.
//

#include "pictureConvert.h"



using namespace std;

    pictureConvert::pictureConvert() {

        int x = 0;

    }


vector <vector<Pixel> >pictureConvert::decodeOneStep(const char* filename)
{
    
    

    
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;
    
    
    
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
 
    for(unsigned long int i = 0, j = 0; i < width*height && j < height; j++, i++){
        
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

int main(){
    
    
    
    
}


