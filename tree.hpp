/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:58 by mnies             #+#    #+#             */
/*   Updated: 2023/01/01 16:04:25 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include "pair.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template <class T>
	struct node
	{
		typedef T						value_type;

		node *left;
		node *right;
		node *parent;
		bool isRed;
		T* value;

		node(T* value, node *parent) : left(NULL), right(NULL), parent(parent), isRed(true), value(value)
		{

		}

		node(const node& other) : left(other.left), right(other.right), parent(other.parent), isRed(other.isRed), value(other.value)
		{

		}
	};

	template <class T, class Compare, class Allocator>
	class tree
	{
		public:
			typedef T															value_type;
			typedef Compare														value_compare;
			typedef Allocator													allocator_type;
			typedef size_t														size_type;
			typedef node<value_type>											node_type;
			typedef map_iterator<node_type>										iterator;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		private:
			node_type* _firstNode;
			value_compare _cmp;
			allocator_type _alloc;
			node_allocator_type _node_alloc;
			size_type			_node_count;

		private:

		public:

			tree(Compare cmp) : _cmp(cmp), _node_count(0)
			{
				_firstNode = NULL;
				// _node_alloc.allocate(1);
				// _node_alloc.construct(_firstNode, node_type(NULL, NULL));
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_type* tmp_parent;
				node_type** tmp;

				tmp_parent = NULL;
				tmp = &_firstNode;
				while(*tmp != NULL)
				{
					tmp_parent = *tmp;
					if (_cmp(value.first, tmp_parent->value->first))
						tmp = &(tmp_parent->left);
					else if (_cmp(tmp_parent->value->first, value.first))
						tmp = &(tmp_parent->right);
					else
						return ft::make_pair<iterator, bool>(iterator(*tmp), false);
				}
				*tmp = make_node(value, tmp_parent);
				return ft::make_pair<iterator, bool>(iterator(*tmp), true);
			}

			node_type* make_node(const value_type& value, node_type* tmp_parent)
			{
				node_type* ret;

				ret = _node_alloc.allocate(1);
				_node_alloc.construct(ret, node_type(_alloc.allocate(1), tmp_parent));
				_alloc.construct((ret)->value, value_type(value));
				_node_count++;
				return(ret);
			}

			/*
			iterator insert(const_iterator pos, const value_type& value) {
				return NULL; //TODO
			}

			iterator erase(const_iterator pos)
			{
				return NULL; //TODO
			}

			template <class Key>
			size_type erase(const Key& key)
			{
				return NULL; //TODO
			}

			void clear()
			{
				//TODO
			}

			void swap(tree& other)
			{
				(void)other; //TODO
			}

			iterator find(const key_type& key)
			{
				return void; //TODO
			}

			const_iterator find(const key_type& key) const
			{
				return void; //TODO
			}

			size_type count(const key_type& key) const
			{
				return void; //TODO
			}


			iterator lower_bound(const key_type& key)
			{
				return void; //TODO
			}

			const_iterator lower_bound(const key_type& key) const
			{
				return void; //TODO
			}

			iterator upper_bound(const key_type& key)
			{
				return void; //TODO
			}

			const_iterator upper_bound(const key_type& key) const
			{
				return void; //TODO
			}

			pair<iterator,iterator> equal_range(const key_type& key)
			{
				return void; //TODO
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& key) const
			{
				return void; //TODO
			}

			iterator begin()
			{
				return
			}

			const_iterator begin() const
			{
				return
			}

			iterator end()
			{
				return
			}

			const_iterator end() const
			{
				return
			}
			*/
			size_type size() const
			{
				return (_node_count);
			}
			/*
			size_type max_size() const
			{
				return
			}*/
	};

}