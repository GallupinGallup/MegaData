//
//  List.h
//  MegaData
//
//  Created by Gallup, Tyler on 2/21/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <assert.h>

template <class Type>
class List {
    
private:
    int size;
    Node<Type> * front;
    
public:
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index, Type data);
    bool contains(Type data);
    int getSize() const;
    Node<Type> * getFront() const;
};

#endif /* Header_h */
