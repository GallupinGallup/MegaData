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
    wordNode = Node<string>("Poopy mcpoopface");
    numberNode = Node<int>();
}

void DataStructureController :: start(){
    cout << "Starting the project" << endl;
    cout << "Switching to the array testing" << endl;
    
    testNodes();
    
    cout << "Finished testing" << endl;
}

void DataStructureController :: testIntArray(){
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++){
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController:: testNodes(){
    cout << "The contentes of Node<stinrg>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}


