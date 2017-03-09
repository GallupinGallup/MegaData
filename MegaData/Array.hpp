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
#include <iostream>
#include <assert.h>
#include "List.hpp"

using namespace std;

template <class Type>
class Array
{
private:
    int size;
    Node<Type> * front;
    
public:
    Array();
    Array(int size);
    
    //Deconstructor
    ~Array<Type>();
    //Copy init
    Array<Type>(const Array<Type> & toBeCopied);
    
    //Helper Methods
    void setAtIndex(int index, Type value);
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    int getSize() const;
    
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
    this -> front = new Node<Type>();
    for (int index= 1; index < size; index++)
    {
        Node<Type> * current  = new Node<Type>();
        current -> setNextPointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current -> getNextPointer();
    }
    current-> setNodeData(value);
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current -> getNextPointer();
    }
    value = current->getNodeData();
    return value;
}

template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}

template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //Move to next node in array
        front = front->getNextPointer();
        cout<< "Moving to the next node. At: " << count << endl;
        //Delete the front pointer
        delete remove;
        cout << "Deleting the old front pointer." << endl;
        //Move deletetothe new front.
        remove=front;
        cout << "Moving to new front pointer>" << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //Builds Data Structures
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNextPointer(front);
        front = temp;
    }
    
    
    
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated -> setNodeData(copyTemp->getNodeData());
        updated = updated -> getNextPointer();
        copyTemp = copyTemp -> getNextPointer();
    }
    
    
    
    
}
template <class Type>
Node<Type> * Array<Type> :: Array<Type> :: getFront() const
{
    return front;
}
#endif /* Array_h */
