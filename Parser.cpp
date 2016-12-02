#include "Parser.h"
using namespace std;


Parser::Parser(vector <vector<Pixel> > &pic) {
    picture=pic;
    //resize bw
    BWArray.resize(pic.size(),vector<Pixel>(pic[0].size(),Pixel()));

}


void Parser::make_Pupil_BW(){
    for (int i = 0; i< picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
        
            if(picture[i][j].isPrettyBlack(picture[i][j])){
                BWArray[i][j].makeBlack(BWArray[i][j]);
            }
            else{
                BWArray[i][j].makeWhite();
            }
        
        
        }
        
    }
    
}




vector<int> Parser::find_Pupil() {
    vector<int> coordinates;
    //weighted center vector
    vector<vector<int> > a;
    
    //needs to find a circle by some predefined contingincies depending on the width and heigh of image. Basically, image needs to be certain size and the eye must be close enough
    
    
    return coordinates;

}

vector<int> Parser::getWeightedCenter(vector<vector<int> >){
    //error catch more than inner vector of 3 length
    //inner vector should be <number of blacks, j>
    
     //follow algorithm on boogie board
    vector<int> a;
    
    
    
    return a;
}


vector<Pixel> Parser::get_Iris_Array(int x, int y, int radius) {
    vector<Pixel> array;
    
    
    
    
    return array;

}
