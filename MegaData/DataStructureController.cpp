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
#include "Queue.hpp"
#include "FoodItem.hpp"
#include "Stack.hpp"
#include "CircularList.hpp"
#include "DoubleList.hpp"

using namespace std;

DataStructureController :: DataStructureController(){
    wordNode = Node<string>();
    numberNode = Node<int>();
}

void DataStructureController :: start(){
    testFoodQueue();
}

void DataStructureController:: testAdvancedFeatures(){
    int showDestructor = 0;
    
    if(showDestructor < 1){
        Array<string> words = Array<string>(5);
        cout << "Destructor stuff" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "first");
    words.setAtIndex(3, "last");
    Array<string> copiedWords = Array<string>(words);
    
    cout << words.getFromIndex(0) << " should = " << copiedWords.getFromIndex(0) << endl;
}

void DataStructureController :: testIntArray(){
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++){
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController:: testList(){
    List<string> food;
    food.addFront("Taco");
    food.addEnd("Steak");
    food.addAtIndex(1, "Jacob is a poop");
    food.addEnd("no");
    
    cout << "Contains \"no\"? " << food.contains("no") << endl << endl;
    
    for(int index = 0; index < food.getSize(); index++){
        cout << food.getFromIndex(index) << " is at index: " << index << endl;
    }
    
    food.remove(3);
    
    cout << "Size: " << food.getSize() << endl << endl;
    cout << "Contains \"no\"? " << food.contains("no") << endl << endl;
}

void DataStructureController:: testNodes(){
    cout << "The contentes of Node<stinrg>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        
        timingList.add(rand());
        
    }
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
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
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
        
        
    }
    
    averageSlow += averageSlow/1000.00;
    averageFast += averageFast/1000.00;
    
    cout << "When you do it in one diretion searching you get an average of: "  << averageSlow<< endl;
    cout << "When you do the BiDirectional way you get: " << averageFast << endl;
}

void DataStructureController:: testIntStack(){
    Stack<int> numberStack;
    
    numberStack.push(811);
    numberStack.add(2315);
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    numberStack.push(00);
    numberStack.push(666);
    numberStack.push(789);
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    int testValue = numberStack.pop();
    cout << "Test value is " << testValue << " and should be 789 " << endl;
    
    int otherTest = numberStack.remove(3);
    cout << "Other test value is " << otherTest << " and should be 666 " << endl;
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    cout << endl;
    
}

void DataStructureController:: testFoodQueue(){
    Queue<FoodItem> foods;
    
    FoodItem FrijolesConQueso("Frijoles con queso");
    FrijolesConQueso.setCost(200);
    FrijolesConQueso.setCalories(2500);
    FrijolesConQueso.isDelicious(true);
    
    FoodItem Pollo("Pollo");
    Pollo.setCost(200);
    Pollo.setCalories(1000);
    Pollo.isDelicious(true);
    
    FoodItem Brócoli("brócoli");
    Brócoli.setCost(1);
    Brócoli.setCalories(60);
    Brócoli.isDelicious(false);
    
    cout << "Size: " << foods.getSize() << endl;
    
    foods.enqueue(FrijolesConQueso);
    foods.add(Pollo);
    
    cout << "Size: " << foods.getSize() << endl;
    
    FoodItem firstItem = foods.peek();
    cout << "Item in queue: " << firstItem.getFoodName() << endl;
    
    foods.enqueue(Brócoli);
    
    FoodItem dequeued = foods.dequeue();
    cout << "The Item dequeued from the queue was: " << dequeued.getFoodName() << endl;
    
    FoodItem removed = foods.dequeue();
    cout << "The Item removed from the queue was: " << removed.getFoodName() << endl << endl;
}
