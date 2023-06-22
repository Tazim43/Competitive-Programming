#include <ext/pb_ds/assoc_container.hpp> // Trie and other PBDS containers
#include <ext/pb_ds/tree_policy.hpp>     // Policy for PBDS containers
#include <iostream>                      // For example usage
using namespace std;
using namespace __gnu_pbds;              // Namespace for PBDS

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie_type;

int main(){


  return 0;

}


// insert(key): Inserts a key into the Trie. It takes the key as input and adds it to the Trie. If the key already exists, it does not insert a duplicate.

// erase(key): Removes a key from the Trie if it exists. It takes the key as input and removes it from the Trie. If the key is not found, no action is taken.

// find(key): Searches for a key in the Trie. It takes the key as input and returns an iterator pointing to the key in the Trie if found, otherwise returns end().

// count(key): Counts the occurrences of a key in the Trie. It takes the key as input and returns the count of occurrences of the key in the Trie (0 or 1 for a standard Trie).

// prefix_range(prefix): Returns a range of keys with a given prefix. It takes the prefix as input and returns a pair of iterators denoting the range of keys with the specified prefix.

// lower_bound(key): Finds the lower bound for a key in the Trie. It takes the key as input and returns an iterator pointing to the first key that is not less than the given key in lexicographical order.

// upper_bound(key): Finds the upper bound for a key in the Trie. It takes the key as input and returns an iterator pointing to the first key that is greater than the given key in lexicographical order.

// empty(): Checks if the Trie is empty. Returns true if the Trie is empty, i.e., it contains no keys, otherwise returns false.

// size(): Returns the number of keys stored in the Trie.

// clear(): Clears the Trie, removing all the keys from it.
