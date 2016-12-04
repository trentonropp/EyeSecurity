#include "Compare.h"
#include <iterator>
#include <math.h>

//the constructor will call all of the methodw
Compare::Compare(std::vector<Pixel> iris1,std::vector<Pixel> iris2) {
	equalize_Arrays();
	correct_Brightness_Differences();
	color_differences = find_Pattern_Differences();
	find_Percent_Similarity();
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
		diff_1 = abs(iris1[i].getRed() - iris2[i].getRed());
		diff_2 = abs(iris1[i].getGreen() - iris2[i].getGreen());
		diff_3 = abs(iris1[i].getBlue() - iris2[i].getBlue());
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
