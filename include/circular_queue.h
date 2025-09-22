#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class CircularQueue
{
private:
    T *queue;
    int capacity;
    int front;
    int back;

public:
// Constructor
    CircularQueue(int size)
    {
        capacity = size + 1;
        queue = new T[capacity];
        front(0);
        back(0);
    }

    // Destructor
    ~CircularQueue()
    {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return front == back;
    }

    // Check if the queue is full
    bool isFull() const
    {
        return (back + 1) % capacity == front;
    }

    // Add an element to the back of the queue
    void enqueue(const T &value)
    {
        if (isFull())
        {
            throw std::overflow_error("Queue is full");
        }
        queue[back] = value;
        back = (back + 1) % capacity;
    }

    // Remove and return the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Queue is empty");
        }
        T value = queue[front];
        front = (front + 1) % capacity;
        return value;
    }

    // Peek at the front element without removing it
    T getFront() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Queue is empty");
        }
        return queue[front];
    }

    // Display the queue elements
    void display() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        int i = front;
        while (i != back)
        {
            std::cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        std::cout << std::endl;
    }
};