#include <vector>
#include <iostream>

using namespace std;

class eyeLibrary {

private:

	vector < vector < vector <Pixel>>> library;

public:

	eyeLibrary() {
	
		count = 0;

		//initialize first dimension of 3d vector to 0, last dimensions are set as 2d pixel
		//array from uploaded picture.

		library(0, vector<vector<Pixel> > &pic);
	}

	void inputPicture(Pixel[][] pic);

	Pixel[][] getPicture();


};

//fucntion definitions either in header of cpp.

//inputPicture function takes in picture that is converted into a 2d pixel array
// and adds it to the 3d vector, which is intended to hold multiple picture arrays.

void eyeLibrary::inputPicture(Pixel[][] pic) {

	//pic is a two dimensional vector of pixels.

	library.push_back(Pixel[][] pic);

}

//fucntion getPicture tranverses the 3d vector and returns a pointer to the first element of the 2d pixel array, which is the converted picture.

Pixel[][] eyeLibrary: getPicture() {

	//need to know what person's pic need to be found in 3d vector.

	vector < vector < vector <Pixel>>>:: iterator x = library.begin();
	vector < vector < vector <Pixel>>>::iterator y = library.begin();

	for (; x != y; x++)
	{  
		String2D::iterator TwoDStart = x->begin();
		String2D::iterator TwoDEnd = y->end();

		for (; TwoDStart != TwoDEnd; TwoDStart++)
		{   
			String1D::iterator ThreeDStart = TwoDStart->begin();
			String1D::iterator ThreeDEnd = TwoDEnd->end();
			for (; ThreeDStart != ThreeDEnd; ThreeDStart++)
			{   

			} 
		} 
	}
}
