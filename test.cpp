
#include "src.hpp"
#include <iostream>

int main() {
    LinkedList<int> * list = new LinkedList<int>;
    LinkedList<int> * stack = new Stack<int>;
    LinkedList<int> * queue = new Queue<int>;
    
    std::cout << "LinkedList" << std::endl;
    list->pushFront(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushFront(4);
    list->print();
    list->popFront();
    list->popBack();
    list->print();
    std::cout << list->size() << std::endl;
    
    std::cout << stack->name() << std::endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    std::cout << stack->peak() << std::endl;
    stack->pop();
    std::cout << stack->pop() << std::endl;
    std::cout << stack->peak() << std::endl;
    
    std::cout << queue->name() << std::endl;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    std::cout << queue->peak() << std::endl;
    queue->pop();
    std::cout << queue->pop() << std::endl;
    std::cout << queue->peak() << std::endl;
    
    delete list;
    delete stack;
    delete queue;

    return 0;
}
