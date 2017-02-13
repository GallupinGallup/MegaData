//
//  Header.h
//  MegaData
//
//  Created by Gallup, Tyler on 2/13/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Header_h
#define Header_h

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type> * nodePointer;
public:
    Node();
    Node(Type nodeData);
    Node(TypeData, Node<Type> * next);
    
    void setNodeData(Type data);
    void setNodePointer(Node<Type> pointer);
    Type getNodeData();
    Node<Type> * getNodePointer();
};

#endif /* Header_h */
