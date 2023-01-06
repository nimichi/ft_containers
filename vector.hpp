/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:58:55 by mnies             #+#    #+#             */
/*   Updated: 2023/01/07 00:04:19 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <stdexcept>
#include <limits>
#include "iterator.hpp"
#include "utilities.hpp"

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			//Member types
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef ft::iterator<random_access_iterator_tag, value_type>		iterator;
			typedef ft::iterator<random_access_iterator_tag, const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		private:
			pointer				_begin;
			pointer				_end;
			pointer				_limit;
			allocator_type		_allocator;

		public:
			//Member functions
			vector(const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _limit(NULL), _allocator(alloc){

			}

			vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc){
				if (n > max_size())
					throw std::length_error("Too long");
				if (n == 0)
				{
					_begin = NULL;
					_end = NULL;
					_limit = NULL;
				}
				else
				{
					_begin = allocate(n);
					_limit = _begin + n;
				}
				_end = _begin + n;
				while(n > 0){
					n--;
					_allocator.construct((_begin + n), val);
				}
			}

			vector(const vector& other) : _allocator(other._allocator){
				pointer tmp_ptr;

				_begin = allocate(other.capacity());
				_limit = _begin + other.capacity();
				_end = _begin;

				tmp_ptr = other._begin;
				while(tmp_ptr != other._end)
				{
					_allocator.construct(_end, *tmp_ptr);
					_end++;
					tmp_ptr++;
				}
			}

			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename enable_if<!ft::is_integral<InputIt>::value>::type* = 0) : _begin(NULL), _end(NULL), _limit(NULL), _allocator(alloc)
			{
				assign(first, last);
			}

			~vector(void){
				while (_end != _begin)
				{
					_end--;
					_allocator.destroy(_end);
				}
				if (_begin != NULL)
					_allocator.deallocate(_begin, capacity());
			}

			iterator begin(){
				return(iterator(this->_begin));
			}

			const_iterator begin() const{
				return(const_iterator(this->_begin));
			}

			iterator end(){
				return(iterator(this->_end));
			}

			const_iterator end() const{
				return(const_iterator(this->_end));
			}

			reverse_iterator rbegin(){
				return(reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const{
				return(const_reverse_iterator(end()));
			}

			reverse_iterator rend(){
				return(reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const{
				return(const_reverse_iterator(begin()));
			}

			allocator_type get_allocator() const{
				return (_allocator);
			}

			void assign( size_type count, const_reference value ){
				if (count > size())
				{
					clear();
					if (_begin != NULL)
						_allocator.deallocate(_begin, capacity());
					_begin = allocate(count);
					_limit = _begin + count;
					_end = _begin;
					while (count > 0)
					{
						--count;
						_allocator.construct(_end, value);
						++_end;
					}
					return;
				}
				while (_begin + count < _end)
				{
					--_end;
					_allocator.destroy(_end);
				}
				while (count > 0)
				{
					--count;
					_begin[count] = value;
				}
			}

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign (InputIterator first, InputIterator last){
				clear();
				assgin_pre(first, last, ft::iterator_category(first));
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			} // inval

			vector& operator=( const vector& other ){
				pointer tmp_ptr;

				tmp_ptr = other._begin;
				while (_end != _begin)
				{
					_end--;
					_allocator.destroy(_end);
				}
				if (_begin != NULL)
					_allocator.deallocate(_begin, capacity());
				_begin = allocate(other.capacity());
				_limit = _begin + other.capacity();
				_end = _begin;
				while(tmp_ptr != other._end)
				{
					_allocator.construct(_end, *tmp_ptr);
					_end++;
					tmp_ptr++;
				}
				return(*this);
			}

			//	Element access
			reference at( size_type pos ){
				if (pos >= size())
					throw std::out_of_range("Error: out of range");
				return (_begin[pos]);
			}

			const_reference at( size_type pos ) const{
				if (pos >= size())
					throw std::out_of_range("Error: out of range");
				return (_begin[pos]);
			}

			reference operator[]( size_type pos ){
				return (_begin[pos]);
			}

			const_reference operator[]( size_type pos ) const{
				return (_begin[pos]);
			}

			reference front(){
				return (*_begin);
			}

			const_reference front() const{
				return (*_begin);
			}

			reference back(){
				return (*(_end - 1));
			}

			const_reference back() const{
				return (*(_end - 1));
			}

			value_type* data(){
				return (_begin);
			}

			const value_type* data() const{
				return (_begin);
			}

			//	Capacity
			bool empty() const{
				if (_begin == _end)
					return (true);
				return (false);
			}

			size_type size() const{
				return (_end - _begin);
			}

			size_type max_size() const{
				if ((size_type)_allocator.max_size() < (size_type)std::numeric_limits<difference_type>::max())
					return _allocator.max_size();
				else
					return std::numeric_limits<difference_type>::max();
				// return std::min<size_type>(std::allocator_traits<allocator_type>::max_size(_allocator), std::numeric_limits<difference_type>::max());
			}

			void reserve( size_type new_cap ){
				if (new_cap >= max_size())
					throw std::length_error("Too long");
				if (new_cap <= capacity())
					return;
				enlarge(new_cap, capacity(), new_cap);
			}

			size_type capacity() const{
				return (_limit - _begin);
			}

			//	Moifiers
			void clear(){
				while (_end > _begin)
				{
					--_end;
					_allocator.destroy(_end);
				}
			}

			iterator insert (iterator pos, const value_type& val){
				size_type pos_size;
				size_type i;

				pos_size = pos.base() - _begin;
				if (_end == _limit)
				{
					enlarge(size() + 1, pos_size);
					if (_begin + pos_size == _end)
						++_end;
					_allocator.construct(_begin + pos_size, val);
					pos = begin() + pos_size;
				}
				else if (pos.base() == _end)
				{
					_allocator.construct(_end, val);
					++_end;
				}
				else
				{
					_allocator.construct(_end, *(_end - 1));
					i = size();
					while(i > pos_size)
					{
						_begin[i] = _begin[i - 1];
						--i;
					}
					++_end;
					*pos = val;
				}
				return (pos);
			}

			void insert(iterator pos, size_type n, const_reference val){
				size_type pos_size;
				size_type i;

				if (n > max_size())
					throw std::length_error("Too long");
				pos_size = pos.base() - _begin;
				if (_end + n > _limit)
				{
					enlarge(size() + n, pos_size, size() + n);
					if (_begin + pos_size == _end)
						_end += n;
					while(n != 0)
					{
						--n;
						_allocator.construct(_begin + pos_size + n, val);
					}
				}
				else if (pos.base() == _end)
				{
					while(n != 0)
					{
						--n;
						_allocator.construct(_begin + pos_size + n, val);
						++_end;
					}
				}
				else
				{
					i = 0;
					while (n > i && _begin + pos_size + i < _end)
					{
						++i;
						_allocator.construct(_end + n - i, *(_end - i));
					}
					while (_begin + pos_size + i < _end)
					{
						++i;
						_end[n - i] = *(_end - i);
					}
					_end += n;
					while (n > i)
					{
						++i;
						_allocator.construct(_begin + pos_size + n - 1, val);
					}
					while (n > 0)
					{
						--n;
						_begin[pos_size + n] = val;
					}
				}
			}

			template<typename input_iterator>
			typename ft::enable_if<!ft::is_integral<input_iterator>::value, void>::type
			insert( iterator pos, input_iterator first, input_iterator last )
			{
				size_type n;
				size_type i;
				const difference_type distance = pos - begin();
				const size_type	old_size = size();
				input_iterator tmp = first;


				if (insert_is_input_iterator_tag(ft::iterator_category(first)))
				{
					if (pos == end())
					{
						while (first != last)
						{
							push_back(*first);
							++first;
						}
					}
					else if (first != last)
					{
						vector tmp(first, last);
						insert(pos, tmp.begin(), tmp.end());
					}
				}
				else
				{
					n = 0;
					while (tmp != last)
					{
						++tmp;
						++n;
					}
					i = 0;
					if (n > 0)
					{
						if (old_size + n > capacity())
						{
							enlarge(old_size + n, distance);
							_end = _begin + n + old_size;
							while (i < n)
							{
								_allocator.construct(_begin + distance + i, *first);
								first++;
								i++;
							}
						}
						else if (pos == end())
						{
							while (first != last)
							{
								_allocator.construct(_end, *first);
								++first;
								++_end;
							}
						}
						else
						{
							i = old_size - distance;
							while (i > 0)
							{
								--i;
								if (_begin + distance + n + i >= _end)
								{
									_allocator.construct(_begin + distance + n + i, _begin[distance + i]);
								}
								else
								{
									_begin[distance + n + i] = _begin[distance + i];
								}
							}
							i = 0;
							while (i < n)
							{
								if (_begin + distance + i >= _end)
								{
									_allocator.construct(_begin + distance + i, *first);
								}
								else
								{
									_begin[distance + i] = *first;
								}
								first++;
								i++;
							}
							_end = _end + n;
						}
					}
				}
			}

			iterator erase( iterator pos ){
				return (erase(pos, pos + 1));
			}

			iterator erase( iterator first, iterator last ){
				size_type count;

				count = 0;
				while (last.base() + count < _end){
					first.base()[count] = last.base()[count];
					count++;
				}
				count = last - first;
				while (count > 0)
				{
					--count;
					--_end;
					_allocator.destroy(_end);
				}
				return first;
			}

			void push_back( const value_type& value )
			{
				if (_end == _limit)
					enlarge(capacity() + 1, capacity());
				_allocator.construct(_end, value);
				++_end;
			}

			void pop_back(){
				if (_begin != _end)
				{
					--_end;
					_allocator.destroy(_end);
				}
			}

			void resize( size_type count, value_type value = value_type() ){
				if (count >= max_size())
					throw std::length_error("Too long");
				if (count > capacity())
					enlarge(count, capacity());
				if (count < size())
				{
					while (_end != _begin + count)
					{
						--_end;
						_allocator.destroy(_end);
					}
				}
				else
				{
					while (_end != _begin + count)
					{
						_allocator.construct(_end, value);
						++_end;
					}
				}
			}

			void swap(vector& other){
				pointer	temp;

				temp = other._begin;
				other._begin = _begin;
				_begin = temp;
				temp = other._end;
				other._end = _end;
				_end = temp;
				temp = other._limit;
				other._limit = _limit;
				_limit = temp;
			}

		private:
			template <typename ForwardIterator>
			inline void assgin_pre(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag)
			{
				size_type		count;
				ForwardIterator	tmp;

				tmp = first;
				count = 0;
				while (tmp != last)
				{
					++count;
					++tmp;
				}
				if (count > capacity())
				{
					if (_begin != NULL)
						_allocator.deallocate(_begin, capacity());
					_begin = allocate(count);
					_end = _begin;
					_limit = _begin + count;
				}
			}

			template <typename ForwardIterator>
			inline void assgin_pre(ForwardIterator, ForwardIterator, ft::input_iterator_tag)
			{

			}

			bool insert_is_input_iterator_tag(ft::input_iterator_tag)
			{
				return true;
			}

			bool insert_is_input_iterator_tag(ft::forward_iterator_tag)
			{
				return false;
			}

			// template<typename input_iterator>
			// void insert_pos( iterator pos, input_iterator first, input_iterator last)
			// {
			// 	size_type pos_size;
			// 	size_type i;
			// 	size_type n;
			// 	input_iterator tmp;

			// 	if((sizeof(value_type) != sizeof(*first)))
			// 		throw std::exception();
			// 	i = 0;
			// 	tmp = first;
			// 	n = 0;
			// 	while (tmp != last)
			// 	{
			// 		++n;
			// 		++tmp;
			// 	}
			// 	pos_size = pos.base() - _begin;
			// 	if (_end + n > _limit)
			// 	{
			// 		enlarge(size() + n, pos_size);
			// 		if (_begin + pos_size == _end)
			// 			_end += n;
			// 		while(n > i)
			// 		{
			// 			_allocator.construct(_begin + pos_size + i, *first);
			// 			++first;
			// 			++i;
			// 		}
			// 	}
			// 	else if (pos.base() == _end)
			// 	{
			// 		while(n > i)
			// 		{
			// 			_allocator.construct(_begin + pos_size + i, *first);
			// 			++i;
			// 			++first;
			// 			++_end;
			// 		}
			// 	}
			// 	else
			// 	{
			// 		while (n > i && _begin + pos_size + i < _end)
			// 		{
			// 			++i;
			// 			_allocator.construct(_end + n - i, *(_end - i));
			// 		}
			// 		while (_begin + pos_size + i < _end)
			// 		{
			// 			++i;
			// 			_end[n - i] = *(_end - i);
			// 		}
			// 		_end += n;
			// 		while (n > i)
			// 		{
			// 			++i;
			// 			++first;
			// 			_allocator.construct(_begin + pos_size + i, *first);
			// 		}
			// 		while (n > i)
			// 		{
			// 			++i;
			// 			++first;
			// 			_begin[pos_size + i] = *first;
			// 		}
			// 	}
			// }

			pointer allocate(size_type new_cap)
			{
				if (new_cap >= max_size())
						throw std::bad_alloc();
				return (_allocator.allocate(new_cap));
			}

			void enlarge(size_type new_cap, size_type pos, size_type increase = 0){
				size_type	i;
				pointer		tmp_ptr;

				if (increase == 0)
				{
					if (size() == 0)
						increase = 1;
					else
						increase = capacity();
					while (increase < new_cap)
					{
						if (increase < max_size() / 2)
							increase = increase * 2;
						else
							increase =  max_size();
					}
				}
				tmp_ptr = allocate(increase);
				i = 0;
				while(i < size() && i < pos)
				{
					 _allocator.construct(tmp_ptr + i, _begin[i]);
					 _allocator.destroy(_begin + i);
					 ++i;
				}
				if (i < size())
				{
					pos = new_cap - size();
					while (i < size())
					{
						_allocator.construct(tmp_ptr + i + pos, _begin[i]);
					 	_allocator.destroy(_begin + i);
						++i;
					}
				}
				else
					pos = 0;
				if (_begin != NULL)
					_allocator.deallocate(_begin, capacity());
				_begin = tmp_ptr;
				_limit = tmp_ptr + increase;
				_end = tmp_ptr + i + pos;
			}
	};

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator<=(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return !(ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end()));
	}

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator>=(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return !(ft::lexicographical_compare(rhs.begin(), --rhs.end(), lhs.begin(), --lhs.end()));
	}

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator<(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return ft::lexicographical_compare(rhs.begin(), --rhs.end(), lhs.begin(), --lhs.end());
	}

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator>(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end());
	}

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator==(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return (!(rhs < lhs || lhs < rhs));
	}

	template <class type1, class alloc1, class type2, class alloc2>
	bool operator!=(const vector<type1, alloc1>& rhs, const vector<type2, alloc2>& lhs)
	{
		return (rhs < lhs || lhs < rhs);
	}

	template <class type, class alloc>
	void swap(vector<type, alloc>& lhs, vector<type, alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}