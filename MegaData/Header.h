//
//  Header.h
//  MegaData
//
//  Created by Gallup, Tyler on 2/15/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include "Node.hpp"
#include <assert.h>

template <class Type>
class Array
{
private:
    int size;
    Node<Type> * front;
    
public:
    array();
    array(int size);
    
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    int getSize();
    
};

template <class Type>
Array<Type> :: Array()
{
    //Never used
    //Default constructor only supplied to avoid compelation error.
}
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    this-> = new Node<Type>();
    for (int index= 1; index < size; index++)
    {
        Node<Type> * current  = new Node<Type>();
        current -> setNodePointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot)
    {
        current = current -> getNodePointer();
    }
    current-> setNodeData(value)
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current -> getNodePointer();
    }
    value = current->getNodeData();
    return value;
}

#endif /* Array_h */
