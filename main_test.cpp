#include "Vector.hpp"

int main(void)
{
    ft::vector<int> vector_1(4, 25);
    ft::vector<int> vector_2(vector_1);
    ft::vector<int> vector_3();
    ft::vector<int> 
    vector_4(ft::iterator<ft::input_iterator_tag, int>, ft::iterator<ft::input_iterator_tag, int>);
    return (0);
}
