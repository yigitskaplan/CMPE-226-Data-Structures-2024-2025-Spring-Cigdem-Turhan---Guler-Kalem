//Yiğit Şevki Kaplan - 23244710009


#include <iostream>

using namespace std;

template <class T>
struct node
{
    T info;
    node<T>* link;
};

template <class T>
class LL
{
    protected:
        node<T> *head, *last;
        int count;
    public:
        LL();
        ~LL();
        bool emptylist();
        int length(){return count;}
        T back();
        T front();
        void destroylist();
        node<T>* search(T&);
        void insertFirst(T&);
        void insertLast(T&);
        void deleteNode(T&);
        friend ostream& operator<<(ostream& os, const LL<T>& lst)
        {
            node<T>* p = lst.head;
            while (p != nullptr)
            {
                os << p->info;
                p = p->link;
            }
        return os;
        }
};

template<class T>
LL<T>::LL()
{
    count = 0;
    head=last = nullptr;
}

template<class T>
bool LL<T>::emptylist()
{
    return head == nullptr;
}

template<class T>
T LL<T>::back()
{
    assert(last != nullptr);
    return last->info;
}

template<class T>
T LL<T>::front()
{
    assert(head != nullptr);
    return head->info;
}

template<class T>
void LL<T>::insertFirst(T &item)
{
    node<T> *p = new node<T>;
    p->info = item;
    p->link = head;
    head = p;
    if(last == nullptr)
    last = p;
    count++;
}

template<class T>
void LL<T>::insertLast(T &item)
{
    node<T> *p=new node<T>;
    p->info = item;
    p->link = nullptr;

    if(head != nullptr)
    {
        last->link = p;
        last = p;
    }
    else
    {
        head = last = p;
    }

    count++;
}

template<class T>
void LL<T>::destroylist()
{
    node<T> *p;

    while (head != nullptr)
    {
        p = head;
        head = head->link;
        delete p;
    }

    last = nullptr;
    count = 0;
}

template<class T>
LL<T>::~LL()
{
    destroylist();
}

template<class T>
node<T>* LL<T>::search(T &item)
{
    bool found = false;
    node<T> *p = head;

    while (p != nullptr && !found)
    {
        if (p->info == item)
        found = true;
        else
        p = p->link;
    }

    return p;
}

template<class T>
void LL<T>::deleteNode(T &item)
{
    node<T> *p, *q;
    bool found = false;

    if (head == nullptr)
    {
        cerr<<"List is empty"<<endl; 
    }
    else
    {
        if (head->info == item)
        {
            p=head;
            head = head->link;
            if (head == nullptr)
            last = nullptr;
            delete p;
            count--;
        }
        else
        {
            p = head; q = head->link;

            while (q != nullptr && !found)
            {
                if (q->info == item)
                found = true;
                else
                {
                    p = q;
                    q = q->link;
                }
            }
            
            if (found)
            {
                p->link = q->link;
                if (last == q)
                last = p;
                delete q;
                count--;
            }
        }
    }
}