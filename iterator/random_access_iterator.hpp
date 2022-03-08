#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef>
#include "iterator.hpp"

namespace ft
{
    /*
     * Iterator clas start
     */
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
	public:
		/*
		 * Some typedef
		 */
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type 	difference_type;
		typedef T*		pointer;
		typedef T&		reference;

		/*
		 *Canonical form
		 */
		random_access_iterator(void) : _ptr(NULL) {}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator &cp) : _ptr(cp._ptr) {}
		virtual ~random_access_iterator(void) {}
		random_access_iterator &operator=(const random_access_iterator &cp) {
		    if (this == &cp)
			return (*this);
		    this->_ptr = cp._ptr;
		    return (*this);
		}
		/*
		 * Getter
		 */
		pointer	getPtr(void) const {
		    return (this->_ptr);
		}
		/*
		 * Other operator overloading
		 */
		reference operator*(void) const {
		    return (*_ptr);
		}
		pointer	operator->(void) {
		    return (&(this->operator*()));
		}
		random_access_iterator &operator++(void) {
		    _ptr++;
		    return (*this);
		}
		random_access_iterator operator++(int) {
		    random_access_iterator ret(*this);
		    operator++();
		    return (ret);
		}
		random_access_iterator &operator--(void) {
		    _ptr--;
		    return (*this);
		}
		random_access_iterator operator--(int) {
		    random_access_iterator ret(*this);
		    operator--();
		    return (ret);
		}
		random_access_iterator operator+(difference_type i) const {
		    return (_ptr + i);
		}
		random_access_iterator operator-(difference_type i) const {
		    return (_ptr - i);
		}
		random_access_iterator &operator+=(difference_type i) {
		    _ptr += i;
		    return (*this);
		}
		random_access_iterator &operator-=(difference_type i) {
		    _ptr -= i;
		    return (*this);
		}
		reference operator[](difference_type i) {
		    return (*(operator+(i)));
		}

		operator random_access_iterator<const T> () const {
		    return (random_access_iterator<const T>(this->_ptr));
		}
	private:
		pointer	_ptr;
    };
    
    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator==
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() == rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator==
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() == rhs.getPtr());
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator!=
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() != rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator!=
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() != rhs.getPtr());
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator<
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() < rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator<
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() < rhs.getPtr());
    }
   
    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator>
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() > rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator>
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() > rhs.getPtr());
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator<=
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() <= rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator<=
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() <= rhs.getPtr());
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator>=
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() >= rhs.getPtr());
    }

    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator>=
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() >= rhs.getPtr());
    }

    template<typename T>
    ft::random_access_iterator<T> operator+
    (typename ft::random_access_iterator<T>::diference_type i, typename ft::random_access_iterator<T> &ite) {
	return (&(*ite) + i);
    }

    template<typename T1, typename T2>
    ft::random_access_iterator<T1> operator+
    (typename ft::random_access_iterator<T1>::diference_type i, typename ft::random_access_iterator<T2> &ite) {
	return (&(*ite) + i);
    }

    template<typename T>
    typename ft::random_access_iterator<T>::difference_type operator-
    (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) {
	return (lhs.getPtr() - rhs.getPtr());
    }
    
    template<typename T1, typename T2>
    typename ft::random_access_iterator<T1>::difference_type operator-
    (const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
	return (lhs.getPtr() - rhs.getPtr());
    }

}
#endif
