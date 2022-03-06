#include "main.hpp"
#include "../Map.hpp"
#include <map>

int ft_map(void)
{
    std::map<int, int>	map_1();
    //ft::map<int, int>	map_2(map_1.begin(), map_1.end());
    std::map<int, int>	map_3(map_1);
    return (0);
}
