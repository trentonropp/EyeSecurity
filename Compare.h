#include <vector>
#include <iostream>

class Compare {
private:
	Pixel[] * iris1;
	Pixel[] * iris2;
	void equalize_Arrays();
	double find_Brightness_Differences();
	std::vector<int> find_Pattern_Differences();
	double find_Percent_Similarity();
public:
	Compare(Pixel[] &iris1, Pixel[] &iris2);
	bool is_same_person();

};