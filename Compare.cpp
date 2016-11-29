#include "Compare.h"
#include <iterator>
#include <math.h>

//the constructor will call all of the methodw
Compare::Compare(Pixel[] & iris1, Pixel[] & iris2) {

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
}


double Compare::find_Brightness_Differences() {

}

//returns an inte difference for each pixel in the arrays
std::vector<int> Compare::find_Pattern_Differences() {
	std::vector<int> result;
	for (int i = 0; i < iris1.size(); i++) {
		int diff_1, diff_2, diff_3;
		diff_1 = iris1[i].getR() - iris2[i].getR();
		diff_2 = iris1[i].getG() - iris2[i].getG();
		diff_3 = iris1[i].getB() - iris2[i].getB();
		result[i] = diff_1 + diff_2 + diff_3; 
	}
	return result; 
}


double Compare::find_Percent_Similarity() {

}


bool Compare::is_same_person() {

}