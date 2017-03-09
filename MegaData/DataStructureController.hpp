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

#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testNodes();
    void testAdvancedFeatures();
    void testListIntro();
    void testListTiming();
    
public:
    DataStructureController();
    void start();
    
};



#endif /* ArrayController_hpp */
