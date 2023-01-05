/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:06 by mnies             #+#    #+#             */
/*   Updated: 2023/01/05 02:58:56 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>

#include "tree.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1) {
			if (!(*first1 == *first2)) return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key																		key_type;
			typedef T																		mapped_type;
			typedef pair<const key_type, mapped_type>										value_type;
			typedef size_t																	size_type;
			typedef ptrdiff_t																difference_type;
			typedef Compare																	key_compare;
			typedef Allocator																allocator_type;
		private:
			typedef	ft::tree<value_type , key_compare, allocator_type>						tree_type;
		public:
			typedef value_type&																reference;
			typedef const value_type&														const_reference;
			typedef typename Allocator::pointer												pointer;
			typedef typename Allocator::const_pointer										const_pointer;
			typedef ft::map_iterator< value_type >											iterator;
			typedef ft::const_map_iterator< value_type >									const_iterator;
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					friend class map;
					key_compare comp;

					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

					bool operator()(const value_type& lhs, const key_type& rhs) const
					{
						return comp(lhs.first, rhs);
					}

					bool operator()(const key_type& lhs, const value_type& rhs) const
					{
						return comp(lhs, rhs.first);
					}
			};

		private:

			tree<value_type, value_compare, allocator_type> _tree;

		public:

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc)
			{

			}

			template <class _InputIterator>
			map(_InputIterator first, _InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc)
			{
				insert(first, last);
			}


			map(const map& other) : _tree(other.value_comp(), other.get_allocator())
			{
				insert(other.begin(), other.end());
			}


			map& operator=(const map& other)
			{
				if (this != &other) {
					_tree.clear();
					_tree.assign_comp_and_alloc(other._tree);
					insert(other.begin(), other.end());
				}
				return *this;
			}


			~map() {

			}

			iterator begin()
			{
				return iterator(_tree.begin());
			}

			const_iterator begin() const
			{
				return const_iterator(_tree.begin());
			}

			iterator end()
			{
				return iterator(_tree.end());
			}

			const_iterator end() const
			{
				return const_iterator(_tree.end());
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			bool empty() const
			{
				return _tree.size() == 0;
			}

			size_type size() const
			{
				return _tree.size();
			}

			size_type max_size() const
			{
				return _tree.max_size();
			}

			mapped_type& operator[](const key_type& key)
			{
				return (_tree[key]);
			}

			mapped_type& at(const key_type& key)
			{
				return (_tree.at(key).second);
			}

			const mapped_type& at(const key_type& key) const
			{
				return (_tree.at(key).second);
			}


			allocator_type get_allocator() const
			{
				return allocator_type();
			}

			key_compare	key_comp() const
			{
				return key_compare();
			}

			value_compare  value_comp() const
			{
				return value_compare(key_comp());
			}

			pair<iterator, bool> insert(const value_type& value)
			{
				return (_tree.insert(value));
			}

			iterator insert(iterator pos, const value_type& value)
			{
				return _tree.insert(pos, value);
			}

			template <class _InputIterator>
			void insert(_InputIterator first, _InputIterator last)
			{
				iterator pos = begin();

				while (first != last)
				{
					pos = _tree.insert(pos, *first);
					++first;
				}
			}

			void erase(iterator pos)
			{
				_tree.erase(pos.base());
				return;
			}

			size_type erase(const key_type& key)
			{
				return _tree.erase(key);
			}

			void erase (iterator first, iterator last)
			{
				return _tree.erase(first.base(), last.base());
			}

			void clear()
			{
				_tree.clear();
			}

			void swap(map& other)
			{
				_tree.swap(other._tree);
			}

			iterator find(const key_type& key)
			{
				return _tree.find(key);
			}

			const_iterator find(const key_type& key) const
			{
				return _tree.find(key);
			}

			size_type count(const key_type& key) const
			{
				return _tree.count(key);
			}

			iterator lower_bound(const key_type& key)
			{
				return iterator(_tree.lower_bound(key));
			}

			const_iterator lower_bound(const key_type& key) const
			{
				return const_iterator(_tree.lower_bound(key));
			}

			iterator upper_bound(const key_type& key)
			{
				return iterator(_tree.upper_bound(key));
			}

			const_iterator upper_bound(const key_type& key) const
			{
				return const_iterator(_tree.upper_bound(key));
			}

			pair<iterator,iterator> equal_range(const key_type& key)
			{
				return (pair<iterator,iterator>(lower_bound(key), upper_bound(key)));
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& key) const
			{
				return (pair<const_iterator,const_iterator>(lower_bound(key), upper_bound(key)));
			}

	};

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare_map(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return ft::lexicographical_compare_map(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return rhs < lhs;
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs)
	{
		lhs.swap(rhs);
	}
}