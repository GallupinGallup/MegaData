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
    Node(Type data, Node<Type> * pointer);
    
    Type getNodeData();
    Node<Type> * getNodePointer();
    void setNodeData(Type data);
    void setNodePointer(Node<Type>* pointer);
    
    
};

/*
 Implamentation section
 */

template<class Type>
Node<Type> :: Node()
{
    //Explicitly DO NOT instanciate the nodeData data member
    this->nodePointer = nullptr;
}
template<class Type>
Node<Type> ::Node(Type data)
{
    this->nodeData = data;
    this->nodePointer = nullptr;
}

template<class Type>
Node<Type> :: Node(Type nodeData, Node<Type> * nodePointer)
{
    this->nodeData = nodeData;
    this->nodePointer = nodePointer;
}

template<class Type>
void Node<Type> :: setNodeData(Type data)
{
    this->nodeData = data;
}

template<class Type>
void Node<Type> :: setNodePointer(Node * nodePointer)
{
    this->nodePointer = nodePointer;
}

template<class Type>
Type Node<Type> :: getNodeData()
{
    return this->nodeData;
}

template<class Type>
Node<Type> * Node<Type> :: getNodePointer()
{
    return this -> nodePointer;
}


#endif /* Node_hpp */
