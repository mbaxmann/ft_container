SRCS	=	main_test.cpp \

HEADER	=	utility/enable_if.hpp \
		utility/equal.hpp \
		utility/pair.hpp \
		iterator/iterator.hpp \
		iterator/iterator_traits.hpp \
		iterator/reverse_iterator.hpp \
		Vector.hpp \

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
