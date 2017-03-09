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
#include "Array.h"
#include <string>
#include "Timer.hpp"
#include "IntNodeArrat.hpp"
#include "List.hpp"
#include "DoubleList.hpp"
#include "Stack.hpp"
#include "Que.hpp"
#include <string>

using namespace std;

class DataStructureController {
    
private:
    void testIntArray();
    void testNodesTypes();
    void testArratTemplate();
    void testDestructor();
    void testAdvancedFeatures();
    void testListIntro();
    void testDoubleList();
    void testLisntTiming();
public:
    DataStructureController();
    void start();
};

#endif /*DataStructureController*/
