#include <vector>
#include <iostream>
#include "Pixel.h"

class Compare {
private:
	/*
	/* These data fields are the arrays of pixels for the two eyes to be compared
	/* and the array of diferences in color between them
	*/
	std::vector<Pixel>  iris1;
	std::vector<Pixel>  iris2;
	std::vector<std::vector<int>> color_differences;

	//the percentage color difference between the eyes
	double percent_color_difference;

	//whether or not the eyes are determined to be the same
	bool is_same;

	void Cut_Array_Ends();
	void equalize_Arrays();
	void correct_Brightness_Differences();
		std::vector<double> Compare_Pixel_Brightness(Pixel p1, Pixel p2);
		double get_Brightness_diff_percentage(double x, double y);
		bool is_brightness_diff(double x, double y, double z);

	std::vector<std::vector<int>> find_Pattern_Differences();
	void find_Percent_Similarity();
public:
	Compare(std::vector<Pixel> iris1, std::vector<Pixel> iris2);
	void is_same_person();

};
