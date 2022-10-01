// archivo.h de templates de pila de listas ligadas 

#include <iostream>
#include <stdexcept>

// template stacknode 
  template <class T>
  class StackNode { 
  public: 
      T data; 
      StackNode<T> *next;
      StackNode();
      StackNode(T val);        
  }; 

  template<class T>
  StackNode<T>::StackNode() : data{}, next{nullptr} {}

  template<class T>
  StackNode<T>::StackNode(T val){
      data = val;
      next = nullptr;
  }
// template stacklinkend list 
  template <class T>
  class StackLinkedList {
      private:
        StackNode<T> *front;
        int numElements;

      public:
        StackLinkedList();
        ~StackLinkedList();
        int getNumElements();
        void print();
        bool isEmpty();
        void push(T value);
        void pop();
        T getTop();
        
  };

// creando un stack vacio 
  template<class T>
  StackLinkedList<T>::StackLinkedList() {
      front = nullptr;
      numElements = 0;
  }

// Liberando memoria del stack 
  template<class T>
  StackLinkedList<T>::~StackLinkedList() {
    StackNode<T> *p, *q;
    p = front;
    while (p != nullptr) {
      q = p->next;
      delete p;
      p = q;
    }
    front = nullptr;
    numElements = 0;
  }
  template<class T>
  int StackLinkedList<T>::getNumElements() {
    return numElements;
  }

  template<class T>
  void StackLinkedList<T>::print() {
    StackNode<T> *ptr = front;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  bool StackLinkedList<T>::isEmpty() {
    return (front == nullptr);
  }

  template<class T>
  void StackLinkedList<T>::push(T value) {
    StackNode<T> *newStackNode = new StackNode<T>(value);
    newStackNode->next = front;
    front = newStackNode;
    numElements++;
  }

  template<class T>
  void StackLinkedList<T>::pop() {
    if (!isEmpty()) {
      StackNode<T> *p = front;
      front = p->next;
      delete p;
      numElements--;
    }
  }

  template<class T>
  T StackLinkedList<T>::getTop() {
    T value = {};
    if (!isEmpty()) 
      value = front->data;
    return value;
  }
