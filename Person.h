//
//  Person.h
//  Created by Alec Unland on 12/1/16.
//

#include <vector>
#include "Pixel.hpp"

using namespace std;

class Person{
    
private:
    vector< vector<Pixel> > irisArrays;
    string name;
    
public:
    Person(string name)
    {
        this->name = name;
    }
    
    string getName();
    void addIrisInstance(vector <Pixel>);
    vector<Pixel> getAverage();
    
};
