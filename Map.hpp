#ifndef MAP_HPP
# define MAP_HPP

#include "utility/binary_search_tree.hpp"
#include "iterator/BST_iterator.hpp"

namespace ft
{
    template <class Arg1, class Arg2, class Result>
    struct binary_function {
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
    };

    template<class T>
    struct less : binary_function<T, T, bool> {
	bool operator()(const T &x, const T &y) const {return (x < y);}
    };

    template<class Key, class T, class Compare = less<Key>
	    class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    };
}

#endif
