#include <iostream>
#include <cassert>

using namespace std;

template<class T>
struct Node
{
    T data;
    Node<T> *link;
};


template<class T>
class LinkedList
{
     friend ostream& operator<< (ostream& os,LinkedList<T>& lst){
     Node<T> *current;
     current = lst.head;

    while(current != NULL)
    {
        os<<current->data<<" "<<endl;
        current = current->link;
    }
    return os;}
     //void print();
    public:
    void initializeList();
    bool isEmpty();
    int length();
    void destroyList();
    T front();
    T back();
    Node<T>* search( T& );
    void insertFirst( T& );
    void insertLast( T& );
    void deleteNode( T& );
    LinkedList();
    ~LinkedList();


    protected:
    int count;
    Node<T> *head;
    Node<T> *last;


};



template<class T>
bool LinkedList<T>::isEmpty()
{
    return(head == NULL);
}

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    last = NULL;
    count = 0;
}

template<class T>
void LinkedList<T>::destroyList()
{
    Node<T> *temp;
    while(head!=NULL)
    {
        temp = head;
        head = head->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template<class T>
void LinkedList<T>::initializeList()
{
    destroyList();
}

template<class T>
int LinkedList<T>::length()
{
    return count;
}

template<class T>
T LinkedList<T>::front()
{
    assert(last != NULL);
    return head->data;
}

template<class T>
T LinkedList<T>::back()
{
    assert(last != NULL);
    return last->data;
}

template<class T>
Node<T>* LinkedList<T>::search( T& searchItem)
{
    Node<T> *current;
    bool found;
    current = head;
    found = false;
    while(current != NULL && !found)
        if(current->data == searchItem)
                found = true;
        else
                current = current->link;

    return current;
}

template<class T>
void LinkedList<T>::insertFirst( T& newItem)
{
    Node<T> *newNode;
    newNode = new Node<T>;
    assert(newNode != NULL);
    newNode->data = newItem;
    newNode->link = head;
    head = newNode;
    count++;
    if(last == NULL)
        last = newNode;

}

template<class T>
void LinkedList<T>::insertLast(T& newItem)
{
    Node<T> *newNode;
    newNode = new Node<T>;
    assert(newNode != NULL);
    newNode->data = newItem;
    newNode->link = NULL;
    if(head == NULL)
    {
        head = newNode;
        last = newNode;
        count++;
    }
    else
    {
        last->link = newNode;
        last = newNode;
        count++;
    }

}

template<class T>
void LinkedList<T>::deleteNode(T& deleteItem)
{
    Node<T> *current;
    Node<T> *trailCurrent;
    bool found;
    if(head == NULL)
        cerr<<"Can not delete from an empty list!\n";
    else
    {
        if(head->data == deleteItem)
        {
                current = head;
                head = head->link;
                count--;
                if(head == NULL)
                                last = NULL;
                delete current;
        }
        else
        {
                found = false;
                trailCurrent = head;
                current = head->link;
                while(current != NULL && !found)
                {
                                if(current->data != deleteItem)
                                {
                                    trailCurrent = current;
                                    current = current->link;
                                }
                                else
                                    found = true;
                }
                if(found)
                {
                                trailCurrent->link = current->link;
                                count--;
                                if(last == current)
                                    last = trailCurrent;
                                delete current;
                }
                else
                                cout<<"Item is not in the list!"<<endl;
        }
    }

}



template<class T>
LinkedList<T>::~LinkedList()
{
    destroyList();
}
