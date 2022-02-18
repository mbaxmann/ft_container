#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace   ft
{
    template<class T, class Allocator = std::allocator<T>>

    class   vector
    {
	public:
		vector(void);
		vector(const &vector cp);
		~vector(void);

		vector	&operator=(const &vector cp);
	protected:
		T			    value_type;
		Allocator		    allocator_type;
		std::size_t		    size_type;
		std::ptrdiff_t		    difference_type;
		T			    &reference;
		const T			    &const_reference;
		Allocator::pointer	    pointer;
		Allocator::const_pointer    const_point;
    };
}

#endif
