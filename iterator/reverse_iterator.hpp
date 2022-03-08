#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include "iterator_traits.hpp"

namespace ft
{
    template <class iterator>
    class reverse_iterator
    {
	public:
		/*
		 * Some typedef
		 */
		typedef	iterator						    iterator_type;
		typedef typename ft::iterator_traits<iterator>::iterator_category   iterator_category;
		typedef typename ft::iterator_traits<iterator>::value_type	    value_type; 
		typedef typename ft::iterator_traits<iterator>::difference_type	    difference_type;
		typedef typename ft::iterator_traits<iterator>::pointer		    pointer;
		typedef typename ft::iterator_traits<iterator>::reference	    reference;
		/*
		 * Almost cannonical form
		 */
		reverse_iterator() : _ite() {}
		explicit reverse_iterator(iterator_type it) : _ite(it) {}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &cp) : _ite(cp.base()) {}
		virtual ~reverse_iterator(void) {}
		iterator_type base(void) const {
		    return (_ite);
		}
		/*
		 *Operator overloading
		 */
		reference operator*(void) const {
		    iterator_type tmp = _ite;
		    return (*(--tmp));
		}
		reverse_iterator operator+(difference_type n) const {
		    return (reverse_iterator(_ite - n));
		}
		reverse_iterator &operator++(void) {
		    --_ite;
		    return (*this);
		}
		reverse_iterator operator++(int) {
		    reverse_iterator tmp = *this;
		    ++(*this);
		    return (tmp);
		}
		reverse_iterator &operator+=(difference_type n) {
		    _ite -= n;
		    return (*this);
		}
		reverse_iterator operator-(difference_type n) const {
		    return (reverse_iterator(_ite + n));
		}
		reverse_iterator &operator--(void) {
		    ++_ite;
		    return (*this);
		}
		reverse_iterator operator--(int) {
		    reverse_iterator tmp = *this;
		    --(*this);
		    return (tmp);
		}
		reverse_iterator &operator-=(difference_type n) {
		    _ite += n;
		    return (*this);
		}
		pointer operator->(void) const {
		    return (&(operator*()));
		}
		reference operator[](difference_type n) const {
		    return (this->base()[-n - 1]);
		}
	private:
		iterator_type	_ite;
    };

    template <class iterator>
    bool operator==
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() == second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator==
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() == second.base());
    }

    template <class iterator>
    bool operator!=
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() != second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator!=
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() != second.base());
    }

    template <class iterator>
    bool operator<
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() > second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator<
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() > second.base());
    }

    template <class iterator>
    bool operator<=
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() >= second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator<=
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() >= second.base());
    }

    template <class iterator>
    bool operator>
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() < second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator>
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() < second.base());
    }

    template <class iterator>
    bool operator>=
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() <= second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator>=
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() <= second.base());
    }

    template <class iterator>
    reverse_iterator<iterator> operator+
    (typename reverse_iterator<iterator>::difference_type n, const reverse_iterator<iterator> &first) {
	return (first + n);
    }

    template <class iterator>
    typename reverse_iterator<iterator>::difference_type operator-
    (const reverse_iterator<iterator> &first, const reverse_iterator<iterator> &second) {
	return (first.base() - second.base());
    }

    template <class iteratorL, class iteratorR>
    bool operator-
    (const reverse_iterator<iteratorL> &first, const reverse_iterator<iteratorR> &second) {
	return (first.base() - second.base());
    }
}

#endif
