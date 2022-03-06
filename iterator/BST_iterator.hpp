#ifndef BST_ITERATOR_HPP
# define BETS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template<typename T>
    class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
	public:
	    typedef typename T::value_type	    value_type;
	    typedef typename ft::iterator
	    <ft::bidirectinal_iterator_tag, value_type>::iterator_category  iterator_category;
	    typedef typename ft::iterator
	    <ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;
	    typedef typename ft::iterator
	    <ft::bidirectional_iterator_tag, value_type>::pointer   pointer;
	    typedef typename ft::iterator
	    <bidirectional_iterator_tag, value_type>::reference reference;

	    BST_iterator(void) :
		_node(),
		_last_node() {}

	    BST_iterator(T *node, T *last_node) :
		_node(node),
		_last_node(last_node) {}

	    BST_iterator(const BST_iterator &cp) :
		_node(cp._node),
		_last_node(cp._last_node) {}
	    virtual ~BST_iterator(void) {}

	    BST_iterator &operator=(const BST_iterator &cp) {
		if (*this == cp)
		    return (*this);
		this->_node = cp._node;
		this->_last_node = cp._last_node;
		return (*this);
	    }

	    bool    operator==(const BST_iterator &ite) {
		return (this->_node == ite->_node);
	    }

	    bool    operator!=(const BST_iterator &ite) {
		return (!(this->_node == ite->_node));
	    }

	    reference	operator*() const {
		return (this->_node->value);
	    }

	    pointer	operator->() const {
		return (&this->_node->value);
	    }

	    BST_iterator &operator++(void) {
		T   *current = _node;

		if (_current->right == _last_node)
		{
		    current = _node->parent;
		    while (current != _last_node && (current->value.first < _node->value.first))
			cursor = cursor->parent;
		    _node = cursor;
		}
		else if (current != _last_node)
		{
		    current = _node->right;
		    if (current == _last_node->parent && current->right == _last_node)
			_node = current;
		    else
			while (current->left != _last_node)
			    current = current->left;
		    _node = current;
		}
		return (*this);
	    }

	    BST_iterator operator++(int) {
		BST_iterator tmp(*this);
		operator++();
		return (tmp);
	    }
	    
	    BST_iterator &operator--(void) {
		T   *current = _node;

		if (_current->left == _last_node)
		{
		    current = _node->parent;
		    while (current != _last_node && (current->value.first > _node->value.first))
			cursor = cursor->parent;
		    _node = cursor;
		}
		else if (current != _last_node)
		{
		    current = _node->left;
		    if (current == _last_node->parent && current->left == _last_node)
			_node = current;
		    else
			while (current->right != _last_node)
			    current = current->right;
		    _node = current;
		}
		return (*this);
	    }

	    BST_iterator operator++(int) {
		BST_iterator tmp(*this);
		operator--();
		return (tmp);
	    }
	private:
	    T	*_node;
	    T	*_last_node;
    };
}

#endif























