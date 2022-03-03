#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator/iterator.hpp"
#include "iterator/iterator_traits.hpp"
#include "iterator/reverse_iterator.hpp"

namespace   ft
{
    template<class T, class Allocator = std::allocator<T>>

    class   vector
    {
	public:
		/*
		 *Typedef
		 */
		typedef	T			    value_type;
		typedef Allocator		    allocator_type;
		typedef reference		    allocator_type::reference;
		typedef	const_reference		    allocator_type::const_reference;
		typedef	pointer			    allocator_type::pointer;
		typedef const_pointer		    allocator_type::const_pointer;
		typedef ft::iterator<ft::random_access_iterator_tag, value_type>    iterator;
		typedef ft::iterator<ft::random_access_iterator_tag, const value_type>	iterator;
		typedef ft::reverse_iterator<iterator>		reverse_iterator;
		typedef	ft_reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename    allocator_type::size_type	size_type;
		/*
		 *Constructor
		 */
		explicit vector(const allocator_type &alloc = allocator_type()) :
		    _alloc(alloc),
		    _M_start(NULL),
		    _M_finish(NULL),
		    _M_end_of_storage(NULL) {}

		explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) : _alloc(alloc) {
		    _M_start = _alloc.allocate(n);
		    _M_end_of_storage = _start + n;
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
			const allocator_type &alloc = allocator_type()) : _alloc(alloc) {
		    typedef typename ft::is_integral<InputIterator>::type   integral;
		    ft::iterator tmp = first;
		    difference_type n = 0;
		    while (tmp != last)
			n++;
		    _M_start = _alloc.allocate(n);
		    _M_end = _M_start;
		    _M_end_of_storage = _M_start + n;
		    while (n)
		    {
			_alloc.construct(_M_end, *first);
			first++;
			_M_end++;
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
		    _alloc.dealloctae(_start, this->capacity());
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
		void assign(InputIterator first, InputIterator last) {
		    typedef typename ft::is_integral<InputIterator>::type integral;
		    size_type	length = 0;
		    ft::iterator    tmp = first;

		    this->clear();
		    while (tmp != last)
		    {
			++tmp;
			length++;
		    }
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

			_M_start_new = _allocallocate(length);
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
	    private:
		pointer		    _M_start;
		pointer		    _M_end;
		pointer		    _M_end_of_storage;
		allocator_type	    _alloc;
    };
}

#endif
























