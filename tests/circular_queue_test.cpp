#include <iostream>
#include "circular_queue.h"

int main()
{
    CircularQueue<int> cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    std::cout << "Front element: " << cq.getFront() << std::endl;

    try
    {
        cq.enqueue(80); // Overflow 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}