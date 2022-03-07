#include "main.hpp"
#include "../Map.hpp"
#include "../utility/pair.hpp"
#include <map>
#include <string>
#include <iostream>

template<class key, class T>
static void display_map(ft::map<key, T> map) {
    typename ft::map<key, T>::iterator ite_1 = map.begin();
    typename ft::map<key, T>::iterator ite_2 = map.end();
    for (; ite_1 != ite_2; ite_1++)
	    std::cout << GREEN << (*ite_1).first << " ";
    std::cout << std::endl;
}

int ft_map(void)
{
    //CONSTRUCTOR TESTING
    std::cout << BLUE << "Testing all map constructor:" << std::endl;
    ft::map<int, int> map_1;
    ft::map<int, std::string> map_2;
    std::cout << GREEN << "Success" << std::endl << std::endl;
    //END OF CONSTRUCTOR TESTING

    //INSERT, BEGIN(), END(), RBEGIN(), REND()
    map_2.insert(ft::make_pair(4, "Coucou"));
    map_1.insert(ft::make_pair(5, 13));
    map_1.insert(ft::make_pair(6, 14));
    map_1.insert(ft::make_pair(7, 15));
    std::cout << BLUE << "Testing begin(), end(), rbegin(), rend()" << std::endl;
    std::cout << CYAN << "Displaying map using begin() to end()" << std::endl;
    display_map<int, std::string>(map_2);
    std::cout << CYAN << "Displaying map using rbegin() to rend()" << std::endl;
    ft::map<int, int>::reverse_iterator ite_1 = map_1.rbegin();
    ft::map<int, int>::reverse_iterator ite_2 = map_1.rend();
    //END OF BEGIN(), END(), REND(), RBEGIN(), REND()

    return (0);
}



