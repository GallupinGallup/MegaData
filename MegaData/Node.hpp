//
//  Header.h
//  MegaData
//
//  Created by Gallup, Tyler on 2/13/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type> * nodePointer;
public:
    Node();
    Node(Type nodeData);
    Node(Type data, Node<Type> * next);
    
    void setNodeData(Type data);
    void setNextPointer(Node<Type>* pointer);
    Type getNodeData();
    Node<Type> * getNextPointer();
};

/*
 Implementation section
 */

template <class Type>
Node<Type> :: Node(){
    // Explicitly DO NOT instantiate the nodeData data member
    this->nodePointer = nullptr;
}


template <class Type>
Node<Type> :: Node(Type nodeData){
    this->nodeData = nodeData;
    this->nodePointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data, Node<Type> * next){
    this->nodeData = data;
    this->nodePointer = next;
}

template <class Type>
void Node<Type> :: setNodeData(Type data){
    this->nodeData = data;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type>* pointer){
    this->nodePointer = pointer;
}

template <class Type>
Type Node<Type> :: getNodeData(){
    return this->nodeData;
}

template <class Type>
Node<Type>* Node<Type> :: getNextPointer(){
    return this->nodePointer;
}


#endif /* Node_hpp */
