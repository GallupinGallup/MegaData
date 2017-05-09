//
//  DataStructuresController.cpp
//  MegaData
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>


using namespace std;

void ArrayController :: start()
{
    // This is an array
    /*
     int intArray[4];
     intArray[0] = 4;
     intArray[1] = 6;
     intArray[2] = 8;
     intArray[3] = 10;
     
     double doubleArray[4] = {23.23, 34.34, 45.45, 56.56};
     int userChoice;
     cout << intArray[3] << endl;
     cout << "Choose a position of doubleArray between 0 and 3" << endl;
     cin >> userChoice;
     if(userChoice > 3 || userChoice < 0)
     {
     cout << "Sorry but that is out of bounds" << endl;
     }
     else
     {
     cout << "The value of " << userChoice << " is " << doubleArray[userChoice] << endl;
     }
     */
    
    //cout << "Starting the project" << endl;
    
    // cout << "Switching to the array testing" << endl;
    // testNodes();
    // cout << "Finished testing" << endl;
    // testAdvancedFeatures();
    // testListIntro();
    testListTiming();
    testFoodQueue();
    testIntStack();
    testBinarySearchTreeOperations();
    
    
}

ArrayController :: ArrayController()
{
    
}

//void ArrayController :: testNodes()
//{
//  cout << "Here is the Node<string>" << endl;
//  cout << wordNode.getNodeData() << endl;
// cout << "Here is the Node<int>" << endl;
//  cout << numberNode.getNodeData() << endl;
//}

//void ArrayController :: testIntArray()
//{
//cout << "Testing the array" << endl;

//IntNodeArray temp = IntNodeArray(3);
// for(int cute = 0; cute < 3; cute++)
// {
//     cout << temp.getFromIndex(cute) << " Is at spot  " << cute << endl;
// }

// cout << "Testing input" << endl;

// for(int index = 0; index < 3; index++)
//{
//    temp.setAtIndex(index, index);
//
// }
// for(int index = 0; index< 3; index++)
//  {
//      cout << temp.getFromIndex(index) << " is at spot " << index << endl;
//  }
//}

void ArrayController :: testAdvancedFeatures()
{
    int showDeconstructor = 0;
    if(showDeconstructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about the deconstructor next." << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at 0");
    words.setAtIndex(3, "in the last spot.");
    Array<string> copiedWords = Array<string>(words);
    
    cout<< "These should match: " << endl;
    cout<< words.getFromIndex(0) << "Should be the same as " << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    
}

void ArrayController :: testListIntro()
{
    string removed;
    List<string> sample;
    sample.addFront("\"My name is larry! FEAR ME!!!!!!\"");
    sample.addEnd("(somewhere distant) I will never fear larry!!!!");
    sample.addAtIndex(0, "As Larry mounted the small hill a new determination filled him.");
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    removed = sample.remove(1);
    
    cout << "You just removed" << removed << endl;
    sample.setAtIndex(1,"However he no longer felt courageous enough to share his message with the world");
    
    cout << sample.getFromIndex(1) << endl;;
    
    if (sample.contains("However he no longer felt courageous enough to share his message with the world") == 0)
    {
        cout << "it contains this yay" << endl;
    }
    else
    {
        cout <<  "no good" << endl;
    }
    
    cout << sample.getEnd() << endl;
    cout << sample.getFront() << endl;
    
}

void ArrayController :: testListTiming()
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
    
    cout << "When you do it in one diretion searching you get an average of: "  << averageSlow << "microseconds" << endl;
    cout << "When you do the BiDirectional way you get: " << averageFast << "microseconds" << endl;
    cout << "The time you save with the 2Directional is: " << averageSlow - averageFast << "microseconds"  << endl;
    totalTimer.displayTimerInformation();
    
}

void ArrayController :: testIntStack()
{
    Stack<int> numberStack;
    numberStack.push(747474747);
    numberStack.add(2323);
    cout << "Both the numbers in order should be 2323 747474747. and is : " << numberStack.pop() << " " << numberStack.remove(0) << endl;
    numberStack.push(77757);
    cout << "There should only be 1 thing in this stack and there is: " << numberStack.getSize() << endl;
    cout << "And the one thing is " << numberStack.peek() << " and should be: 77757" << endl;;
    numberStack.add(7);
    numberStack.add(6);
    numberStack.add(5);
    numberStack.add(4);
    numberStack.add(3);
    numberStack.add(2);
    numberStack.add(1);
    cout << "Then it should count up to seven: " << numberStack.pop()<< numberStack.pop()<< numberStack.pop()<< numberStack.pop()<< numberStack.pop()<< numberStack.pop()<< numberStack.pop()<<endl;
}

void ArrayController :: testFoodQueue()
{
    
    Queue<FoodItem> tastyFood;
    FoodItem rice("Bland Chinese Dish");
    tastyFood.enqueue(rice);
    FoodItem boring;
    tastyFood.add(boring);
    FoodItem removed = tastyFood.dequeue();
    cout << "The item removed from the queue was: "<< removed.getFoodName() << " and should be: Bland Chinese Dish" << endl;
    FoodItem mochi("Chinese Dessert");
    tastyFood.add(mochi);
    int sizeOfFood = tastyFood.getSize();
    cout << "The restuants food order queues was: "<< sizeOfFood << " and should be: 2" << endl;
    FoodItem crushedGoldFish = tastyFood.remove(0);
    cout << "The restuants got rid of: "<< crushedGoldFish.getFoodName()  << " rice and mochi" << endl;
    tastyFood.peek();
    cout << "And the food in the highest priority is: " << tastyFood.peek().getFoodName() << " and should be: Chinese Dessert"<< endl;
    cout << "And the size afer all this would be 1 and is:" << tastyFood.getSize() << endl;
    
}

void ArrayController :: testBinarySearchTreeOperations()

{
    
    BinarySearchTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    
    
}

void ArrayController :: testBinarySearchData()

{
    
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    BinarySearchTree<CrimeData> crimeTree = fileData.readCrimeDataToBinarySearchTree("/Users/asmi0816/Documents/crime.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
}

void ArrayController :: testAVLTreeOperations()

{
    
    AVLTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
    
}

void ArrayController :: testAVLData()

{
    
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/cody.henrichsen/Documents/crimes.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
    
}
