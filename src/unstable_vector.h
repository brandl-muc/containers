/*
    unstable_vector - A std::vector based container wich has member functions
        with higher speed by not preserving the order of its elements
    Copyright (C) 2017 Matthäus Brandl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <vector>

namespace mbr
{
    namespace container
    {
        template <class T, class Allocator = std::allocator<T>>
        class unstable_vector
        {
        public: // types
        	using vector_type = typename std::vector<T, Allocator>;
        	using value_type = typename vector_type::value_type;
        	using allocator_type = typename vector_type::allocator_type;
        	using size_type = typename vector_type::size_type;
        	using difference_type = typename vector_type::difference_type;
        	using reference = value_type &;
        	using const_reference = value_type const &;
        	using pointer = typename std::allocator_traits<Allocator>::pointer;
        	using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        	using iterator = typename vector_type::iterator;
        	using const_iterator = typename vector_type::const_iterator;
        	using reverse_iterator = typename vector_type::reverse_iterator;
        	using const_reverse_iterator = typename vector_type::const_reverse_iterator;
        	
        public: // methods
        	// constructor
        	unstable_vector()
        		: unstable_vector(Allocator())
        	{}
        	
        	explicit unstable_vector(Allocator const & alloc)
        		: m_vector(alloc)
        	{}
        	
        	unstable_vector(size_type const count, T const & value, Allocator const & alloc = Allocator())
        		: m_vector(count, value, alloc)
        	{}
        	
        	explicit unstable_vector(size_type const count, const Allocator& alloc = Allocator())
        		: m_vector(count, alloc)
        	{}
        	
        	template <class InputIt>
        	unstable_vector(InputIt const first, InputIt const last, Allocator const & alloc = Allocator())
				: m_vector(first, last, alloc)
		    {}
        	
        	unstable_vector(unstable_vector const & other)
        		: m_vector(other.m_vector)
        	{}
        	
        	unstable_vector(unstable_vector const & other, Allocator const & alloc)
        		: m_vector(other.m_vector, alloc)
        	{}
        	
        	unstable_vector(unstable_vector && other)
        		: m_vector(std::move(other.m_vector))
        	{}
        	
        	unstable_vector(unstable_vector && other, Allocator const & alloc)
        		: m_vector(std::move(other.m_vector), alloc)
        	{}

        	unstable_vector(vector_type const & other)
    			: m_vector(other)
        	{}
    	
        	unstable_vector(vector_type const & other, Allocator const & alloc)
				: m_vector(other, alloc)
			{}
    	
        	unstable_vector(vector_type && other)
				: m_vector(std::move(other))
			{}

        	unstable_vector(vector_type && other, Allocator const & alloc)
				: m_vector(std::move(other), alloc)
			{}

        	unstable_vector(std::initializer_list<T> const ilist, Allocator const & alloc = Allocator())
        		: m_vector(ilist, alloc)
        	{}
        	
        	// destructor
        	~unstable_vector() = default;
        	
        	// assignment
        	unstable_vector & operator=(unstable_vector const & other)
        	{
        		m_vector = other.m_vector;
        		return *this;
        	}
        	
        	unstable_vector & operator=(unstable_vector && other)
        	{
        		m_vector = std::move(other.m_vector);
        		return *this;
        	}
        	
        	unstable_vector & operator=(vector_type const & other)
        	{
        		m_vector = other;
        		return *this;
        	}
        	
        	unstable_vector & operator=(vector_type && other)
        	{
        		m_vector = std::move(other);
        		return *this;
        	}
        	
        	unstable_vector & operator=(std::initializer_list<T> const ilist)
        	{
        		m_vector = ilist;
        		return *this;
        	}
        	
        	void assign(size_type const count, T const & value)
        	{
        		m_vector.assign(count, value);
        	}

        	template <class InputIt>
        	void assign(InputIt first, InputIt last)
        	{
        		m_vector.assign(first, last);
        	}

        	void assign(std::initializer_list<T> const ilist)
        	{
        		m_vector.assign(ilist);
        	}
        	
        	// element access
        	reference at(size_type const pos)
        	{
        		return m_vector.at(pos);
        	}
        			
        	const_reference at(size_type const pos) const
        	{
        		return m_vector.at(pos);
        	}

        	reference operator[](size_type const pos)
        	{
        		return m_vector[pos];
        	}
        	        			
        	const_reference operator[](size_type const pos) const
        	{
        		return m_vector[pos];
        	}
        	
        	reference front()
        	{
        		return m_vector.front();
        	}
        			
        	const_reference front() const
        	{
        		return m_vector.front();
        	}
        	
        	reference back()
        	{
        		return m_vector.back();
        	}
        			
        	const_reference back() const
        	{
        		return m_vector.back();
        	}
       		
        	pointer data() noexcept
        	{
        		return m_vector.data();
        	}

        	const_pointer data() const noexcept
        	{
        		return m_vector.data();
        	}
        		
        	// iterators
        	iterator begin() noexcept
			{
        		return m_vector.begin();
			}
        			
        	const_iterator begin() const noexcept
			{
				return m_vector.begin();
			}
        			
        	const_iterator cbegin() const noexcept
			{
        		return m_vector.cebgin();
			}
        	
        	iterator end() noexcept
			{
        		return m_vector.end();
			}
        			
        	const_iterator end() const noexcept
			{
				return m_vector.end();
			}
        			
        	const_iterator cend() const noexcept
			{
				return m_vector.cend();
			}
        	
        	reverse_iterator rbegin() noexcept
			{
        		return m_vector.rbegin();
			}
        			
        	const_reverse_iterator rbegin() const noexcept
			{
				return m_vector.rbegin();
			}
        			
        	const_reverse_iterator crbegin() const noexcept
			{
				return m_vector.crbegin();
			}
        	
        	reverse_iterator rend() noexcept
			{
				return m_vector.rend();
			}
        			
        	const_reverse_iterator rend() const noexcept
			{
				return m_vector.rend();
			}
        			
        	const_reverse_iterator crend() const noexcept
			{
				return m_vector.crend();
			}
        	
        	// allocator
        	allocator_type get_allocator() const
        	{
        		return m_vector.get_allocator();
        	}
        	
        	// capacity
        	bool empty() const noexcept
        	{
        		return m_vector.empty();
        	}
        	
        	size_type size() const noexcept
			{
        		return m_vector.size();
			}
        	
        	size_type max_size() const noexcept
			{
				return m_vector.max_size();
			}
        	
        	void reserve(size_type const new_cap)
        	{
        		m_vector.reserve(new_cap);
        	}
        	
        	size_type capacity() const noexcept
			{
				return m_vector.capacity();
			}
        	
        	void shrink_to_fit()
        	{
        		m_vector.shrink_to_fit();
        	}
        		
        	
        private: // variables
        	vector_type m_vector;
        };
    }
}
