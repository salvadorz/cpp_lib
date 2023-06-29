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
/**
 * @file Queue.hpp
 * @author Salvador Z
 * @version 1.0
 * @brief File for a Meta-Queue class
 *
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

// Includes
#include <cstdint>

namespace ds {
/**
 * @brief Meta-Queue class buffer it's allocated in Stack. Usage: ds::Queue<int, 5> q;
 *
 * @tparam T type of held elements
 * @tparam max_elements of elements the queue can hold
 */
template <class T, uint16_t max_elements> class Queue {
private:
  T        _buff[max_elements];
  bool     _full = false;
  uint16_t _head = 0;
  uint16_t _tail = 0;

public:
  explicit Queue() = default;
  virtual ~Queue() {}

  /**
   * @brief Returns the max number of elements can hold the queue
   */
  uint16_t max_size() const;

  /**
   * @brief Returns the number of elements in the queue
   * @return Number of elements in the queue
   */
  uint16_t size() const;

  /**
   * @brief Returns true if the queue is empty
   */
  bool empty() const;

  /**
   * @brief Push an element to the queue, if the queue is full, the oldest element is overwritten
   * @param element Element to be pushed
   */
  void push(T element);

  /**
   * @brief Pops an element from the queue, reduces the container size by one
   * @return true if an (oldest) element was popped, false otherwise (buffer is empty)
   */
  bool pop();

  /**
   * @brief Inserts an element at the head of the queue, after its current last element
   * @param element to be inserted
   * @return true if the element was inserted, false if full
   */
  bool enqueue(T element);

  /**
   * @brief Retrieves the element at the tail of the queue (oldest element)
   * @param element to be put the value of the element
   * @return true if the element was retrieved, false if empty
   */
  bool dequeue(T &element);

  T front();
};

} // namespace ds

#endif /* QUEUE_HPP_ */
