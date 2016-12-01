#include "Compare.h"
#include <iterator>
#include <math.h>

//the constructor will call all of the methods
Compare::Compare(Pixel[] & iris1, Pixel[] & iris2) {

	/* adjusts sizes of arrays to be
	proportionally equal to the smallest array */
	equalize_Arrays();

	/* equalise brightness difference in image arrays due to exposures
	abnormalities*/
	correct_Brightness_Differences();

	/* TODO this gonna change when akis fixes stuff */
	color_differences = find_Pattern_Differences();

	/* main authentication function to find degree of eye similarity to
	"control" */
	find_Percent_Similarity();

	/* function to determine if the eyes are similar -- the boolean is a
	data field called is_same */
	is_same_person();
}




void Compare::equalize_Arrays() {
	std::vector<Pixel> bigger_Array;
	std::vector<Pixel> smaller_Array;
	if (iris1.size() > iris2.size()) {
		bigger_Array = iris1;
		smaller_Array = iris2;
	}
	else {
		bigger_Array = iris2;
		smaller_Array = iris1;
	}
	int diff = bigger_Array.size() - smaller_Array.size();
	int jump_size = bigger_Array.size() / diff;
	for (int i = 0; i < bigger_Array.size(); i++) {
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


void Compare::correct_Brightness_Differences() {
	return;
}

//returns an inte difference for each pixel in the arrays
std::vector<int> Compare::find_Pattern_Differences() {
	std::vector<int> result;
	for (int i = 0; i < iris1.size(); i++) {
		int diff_1, diff_2, diff_3;
		diff_1 = abs(iris1[i].getR() - iris2[i].getR());
		diff_2 = abs(iris1[i].getG() - iris2[i].getG());
		diff_3 = abs(iris1[i].getB() - iris2[i].getB());
		result[i] = diff_1 + diff_2 + diff_3;
	}
	return result;
}


void Compare::find_Percent_Similarity() {
	const double MAX_DIFF_VALUE = 3 * 252;
	double result;
	std::vector<double> percent_color_diff;
	for (int i = 0; i < color_differences.size(); i++) {
		percent_color_diff[i] = color_differences[i] / MAX_DIFF_VALUE;
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
