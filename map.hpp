/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:06 by mnies             #+#    #+#             */
/*   Updated: 2023/01/01 16:06:39 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>

#include "tree.hpp"

namespace ft
{
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
			typedef ft::map_iterator<typename tree_type::node_type>							iterator; //TODO
			// typedef __map_const_iterator<typename __base::const_iterator>	const_iterator; //TODO
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		private:

				tree<value_type, key_compare, allocator_type> _tree;
				allocator_type _alloc;

		public:

			// class value_compare : public binary_function<value_type, value_type, bool>
			// {
			// 	friend class map;
			// 	protected:
			// 		key_compare comp;

			// 		value_compare(key_compare c) : comp(c) {}
			// 	public:

			// 		bool operator()(const value_type& __x, const value_type& __y) const
			// 		{
			// 			return comp(__x.first, __y.first);
			// 		}
			// };


			map() : _tree(key_compare())
			{

			}

			/*

			explicit map(const key_compare& comp) : tree(comp)
			{

			}


			explicit map(const key_compare& comp, const allocator_type& alloc) : tree(comp, typename __base::allocator_type(alloc))
			{

			}

			template <class _InputIterator>
			map(_InputIterator first, _InputIterator last, const key_compare& comp = key_compare()) : tree(comp)
			{
				insert(first, last);
			}

			template <class _InputIterator>
			map(_InputIterator first, _InputIterator last, const key_compare& comp, const allocator_type& alloc) : tree(comp, typename __base::allocator_type(alloc))
			{
				insert(first, last);
			}


			map(const map& other) : tree(other.tree)
			{
				insert(other.begin(), other.end());
			}


			map& operator=(const map& other)
			{
				if (this != &other) {
					tree.clear();
					tree.value_comp() = other.tree.value_comp();
					tree.__copy_assign_alloc(other.tree);
					insert(other.begin(), other.end());
				}
				return *this;
			}


			~map() {

			}


			iterator begin()
			{
				return tree.begin();
			}

			const_iterator begin() const
			{
				return tree.begin();
			}

			iterator end()
			{
				return tree.end();
			}

			const_iterator end() const
			{
				return tree.end();
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

			*/
			bool empty() const
			{
				return _tree.size() == 0;
			}

			size_type size() const
			{
				return _tree.size();
			}
			/*
			size_type max_size() const
			{
				return tree.max_size();
			}

			mapped_type& operator[](const key_type& key);

			mapped_type& at(const key_type& key);
			const mapped_type& at(const key_type& key) const;


			allocator_type get_allocator() const
			{
				return allocator_type(tree.__alloc());
			}

			key_compare	key_comp() const
			{
				return tree.value_comp().key_comp();
			}

			value_compare  value_comp() const
			{
				return value_compare(tree.value_comp().key_comp());
			}
	*/
			pair<iterator, bool> insert(const value_type& value)
			{
				return (_tree.insert(value));
			}
	/*
			iterator insert(const_iterator pos, const value_type& value)
			{
				return tree.insert(pos.__i_, value);
			}

			template <class _InputIterator>
			void insert(_InputIterator first, _InputIterator last)
			{
				for (const_iterator end = cend(); first != last; ++first)
					insert(end.__i_, *first);
			}

			iterator erase(iterator pos)
			{
				return tree.erase(pos.__i_);
			}

			size_type erase(const key_type& key)
			{
				return tree.__erase_unique(key);
			}

			void clear()
			{
				tree.clear();
			}


			void swap(map& other)
			{
				tree.swap(other.tree);
			}

			iterator find(const key_type& key)
			{
				return tree.find(key);
			}

			const_iterator find(const key_type& key) const
			{
				return tree.find(key);
			}

			size_type count(const key_type& key) const
			{
				return tree.__count_unique(key);
			}


			iterator lower_bound(const key_type& key)
			{
				return tree.lower_bound(key);
			}

			const_iterator lower_bound(const key_type& key) const
			{
				return tree.lower_bound(key);
			}

			iterator upper_bound(const key_type& key)
			{
				return tree.upper_bound(key);
			}

			const_iterator upper_bound(const key_type& key) const
			{
				return tree.upper_bound(key);
			}

			pair<iterator,iterator> equal_range(const key_type& key)
			{
				return tree.__equal_range_unique(key);
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& key) const
			{
				return tree.__equal_range_unique(key);
			}
			*/
	};
}