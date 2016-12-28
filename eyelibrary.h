#ifndef EYELIBRARY_H
#define EYELIBRARY_H

#include <vector>
#include <iostream>

//include classes Pixel and pictureConvert.

#include "Pixel.h"
#include "pictureConvert.h"

using namespace std;

class eyeLibrary {

private:

	//3D vector that stores each picture file, that consists of a 2D Pixel array.

        vector < vector < vector <Pixel> > > library;

public:

	//member functions of eyeLibrary.

	eyeLibrary();
	
	void inputPicture(string filename);

	vector < vector <Pixel> > getPicture(int x);

};

#endif
