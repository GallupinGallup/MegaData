//
//  CircularList.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 3/1/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    BiDirectionalNode<Type> * findNode(int index);
public:
    CircularList();
    ~CircularList();
    
    void add(Type data);
    Type remove(int index);
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
    //other methods.
    
    
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    //deal with circle list stuff only here.
    
}

template <class Type>
CircularList<Type> :: ~CircularList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    {
        BiDirectionalNode<Type> * remove = this->getFront();
        while(this->getFront() != nullptr)
        {
            this->setFront(this->getFront()->getNextPointer());
            delete remove;
            remove = this->getFront();
        }
    }
}

template <class Type>
BiDirectionalNode<Type> * CircularList<Type> :: findNode(int index)
{
    BiDirectionalNode<Type> * nodeToFind;
    if(index < this->getSize() / 2)
       {
           nodeToFind = this->getEnd();
           for(int spot = this->getSize() - 1; spot > index; spot--)
           {
               nodeToFind = nodeToFind->getPreviousPointer();
           }
       }
       return nodeToFind;
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    BiDirectionalNode<Type> * addMe = new BiDirectionalNode <Type>(data);
    
    if(this->getSize() == 0)
    {
        this->setFront(addMe);
        this->setEnd(addMe);
        addMe->setPreviousPointer(this->getFront());
        this->getFront()->setNextPointer(this->getEnd());
    }
    this->setSize(this->getSize() + 1);
    
}

template <class Type>
Type CircularList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->getSize());
    
    Type removedValue;
    
    BiDirectionalNode<Type> * oldPrevious = removedValue->getPreviousPointer();
    BiDirectionalNode<Type> * oldNext = removedValue->getNextPointer();
    
    if(this->getSize() > 1)
    {
        oldPrevious->setNextPointer(oldNext);
        oldNext->setPreviousPointer(oldPrevious);
        
        if(index == 0)
        {
            this->setFront(this->getFront()->getNextPointer());
        }else if(index == this->getSize() -1)
        {
            this->setEnd(this->getEnd()->getPrebiousPointer());
        }
    }else{
        this->setSize(this->getSize);
        this->endPointer(nullptr);
    }
    
}

template <class Type>
Type CircularList<Type> :: setAtIndex(int index, Type data)
{
    assert(index);
}
#endif /* CircularList_h */
