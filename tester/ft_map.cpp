#include "main.hpp"
#include "../Map.hpp"
#include "../utility/pair.hpp"
#include <map>
#include <string>
#include <iostream>

template<class key, class T>
static void display_map(ft::map<key, T> &map) {
    typename ft::map<key, T>::iterator ite_1 = map.begin();
    typename ft::map<key, T>::iterator ite_2 = map.end();
    for (; ite_1 != ite_2; ite_1++)
	    std::cout << GREEN << (*ite_1).first << " " << (*ite_1).second << std::endl;
    std::cout << std::endl;
}

int ft_map(void)
{
    struct timeval begin;
    struct timeval end;
    gettimeofday(&begin, 0);
    //CONSTRUCTOR TESTING
    std::cout << BLUE << "Testing all map constructor:" << std::endl;
    ft::map<int, std::string> map_2;
    ft::map<int, std::string> map_1;
    std::cout << GREEN << "Success" << std::endl << std::endl;
    //END OF CONSTRUCTOR TESTING

    //INSERT, BEGIN(), END(), RBEGIN(), REND()
    std::cout << BLUE << "Testing begin(), end(), rbegin(), rend()" << std::endl;
    std::cout << CYAN << "Insert some value to map_1" << std::endl;
    map_1.insert(ft::make_pair(4, "Coucou"));
    map_1.insert(ft::make_pair(5, "42"));
    map_1.insert(ft::make_pair(6, "YIYIIYIYYII"));
    map_1.insert(ft::make_pair(7, "?.?"));
    std::cout << CYAN << "Displaying map using begin() to end()" << std::endl;
    display_map<int, std::string>(map_1);
    std::cout << CYAN << "Displaying map using rbegin() to rend()" << std::endl;
    ft::map<int, std::string>::reverse_iterator ite_1 = map_1.rbegin();
    ft::map<int, std::string>::reverse_iterator ite_2 = map_1.rend();
    for (; ite_1 != ite_2; ite_1++)
	    std::cout << GREEN << (*ite_1).first << " " << (*ite_1).second << std::endl;
    std::cout << std::endl;
    std::cout << CYAN << "Inserting to map_2 value of map_1" << std::endl;
    map_2.insert(map_1.begin(), map_1.end());
    std::cout << CYAN << "map_2:" << std::endl;
    display_map(map_2);
    //END OF BEGIN(), END(), REND(), RBEGIN(), REND()

    //EMPTY, SIZE, MAX_SIZE, CLEAR, OPERATOR=
    std::cout << BLUE << "Testing empty, size, max_size, clear, operator=" << std::endl;
    std::cout << CYAN << "Is map_1 empty? : " << GREEN << map_1.empty() << std::endl;
    std::cout << CYAN << "map_1 size : " << GREEN << map_1.size() << std::endl;
    std::cout << CYAN << "map_1	max_size : " << GREEN << map_1.max_size() << std::endl;
    std::cout << CYAN << "Clearing map_1" << std::endl;
    map_1.clear();
    std::cout << CYAN << "Is map_1 empty? : " << GREEN << map_1.empty() << std::endl;
    std::cout << CYAN << "map_1 size : " << GREEN << map_1.size() << std::endl;
    std::cout << CYAN << "map_1	max_size : " << GREEN << map_1.max_size() << std::endl;
    std::cout << CYAN << "map_1 = map_2" << std::endl;
    map_1 = map_2;
    std::cout << CYAN << "map_2" << std::endl;
    display_map(map_2);
    std::cout << CYAN << "map_1" << std::endl;
    display_map(map_1);
    //END OF EMPTY, SIZE, MAX_SIZE, CLEAR, OPERATOR=

    //ERASE, SWAP
    std::cout << BLUE << "Testing erase, swap" << std::endl;
    std::cout << CYAN << "Clearing map_1" << std::endl;
    map_1.clear();
    std::cout << CYAN << "Adding some value to map_1" << std::endl;
    map_1.insert(ft::make_pair(4, "de nouvelle chose"));
    map_1.insert(ft::make_pair(88, "pourqoi pas"));
    map_1.insert(ft::make_pair(-6, "non")); 
    std::cout << CYAN << "map_2" << std::endl;
    display_map(map_2);
    std::cout << CYAN << "map_1" << std::endl;
    display_map(map_1);
    std::cout << CYAN << "Swaping map_1 and map_2" << std::endl;
    map_2.swap(map_1);
    std::cout << CYAN << "map_2" << std::endl;
    display_map(map_2);
    std::cout << CYAN << "map_1" << std::endl;
    display_map(map_1);
    std::cout << CYAN << "Erasing 2nd element of map_2" << std::endl;
    ft::map<int, std::string>::iterator tmp = map_2.begin();
    tmp++;
    map_2.erase(tmp);
    display_map(map_2);
    std::cout << CYAN << "Erasing 2 last element of map_1" << std::endl;
    tmp = map_1.begin();
    tmp++;
    tmp++;
    map_1.erase(tmp, map_1.end());
    display_map(map_1);
    std::cout << CYAN << "Erasing key -6 of map_2" << std::endl;
    map_2.erase(-6);
    display_map(map_2);
    //END OF ERASE, SWAP

    //KEY_COMP, VALUE_COMP, OPERATOR[]
    std::cout << BLUE << "Testing key_comp, value_comp, operator[]" << std::endl;
    std::cout << CYAN << "Getting key_comp copy" << std::endl;
    ft::map<int, std::string>::key_compare key_cp = map_1.key_comp();
    std::cout << CYAN << "Comparing key 33 and key -666 using the key_comp copy : ";
    std::cout << GREEN << key_cp(33, -666) << std::endl;
    std::cout << CYAN << "Comparing key -666 and key 33 using the key_comp copy : ";
    std::cout << GREEN << key_cp(-666, 33) << std::endl;
    std::cout << CYAN << "Getting value_comp copy" << std::endl;
    ft::map<int, std::string>::value_compare value_cp = map_1.value_comp();
    std::cout << CYAN << "Comparing pair(33, ""test"") and pair(-666, ""nop"")  using the value_comp copy : ";
    std::cout << GREEN << 
    value_cp(ft::make_pair(33, "test") , ft::make_pair(-666, "nop")) << std::endl;
    std::cout << CYAN << "Comparing pair(-666, ""nop"") and pair(33, ""test"")  using the value_comp copy : ";
    std::cout << GREEN <<
    value_cp(ft::make_pair(-666, "nop") , ft::make_pair(33, "test")) << std::endl;
    std::cout << CYAN << "map_1[5] : " << GREEN << map_1[5] << std::endl;
    std::cout << CYAN << "map_1[4] : " << GREEN << map_1[4] << std::endl;
    std::cout << CYAN << "map_2[88] : " << GREEN << map_2[88] << std::endl << std::endl;
    //END OF KEY_COMP, VALUE_COMP, OPERATOR[]
    
    //FIND, COUNT, LOWER_BOUND, UPPER_BOUND, EQUAL_RANGE
    std::cout << BLUE << "Testing find, count, lower_bound, upper_bound, equal_range" << std::endl;
    std::cout << CYAN << "Adding some element to map_2" << std::endl;
    map_2.insert(ft::make_pair(39, "Nouveau"));
    map_2.insert(ft::make_pair(54, "element"));
    map_2.insert(ft::make_pair(60, "testing"));
    map_2.insert(ft::make_pair(89, "fin"));
    display_map(map_2);
    std::cout << CYAN << "Finding element 54: " << GREEN << (*(map_2.find(54))).second << std::endl;
    std::cout << CYAN << "Counting occurence of (k = 60) element: " << GREEN
    << map_2.count(60) << std::endl;
    std::cout << CYAN << "Lowerbound of k = 54: " << GREEN << (*(map_2.lower_bound(54))).second << std::endl;
    std::cout << CYAN << "Upperbound of k = 54: " << GREEN << (*(map_2.upper_bound(54))).second << std::endl;
    std::cout << CYAN << "map_2.equal_range(60) : " << GREEN << (*(map_2.equal_range(60)).first).first << std::endl;

    gettimeofday(&end, 0);
    std::cout << "Time: " << (end.tv_usec - begin.tv_usec) << std::endl;
    //END
    return (0);
}

















