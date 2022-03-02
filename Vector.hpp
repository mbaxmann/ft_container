#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace   ft
{
    template<class T, class Allocator = std::allocator<T>>

    class   vector
    {
	public:
		/*
		 *Member type declaration:
		 */
		typedef	T			    value_type;
		typedef Allocator		    allocator_type;
		typedef reference		    allocator_type::reference;
		typedef	const_reference		    allocator_type::const_reference;
		typedef	pointer			    allocator_type::pointer;
		typedef const_pointer		    allocator_type::const_pointer;
		/*
		 *Cannonical form:
		 */
		vector(void);
		vector(const &vector cp);
		~vector(void);

		vector	&operator=(const &vector cp);
	protected:
    };
}

#endif
