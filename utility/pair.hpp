#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
	public:
	    typedef T1		first_type;
	    typedef T2		second_type;
	    
	    first_type	first;
	    second_type	second;
	    pair(void) : first(), second() {}
	    template <class U, class V>
	    pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
	    pair(const first_type &a, const second_type &b) : first(a), second(b) {}
	    pair &operator=(const pair &pr) {
		if (*this == pr)
		    return (*this);
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	    }
    };

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y) {
	return (pair<T1, T2>(x, y));
    }
}

#endif
