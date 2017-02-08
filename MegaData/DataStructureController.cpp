//
//  DataStructuresController.cpp
//  MegaData
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "IntNode.hpp"
#include "IntNodeArray.hpp"

using namespace std;

DataStructureController :: DataStructureController(){
    
}

void DataStructureController :: start(){
    cout << "Starting the project" << endl;
    cout << "Switching to the array testing" << endl;
    
    testIntArray();
    
    cout << "Finished testing" << endl;
}

void DataStructureController :: testIntArray(){
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++){
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
    
    cout << "Testing input" << endl;
    
    for(int index = 0; index < 3; index ++)
    {
        cout << temp.getFromIndex(index) << " is at spot "<< index << endl;
    }
}
