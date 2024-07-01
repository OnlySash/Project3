#ifndef NODE_H
#define NODE_H
#include <string>
template<typename T>
class Node {
private:
    T data;
public:
    Node(); // Data less Constructor
    Node(T data); // Normal Constructor
    T getData(); // Getter
    void setData(T value); // Setter
};

#include "Node.cpp"

#endif // NODE_H

