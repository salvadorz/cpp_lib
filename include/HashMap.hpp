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
 * @file HashMap.hpp
 * @author Salvador Z
 * @version 1.0
 * @brief File for HashMap and HashNode classes
 *
 */

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

// Includes
#include <cstdint>
#include <iostream>

// Defines
#define HASH_MAX_TABLE_SIZE (4)

namespace ds {

/**
 * @brief HashNode class stores key and value (addressed by void pointer)
 * The HashNode or HashMap does not allocate any memory, only stores the reference of the value
 * address received.
 */
class HashNode {
public:
  int       key;
  void     *val_ptr;
  HashNode *next;

public:
  HashNode(int key, void *val) : key(key), val_ptr(val), next(nullptr) {}
  HashNode(const HashNode &) = delete;
};

/**
 * @brief HashMap class
 */
class HashMap {
private:
  HashNode **htable;      // Hash table - array of pointers to HashNodes
  uint32_t   htable_size; // max size of hash table
  bool const unique_id;   // if true, only one entry per key

  /**
   * Hash Function
   */
  int HashFunc(int key) const;

public:
  HashMap();
  HashMap(bool unique = true, uint32_t size = HASH_MAX_TABLE_SIZE);
  HashMap(const HashMap &)            = delete;
  HashMap(HashMap &&)                 = delete;
  HashMap &operator=(const HashMap &) = delete;
  HashMap &operator=(HashMap &&)      = delete;
  ~HashMap();

  /**
   * @brief Insert Element with key
   */
  int Insert(int const key, void *value) const;

  /**
   * @brief Remove Element with a key
   */
  int Remove(int const key) const;

  /**
   * @brief Search Element with a key
   */
  bool Search(int const key) const;

  /**
   * @brief Get Element with a key
   */
  void *GetValue(int const key);

  /**
   * @brief Get first key
   */
  int GetFirstKey() const;

  /**
   * @brief Get next key after current @param key
   */
  int GetNextKey(int const key) const;

}; // end class HashMap

} // namespace ds

#endif /* HASHMAP_HPP_ */