//
//  FileController.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 3/29/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "DoubleList.hpp"
#include "FoodItem.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class FileController{
private:
    DoubleList<FoodItem> foodItemList;
    
public:
    DoubleList<FoodItem> readDataFromFile(string filename);
    void writeFoodItemDataStatistis(DoubleList<FoodItem> sourc, string filename);
};

#endif /* FileController_hpp */
