#include <vector>
#include <iostream>

class Compare {
private:
	std::vector<Pixel>  iris1;
	std::vector<Pixel>  iris2;
	void equalize_Arrays();
	double find_Brightness_Differences();
	std::vector<int> find_Pattern_Differences();
	double find_Percent_Similarity();
public:
	Compare(std::vector<Pixel> iris1, std::vector<Pixel> iris2);
	bool is_same_person();

};