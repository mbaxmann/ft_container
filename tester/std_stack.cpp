#include "main.hpp"
#include <stack>
#include <vector>
#include <deque>
#include <iostream>

int std_stack(void)
{
    struct timeval begin;
    struct timeval end;
    gettimeofday(&begin, 0);
    std::cout << CYAN  << "Constructing stack object" << std::endl;
    std::stack<int> stack_1;
    std::cout << CYAN << "Constructing 2 stack obejct with the STL deque and vector underlying container";
    std::cout << std::endl;
    std::stack<int, std::vector<int> > test;
    std::stack<int, std::deque<int> > test2;
    std::cout << GREEN << "OK" << std::endl;
    std::cout << CYAN << "stack_1.empty() : " << GREEN << stack_1.empty() << std::endl;
    std::cout << CYAN << "Push to stack_1 : 0 , -16, 42, 300" << std::endl;
    stack_1.push(0);
    stack_1.push(-16);
    stack_1.push(42);
    stack_1.push(300);
    std::cout << CYAN << "stack_1.size() : " << GREEN << stack_1.size() << std::endl;
    std::cout << CYAN << "stack_1.top() : " << GREEN << stack_1.top() << std::endl;
    std::cout << CYAN << "Popping stack_1" << std::endl;
    stack_1.pop();
    std::cout << CYAN << "stack_1.top() : " << GREEN << stack_1.top() << std::endl;
    std::cout << CYAN << "stack_1.empty() : " << GREEN << stack_1.empty() << std::endl;
    std::cout << CYAN << "stack_1.size() : " << GREEN << stack_1.size() << std::endl;

    gettimeofday(&end, 0);
    std::cout << "Time: " << (end.tv_usec - begin.tv_usec) << std::endl;
    return (0);
}
