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

void DataStructureController:: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match: "<< endl;
    cout << words.getFromIndex(0) << " should be the same as "
    << copiedWords.getFromIndex(0) << endl;
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


