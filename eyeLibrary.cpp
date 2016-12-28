
#include "eyelibrary.h"
using namespace std;



//fucntion definitions either in header of cpp.

//inputPicture function takes in picture that is converted into a 2d pixel array
// and adds it to the 3d vector, which is intended to hold multiple picture arrays.

eyeLibrary::eyeLibrary(){
}

        void eyeLibrary::inputPicture(string filename){
           pictureConvert picCon;
           vector<vector<Pixel> > a = picCon.decodeOneStep(filename.c_str());
           library.push_back(a);
        }

        vector < vector <Pixel> > eyeLibrary::getPicture(int x){

          return library[x];

        }
