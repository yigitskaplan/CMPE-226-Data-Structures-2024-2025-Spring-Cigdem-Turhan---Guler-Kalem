// Yiğit Şevki Kaplan - 23244710009


#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Stack{
    private:
        T* arr;
        int top;
        int size;
    public:
        Stack(int = 100);
        bool isEmpty(){return top == 0;}
        bool isFull(){return top == size;}
        void destroy(){top = 0;}
        T pop();
        void push(T&);
        ~Stack(){delete[] arr;}
        T stop();
};

template <class T>
Stack<T>::Stack(int stackSize){
    size = stackSize;
    top = 0;
    arr = new T[size];
}

template <class T>
void Stack<T>::push(T& item){
    if (!isFull()){
        arr[top++] = item;
    } else {
        cout << "Stack is full" << endl;
    }
}

template <class T>
T Stack<T>::pop(){
    assert (!isEmpty());
    return arr[--top];
}

template <class T>
T Stack<T>::stop(){
    assert (!isEmpty());
    return arr[top - 1];
}
