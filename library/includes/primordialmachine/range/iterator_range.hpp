///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Range Library
// Copyright (C) 2017-2018 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "primordialmachine/range/_range.hpp"

namespace primordialmachine {

template<typename ITERATOR, typename ENABLED = void>
struct iterator_range;

/// @internal
template<typename ITERATOR>
struct iterator_range<ITERATOR, void> : public detail::range
{
  using iterator_type = ITERATOR;

  iterator_range();

  iterator_range(iterator_type begin, iterator_type end);

  iterator_type begin() const;

  iterator_type end() const;

  bool empty() const;

private:
  iterator_type m_begin;

  iterator_type m_end;

}; // struct iterator_range

template<typename ITERATOR>
iterator_range<ITERATOR>::iterator_range()
  : m_begin()
  , m_end()
{}

template<typename ITERATOR>
iterator_range<ITERATOR>::iterator_range(iterator_type begin, iterator_type end)
  : m_begin(begin)
  , m_end(end)
{}

template<typename ITERATOR>
typename iterator_range<ITERATOR>::iterator_type
iterator_range<ITERATOR>::begin() const
{
  return m_begin;
}

template<typename ITERATOR>
typename iterator_range<ITERATOR>::iterator_type
iterator_range<ITERATOR>::end() const
{
  return m_end;
}

template<typename ITERATOR>
bool
iterator_range<ITERATOR>::empty() const
{
  return m_begin == m_end;
}

} // namespace engine::component_model
