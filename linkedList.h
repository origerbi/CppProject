#pragma once
#include <ostream>

template <typename T>
class LinkedList
{
public:
    explicit LinkedList<T>(const T& t);
    LinkedList<T>();
    LinkedList<T>(const LinkedList<T>& other) = default;
    LinkedList<T>& operator=(const LinkedList<T>& other) = default;
    LinkedList<T>& operator=(LinkedList<T>&& other) noexcept = default;
    LinkedList<T>(LinkedList<T>&& other) noexcept = default;
    ~LinkedList<T>();
    void AddItem(const T& t);
    bool RemoveItem(int index);
    bool HasNext() const;
    LinkedList<T>* Next;
    T* Value;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
    {
        while (list.Next != nullptr)
        {
            os << list.Value << std::endl;
            list = list.Next;
        }
        return os;
    }
};

template <typename T>
LinkedList<T>::LinkedList(const T& t) : Next(nullptr), Value(new T(t))
{
}

template <typename T>
LinkedList<T>::LinkedList() : Next(nullptr), Value(nullptr)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    delete Next;
    delete Value;
}

template <typename T>
void LinkedList<T>::AddItem(const T& t)
{
    if (Next != nullptr)
    {
        Next->AddItem(t);
    }
    else
    {
        Next = new LinkedList<T>(t);
    }
}

template <typename T>
bool LinkedList<T>::RemoveItem(const int index)
{
    if (Next == nullptr)
        return false;
    if (index > 0)
    {
        return Next->RemoveItem(index - 1);
    }
    if (index == 0)
    {
        const LinkedList<T>* temp = Next;
        Next = Next->Next;
        temp->Next = nullptr;
        delete temp;
        return true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::HasNext() const
{
    return Next != nullptr;
}
