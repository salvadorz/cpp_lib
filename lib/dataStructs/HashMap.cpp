#include "HashMap.hpp"


int ds::HashMap::HashFunc(int key) const {

  return (key % htable_size);
}

ds::HashMap::HashMap() : htable_size(HASH_MAX_TABLE_SIZE), unique_id(true) {
  htable    = new HashNode *[htable_size];

  for (uint32_t i = 0; i < htable_size; ++i)
    htable[i] = nullptr;
}

ds::HashMap::HashMap(bool unique, uint32_t size) : htable_size(size), unique_id(unique) {
  htable    = new HashNode *[htable_size];

  for (uint32_t i = 0; i < htable_size; ++i)
    htable[i] = nullptr;
}

ds::HashMap::~HashMap() {
  for (uint32_t i = 0; i < htable_size; ++i) {

    HashNode *entry = htable[i];

    while (entry != nullptr) {

      HashNode *head = entry;

      entry = entry->next;
      delete head;
    }
  }

  delete[] htable;
}

int ds::HashMap::Insert(int const key, void *value) const {
  int       exec_ok  = -1;
  int const hash_val = HashFunc(key);

  if (0 > key) {
    return exec_ok;
  }

  HashNode *prev  = nullptr;
  HashNode *entry = htable[hash_val];

  // find a NULL entry
  while (entry != nullptr) {

    // Update value if key already exists for unique keys
    if (unique_id && entry->key == key) {
      entry->val_ptr = value;
      exec_ok        = 0;
      break; // we are done
    }
    prev  = entry;
    entry = entry->next;
  }

  if (entry == nullptr) {
    entry = new HashNode(key, value);

    if (prev == nullptr) {
      // We're at the top of the table.
      htable[hash_val] = entry;
    } else {
      // We're at the bottom of the table.
      prev->next = entry;
    }
    exec_ok = 0;
  }

  return exec_ok;
}

int ds::HashMap::Remove(int const key) const {
  int const hash_val = HashFunc(key);

  HashNode *prev  = nullptr;
  HashNode *entry = htable[hash_val];

  if (entry == nullptr) {
    return -1;
  }
  while (entry != nullptr) {
    if (entry->key == key) {
      if (prev == nullptr) {
        // We're at the top of the table. Replace with the next entry.
        htable[hash_val] = entry->next;
      } else {
        // We're at the bottom of the table.
        prev->next = entry->next;
      }
      delete entry;

      if (unique_id) break; // if unique key, we are done

      entry = prev; // To keep checking if more entries exist with same key.

    } else { // after delete entry needs to be updated
      prev  = entry;
      entry = entry->next;
    }
  }

  return 0;
}

bool ds::HashMap::Search(int const key) const {
  bool      found    = false;
  int const hash_val = HashFunc(key);

  HashNode *entry = htable[hash_val];

  if (entry == nullptr) {
    return false;
  }

  while (entry != nullptr) {
    if (entry->key == key) {
      found = true;
      break;
    }
    entry = entry->next;
  }
  return found;
}

void *ds::HashMap::GetValue(int const key) {
  void     *val_ptr  = nullptr;
  int const hash_val = HashFunc(key);

  HashNode *entry = htable[hash_val];

  if (entry == nullptr) {
    return nullptr;
  }

  while (entry != nullptr) {
    if (entry->key == key) {
      val_ptr = entry->val_ptr;
      break;
    }
    entry = entry->next;
  }
  return val_ptr;
}

int ds::HashMap::GetFirstKey() const {
  int key = -1;

  HashNode *entry = nullptr;

  for (uint32_t i = 0; i < htable_size; ++i) {
    entry = htable[i];

    // Only need to check the top of each list.
    if (entry != nullptr) {
      key = entry->key;
      break;
    }
  }
  return key;
}

int ds::HashMap::GetNextKey(int const key) const {
  int  nextKey = -1;
  bool found   = false;

  if (key == -1) return GetFirstKey();

  HashNode *entry = nullptr;

  for (uint32_t i = 0; i < htable_size; ++i) {
    entry = htable[i];

    while (entry != nullptr) {
      if (found) {
        nextKey = entry->key;
        break;
      } else if (key == entry->key) {
        found = true;
      }
      entry = entry->next;
    }

    if (nextKey != -1) break;
  }

  return nextKey;
}
