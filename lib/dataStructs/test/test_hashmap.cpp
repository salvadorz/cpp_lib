#include "HashMap.hpp"
 //Temporal only for now
void ds::HashMap::Print() {
  int index;
  int level;

  HashNode *entry;

  for (index = 0; index < HASH_MAX_TABLE_SIZE; index++) {
    entry = htable[index];
    printf("Hash table index: %d\n", index);
    level = 0;

    if (entry == NULL) {
      printf("  Level: %d, ptr=%x\n", level, 0);
    } else {
      while (entry != NULL) {
        printf("  Level: %d, ptr=%p, key=%d, value=%p, next=%p\n", level, (void *)entry, entry->key,
               entry->val_ptr, (void *)entry->next);

        // Walk down
        entry = entry->next;
        level++;

      } // if
    }   // else

  } // end - for

} // Print

int main() {

  ds::HashMap hash(true);
  int         key;
  int        *value;

  // char  char_array[16] = "0123456789acbde";
  // char *ptr;

  // ------------------------------------------
  // Insert 1 element
  // ------------------------------------------

  printf(">>> TEST : Insert 1\n");
  key   = 4;
  value = (int *)1;
  hash.Insert(key, value);

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Insert a colliding key, ie a key that hashes
  // to a prev hashed key value.
  // ------------------------------------------
  printf(">>> TEST : Insert 1 where key collides\n");
  key   = 8;
  value = (int *)2;
  hash.Insert(key, value);

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Fill the htable first level
  // ------------------------------------------
  printf(">>> TEST : Fill htable[]\n");
  key   = 5;
  value = (int *)100;
  hash.Insert(key, value);
  key   = 6;
  value = (int *)200;
  hash.Insert(key, value);
  key   = 7;
  value = (int *)300;
  hash.Insert(key, value);

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Add some more
  // ------------------------------------------
  printf(">>> TEST : Add some more\n");
  key   = 12;
  value = (int *)30;
  hash.Insert(key, value);
  key   = 13;
  value = (int *)110;
  hash.Insert(key, value);
  key   = 14; // 14 2
  value = (int *)210;
  hash.Insert(key, value);
  key   = 15;
  value = (int *)310;
  hash.Insert(key, value);
  key   = 1;
  value = (int *)50;
  hash.Insert(key, value);
  key   = -2;
  value = (int *)70;
  if (hash.Insert(key, value))
    printf("Error: Insert of %d should have failed\n", value);
  else
    printf("Info: Insert of %d failed as expected\n", value);

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Remove a couple
  // ------------------------------------------
  printf(">>> TEST : Remove 3: 8, 5, 15\n");
  hash.Remove(8);  // htable[0], middle list entry
  hash.Remove(5);  // htable[1], first entry
  hash.Remove(15); // htable[2], last entry

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Search
  // ------------------------------------------
  printf(">>> TEST : Search for 14\n");
  // search for a present value
  if (hash.Search(14))
    printf("Found key = 14\n");
  else
    printf("Error: did not find key = 14\n");
  printf("\n");

  // search for a non-present value
  printf(">>> TEST : Non-existant key 67\n");
  if (hash.Search(67) == 0)
    printf("Info: key 67 was not found\n");
  else
    printf("Error: key 67 should not have been found\n");
  printf("\n");

  // ------------------------------------------
  // Update existing entry
  // ------------------------------------------
  printf(">>> TEST : Update existing entry, 12 with 3\n");
  key   = 12;
  value = (int *)3;
  hash.Insert(key, value); // update 15 from 310 to 311

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Try to remove a non-existant key
  // ------------------------------------------
  printf(">>> TEST : Try removing non-existant entry\n");
  hash.Remove(27);

  hash.Print();
  printf("\n");

  // ------------------------------------------
  // Cycle through the keys
  // ------------------------------------------
  printf(">>> TEST : Cycle through the keys\n");
  printf("List of keys:\n");
  key = hash.GetFirstKey();
  printf("  kei = %d\n", key);

  key = hash.GetNextKey(key);
  while (key != -1) {
    printf("  key = %d\n", key);
    key = hash.GetNextKey(key);
  }
  printf("\n");

  // ------------------------------------------
  // Add a ptr to an array of chars
  // ------------------------------------------
  /*
  printf(">>> TEST : Add ptr to an array of chars\n");
  key = 19;
  ptr = &char_array[0];
  hash.Insert(key, ptr);

  hash.Print();
  printf("\n");
*/
  return 0;
}