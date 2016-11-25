//
// Created by Jad Zeineddine on 11/24/16.
//

#include "pictureConvert.h"



using namespace std;

    pictureConvert::pictureConvert() {

        int x = 0;

    }


    vector <vector<rgb> > PictureConvert::PixelArray(string filename) {

        GBufferedImage img;
        img.load(filename);

        GRectangle x = img.getBounds();
        int height = (int) x.getHeight();
        int width = (int) x.getWidth();
        vector <vector<rgb> > array[height][width];
        rgb pixel();

        for(int i = 0; i < height; i++){
            for(int j = 0; J<width; j++){

                array[i][j]=pixel.colorConverter(img.getRGB(i,j));;

            }

        }

        return array;
    }
/*

int main(){

    string file = "Iris.jpg";
    pictureConvert a;
    vector< vector <rgb> > vector1 = a.PixelArray(file);

    for (int i = 0; i < vector1.size(); ++i) {
        for (int j = 0; j < vector1[i].size(); ++j) {
            cout<<"(Red =  "<< vector1[i][j].getRed() << ", Green = " << vector1[i][j].getGreen() << ", Blue= " <<
                vector1[i][j].getBlue() << ")"<< endl;
        }

    }




}
*/
