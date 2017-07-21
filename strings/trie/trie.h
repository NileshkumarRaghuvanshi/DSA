#ifndef TRIE_H
#define TRIE_H

typedef int val;
typedef struct trieNode *trieRoot;

trieRoot createTrie();
void destroyTrie(trieRoot root);

int trieAdd(trieRoot *root, char *key, val value);
void trieRemove(trieRoot root, char *key);

val trieGetValue(trieRoot root, char *key);
int trieIsMember(trieRoot root, char *key);

void trieKeyWithMatchingPrefix(trieRoot root, char *key);
void triePrintKeys(trieRoot root);
#endif //TRIE_H
