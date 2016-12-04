#include <vector>
#include <iostream>


#include "Pixel.h"

class Compare {
private:
	std::vector<Pixel>  iris1;
	std::vector<Pixel>  iris2;
	std::vector<int>  color_differences;
	double percent_color_difference;
	bool is_same;
	void equalize_Arrays();
	void correct_Brightness_Differences();
	std::vector<int> find_Pattern_Differences();
	void find_Percent_Similarity();
public:
	Compare(std::vector<Pixel> iris1, std::vector<Pixel> iris2);
	void is_same_person();

};
