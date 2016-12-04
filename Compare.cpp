#include "Compare.h"
#include <iterator>
#include <math.h>

//the constructor will call all of the methods
Compare::Compare(std::vector<Pixel> iris1, std::vector<Pixel> iris2) {
	Cut_Array_Ends();
	equalize_Arrays();
	correct_Brightness_Differences();
	color_differences = find_Pattern_Differences();
	find_Percent_Similarity();
	is_same_person();
}

/*
this method will cut the array sizes down by a specific percentage
*/
void Compare::Cut_Array_Ends() {
	int size1 = iris1.size();
	int size2 = iris2.size();
	double size1_cut_amt = (double)size1 / 40;
	double size2_cut_amt = (double)size2 / 40;

	for (int i = 0; i < size1_cut_amt; i++) {
		iris1.erase(iris1.begin());
	}
	for (int i = 0; i < size1_cut_amt; i++) {
		iris1.erase(iris1.end());
	}

	for (int i = 0; i < size2_cut_amt; i++) {
		iris2.erase(iris2.begin());
	}
	for (int i = 0; i < size2_cut_amt; i++) {
		iris2.erase(iris2.end());
	}

	return;
}

void Compare::equalize_Arrays() {
	std::vector<Pixel> bigger_Array;
	std::vector<Pixel> smaller_Array;

	if (iris1.size() > iris2.size()) 
	{
		bigger_Array = iris1;
		smaller_Array = iris2;
	}
	else 
	{
		bigger_Array = iris2;
		smaller_Array = iris1;
	}

	int diff = bigger_Array.size() - smaller_Array.size();
	int jump_size = bigger_Array.size() / diff;

	int size = bigger_Array.size();
	for (int i = 0; i < size; i++) {
		if (i % jump_size == 0) {
			bigger_Array.erase(bigger_Array.begin() + i);
		}
	}
	if (iris1.size() > iris2.size()) {
		iris1 = bigger_Array;
	}
	else {
		iris2 = bigger_Array;
	}
	return;
}

std::vector<double> Compare::Compare_Pixel_Brightness(Pixel p1, Pixel p2) {
	std::vector<double> result;

	result[0] = (double)p1.getR() / (double)p2.getR();
	result[1] = (double)p1.getG() / (double)p2.getG();
	result[2] = (double)p1.getB() / (double)p2.getB();

	return result;

}

double Compare::get_Brightness_diff_percentage(double x, double y) {
	double min;
	if (x > y) {
		min = y;
	}
	else {
		min = x;
	}
	return abs( (x - y) / (min) );
}

bool Compare::is_brightness_diff(double x, double y, double z) {
	return get_Brightness_diff_percentage(x, y) < 0.15 && get_Brightness_diff_percentage(y, z) < 0.15 && get_Brightness_diff_percentage(x, z) < 0.15;
}


void Compare::correct_Brightness_Differences() {
	std::vector<double> comparison;
	int comparison_percentage;
	int pixel_avg;
	bool is_same_color = false;
	for (int i = 0; i < iris1.size(); i++) {
		comparison = Compare_Pixel_Brightness(iris1[i], iris2[i]);
		if (is_brightness_diff(comparison[0], comparison[1], comparison[2])) {
			is_same_color = true;
			continue;
		}
		pixel_avg = (comparison[1] + comparison[2] + comparison[3]) / 3;
		if (iris1[i]->getBrightness() > iris2[i]->getBrightness()) {
			iris2[i]->Brighten(pixel_avg);
		}
		else {
			iris1[i]->Brighten(pixel_avg);
		}
	}

	return;
}

//returns an inte difference for each pixel in the arrays
std::vector<std::vector<int>> Compare::find_Pattern_Differences() {
	std::vector<std::vector<int>> result;
	for (int i = 0; i < iris1.size(); i++) {
		int diff_1, diff_2, diff_3;
		result[i][0] = abs(iris1[i].getR() - iris2[i].getR());
		result[i][1] = abs(iris1[i].getG() - iris2[i].getG());
		result[i][2] = abs(iris1[i].getB() - iris2[i].getB());
	}
	return result; 
}


void Compare::find_Percent_Similarity() {
	const double MAX_DIFF_VALUE = 252*3; 
	double result;
	std::vector<double> percent_color_diff;
	for (int i = 0; i < color_differences.size(); i++) {
		percent_color_diff[i] = color_differences[i][0] + color_differences[i][1] + color_differences[i][2] / MAX_DIFF_VALUE;
		result += percent_color_diff[i];
	}
	percent_color_difference = result/percent_color_diff.size();
	return;
}


void Compare::is_same_person() {
	//10% is arbitrary, we can change it depending on how our tests go
	if (percent_color_difference > 0.10 ) {
		is_same = true;
	}
	else is_same = false;
	return;
}
