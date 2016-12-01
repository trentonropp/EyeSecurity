#include <vector>
#include "Pixel.h"
#include <iostream>

using namespace std;
class Parser {

private:

    vector<vector<Pixel> > picture;
    vector<int> find_Pupil();
public:
	Parser(vector <vector<Pixel> > &pic);
    vector <Pixel> get_Iris_Array(int x, int y, int radius);
};
