#include <vector>
#include <iostream>

class Compare {
private:
	std::vector<Pixel>  iris1;
	std::vector<Pixel>  iris2;
	std::vector<std::vector<int>> color_differences;
	double percent_color_difference;
	bool is_same;
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