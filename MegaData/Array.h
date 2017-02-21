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
#include <iostream>

using namespace std;

template <class Type>
class Array{
    
private:
    Node<Type> * front;
    int size;
    
public:
    Array();
    Array(int size);
    
    ~Array<Type>();
    Array<Type>(const Array<Type> & toBeCopied);
    
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    int getSize() const;
    Node<Type> * getFront() const;
};

template <class Type>
Array<Type> :: Array(){
    
}

template <class Type>
Array<Type> :: Array(int size){
    
    assert(size > 0);
    
    this->size = size;
    this->front = new Node<Type>();
    
    for(int index = 1; index < size; index++){
        Node<Type> * current = new Node<Type>();
        current->setNodePointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data){
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++){
        current = current->getNodePointer();
    }
    
    current->setNodeData(data);
}

template <class Type>
Type Array<Type> :: getFromIndex(int index){
    assert(index >= 0 && index < size);
    
    Type value;
    
    Node<Type>* current = front;
    for(int pos = 0; pos < index; pos++){
        current = current-> getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

template <class Type>
int Array<Type> :: getSize() const{
    return size;
}

template <class Type>
Node<Type> * Array<Type> :: getFront() const{
    return front;
}

template <class Type>
Array<Type> :: ~Array(){
    int count = size;
    Node<Type> * remove = front;
    while (front != nullptr) {
        front = front->getNodePointer();
        cout << "Moving the next node. At " << count << endl;
        delete remove;
        cout << "Deleted the old front pointer." << endl;
        remove = front;
        cout << "Moving the new front pointer" << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}


template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied){
    this->size = toBeCopied.getSize();
    
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++){
        Node<Type> * temp = new Node<Type>();
        temp->setNodePointer(front);
    }
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++){
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNodePointer();
        copyTemp = copyTemp->getNodePointer();
    }
}

#endif /* Array_h */
