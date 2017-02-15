//
//  Header.h
//  MegaData
//
//  Created by Gallup, Tyler on 2/15/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Header_h
#define Header_h

#inclued "Node.h"
#include <assert.h>

template < class Type>
class Array
{
private:
    int size;
    node<Type> * front;
public:
    Array();
    Array(intSize);
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    int getSize;
};

template <class Type>
Array<Type> :: Array()
{
    //Never used
    //Default constructor only supplied to avoid compication error!
}
templat <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    this->front = new Node<Type>();
    
    for(int index = 1; index < sixe; index++)
    {
        Node<Type>() * current = new Node<Type>();
        current->setNodePointer(front);
        front = current;
    }
}

tempalt <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert
}

#endif /* Header_h */
