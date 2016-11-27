#include <vector>

class Parser {
private:
	int pupil_X;
	int pupil_Y;
	int pupil_Z;
	Pixel[][] pic;
	std::vector<int> find_Pupil();
public:
	Parser(Pixel[][] &pic);
	*Pixel[] get_Iris_Array(int x, int y, int radius);
};
