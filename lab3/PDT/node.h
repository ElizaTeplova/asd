//
// Created by mrbab on 21.03.2023.
//

#ifndef LAB3_NODE_H
#define LAB3_NODE_H

template<typename T>
class Node {
private:
    T value;
    Node* left;
    Node* right;

public:
    Node();

    Node(T value, Node *left, Node *right) : value(value), left(left), right(right) {}
};

#endif //LAB3_NODE_H
