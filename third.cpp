
#include <iostream>

template<typename T>
class List
{
public:
    List();
    ~List();
    void push_back(T data);
    int GetSize() { return Size; }
    void pop(int index);

    T& operator[](const int index);

private:
    template<typename T>

    class Node 
    {
    public:
        Node* pNext;
        T data;
        Node(T data=T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    
    Node<T> * head;

};
 
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else 
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::pop(int index)
{
    Node<T>* previous = this->head;
    for (int i = 0; i < index - 1; i++)
    {
        previous = previous->pNext;
    }

    Node<T>* toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;

    Size--;
}



template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;

    while(current!= nullptr)
    {
        if (counter == index) 
        {
            return current->data;
        }
        current = current->pNext;
        counter++;

    }
}



int main()
{   
    using namespace std;
   
    List<string> prod;
    string tobuy[11] = { "Apples","Porridge","Cucumbers", "Tomatoes","Orange juice","Peanuts","Peas","Salt","Sugar","Pepper","Shampoo"};
    for (int i = 0; i < 11;i++) {
        prod.push_back(tobuy[i]);
    }


    List<int> amount;
    int money[11] = { 200,100,325,240,700,550,300,50,170,30,576};
    for (int i = 0; i < 11; i++) {
        amount.push_back(money[i]);
    }

    amount.pop(amount.GetSize() / 2);
    prod.pop(prod.GetSize() / 2);
 

   for (int i = 0; i < prod.GetSize(); i++)
   {
       cout << prod[i] << "->"<<amount[i]<< endl;
       cout << endl;
   }

    
    int sum=0;
    for (int i = 0; i < prod.GetSize(); i++) 
    {
        sum += amount[i];
    }
    cout << "Overall:" <<sum;

    return 0;


}
