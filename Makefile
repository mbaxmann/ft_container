SRCS	=	tester/main.cpp \
		tester/ft_vector.cpp \
		tester/ft_map.cpp \

HEADER	=	tester/main.hpp \
		utility/enable_if.hpp \
		utility/equal.hpp \
		utility/pair.hpp \
		utility/binary_search_tree.hpp \
		iterator/iterator.hpp \
		iterator/iterator_traits.hpp \
		iterator/reverse_iterator.hpp \
		iterator/BST_iterator.hpp \
		Vector.hpp \
		Map.hpp \

OBJS    =       ${SRCS:.cpp=.o}

CXX      =       c++

CXXFLAGS   =       -Wall -Wextra -Werror -std=c++98 -g

NAME    =	ft_container_test

RM      =       rm -rf

all:    ${NAME}

%.o: %.cpp	${HEADER}
	${CXX} ${CXXFLAGS} -o $@ -c $<

${NAME}:        ${HEADER} ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:         clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
