#include "Node.h"

// Constructor implementation
template<typename T>
Node<T>::Node(){}

// Constructor implementation
template<typename T>
Node<T>::Node(T data) : data(data) {}

// Getter implementation
template<typename T>
T Node<T>::getData() {
    return data;
}

// Setter implementation
template<typename T>
void Node<T>::setData(T value) {
    data = value;
}

// Explicit template instantiation
template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;
