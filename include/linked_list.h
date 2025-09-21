#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node *head;
    size_t length; // unsigned integer for length of the list

public:
    // Constructor
    LinkedList() : head(nullptr), length(0) {}
    // Destructor
    ~LinkedList()
    {
        clear();
    }

    // Deletes all nodes and frees the memory.
    void clear()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        length = 0;
    }

    // Returns the number of elements in the list.
    size_t size() const
    {
        return length;
    }

    // Checks if the list is empty.
    bool isEmpty() const
    {
        return length == 0;
    }

    // Adds a new node with the given data to the beginning of the list.
    void prepend(T value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Adds a new node with the given data to the end of the list.
    void append(T value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
    }

    // Inserts a new node at a specified index.
    void insertAt(size_t index, T value)
    {
        if (index > length)
            throw std::out_of_range("Index out of range");
        if (index == 0)
        {
            prepend(value);
            return;
        }
        Node *temp = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    // Removes the first node that contains the specified value.
    void remove(T value)
    {
        if (!head)
            return;
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            length--;
            return;
        }

        Node *current = head;
        while (current->next && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            length--;
        }
    }

    // Removes the node at a specified index.
    void removeAt(size_t index)
    {
        if (index >= length)
            throw std::out_of_range("Index out of range");
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            length--;
            return;
        }

        Node *current = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }

    // Finds the first node with the specified value and returns a pointer to it.
    Node *find(T value) const
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Prints all elements of the list to the console.
    void display() const
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }

        std::cout << "nullptr" << std::endl;
    }
};