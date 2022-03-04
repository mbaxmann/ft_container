#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    /*
     * Empty class for iterator specialisation
     */
    class random_access_iterator_tag {};
    class bidirectional_iterator_tag {};
    class forward_iterator_tag {};
    class input_iterator_tag {};
    class output_iterator_tag {};

    /*
     * Iterator clas start
     */
    template <class Category, class T, class Distance = ptrdiff_t,
	      class Pointer = T*, class Reference = T&>
    class iterator
    {
	public:
		/*
		 * Some typedef
		 */
		typedef T		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		/*
		 *Canonical form
		 */
		iterator(void) : _ptr(NULL) {}
		iterator(pointer ptr) : _ptr(ptr) {}
		iterator(const iterator &cp) : _ptr(cp._ptr) {}
		virtual ~iterator(void) {}
		iterator &operator=(const iterator &cp) {
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
		iterator &operator++(void) {
		    _ptr++;
		    return (*this);
		}
		iterator operator++(int) {
		    iterator ret(*this);
		    operator++();
		    return (ret);
		}
		iterator &operator--(void) {
		    _ptr--;
		    return (*this);
		}
		iterator operator--(int) {
		    iterator ret(*this);
		    operator--();
		    return (ret);
		}
		iterator operator+(difference_type i) const {
		    return (_ptr + i);
		}
		iterator operator-(difference_type i) const {
		    return (_ptr - i);
		}
		iterator &operator+=(difference_type i) {
		    _ptr += i;
		    return (*this);
		}
		iterator &operator-=(difference_type i) {
		    _ptr -= i;
		    return (*this);
		}
		reference operator[](difference_type i) {
		    return (*(operator+(i)));
		}
	private:
		pointer	_ptr;
    };
    
    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator==
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() == second.getPtr());
    }

    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator!=
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() != second.getPtr());
    }    
    
    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator<
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() < second.getPtr());
    }
    
    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator>
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() > second.getPtr());
    }

    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator<=
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() <= second.getPtr());
    }

    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator>=
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() >= second.getPtr());
    }

    template<class Category, typename T>
    ft::iterator<Category, T> operator+
    (typename ft::iterator<Category, T>::diference_type i, typename ft::iterator<Category, T> &ite) {
	return (&(*ite) + i);
    }

    template<class Category, typename T>
    typename ft::iterator<Category, T>::difference_type operator-
    (const ft::iterator<Category, T> first, const ft::iterator<Category, T> second) {
	return (first.getPtr() - second.getPtr());
    }
}
#endif
