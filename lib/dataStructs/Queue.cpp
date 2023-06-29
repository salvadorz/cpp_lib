/*******************************************************************************
 * Copyright (C) 2023 by Salvador Z                                            *
 *                                                                             *
 * This file is part of CPP_LIB                                                *
 *                                                                             *
 *   Permission is hereby granted, free of charge, to any person obtaining a   *
 *   copy of this software and associated documentation files (the Software)   *
 *   to deal in the Software without restriction including without limitation  *
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,  *
 *   and/or sell copies ot the Software, and to permit persons to whom the     *
 *   Software is furnished to do so, subject to the following conditions:      *
 *                                                                             *
 *   The above copyright notice and this permission notice shall be included   *
 *   in all copies or substantial portions of the Software.                    *
 *                                                                             *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   *
 *   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARANTIES OF MERCHANTABILITY *
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL   *
 *   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR      *
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,     *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE        *
 *   OR OTHER DEALINGS IN THE SOFTWARE.                                        *
 ******************************************************************************/

#include "Queue.hpp"
#include <iostream>

template <class T, uint16_t max_elements>

uint16_t ds::Queue<T, max_elements>::max_size() const {
  return max_elements;
}

template <class T, uint16_t max_elements>

uint16_t ds::Queue<T, max_elements>::size() const {
  uint16_t size = 0;

  if (!empty()) {
    size = (0 >= _head - _tail) ? max_elements + (_head - _tail) : _head - _tail;
  }
  return size;
}

template <class T, uint16_t max_elements>

bool ds::Queue<T, max_elements>::empty() const {
  return (!_full && (_head == _tail));
}

template <class T, uint16_t max_elements>

void ds::Queue<T, max_elements>::push(T element) {
  if (_full) {
    _tail = ((++_tail) == max_elements) ? 0 : _tail;
  }
  _buff[_head] = element;

  _head = ((++_head) == max_elements) ? 0 : _head;
  _full = (_head == _tail) ? true : false;
}

template <class T, uint16_t max_elements>

bool ds::Queue<T, max_elements>::pop() {
  bool is_ok = true;

  if (!empty()) {
    _tail = ((++_tail) == max_elements) ? 0 : _tail; // frees one slot
    _full = false;
  } else {
    is_ok = false;
  }
  return is_ok;
}

template <class T, uint16_t max_elements>

bool ds::Queue<T, max_elements>::enqueue(T element) {
  bool is_ok = true;

  if (!_full) {
    _buff[_head] = element;

    _head = ((++_head) == max_elements) ? 0 : _head;
    _full = (_head == _tail) ? true : false;
  } else {
    is_ok = false;
  }
  return is_ok;
}

template <class T, uint16_t max_elements>

bool ds::Queue<T, max_elements>::dequeue(T &element) {
  bool is_ok = true;

  if (!empty()) {
    element = _buff[_tail];

    _tail = ((++_tail) == max_elements) ? 0 : _tail;
    _full = false;
  } else {
    is_ok = false;
  }
  return is_ok;
}

template <class T, uint16_t max_elements>

T ds::Queue<T, max_elements>::front() {
  if (empty()) return T();

  T element = _buff[_tail];

  _tail = (++_tail) == max_elements ? 0 : _tail;
  _full = false;

  return element;
}
