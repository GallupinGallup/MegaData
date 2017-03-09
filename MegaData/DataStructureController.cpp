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
#include "List.hpp"

using namespace std;

DataStructureController :: DataStructureController(){
    wordNode = Node<string>();
    numberNode = Node<int>();
}

void DataStructureController :: start(){
    testList();
}

void DataStructureController:: testAdvancedFeatures(){
    int showDestructor = 0;
    
    if(showDestructor < 1){
        Array<string> words = Array<string>(5);
        cout << "There should be message about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "Int the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match: " << endl;
    cout << words.getFromIndex(0) << " Should be the same as " << copiedWords.getFromIndex(0) << endl;
}

void DataStructureController :: testIntArray(){
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++){
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController:: testList(){
    List<string> taco;
    taco.addFront("Welcome to disneyland");
    taco.addEnd("The end is nigh.");
    taco.addAtIndex(1, "This is the 2nd (3rd) pos");
    taco.addEnd("Conman");
    
    cout << "Contains \"Conman\"? " << taco.contains("Conman") << endl << endl;
    
    for(int index = 0; index < taco.getSize(); index++){
        cout << taco.getFromIndex(index) << " is at index: " << index << endl;
    }
    
    taco.remove(3);
    
    cout << "Size: " << taco.getSize() << endl << endl;
    cout << "Contains \"Conman\"? " << taco.contains("Conman") << endl << endl;
}

void DataStructureController:: testNodes(){
    cout << "The contentes of Node<stinrg>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController:: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime[1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index<1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTimer[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTimer[index];
        averageFast += fastTimer[index];
    }
    
    averageSlow = averageSlow/100;
    averageFast = averageFase/100;
}
