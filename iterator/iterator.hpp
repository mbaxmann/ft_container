#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
    class random_access_iterator_tag {};
    class bidirectional_iterator_tag {};
    class forward_iterator_tag {};
    class input_iterator_tag {};
    class output_iterator_tag {};

    template <class Category, class T, class Distance = ptrdiff_t,
	     class Pointer = T*, class Reference = T&>
    class iterator {
	public:
	    typedef T		        value_type;
	    typedef Distance		difference_type;
	    typedef Pointer		pointer;
	    typedef Reference		reference;
	    typedef Category		iterator_category;
    };

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
}

#endif
