#include <iostream>
#include "linked_list.h"

int main()
{
    LinkedList<int> list;

    list.append(10);
    list.append(5);
    list.append(30);
    list.append(20);
    list.append(25);
    list.append(15);

    std::cout << "List: ";
    list.display();

    std::cout << "Size of the list: " << list.size() << std::endl;

    list.insertAt(4, 18);
    std::cout << "18 added to the 4th index: ";

    list.display();

    list.remove(25);
    std::cout << "25 deleted: ";
    list.display();

    list.removeAt(2);
    std::cout << "2nd index deleted: ";
    list.display();

    auto found = list.find(18);
    if (found)
        std::cout << "18 found!" << std::endl;
    else
        std::cout << "18 not found!" << std::endl;

    list.clear();
    std::cout << "List cleared. Is it empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}