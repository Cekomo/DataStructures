#include "Stack.h"

int main() {
    Stack stack;

    stack.Push(15);
    stack.Push(31);
    stack.Push(57);

    stack.Pop();

    std::cout << "Stack size: " << stack.GetSize() << " Latest Node: " << stack.Peek() << std::endl;
    std::cout << "Stack is empty: " << stack.IsEmpty() << std::endl;

    stack.Clear();

    std::cout << "Stack size: " << stack.GetSize() << std::endl;

    return 0;
}