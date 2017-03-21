//
//  DataStructuresController.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//
#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "Node.hpp"
#include "Array.hpp"
#include "CircularList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "DoubleList.hpp"
#include "DoublyLinkedList.hpp"
#include "BiDirectionalNode.hpp"
#include "Timer.hpp"

#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testAdvancedFeatures();
    void testList();
    void testListTiming();
    void testNodes();
    void testIntStack();
    void testFoodQueue();
    
public:
    DataStructureController();
    void start();
    
};

#endif /*DataStructureController*/
