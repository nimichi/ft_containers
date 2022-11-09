/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:58 by mnies             #+#    #+#             */
/*   Updated: 2022/11/04 15:56:27 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

namespace ft {
	template<class T, class Allocator = std::allocator<T> > class vector
	{
		private:

		public:
			//Member typdef
			template< bool B, class T = void > struct enable_if;
			template< class Iter > struct iterator_traits;
			template< class T > struct iterator_traits<T*>;
			template< class Iter > class reverse_iterator;
			template< class T > struct is_integral;
			// TODO compare
			template< class T1, class T2 > struct pair;
			template< class T1, class T2 > std::pair<T1, T2> make_pair( T1 t, T2 u );

			//Member types
			typedef typename T                                     value_type;
			typedef typename Allocator                             allocator_type;
			typedef typename size_t                                size_type;
			typedef typename ptrdiff_t                             difference_type;
			typedef typename value_type&                           reference;
			typedef typename const value_type&                     const_reference;
			typedef typename value_type*                           pointer;
			typedef typename const value_type*                     const_pointer;
			typedef typename MyIterator<value_type>                iterator;
			typedef typename MyConstIterator<value_type>           const_iterator;
			typedef typename std::reverse_iterator<iterator>       reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

			//Member functions
			vector(void);
			~vector(void);
			vector& operator=( const vector& other ); //inval
			void assign( size_type count, const T& value ); //inval
			allocator_type get_allocator() const;

			//	Element access
			reference at( size_type pos );
			const_reference at( size_type pos ) const;
			reference operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			T* data();
			const T* data() const;

			//	Capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void reserve( size_type new_cap ); //inval
			size_type capacity() const;

			//	Moifiers
			void clear(); //inval
			iterator insert( const_iterator pos, const T& value ); //inval
			iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			constexpr iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last ); //inval
			iterator erase( iterator pos ); //inval
			iterator erase( iterator first, iterator last ); //inval
			void push_back( const T& value ); //inval
			void pop_back(); //inval
			void resize( size_type count, T value = T() ); //inval
			void swap( vector& other ); //inval
	};

	template< class T, class Allocator > bool operator==( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > bool operator!=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > bool operator<( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > bool operator<=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > bool operator>( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > bool operator>=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	template< class T, class Allocator > void swap( std::vector<T,Allocator>& lhs, std::vector<T,Allocator>& rhs );
}