#ifndef PERSON_H
#define PERSON_H

//
//  Person.h
//  Created by Alec Unland
//
#pragma once
#include <vector>
#include "Pixel.h"

using namespace std;

class Person{

private:
    vector< vector<Pixel> > *irisArrays;
        //used to hold multiple vectors of pixels taken from the iris from different pictures
    string name;

public:
    //constructor
    Person(string ame)
    {
        irisArrays=new vector<vector<Pixel> >;
        //irisArrays=new vector< vector<Pixel> >();
        this->name = ame;
    }

    string getName();
    void addIrisInstance(vector <Pixel> iris);
        //adds an iris vector to a person's collection of different iris' (irisArrays)
    void removeIrisInstance(int index);
        //removes an iris from irisArrays
    vector<Pixel> getAverage(int index);
        //returns the iris at the given index of irisArrays
    vector<Pixel> getRandom();
        //returns a random iris from irisArrays
};


#endif
