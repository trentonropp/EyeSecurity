//
//  Person.cpp
//  Created by Alec Unland
//

#include "Person.h"
#include <vector>
#include <stdlib.h>

using namespace std;

//returns the name of the person
string Person::getName()
{
    return name;
}

//adds a new iris to a person's vector of iris'
void Person::addIrisInstance(vector <Pixel> iris)
{
    irisArrays.push_back(iris);
    return;
}

//removes an iris from irisArrays
void Person::removeIrisInstance(int index)
{
    irisArrays.erase(index);
    return;
}

//returns the iris from the given index of irisArrays
vector<Pixel> Person::getAverage(int index)
{
    vector<Pixel> avg;
    
    return irisArrays[index];
}

//reurns a random iris from irisArrays
vector<Pixel> Person::getRandom()
{
    //generates random number between 0 and the size of irisArrays
    v1 = rand() % irisArrays.size();
    
    return irisArrays[v1];
}
