#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <cstddef>
#include <stdexcept>
#include "iterator/random_access_iterator.hpp"
#include "iterator/iterator_traits.hpp"
#include "iterator/reverse_iterator.hpp"
#include "utility/enable_if.hpp"

namespace   ft
{
    template<class T, class Allocator = std::allocator<T> >
    class   vector
    {
	public:
		/*
		 *Typedef
		 */
		typedef	T			    value_type;
		typedef Allocator		    allocator_type;
		typedef typename allocator_type::reference   reference;
		typedef	typename allocator_type::const_reference	    const_reference;
		typedef	typename allocator_type::pointer		    pointer;
		typedef typename allocator_type::const_pointer	    const_pointer;
		typedef ft::random_access_iterator<value_type>    iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>		reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename    allocator_type::size_type	size_type;
		/*
		 *Constructor
		 */
		explicit vector(const allocator_type &alloc = allocator_type()) :
		    _alloc(alloc),
		    _M_start(NULL),
		    _M_end(NULL),
		    _M_end_of_storage(NULL) {}

		explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) : _alloc(alloc) {
		    _M_start = _alloc.allocate(n);
		    _M_end_of_storage = _M_start + n;
		    _M_end = _M_start;
		    while (n)
		    {
			_alloc.construct(_M_end, val);
			_M_end++;
			n--;
		    }
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if
			<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) 
			: _alloc(alloc) {
		    difference_type n = ft::dist(first, last);
		    _M_start = _alloc.allocate(n);
		    _M_end = _M_start;
		    _M_end_of_storage = _M_start + n;
		    while (n)
		    {
			_alloc.construct(_M_end, (*first));
			++first;
			++_M_end;
			n--;
		    }
		}

		vector(const vector &x) :
		    _alloc(x._alloc),
		    _M_start(NULL),
		    _M_end(NULL),
		    _M_end_of_storage(NULL) {
		    this->insert(this->begin(), x.begin(), x.end());
		}
		/*
		 * End of constructor
		 */
		~vector() {
		    this->clear();
		    _alloc.deallocate(_M_start, this->capacity());
		}

		vector	&operator=(const vector &x) {
		    if (*this == x)
			return (*this);
		    this->clear();
		    this->insert(this->end(), x.begin(), x.end());
		    return (*this);
		}
		/*
		 *Iterator function related
		 */
		iterator begin() {
		    return (_M_start);
		}

		const_iterator begin() const {
		    return (_M_start);
		}

		iterator end() {
		    return (_M_end);
		}

		const_iterator end() const {
		    return (_M_end);
		}

		reverse_iterator rbegin() {
		    return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const {
		    return (reverse_iterator(this->end()));
		}

		reverse_iterator rend() {
		    return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const {
		    return (reverse_iterator(this->begin()));
		}
		/*
		 *Capacity function related
		 */
		size_type   size() const {
		    return (this->_M_end - this->_M_start);
		}

		size_type   max_size() const {
		    return (allocator_type().max_size());
		}

		void	resize(size_type n, value_type val = value_type()) {
		    if (n > this->max_size())
			throw(std::length_error("vector::resize"));
		    else if (n < this->size())
		    {
			while (n < this->size())
			{
			    --_M_end;
			    _alloc.destroy(_M_end);
			}
		    }
		    else
			this->insert(this->end(), n - this->size(), val);
		}

		size_type   capacity() const {
		    return (this->_M_end_of_storage - this->_M_start);
		}

		bool	empty() const {
		    if (size() == 0)
			return (true);
		    return (false);
		}

		void	reserve(size_type n) {
		    if (n > this->max_size())
			throw(std::length_error("vector::reserve"));
		    else if (n > this->capacity())
		    {
			pointer	_M_start_stock = _M_start;
			pointer _M_end_stock = _M_end;
			size_type size_stock = this->size();
			size_type capacity_stock = this->capacity();

			_M_start = _alloc.allocate(n);
			_M_end_of_storage = _M_start + n;
			_M_end = _M_start;
			while (_M_start_stock != _M_end_stock)
			{
			    _alloc.construct(_M_end, *_M_start_stock);
			    _M_end++;
			    _M_start_stock++;
			}
			_alloc.deallocate(_M_start_stock - size_stock, capacity_stock);
		    }
		}
		/*
		 *Element access related
		 */
		reference operator[](size_type n) {
		    return (*(_M_start + n));
		}

		const_reference operator[](size_type n) const {
		    return (*(_M_start + n));
		}

		reference   at(size_type n) {
		    if (n >= this->size())
			throw(std::out_of_range("vector::at"));
		    else
			return ((*this)[n]);
		}

		reference front() {
		    return (*_M_start);
		}

		const_reference front() const {
		    return (*_M_start);
		}

		reference   back() {
		    return (*(_M_end - 1));
		}

		const_reference	back() const {
		    return (*(_M_end - 1));
		}
		/*
		 *Modifiers function related
		 */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::
		value, InputIterator>::type* = NULL) {
		    size_type	length = ft::dist(first, last);

		    this->clear();
		    if (length <= size_type(_M_end_of_storage - _M_start))
		    {
			while (*first != *last)
			{
			    _alloc.construct(_M_end, *first);
			    ++first;
			    ++_M_end;
			}
		    }
		    else
		    {
			pointer _M_start_new = pointer();
			pointer	_M_end_new = pointer();
			pointer _M_end_of_storage_new = pointer();

			_M_start_new = _alloc.allocate(length);
			_M_end_new = _M_start_new;
			_M_end_of_storage = _M_start_new + length;
			while (*first != *last)
			{
			    _alloc.construct(_M_end_new, *first);
			    ++first;
			    ++_M_end_new;
			}
			_alloc.deallocate(_M_start, this->capacity());
			_M_start = _M_start_new;
			_M_end = _M_end_new;
			_M_end_of_storage = _M_end_of_storage_new;
		    }
		}

		void	assign(size_type n, const value_type &val) {
		    this->clear();
		    if (n < 0)
			return ;
		    if (n <= size_type(_M_end_of_storage - _M_start))
		    {
			while (n)
			{
			    _alloc.construct(_M_end, val);
			    ++_M_end;
			    --n;
			}
		    }
		    else
		    {
			_alloc.deallocate(_M_start, this->capacity());
			_M_start = _alloc.allocate(n);
			_M_end = _M_start;
			_M_end_of_storage = _M_start + n;
			while (n)
			{
			    _alloc.construct(_M_end, val);
			    ++_M_end;
			    --n;
			}
		    }
		}

		void	push_back(const value_type &val) {
		    size_type capacity_new;

		    if (_M_end == _M_end_of_storage)
		    {
			capacity_new = this->size() + 1;
			this->reserve(capacity_new);
		    }
		    _alloc.construct(_M_end, val);
		    ++_M_end;
		}

		void	pop_back() {
		    _alloc.destroy(&this->back());
		    --_M_end;
		}

		iterator insert(iterator position, const value_type &val) {
		    size_type len = &(*position) - _M_start;
		    if (this->size() + 1 < size_type(_M_end_of_storage))
		    {
			for (size_type i = 0; i < len; i++)
			    _alloc.construct(_M_end - i, *(_M_end - i - 1));
			++_M_end;
			_alloc.construct(&(*position), val);
		    }
		    else
		    {
			pointer _M_start_new = pointer();
			pointer	_M_end_new = pointer();
			pointer	_M_end_of_storage_new = pointer();
			int capacity_new;

			if (this->size() == 0)
			    capacity_new = 1;
			else
			    capacity_new = this->size() * 2;
			_M_start_new = _alloc.allocate(capacity_new);
			_M_end_new = _M_start_new + this->size() + 1;
			_M_end_of_storage_new = _M_start_new + capacity_new;

			for (size_type i = 0; i < len; i++)
			    _alloc.construct(_M_start_new + i, *(_M_start + i));
			_alloc.construct(_M_start_new + len, val);
			for (size_type j = 0; j < this->size() - len; j++)
			    _alloc.construct(_M_end_new - j - 1, *(_M_end - j - 1));
			for (size_type k = 0; k < this->size(); k++)
			    _alloc.destroy(_M_start + k);
			if (_M_start)
			    _alloc.deallocate(_M_start, this->capacity());
			_M_start = _M_start_new;
			_M_end = _M_end_new;
			_M_end_of_storage = _M_end_of_storage_new;
		    }
		    return (iterator(_M_start + len));
		}

		void insert(iterator position, size_type n, const value_type &val) {
		    size_type len = &(*position) - _M_start;

		    if (n == 0)
			return ;
		    if (n > this->max_size())
			throw(std::length_error("vector::insert"));
		    if (n <= size_type(_M_end_of_storage - _M_end))
		    {
			for (size_type i = 0; i < this->size() - len; i++)
			    _alloc.construct(_M_end - i + (n - 1), *(_M_end - i - 1));
			_M_end += n;
			while (n)
			{
			    _alloc.construct(&(*position) + (n - 1), val);
			    --n;
			}
		    }
		    else
		    {
			pointer	_M_start_new = pointer();
			pointer	_M_end_new = pointer();
			pointer	_M_end_of_storage_new = pointer();
			int capacity_new;

			capacity_new = this->size() + n;
			_M_start_new = _alloc.allocate(capacity_new);
			_M_end_new = _M_start_new + this->size() + n;
			_M_end_of_storage = _M_start_new + capacity_new;
			for (int i = 0; i < (&(*position) - _M_start); i++)
			    _alloc.construct(_M_start_new + i, *(_M_start + i));
			for (size_type j = 0; j < n; j++)
			    _alloc.construct(_M_start_new + len + j, val);
			for (size_type k = 0; k < (this->size() - len); k++)
			    _alloc.construct(_M_end_new - k - 1, *(_M_end - k - 1));
			for (size_type l = 0; l < this->size(); l++)
			    _alloc.destroy(_M_start + l);
			_alloc.deallocate(_M_start, this->capacity());
			_M_start = _M_start_new;
			_M_end = _M_end_new;
			_M_end_of_storage = _M_end_of_storage_new;
		    }
		}

		    template<class InputIterator>
		    void insert(iterator position, InputIterator first, InputIterator last,
		    typename ft::enable_if<!ft::is_integral<InputIterator>::value,
		    InputIterator>::type* = NULL) {
			size_type ite_len = dist(first, last);
			size_type len = &(*position) - _M_start;

			if (size_type(_M_end_of_storage - _M_end) >= ite_len)
			{
			    for (size_type i = 0; i < this->size() - len; i++)
				_alloc.construct(_M_end - i + (ite_len - 1), *(_M_end - i - 1));
			    _M_end += ite_len;
			    while (&(*first) != &(*last))
			    {
				_alloc.construct(&(*position), *first);
				++first;
				++position;
			    }
			}
			else
			{
			    pointer _M_start_new = pointer();
			    pointer _M_end_new = pointer();
			    pointer _M_end_of_storage_new = pointer();
			    int capacity_new = this->size() + ite_len;

			    _M_start_new = _alloc.allocate(capacity_new);
			    _M_end_new = _M_start_new + capacity_new;
			    _M_end_of_storage_new = _M_end_new;
			    for (int i = 0; i < &(*position) - _M_start; i++)
				_alloc.construct(_M_start_new + i, *(_M_start + i));
			    for (int j = 0; &(*first) != &(*last); first++, j++)
				_alloc.construct(_M_start_new + len + j, *first);
			    for (size_type k = 0; k < this->size() - len; k++)
				_alloc.construct(_M_start_new + len + ite_len + k, *(_M_start + len + k));
			    for (size_type l = 0; l < this->size(); l++)
				_alloc.destroy(_M_start + l);
			    _alloc.deallocate(_M_start, this->capacity());
			    _M_start = _M_start_new;
			    _M_end = _M_end_new;
			    _M_end_of_storage = _M_end_of_storage_new;
			}
		    }

		    iterator erase(iterator position) {
			pointer	ret = &(*position);

			_alloc.destroy(&(*position));
			if (&(*position) + 1 == _M_end)
			    _alloc.destroy(&(*position));
			else
			{
			    for (int i = 0; i < _M_end - &(*position) - 1; i++)
			    {
				_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
				_alloc.destroy(&(*position) + i + 1);
			    }
			}
			--_M_end;
			return (iterator(ret));
		    }

		    iterator erase(iterator first, iterator last) {
			pointer	ret = &(*first);

			while (&(*first) != &(*last))
			{
			    _alloc.destroy(&(*first));
			    ++first;
			}
			for (int i = 0; i < _M_end - &(*last); i++)
			{
			    _alloc.construct(ret + i, *(&(*last) + i));
			    _alloc.destroy(&(*last) + i);
			}
			_M_end -= (&(*last) - ret);
			return (iterator(ret));
		    }

		    void swap(vector &x) {
			if (x == *this)
			    return ;
			pointer	_M_start_stock = x._M_start;
			pointer	_M_end_stock = x._M_end;
			pointer	_M_end_of_storage_stock = x._M_end_of_storage;
			allocator_type _alloc_stock = x._alloc;
			x._M_start = this->_M_start;
			x._M_end = this->_M_end;
			x._M_end_of_storage = this->_M_end_of_storage;
			x._alloc = this->_alloc;
			this->_M_start = _M_start_stock;
			this->_M_end = _M_end_stock;
			this->_M_end_of_storage = _M_end_of_storage_stock;
			this->_alloc = _alloc_stock;
		    }

		    void clear() {
			size_type tmp = this->size();
			while (tmp)
			{
			    --_M_end;
			    _alloc.destroy(_M_end);
			    --tmp;
			}
		    }

		    allocator_type  get_allocator() const {
			return (_alloc);
		    }
	    private:
		allocator_type	    _alloc;
		pointer		    _M_start;
		pointer		    _M_end;
		pointer		    _M_end_of_storage;

    };

    template<class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	typename ft::vector<T>::const_iterator first1 = lhs.begin();
	typename ft::vector<T>::const_iterator first2 = rhs.begin();
	if (lhs.size() != rhs.size())
	    return (false);
	while (first1 != lhs.end())
	{
	    if (first2 == rhs.end() || *first2 != *first1)
		return false;
	    ++first1;
	    ++first2;
	}
	return (true);
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (!(lhs == rhs));
    }

    template<class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	typename ft::vector<T>::const_iterator first1 = lhs.begin();
	typename ft::vector<T>::const_iterator first2 = rhs.begin();
	while (first1 != lhs.end())
	{
	    if (first2 == rhs.end() || *first2 < *first1)
		return false;
	    else if (*first2 > *first1)
		return (true);
	    ++first1;
	    ++first2;
	}
	return (false);
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (!(rhs < lhs));
    }

    template<class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (rhs < lhs);
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	return (!(lhs < rhs));
    }

    template<class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
	x.swap(y);
    }
}

#endif
