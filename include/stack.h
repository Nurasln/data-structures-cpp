#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    T *arr;
    int capacity;
    int top;

    // Resize the internal array
    void resize(int new_capacity)
    {
        T *new_arr = new T[new_capacity];
        for (int i = 0; i <= top; ++i)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    // Constructor
    Stack(int initial_capacity = 10) : capacity(initial_capacity), top(-1)
    {
        arr = new T[capacity];
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(const T &value)
    {
        if (top + 1 == capacity)
        {
            resize(capacity * 2);
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    void pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        top--;
    }

    // Get the top element of the stack
    T peek() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Get the current size of the stack
    int size() const
    {
        return top + 1;
    }
};