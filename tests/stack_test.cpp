#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl;
    std::cout << "Stack size is: " << stack.size() << std::endl;

    stack.pop();
    std::cout << "Top element after pop is: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    try
    {
        stack.pop(); // This should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
    
    return 0;
}