#include <iostream>
#include <string>

template<typename T>
class Node {
public:
    T data;
    Node* prev, * next;
    
public:
    Node(T data) {
        this->data = data;
        this->prev = this->next = NULL;
    }
    
};
template<typename T>
class LinkedList {
public:
   
    Node<T>* head, * tail;

    LinkedList() {
        
        head = tail = NULL;
    }
    
    Node<T>* push_back(T data) {
        Node<T>* ptr = new Node<T>(data);

        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        tail = ptr;

        return ptr;
        
    }
    
    Node<T>* getAt(int index) {
        Node<T>* ptr = head;
        int n = 0;

        while (n != index) {
            if (ptr == NULL)
                return ptr;
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }

    
    
    
    void erase(int index) {
        Node<T>* ptr = getAt(index);
        if (ptr == NULL)
            return;

        Node<T>* left = ptr->prev;
        Node<T>* right = ptr->next;
        left->next = right;
        right->prev = left;

        delete ptr;
    }
    
    
};



int main()
{
    using namespace std;
    
    int S = 0;
    LinkedList<string> lst;
    lst.push_back("Laptop");
    lst.push_back("IPhone");
    lst.push_back("Products");
    lst.push_back("Netflix");
    lst.push_back("Spotify");

    
    for (Node<string>* ptr = lst.head; ptr != NULL; ptr = ptr->next)
    {
        S++;
    }
    
    lst.erase(S / 2);
    
    

    LinkedList<int> L;
    L.push_back(50000);
    L.push_back(75000);
    L.push_back(6000);
    L.push_back(1000);
    L.push_back(1500);

    L.erase(S / 2);
    for (Node<string>* ptr = lst.tail; ptr != NULL; ptr = ptr->prev) {

        cout << ptr->data << '\t';
        
    }
    cout << endl;
    for (Node<int>* ptr = L.tail; ptr != NULL; ptr = ptr->prev) {
       
        cout << ptr->data << '\t';
        
    }
    
    
}