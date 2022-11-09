#pragma once

template <typename T>
class LinkedList
{
    struct Node
    {
        T data;
        Node *next;
        Node *previous;
        Node(T _data, Node *_next = nullptr, Node *_previous = nullptr) : data(_data), next(_next), previous(_previous) {}
    };
    Node *first = nullptr;
    Node *last = nullptr;

public:
    void add(T data);
    void remove(T element);
    bool isEmpty() const;
    T getFront() const;
    T getBack() const;
    bool contains(T element) const;
    void enqueue(T element);
    void dequeue();
    void pop
};

template <typename T>
void LinkedList<T>::add(T data)
{
    Node *newNode = new Node(data);
    if (first == nullptr)
        first = last = newNode;
    else 
    {
        last->next = newNode;
        last = newNode;
    }
}

template <typename T>
void LinkedList<T>::remove(T element)
{
    Node *removeMe = first;
    T returnMe = first->data;
    if (first == nullptr)
        throw EmptyException(); // Not real 
    if (last == first)
        last = nullptr;
    first = first->next;
    delete removeMe;
    return returnMe;
}