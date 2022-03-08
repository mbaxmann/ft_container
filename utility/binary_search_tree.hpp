#ifndef BINARY_SEARCH_TREE
# define BINARY_SEARCH_TREE

#include <cwchar>
#include <memory>
#include "../iterator/BST_iterator.hpp"
#include "pair.hpp"
#include "enable_if.hpp"

namespace ft
{
    template<typename T>
    class   node
    {
	public:
	    typedef T	    value_type;

	    value_type	value;
	    node	*parent;
	    node	*left;
	    node	*right;

	    node(void) :
		value(),
		parent(NULL),
		left(NULL),
		right(NULL)
	    {}

	    node(const value_type &val, node *parent = NULL,
		    node *left = NULL, node *right = NULL) :
		value(val),
		parent(parent),
		left(left),
		right(right)
	    {}

	    node(node *parent = NULL, node *left = NULL, node *right = NULL) :
		value(),
		parent(parent),
		left(left),
		right(right)
	    {}

	    node(const node &cp) :
		value(cp.value),
		parent(cp.parent),
		left(cp.left),
		right(cp.right)
	    {}

	    virtual ~node(void) {}

	    node    &operator=(const node &cp) {
		if (*this == cp)
		    return (*this);
		this->value = cp.value;
		this->parent = cp.parent;
		this->left = cp.left;
		this->right = cp.right;
		return (*this);
	    }

	    bool    operator==(const node &cp) {
		if (this->value == cp.value)
		    return (true);
		return (false);
	    }
    };

    template<class T, class Compare = ft::less<T>, class Node = ft::node<T>,
	    class alloc = std::allocator<T>, class Node_alloc = std::allocator<Node> >
    class BST
    {
	public:
	    typedef T				    value_type;
	    typedef Node_alloc			    node_alloc;
	    typedef size_t			    size_type;
	    typedef Node *			    nodePTR;
	    typedef ft::BST_iterator<Node, Compare>		iterator;
	    typedef ft::BST_const_iterator<Node, Compare>	const_iterator;

	    nodePTR	_last_node;
	    node_alloc	_node_alloc;

	    BST(const node_alloc &node_alloc_init = node_alloc()) :
		_node_alloc(node_alloc_init) {
		_last_node = _node_alloc.allocate(1);
		_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
	    }

	    ~BST(void) {
		_node_alloc.destroy(_last_node);
		_node_alloc.deallocate(_last_node, 1);
	    }
	    
	    ft::pair<iterator, bool> insert(value_type to_add) {
		nodePTR	new_node = _node_alloc.allocate(1);
		nodePTR	prev_node = _last_node;
		nodePTR	current_node = _last_node->parent;
		char	side = 'R';
		int	key;

		while (current_node != _last_node)
		{
		    key = current_node->value.first;
		    if (key == to_add.first)
			return (ft::make_pair(iterator(current_node, _last_node), false));
		    prev_node = current_node;
		    if (to_add.first > key)
		    {
			side = 'R';
			current_node = current_node->right;
		    }
		    else
		    {
			side = 'L';
			current_node = current_node->left;
		    }
		}
		_node_alloc.construct(new_node, Node(to_add, prev_node, _last_node, _last_node));
		if (prev_node == _last_node)
		    _last_node->parent = new_node;
		else if (side == 'R')
		    prev_node->right = new_node;
		else
		    prev_node->left = new_node;
		_last_node->left = getLowestNode(_last_node->parent);
		_last_node->right = getHighestNode(_last_node->parent);
		_last_node->value.first += 1;
		return (ft::make_pair(iterator(new_node, _last_node), true));
	    }

	    void removeKey(value_type to_remove) {
		_removeKey(_last_node->parent, to_remove);
	    }

	    nodePTR searchKey(value_type to_find) {
		nodePTR	node = _last_node->parent;

		while (node != _last_node)
		{
		    if (node->value.first == to_find.first)
			return (node);
		    if (node->value.first > to_find.first)
			node = node->left;
		    else
			node = node->right;
		}
		return (node);
	    }

	    void    swap(BST &second) {
		nodePTR	    stock = this->_last_node;

		if (this == &second)
		    return ;
		this->_last_node = second._last_node;
		second._last_node = stock;
	    }

	    size_type	max_size() const {
		return (node_alloc().max_size());
	    }

	private:
	    nodePTR getLowestNode(nodePTR root) {
		while (root != _last_node && root->left != _last_node)
		    root = root->left;
		return (root);
	    }

	    nodePTR getHighestNode(nodePTR root) {
		while (root != _last_node && root->right != _last_node)
		    root = root->right;
		return (root);
	    }

	    void replaceParent(nodePTR node, nodePTR new_node) {

		if (node->parent != _last_node)
		{
		    if (_last_node->parent == node)
			_last_node->parent = new_node;
		    if (node == node->parent->left)
			node->parent->left = new_node;
		    else
			node->parent->right = new_node;
		}
		else
		    _last_node->parent = new_node;
		_last_node->left = getLowestNode(_last_node->parent);
		_last_node->right = getHighestNode(_last_node->parent);
		_last_node->value.first -= 1;
		if (new_node != _last_node)
		    new_node->parent = node->parent;
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	    }

	    void replaceChildren(nodePTR &to_remove, nodePTR new_node) {
		if (new_node->parent != _last_node)
		    if (new_node->parent != to_remove)
			new_node->parent->left = new_node->right;
		new_node->parent = to_remove->parent;
		if (to_remove->left != new_node)
		    new_node->left = to_remove->left;
		if (to_remove->right != new_node)
		    new_node->right = to_remove->right;
		if (to_remove->parent != _last_node)
		{
		    if (to_remove->parent->left == to_remove)
			to_remove->parent->left = new_node;
		    else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = new_node;
		}
		else
		    _last_node->parent = new_node;
		if (to_remove->left != _last_node && to_remove->left != new_node)
		    to_remove->left->parent = new_node;
		if (to_remove->right != _last_node && to_remove->right != new_node)
		    to_remove->right->parent = new_node;
		if (to_remove->parent != _last_node)
		{
		    to_remove->left = _last_node;
		    to_remove->right = _last_node;
		    to_remove->parent = new_node;
		}
		_last_node->left = getLowestNode(_last_node->parent);
		_last_node->right = getHighestNode(_last_node->parent);
		_last_node->value.first -= 1;
		_node_alloc.destroy(to_remove);
		_node_alloc.deallocate(to_remove, 1);
	    }

	    void _removeKey(nodePTR node, value_type to_remove) {
		if (to_remove.first < node->value.first)
		    _removeKey(node->left, to_remove);
		else if (to_remove.first > node->value.first)
		    _removeKey(node->right, to_remove);
		else if (node->left != _last_node && node->right != _last_node)
		{
		    nodePTR successor = getLowestNode(node->right);
		    replaceChildren(node, successor);
		}
		else if (node->left != _last_node)
		    replaceParent(node, node->left);
		else if (node->right != _last_node)
		    replaceParent(node, node->right);
		else
		    replaceParent(node, _last_node);
	    }
    };
}

#endif



























