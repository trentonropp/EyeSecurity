#include "Parser.h"
using namespace std;


Parser::Parser(vector <vector<Pixel> > pic) {
    picture=pic;
    //resize bw
    BWArray.resize(pic.size(),vector<Pixel>(pic[0].size(),Pixel()));
    makePupilBW();

}


void Parser::makePupilBW(){
    
    
    for (int i = 0; i< picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
        
            if(picture[i][j].isPrettyBlack()){
                BWArray[i][j].makeBlack();
            }
            else{
                BWArray[i][j].makeWhite();
            }
        
        
        }
        
    }
    
}




vector<int> Parser::findPupil() {
    vector<int> coordinates;
    //weighted center vector, may not need to do this
    vector<vector<int> > a;
    //change this for pupil circularity
    double varianceInRadiusValue=.04;
    //change this for pupil size
    double varianceInSize = .05;
    //minumim circularity
    varianceInRadius = varianceInRadiusValue*BWArray.size();
    //minimum size of pupil
    minRadius = (int) ((double)varianceInSize*((double)BWArray.size()/2));
    int saveI = 0;
    int saveJ = 0;
    
    
    //cout<< "finding pupil" << endl;
    
    vector <int> radii;
    for (int i = 0; i < BWArray.size(); i++) {
        for (int j = 0; j < BWArray[0].size(); j++) {
            if (BWArray[i][j].isActuallyBlack()) {
                radii = getRadiusVector(i, j);
                //cout<< "is circular " << isCircularEnough(radii) << "  is it largest? " << isLargestRadius(radii) <<  "   and is it large enough ? " << isLargeEnough(radii) << endl;
                if(isCircularEnough(radii)  && isLargestRadius(radii) && isLargeEnough(radii)){
                    saveI=i;
                    saveJ=j;
                    
                }
            }
        }
    }
    
    cout<< "min radius is " << minRadius<< endl;
    cout<< "largestPupilRadius is " << largestPupilRadius<< endl;
    
    cout<< "I is " << saveI << endl;
    cout<< "J is " << saveJ << endl;
    
    if (largestPupilRadius<minRadius) {
        cout<< "error Pupil not large enough"<< endl;
    }
    
    //could be reversed?
    coordinates.push_back(saveI);
    coordinates.push_back(saveJ);
    pupilJ=saveJ;
    pupilI=saveI;
    
    
    //needs to find a circle by some predefined contingincies depending on the width and heigh of image. Basically, image needs to be certain size and the eye must be close enough
    
    
    return coordinates;

}



int Parser::getUpRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack()  && i > 0; i--) {
        radCounter++;
        //cout<< "radcounter = "<<radCounter<< endl;
    }
    
    return radCounter;
}

int Parser::getDownRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); i++) {
        radCounter++;
    }
    
    return radCounter;
}


int Parser::getRightRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); j++) {
        radCounter++;
    }
    
    return radCounter;
}




int Parser::getLeftRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); j--) {
        radCounter++;
    }
    
    return radCounter;
}


vector<int> Parser::getRadiusVector(int i, int j){
    
    vector<int> a;
    
    //you dont have to use RightRadiusm
    int radiusToAdd = getUpRadius(i, j);
    //cout<< "radius to add = " << radiusToAdd<< endl;
    a.push_back(radiusToAdd);
    radiusToAdd = getDownRadius(i, j);
    a.push_back(radiusToAdd);
    radiusToAdd = getLeftRadius(i, j);
    a.push_back(radiusToAdd);
    radiusToAdd = getRightRadius(i, j);
    a.push_back(radiusToAdd);

    
    return a;
}

/**
 Largest Radius returns if the value is the largest radius
 */
bool Parser::isLargestRadius(vector<int> radii){
    int r = getAvg(radii);
    if( r >= largestPupilRadius){
        
        largestPupilRadius = r;
        return true;
    }
    
    return false;
}




/**
 checks if all the radii are more than the minimum pupil size
 */
bool Parser::isLargeEnough(vector<int> radii){
    for (int i = 0; i<radii.size(); i++) {
        if( i > minRadius)
            return false;
    }
    
    return true;
}

bool Parser::isCircularEnough(vector<int> radii){
    
    for (int i = 0; i+1 < radii.size() ; i++) {
        if(abs(radii[i]-radii[i+1]) > varianceInRadius)
            return false;
    }
    
    return true;
    
}


int Parser::getAvg(vector<int> radii){
    int sum=0;
    int i=0;
    for(; i < radii.size(); i++){
        sum+=radii[i];
    }
    return (int)(((double)sum/(double)i));
}

vector<int> Parser::getWeightedCenter(vector<vector<int> > b, int bound){
    //error catch more than inner vector of 3 length
    //inner vector should be <number of blacks, j>
    int heightCenter = 0;
    int widthCenter=0;
     //follow algorithm on boogie board
    int topSum = 0;
    int bottomSum = 0;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            topSum +=( b[i][0] * b[i][1] );
            bottomSum+= b[i][0];
        }
    }
    heightCenter= (int) (((double)topSum) / ((double)bottomSum));
    
    
    widthCenter= b[heightCenter][0]/2+bound;
    
    
    

    

    vector<int> a;
    a[0]=heightCenter;
    a[1]=widthCenter;
    
    
    
    
    return a;
}

int Parser::getLeftEdgeCoordinates(){
    
    int j = pupilJ;
    
    for(; BWArray[pupilI][j].isActuallyBlack(); j--){
        
    }
    
    cout<< "left edge j = " << j<< endl;
    
    return j;
}


vector<Pixel> Parser::getIrisArray() {
    //Add a method to this that adjusts brightness based on pupil and iris size (while loop until correct iris size);
    
    vector<Pixel> array;
    
    findPupil();
    
    cout<< " getLeftEdgeCoordinates is " << getLeftEdgeCoordinates() << endl;
    
    for(int i = getLeftEdgeCoordinates(); !picture[pupilI][i].isPrettySclera(); i--){
        array.push_back(picture[pupilI][i]);
    }
    
    
    return array;

}
