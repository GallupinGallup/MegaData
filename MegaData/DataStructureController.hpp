//
//  DataStructuresController.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef ArrayController_hpp
#define ArrayController_hpp

#include "Node.hpp"
#include "Array.hpp"
#include "CircularList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "DoubleList.hpp"
#include "DoublyLinkedList.hpp"
#include "BiDirectionalNode.hpp"
#include "Timer.hpp"
#include "FoodItem.hpp"
#include "CircularList.hpp"
#include "FileController.hpp"
#include "BinarySearchTreeNode.h"
#include "Tree.h"
#include "BinarySearchTree.h"

#include <string>

using namespace std;

class ArrayController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testNodes();
    void testAdvancedFeatures();
    void testListIntro();
    void testListTiming();
    void testIntStack();
    void testFoodQueue();
    void testCircularList();
    void testBinarySearchTreeOperations();
    void testBinarySearchData();
    void testAVLTreeOperations();
    void testAVLData();
    
public:
    ArrayController();
    void start();
    
};
