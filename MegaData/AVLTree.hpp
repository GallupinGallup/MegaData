//
//  AVLTree.hpp
//  MegaData
//
//  Created by Gallup, Tyler on 4/21/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation (BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balanceSubTree (BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent);
    
    int heightDifference(BinarySearchTreeNode<Type>* parent);
    
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
    
};

//negative means the right child is greater than the left
template<class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftChild());
    int rightHeight = this->calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight;
    rreturn balance;
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> *parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    parent->setLeftChild(changedNode->getRightChild());
    changedNode->setRightChild(parent);
    return changedNode;
    
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation(BinarySearchTreeNode<Type> *parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    parent->setRightChild(changedNode->getLeftChild());
    changedNode->setLeftChild(parent);
    return changedNode;
    
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTreeNode<Type> *parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
    
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTreeNode<Type> *parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
    
}


template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinarySearchTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftChild()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if (heightDifference(parent->getRightChild()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}


template <class Type>
AVLTree<Type>:: AVLTree() : BinarySearchTree<Type>()
{
    
}

template <class Type>
AVLTree<Type>:: ~AVLTree()
{
    delete this->getRoot();
}


template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> ::  insertNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinarySearchTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getLeftChild(),iserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightChild(),iserted));
        parent = balanceSubTree(parent);
    }
    retun parent;
}

template<class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

template<class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}
template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(root !nullptr);
    BinaySearchTreeNode<Type> * largest = getLeftMostChild(root);
    return smallest->getNodeData();
}

template<class Type>
Type BinarySerachTree<Tpye> :: FindMaximum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Tpye * largest = getRightMosetChild(root);
    return largest->getNodeData();
}


#endif /* AVLTree_h */
