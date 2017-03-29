//
//  FileController.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 3/29/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef FileController_h
#define FileController_h

#include "DoubleList.hpp"
#include "FoodItem.hpp"
#include "CrimeData.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileController
{
private:
    doubleList<foodItem> foodItemList;
    
public:
    DoubleList<FoodItem> readDataFromFiel(string filename);
    void writeFoodDataStisics(DoubleList<FoodItem> source, string fileName);
    
};

#endif /* FileController_h */
