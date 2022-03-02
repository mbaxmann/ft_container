#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include "iterator.hpp"

namespace ft
{
    template <class iterator>
    class iterator_traits
    {
	public:
	    typedef iterator::difference_type		difference_type;
	    typedef iterator::value_type		value_type;
	    typedef iterator::pointer			pointer;
	    typedef iterator::reference			reference;
	    typedef iterator::iterator_category		iterator_category;
    }

    template <class T>
    class iterator_traits<T*>
    {
	pulic:
	    typedef ptrdiff_t				difference_type;
	    typedef T					value_type;
	    typedef T*					pointer;
	    typedef T&					reference;
	    typedef ft::random_access_iterator_tag	iterator_category;
    }

    template <class T>
    class iterator_traits<const T*>
    {
	public:
	    typedef ptrdiff_t				difference_type;
	    typedef T					value_type;
	    typedef const T*				pointer;
	    typedef const T&				reference;
	    typedef ft::random_access_iterator_tag	iterator_category;
    }
}

#endif
