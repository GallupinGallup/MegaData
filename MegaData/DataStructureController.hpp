//
//  DataStructuresController.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "Node.h"
#include <string>

using namespace std;

class DataStructureController {
    
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testNodes();
public:
    DataStructureController();
    void start();
};

#endif /*DataStructureController*/
