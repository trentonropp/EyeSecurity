#include <vector>
#include "Pixel.h"
#include <iostream>

using namespace std;
class Parser {

private:
    vector<vector <Pixel> > BWArray;
    vector<vector<Pixel> > picture;
    void make_Pupil_BW();
    vector<int> find_Pupil();
    vector<int> getWeightedCenter(vector<vector<int> >);

    
public:
	Parser(vector <vector<Pixel> > &pic);
    vector <Pixel> get_Iris_Array(int x, int y, int radius);
};
