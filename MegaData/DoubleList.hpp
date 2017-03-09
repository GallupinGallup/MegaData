//
//  DoubleList.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 3/3/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
    
    
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromInde(int index);
    Type getFromIndexFast(int index);
};

template <class Type>
void DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
    }
    else
    {
        this->getEnd()->setNextPointer(addedNode);
        addedNode -> setPreviosPointer(this->getEnd());
    }
    this->setEnd(addedNode);
    this->setSize(this->getSize()+1);
}




template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove= this->getFront();
    }
}


template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    for(int spot = 0; spot < index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp = nodeToTakeOut->getNNextPointer();
    
    BiDirectionalNode<Type> * prev = nodeToTakeOut->getPreviousPointer();
    BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();
    
    prev->setNextPointer(next);
    next->setPrevoiusPointer(prev);
    
    delete nodeToTakeOut;
    
    this->setSize(this->gettSize()-1);
    return derp;
    
}

template< class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
    assert(index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() /2
       {
           reference = this->fetFront();
           for(int position = 0; position < index; position++)
           {
               reference = reference->getNextPointer();
           }
       }else{
           reference = this->getEnd();
           for(int position = this->getSize() - 1; position > index; position--)
           {
               reference = reerence->getPreviousPointer();
           }
           
           valueAtIndex = reference->getNodeData();
           return valueAtIndex;
       }
}
#endif /* DoubleList_h */
