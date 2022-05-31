#ifndef NODE_H
#define NODE_H
#include "Binarytree.hpp"
template <class T>
class Node
{

private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T item)
    {
        data=item;
        left= nullptr;
        right= nullptr;
    }
    T Get()
    {
        return data;
    };
    Node * GetLeft()
    {
        return this->left;
    }
    Node * GetRight()
    {
        return this->left;
    }
};
#endif //NODE_H
