#include <vector>
#include <iostream>

#include "Pixel.h"

using namespace std;
class Parser {

private:


    void makePupilBW();
    vector<int> findPupil();
    vector<int> getWeightedCenter(vector<vector<int> >, int bound);
    int largestPupilRadius = 0;
    int minRadius;
    int varianceInRadius;
    int getUpRadius(int i , int j );
    int getDownRadius(int i , int j);
    int getLeftRadius(int i, int j);
    int getRightRadius(int i , int j);
    bool isLargestRadius(vector<int> radii);
    bool isCircularEnough(vector<int> radii);
    bool isLargeEnough(vector<int> radii);
    int getAvg(vector<int> radii);
    int pupilI=0;
    int pupilJ=0;
    vector<int> getRadiusVector(int i, int j);
    int getLeftEdgeCoordinates();

public:
    vector<vector<Pixel> > picture;
    vector<vector <Pixel> > BWArray;
	Parser(vector <vector<Pixel> > &pic);
    vector <Pixel> getIrisArray();
};
