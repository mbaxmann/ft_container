#include <vector>
#include "main.hpp"
#include <iostream>

template<typename T>
static void display_vector(std::vector<T> vec) {
    typename std::vector<T>::iterator ite_1 = vec.begin();
    typename std::vector<T>::iterator ite_2 = vec.end();
    for (int i = 0; (ite_1 + i) != ite_2; i++)
	    std::cout << GREEN << *(ite_1 + i) << " ";
    std::cout << std::endl;
}

int std_vector(void)
{
    struct timeval begin;
    struct timeval end;
    gettimeofday(&begin, 0);
    //CONSTRUCTOR TESTING
    std::cout << BLUE << "Testing all vector constructor:" << std::endl;
    std::vector<int> vector_1(4, 25);
    std::vector<int> vector_2(vector_1);
    std::vector<int> vector_3;
    std::vector<int> 
    vector_4(std::iterator<std::input_iterator_tag, int>, std::iterator<std::input_iterator_tag, int>);
    std::cout << GREEN << "Success" << std::endl << std::endl;
    //END OF CONSTRUCTOR TESTING

    //BEGIN(), END(), RBEGIN(), REND()
    vector_2.clear();
    vector_2.push_back(1);
    vector_2.push_back(2);
    vector_2.push_back(3);
    vector_2.push_back(4);
    vector_2.push_back(5);
    std::cout << BLUE << "Testing begin(), end(), rbegin(), rend()" << std::endl;
    std::cout << CYAN << "Displaying vector using begin() to end()" << std::endl;
    display_vector(vector_2);
    std::cout << CYAN << "Displaying vector using rbegin() to rend()" << std::endl;
    std::vector<int>::reverse_iterator ite_1 = vector_2.rbegin();
    std::vector<int>::reverse_iterator ite_2 = vector_2.rend();
    for (; ite_1 != ite_2; ite_1++)
	std::cout << GREEN << *ite_1 << " ";
    std::cout << std::endl << std::endl;
    //END OF BEGIN(), END(), REND(), RBEGIN(), REND()

    //PUSH_BACK POP_BACK
    std::cout << BLUE << "Testing push_back(), pop_back()" << std::endl;
    std::cout << CYAN << "Vector size : " << GREEN << vector_3.size() << std::endl;
    std::cout << CYAN << "Pushing numbers: 3, -5, 30, 13" << std::endl;
    vector_3.push_back(3);
    vector_3.push_back(-5);
    vector_3.push_back(30);
    vector_3.push_back(13);
    std::cout << CYAN << "Getting iterator begin() and end()" << std::endl;
    std::cout << CYAN << "Display the vector:" << std::endl;
    display_vector(vector_3);
    if (vector_3.size() == 4)
    {
	std::cout << GREEN << "Vector size : " << vector_3.size() << std::endl;
    }
    else
    {
	std::cout << RED << "Vector size : " << vector_3.size() << std::endl;
	std::cout << RED << "FAILLED" << std::endl << std::endl;
    }
    std::cout << CYAN << "Popping 2 elements of vector" << std::endl;
    vector_3.pop_back();
    vector_3.pop_back();
    if (vector_3.size() == 2)
    {
	std::cout << GREEN << "Vector size : " << vector_3.size() << std::endl;
	std::cout << GREEN << "Success" << std::endl << std::endl;
    }
    else
    {
	std::cout << RED << "Vector size : " << vector_3.size() << std::endl;
	std::cout << RED << "FAILLED" << std::endl << std::endl;
    }
    //END OF PUSH_BACk POP_BACK
    
    //ASSIGN, INSERT, CLEAR, ERASE, SWAP
    std::cout << BLUE << "Testing assign, insert, clear, erase" << std::endl;
    std::cout << CYAN << "Vector_1:" << std::endl;
    display_vector(vector_1);
    std::cout << CYAN << "Assigning to Vector_2 the value of Vector_1" << std::endl;
    vector_3.assign(vector_1.begin(), vector_1.end());
    std::cout << CYAN << "Vector_2:" << std::endl;
    display_vector(vector_3);
    std::cout << CYAN << "Clearing vector_2:" << std::endl;
    vector_3.clear();
    if (vector_3.size() == 0)
	std::cout << GREEN << "vector_2 size: " << vector_3.size() << std::endl;
    else
	std::cout << RED << "vector_2 size: " << vector_3.size() << std::endl;
    std::cout << CYAN << "Assigning to vector_2 10 value of 666:" << std::endl;
    vector_3.assign(10, 666);
    std::cout << CYAN << "Vector_2:" << std::endl;
    display_vector(vector_3);
    if (vector_3.size() == 10)
	std::cout << "vector_2 size: " << vector_3.size() << std::endl;
    else
	std::cout << RED << "vector_2 size: " << vector_3.size() << std::endl;
    std::cout << CYAN << "Inserting 42 to vector_2 in 5 position" << std::endl;
    vector_3.insert(vector_3.begin() + 5, 42);
    display_vector(vector_3);
    std::cout << CYAN << "Inserting 3 time the value 33 to vector_2 in 6 position" << std::endl;
    vector_3.insert(vector_3.begin() + 6, 3, 33);
    display_vector(vector_3);
    std::cout << CYAN << "Vector_1" << std::endl;
    display_vector(vector_1);
    std::cout << CYAN << "Inserting vector_1 in vector_2 in 5 position" << std::endl;
    vector_3.insert(vector_3.begin() + 5, vector_1.begin(), vector_1.end());
    display_vector(vector_3);
    std::cout << CYAN << "Erasing 42 from vector_2" << std::endl;
    vector_3.erase(vector_3.begin() + 9);
    display_vector(vector_3);
    std::cout << CYAN << "Erasing all 33 from vector_2" << std::endl;
    vector_3.erase(vector_3.begin() + 9, vector_3.begin() + 12);
    display_vector(vector_3);
    std::cout << CYAN << "Swaping vector_2 with vector_1" << std::endl;
    vector_3.swap(vector_1);
    std::cout << CYAN << "Vector_2" << std::endl;
    display_vector(vector_3);
    std::cout << CYAN << "Vector_1" << std::endl;
    display_vector(vector_1);
    std::cout << CYAN << "Swaping vector_2 with vector_1 with the non member function" << std::endl;
    std::swap(vector_3, vector_1);
    std::cout << CYAN << "Vector_2" << std::endl;
    display_vector(vector_3);
    std::cout << CYAN << "Vector_1" << std::endl;
    display_vector(vector_1);
    std::cout << std::endl;
    //END OF ASSING, INSERT, CLEAR, ERASE, SWAP

    //MAX_SIZE, RESIZE, CAPACITY, EMPTY, RESERVE
    std::cout << BLUE << "Testing max_size, resize, capacity, empty, reserve" << std::endl;
    std::cout << CYAN << "Clearing vector_1" << std::endl;
    vector_1.clear();
    std::cout << CYAN << "vector_1 max_size: " << GREEN << vector_1.max_size() << std::endl;
    std::cout << CYAN << "vector_1 is empty? : " << GREEN << vector_1.empty() << std::endl;
    std::cout << CYAN << "vector_1 capacity : " << GREEN << vector_1.capacity() << std::endl;
    std::cout << CYAN << "Reserving a capacity of 10 for vector_1" << std::endl;
    vector_1.reserve(10);
    std::cout << CYAN << "vector_1 capacity : " << GREEN << vector_1.capacity() << std::endl;
    std::cout << CYAN << "Resizing vector_1 to contain 4" << std::endl;
    vector_1.resize(4);
    display_vector(vector_1);
    std::cout << CYAN << "Resizing vector_1 to contain 1" << std::endl;
    vector_1.resize(1);
    display_vector(vector_1);
    std::cout << std::endl;
    //END OF MAX_SIZE, RESIZE, CAPACITY, EMPTY, RESERVE

    //OPERATOR[], AT, FRONT, BACK
    std::cout << BLUE << "Testing operator[], at, front, back" << std::endl;
    std::cout << CYAN << "vector_2[6]: " << GREEN << vector_3[6] << std::endl;
    std::cout << CYAN << "vector_2[9]: " << GREEN << vector_3[9] << std::endl;
    std::cout << CYAN << "vector_2 at 6 posittion: " << GREEN << vector_3.at(6) << std::endl;
    std::cout << CYAN << "Pushing 22 to vector_2" << std::endl;
    vector_3.push_back(22);
    display_vector(vector_3);
    std::cout << CYAN << "vector_2 front: " << GREEN << vector_3.front() << std::endl;
    std::cout << CYAN << "vector_2 back: " << GREEN << vector_3.back() << std::endl << std::endl;
    //END OF OPERATOR[], AT, FRONT, BACK
   
    //TESTING ALL OPERATOR
    std::cout << BLUE << "Testing all operator" << std::endl;
    std::cout << CYAN << "vector_1" << std::endl;
    display_vector(vector_2);
    std::cout << CYAN << "vector_2" << std::endl;
    display_vector(vector_3);
    std::cout << CYAN << "vector_1 == vector_2: " << GREEN << (vector_2 == vector_3) << std::endl;
    std::cout << CYAN << "vector_1 != vector_2: " << GREEN << (vector_2 != vector_3) << std::endl;
    std::cout << CYAN << "vector_1 < vector_2: " << GREEN << (vector_2 < vector_3) << std::endl;
    std::cout << CYAN << "vector_1 <= vector_2: " << GREEN << (vector_2 <= vector_3) << std::endl;
    std::cout << CYAN << "vector_1 > vector_2: " << GREEN << (vector_2 > vector_3) << std::endl;
    std::cout << CYAN << "vector_1 >= vector_2: " << GREEN << (vector_2 >= vector_3) << std::endl;
    std::cout << CYAN << "vector_1 = vector_2: " << std::endl;
    vector_2 = vector_3;
    std::cout << CYAN << "vector_1" << std::endl;
    display_vector(vector_2);
    std::cout << CYAN << "vector_2" << std::endl;
    display_vector(vector_3);
    //END OF OPERATOR TESTING

    //ITERATOR
    std::cout << BLUE << "Testing iterator" << std::endl;
    std::cout << CYAN << "iterator it_1 = vector_1.begin()" << std::endl;
    std::cout << CYAN << "iterator it_2 = vector_2.begin()" << std::endl;
    std::cout << CYAN << "const_iterator it_3 = vector_1.begin()" << std::endl;
    std::vector<int>::iterator it_1 = vector_2.begin();
    std::vector<int>::iterator it_2 = vector_3.begin();
    std::vector<int>::const_iterator it_3 = vector_2.begin();
    std::cout << CYAN << "it_1 == it_2 : " << GREEN << (it_1 == it_2) << std::endl;
    std::cout << CYAN << "it_3 == it_2 : " << GREEN << (it_3 == it_2) << std::endl;

    std::cout << CYAN << "it_1 != it_2 : " << GREEN << (it_1 != it_2) << std::endl;
    std::cout << CYAN << "it_3 != it_2 : " << GREEN << (it_3 != it_2) << std::endl;

    std::cout << CYAN << "it_1 < it_2 : " << GREEN << (it_1 < it_2) << std::endl;
    std::cout << CYAN << "it_3 < it_2 : " << GREEN << (it_3 < it_2) << std::endl;

    std::cout << CYAN << "it_1 <= it_2 : " << GREEN << (it_1 <= it_2) << std::endl;
    std::cout << CYAN << "it_3 <= it_2 : " << GREEN << (it_3 <= it_2) << std::endl;

    std::cout << CYAN << "it_1 > it_2 : " << GREEN << (it_1 > it_2) << std::endl;
    std::cout << CYAN << "it_3 > it_2 : " << GREEN << (it_3 > it_2) << std::endl;

    std::cout << CYAN << "it_1 >= it_2 : " << GREEN << (it_1 >= it_2) << std::endl;
    std::cout << CYAN << "it_3 >= it_2 : " << GREEN << (it_3 >= it_2) << std::endl;

    gettimeofday(&end, 0);
    std::cout << "Time: " << (end.tv_usec - begin.tv_usec) << std::endl;
    return (0);
}
