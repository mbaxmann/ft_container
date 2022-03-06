#include "main.hpp"
#include <iostream>

void	execute_cmd(std::string cmd)
{
    if (!cmd.compare("ft_vector"))
	ft_vector();
    else if (!cmd.compare("ft_map"))
	ft_map();
}

int main(void)
{
    std::string	cmd = "init";

    while (cmd.compare("exit"))
    {
	std::cout << "Enter command: ";
	std::cin >> cmd;
	execute_cmd(cmd);
    }
    return (0);
}
