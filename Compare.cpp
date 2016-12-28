#include "Compare.h"
#include <iterator>
#include <math.h>

//the constructor will call all of the methodw
Compare::Compare(std::vector<Pixel> iris1,std::vector<Pixel> iris2) {
    this->iris1=iris1;
    this->iris2=iris2;
    
    //These methods actually do the comparison
    equalize_Arrays();
    correct_Brightness_Differences();
    color_differences = find_Pattern_Differences();
    find_Percent_Similarity();
    is_same_person();
    std::cout << "\nPercent difference: " << percent_color_difference << std::endl;
}



//this method makes the two arrays the same size, for ease of comparison
void Compare::equalize_Arrays() {
    //first it determines which array is larger, using the following code
    std::vector<Pixel> bigger_Array;
    std::vector<Pixel> smaller_Array;
    
    std::cout<< "iris size1 = " << iris1.size() << std::endl;
    std::cout<< "iris size2 = " << iris2.size() << std::endl;
    
    if (iris1.size() > iris2.size()) {
        bigger_Array = iris1;
        smaller_Array = iris2;
    }
    else {
        bigger_Array = iris2;
        smaller_Array = iris1;
    }
    
    int diff = bigger_Array.size() - smaller_Array.size();
    //in order to reduces the size, one pixel is cut from the larger array every set amount of distance
    int jump_size = bigger_Array.size() / diff;
    
    
    //this iterates through the vector
    for (int i = 0; i < bigger_Array.size(); i++) {
        //if the jump distance has been traveled, remove that pixel
        if (i % jump_size == 0) {
            bigger_Array.erase(bigger_Array.begin() + i);
        }
    }
    
    
    
    //puts the shortened larger array back in place of the old one
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

//returns an integer difference for each pixel in the arrays
std::vector<int> Compare::find_Pattern_Differences() {
    std::vector<int> result;
    
    //iterates through the vector
    for (int i = 0; i < iris1.size() &&i< iris2.size(); i++) {
        //finds the difference in R, G, and B values for each pixel
        int diff_1, diff_2, diff_3;
        diff_1 = abs(iris1[i].getRed() - iris2[i].getRed());
        diff_2 = abs(iris1[i].getGreen() - iris2[i].getGreen());
        diff_3 = abs(iris1[i].getBlue() - iris2[i].getBlue());
        
        //commented out print statement to check for errors in difference calculations
        //std::cout<< " diff1 = " << diff_1 << "  diff2 = " << diff_2 << "  diff3 = " << diff_3 << std::endl;
        
        //pushes the sum of the differences onto the vector
        result.push_back(diff_1+diff_2+diff_3);
    }
    return result;
}


//This method finds the percentage similarity between the two iris vectors
void Compare::find_Percent_Similarity() {
    
    //sets the maximum value that the difference can be is 252 for each of R, G, and B
    const double MAX_DIFF_VALUE = 3 * 252;
    double result;
    std::vector<double> percent_color_diff;
    
    //iterates through the vector
    for (int i = 0; i < color_differences.size() ; i++) {
        //percentage of difference found by dividing actual difference by possible difference
        percent_color_diff.push_back((color_differences[i]/MAX_DIFF_VALUE));
        //sums the total percentage difference
        result += percent_color_diff[i];
    }
    
    //sets the final percentage difference as average of the difference percentage in each pixel
    percent_color_difference = result/percent_color_diff.size();
    
    return;
}


//this method checks to see if the person is the same
bool Compare::is_same_person() {
    
    //50% is arbitrary, it can be changed to make the criteria more or less stringent
    if (percent_color_difference <= 0.14 ) {
        is_same = true;
    }
    else is_same = false;
    return is_same;
}







