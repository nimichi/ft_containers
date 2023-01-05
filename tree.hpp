/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:58 by mnies             #+#    #+#             */
/*   Updated: 2023/01/05 19:03:36 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "pair.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template <class T, class Compare, class Allocator>
	class tree
	{
		public:
			typedef T															value_type;
			typedef typename value_type::key_type								key_type;
			typedef typename value_type::mapped_type							mapped_type;
			typedef Compare														value_compare;
			typedef Allocator													allocator_type;
			typedef size_t														size_type;
			typedef node<value_type>											node_type;
			typedef ft::map_iterator< value_type >								iterator;
			typedef ft::const_map_iterator< value_type  >						const_iterator;
			typedef ptrdiff_t													difference_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		private:
			value_compare		_cmp;
			allocator_type		_alloc;
			node_allocator_type	_node_alloc;
			size_type			_node_count;
			node_type*			_head_node;
			node_type*			_begin_node;

		private:

			void order(node_type* node)
			{
				bool isDone;

				isDone = false;
				while(isDone == false)
				{
					if (node->parent == end())
					{
						node->isRed = false;
						isDone = true;
					}
					else if (node->parent->isRed == false)
					{
						isDone = true;
					}
					else if ((node->parent->parent->left == node->parent && node->parent->parent->right != _head_node && node->parent->parent->right->isRed) ||
							(node->parent->parent->right == node->parent && node->parent->parent->left != _head_node && node->parent->parent->left->isRed))
					{
						node->parent->parent->isRed = true;
						node->parent->parent->right->isRed = false;
						node->parent->parent->left->isRed = false;
						node = node->parent->parent;
					}
					else if ((node->parent->parent->left == node->parent && (node->parent->parent->right == _head_node || !node->parent->parent->right->isRed)) ||
							(node->parent->parent->right == node->parent && (node->parent->parent->left == _head_node || !node->parent->parent->left->isRed)))
					{
						if (node->parent->left == node && node->parent->parent->right == node->parent)
						{
							right_rotate_with_parent(node);
							if (node->parent->left == node)
								node = node->left;
							else
								node = node->right;
						}
						else if (node->parent->right == node && node->parent->parent->left == node->parent)
						{
							left_rotate_with_parent(node);
							if (node->parent->left == node)
								node = node->left;
							else
								node = node->right;
						}
						else if (node->parent->left == node)
						{
							right_rotate_with_parent(node->parent);
							node->parent->isRed = false;
							node->parent->right->isRed = true;
							isDone = true;
						}
						else
						{
							left_rotate_with_parent(node->parent);
							node->parent->isRed = false;
							node->parent->left->isRed = true;
							isDone = true;
						}
					}
				}
			}

			void left_rotate_with_parent(node_type* node)
			{
				if (node->left != _head_node)
					node->left->parent = node->parent;
				node->parent->right = node->left;
				node->left = node->parent;
				node->parent = node->parent->parent;
				node->left->parent = node;
				if (node->parent->left == node->left)
					node->parent->left = node;
				else
					node->parent->right = node;
			}

			void right_rotate_with_parent(node_type* node)
			{
				if (node->right != _head_node)
					node->right->parent = node->parent;
				node->parent->left = node->right;
				node->right = node->parent;
				node->parent = node->parent->parent;
				node->right->parent = node;
				if (node->parent->right == node->right)
					node->parent->right = node;
				else
					node->parent->left = node;
			}

			node_type* make_node(const value_type& value, node_type* tmp_parent)
			{
				node_type* ret;

				ret = _node_alloc.allocate(1);
				_node_alloc.construct(ret, node_type(_alloc.allocate(1), tmp_parent, _head_node));
				_alloc.construct((ret)->value, value_type(value));
				++_node_count;
				return(ret);
			}

			void destroy_node(node_type* node)
			{
				_alloc.destroy(node->value);
				_alloc.deallocate(node->value, 1);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				--_node_count;
			}

			void erase_transplant(node_type* node, node_type* child)
			{
				if (node->parent == _head_node)
					_head_node->left = child;
				else if (node == node->parent->left)
					node->parent->left = child;
				else
					node->parent->right = child;
				child->parent = node->parent;
			}

			void erase_fixup(node_type* x)
			{
				node_type* w;

				while(x != _head_node && x->isRed == false)
				{
					if(x == x->parent->left)
					{
						w = x->parent->right;
						if (w->isRed)
						{
							w->isRed = false;
							x->parent->isRed = true;
							left_rotate_with_parent(w);
							w = x->parent->right;
						}
						if (!w->left->isRed && !w->right->isRed)
						{
							w->isRed = true;
							x = x->parent;
						}
						else
						{
							if (!w->right->isRed)
							{
								w->left->isRed = false;
								w->isRed = true;
								right_rotate_with_parent(w->left);
								w = x->parent->right;
							}
							w->isRed = x->parent->isRed;
							x->parent->parent->isRed = false;
							w->right->isRed = false;
							left_rotate_with_parent(w);
							x = _head_node;
						}
					}
					else
					{
						w = x->parent->left;
						if (w->isRed)
						{
							w->isRed = false;
							x->parent->isRed = true;
							right_rotate_with_parent(w);
							w = x->parent->left;
						}
						if (!w->right->isRed && !w->left->isRed)
						{
							w->isRed = true;
							x = x->parent;
						}
						else
						{
							if (!w->left->isRed)
							{
								w->right->isRed = false;
								w->isRed = true;
								left_rotate_with_parent(w->right);
								w = x->parent->left;
							}
							w->isRed = x->parent->isRed;
							x->parent->parent->isRed = false;
							w->left->isRed = false;
							right_rotate_with_parent(w);
							x = _head_node->left;
						}
					}
				}
				x->isRed = false;
			}

			node_type* erase_increament(node_type* node)
			{
				if (node->right != _head_node)
				{
					node = node->right;
					while (node->left != _head_node)
						node = node->left;
					return (node);
				}
				while (node == node->parent->right)
					node = node->parent;
				return (node->parent);
			}

			void move_begin_node()
			{
				while(_begin_node->left != _head_node)
				{
					_begin_node = _begin_node->left;
				}
			}

		public:

			tree(value_compare cmp, allocator_type alloc) : _cmp(cmp), _alloc(alloc), _node_alloc(node_allocator_type()), _node_count(0), _head_node(_node_alloc.allocate(1)), _begin_node(_head_node)
			{
				_node_alloc.construct(_head_node, node_type(NULL, NULL, NULL));
				_head_node->left = _head_node;
				_head_node->right = _head_node;
			}

			~tree()
			{
				clear();
				_node_alloc.destroy(_head_node);
				_node_alloc.deallocate(_head_node, 1);
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_type* tmp_parent;
				node_type** tmp;

				tmp_parent = _head_node;
				tmp = &(_head_node->left);
				while(*tmp != _head_node)
				{
					tmp_parent = *tmp;
					if (_cmp(value, *(tmp_parent->value)))
						tmp = &(tmp_parent->left);
					else if (_cmp(*(tmp_parent->value), value))
						tmp = &(tmp_parent->right);
					else
						return ft::make_pair<iterator, bool>(iterator(*tmp), false);
				}
				*tmp = make_node(value, tmp_parent);
				order(*tmp);
				move_begin_node();
				return ft::make_pair<iterator, bool>(iterator(*tmp), true);
			}

			iterator insert(iterator pos, const value_type& value)
			{
				(void) pos;

				return (insert(value).first);
			}

			size_type erase(const key_type& key)
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
					{
						erase(tmp);
						return (1);
					}
				}
				return (0);
			}

			void erase (node_type* first, node_type* last)
			{
				node_type* tmp;
				while (first != last)
				{
					tmp = first;
					first = erase_increament(first);
					erase(tmp);
				}
			}

			node_type* erase(node_type* node)
			{
				node_type* next_node;
				node_type* fix_node;

				if (node == _begin_node)
					_begin_node = erase_increament(_begin_node);
				if (node->left == _head_node || node->right == _head_node)
				{
					if(node->left == _head_node)
						fix_node = node->right;
					else
						fix_node = node->left;
					erase_transplant(node, fix_node);
				}
				else
				{
					next_node = node->right;
					while (next_node->left != _head_node)
						next_node = next_node->left;
					fix_node = next_node->right;
					if (next_node->parent == node)
						fix_node->parent = next_node;
					else
					{
						erase_transplant(next_node, next_node->right);
						next_node->right = node->right;
						next_node->right->parent = next_node;
					}
					erase_transplant(node, next_node);
					next_node->left = node->left;
					next_node->left->parent = next_node;
					next_node->isRed = node->isRed;
				}
				if (node->isRed == false)
					erase_fixup(fix_node);
				destroy_node(node);
				return (fix_node);
			}

			void clear()
			{
				node_type* tmp;

				while(_node_count != 0)
				{
					tmp = _head_node->left;
					while(1)
					{
						if (tmp->right != _head_node)
							tmp = tmp->right;
						else if (tmp->left != _head_node)
							tmp = tmp->left;
						else
						{
							if(tmp->parent->right == tmp)
								tmp->parent->right = _head_node;
							else
								tmp->parent->left = _head_node;
							destroy_node(tmp);
							break;
						}
					}
				}
				_begin_node = _head_node;
			}


			void swap(tree& other)
			{
				value_compare		_cmp_tmp = other._cmp;;
				allocator_type		_alloc_tmp;
				node_allocator_type	_node_alloc_tmp;
				size_type			_node_count_tmp;
				node_type*			_node_tmp;

				other._cmp = _cmp;
				_cmp = _cmp_tmp;
				_alloc_tmp = other._alloc;
				other._alloc = _alloc;
				_alloc = _alloc_tmp;
				_node_alloc_tmp = other._node_alloc;
				other._node_alloc = _node_alloc;
				_node_alloc = _node_alloc_tmp;
				_node_count_tmp = other._node_count;
				other._node_count = _node_count;
				_node_count = _node_count_tmp;
				_node_tmp = other._begin_node;
				other._begin_node = _begin_node;
				_begin_node = _node_tmp;
				_node_tmp = other._head_node;
				other._head_node = _head_node;
				_head_node = _node_tmp;
			}

			iterator find(const key_type& key)
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
						return (iterator(tmp));
				}
				return (iterator(_head_node));
			}

			const_iterator find(const key_type& key) const
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
						return (const_iterator(tmp));
				}
				return (const_iterator(_head_node));
			}

			value_type& at(const key_type& key) const
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
						return (*(tmp->value));
				}
				throw std::out_of_range("Key not found!");
			}

			mapped_type& operator[](const key_type& key)
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
						return (tmp->value->second);
				}
				return ((*(insert(value_type(key, mapped_type())).first)).second);
			}

			size_type count(const key_type& key) const
			{
				node_type* tmp;

				tmp = _head_node->left;
				while(tmp != _head_node)
				{
					if (_cmp(key, *(tmp->value)))
						tmp = tmp->left;
					else if (_cmp(*(tmp->value), key))
						tmp = tmp->right;
					else
						return (1);
				}
				return (0);
			}

			node_type* lower_bound(const key_type& key) const
			{
				node_type* ret = _head_node;
				node_type* node = _head_node->left;
				while (node != _head_node)
				{
					if (!_cmp(*(node->value), key))
					{
						ret = node;
						node = node->left;
					}
					else
					{
						node = node->right;
					}
				}
				return ret;
			}

			node_type* upper_bound(const key_type& key) const
			{
				node_type* ret = _head_node;
				node_type* node = _head_node->left;
				while (node != _head_node)
				{
					if (_cmp(key, *(node->value)))
					{
						ret = node;
						node = node->left;
					}
					else
					{
						node = node->right;
					}
				}
				return ret;
			}

			pair<iterator,iterator> equal_range(const key_type& key)
			{
				(void) key;
				return NULL; //TODO
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& key) const
			{
				(void) key;
				return NULL; //TODO
			}


			node_type* begin() const
			{
				return (_begin_node);
			}


			node_type* end() const
			{
				return (_head_node);
			}


			size_type size() const
			{
				return (_node_count);
			}

			size_type max_size() const
			{
				if ((size_type)_node_alloc.max_size() < (size_type)std::numeric_limits<difference_type>::max())
					return _node_alloc.max_size();
				else
					return std::numeric_limits<difference_type>::max();
			}

			void assign_comp_and_alloc(const tree& other)
			{
				_cmp = other._cmp;
				_alloc = allocator_type(other._alloc);
			}
	};

}