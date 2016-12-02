//
//  Person.cpp
//  Created by Alec Unland on 12/1/16.
//

#include "Person.hpp"
#include <vector>

using namespace std;

//returns the name of the person
string getName()
{
    return name;
}

//adds a new iris to a person's vector of iris'
void addIrisInstance(vector <Pixel> iris)
{
    irisArrays.push_back(iris);
}

//calculates the average RGB value of the persons iris array
vector<Pixel> getAverage()
{
    
}
