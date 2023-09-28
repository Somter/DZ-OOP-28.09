// DZ OOP 28.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Реализовать шаблонный класс "Очередь" на основе двусвязного списка.	
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public: 
    T data;
    Node* next;
    Node* prev;

    Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue
{
private:
    Node<T>* Head; // Голова
    Node<T>* Tail; // Хвост
    int count;

public:
    Queue();

    ~Queue();

    bool isEmpty() const;

    int size() const;

    void InputQueue(const T& value);

    void DeleteElm();

    T GetElem() const;  

    void Print() const;
};

template <typename T>
Queue<T>::Queue() : Head(nullptr), Tail(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue()
{
    while (!isEmpty())
    {
        DeleteElm();
    }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
int Queue<T>::size() const
{
    return count;
}

template <typename T>
void Queue<T>::InputQueue(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty())
    {
        Head = Tail = newNode;
    }
    else
    {
        newNode->prev = Tail;
        Tail->next = newNode;
        Tail = newNode;
    }
    count++;
}

template <typename T>
void Queue<T>::DeleteElm()
{
    if (isEmpty())
    {
        cout << "Очередь пуста. " << endl;
        return;
    }

    Node<T>* CurElem = Head;
    Head = Head->next;
    if (Head != nullptr)
    {
        Head->prev = nullptr;
    }
    delete CurElem;
    count--;

    if (isEmpty())
    {
        Tail = nullptr;
    }
}

template <typename T>
T Queue<T>::GetElem() const 
{
    if (isEmpty())
    {
        cout << "Очередь пуста " << endl;
    }
    return Head->data;
}

template <typename T>
void Queue<T>::Print() const
{
    Node<T>* CurElem = Head;
    while (CurElem != nullptr)
    {
        cout << CurElem->data << " ";
        CurElem = CurElem->next;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    Queue<int> queue;

    for (int i = 0; i < 8; i++)
    {
        int number = rand() % 10;
        queue.InputQueue(number);   
    }
    queue.Print();
    queue.DeleteElm();
    queue.Print();
 
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
