#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "symbol.h"

/** @file symbol.c
 *  @brief You will modify this file and implement the symbol.h interface
 *  @details Your implementation of the functions defined in symbol.h.
 *  You may add other functions if you find it helpful. Added functions
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 * <p>
 * @author <b>Your name</b> goes here
 */

/** size of LC3 memory */
#define LC3_MEMORY_SIZE  (1 << 16)

/** Provide prototype for strdup() */
char *strdup(const char *s);

/** defines data structure used to store nodes in hash table */
typedef struct node {
  struct node* next;     /**< linked list of symbols at same index */
  int          hash;     /**< hash value - makes searching faster  */
  symbol_t     symbol;   /**< the data the user is interested in   */
} node_t;

/** defines the data structure for the hash table */
struct sym_table {
  int      size;        /**< size of hash table         */
  node_t** hash_table;  /**< array of linked list heads */
  char**   addr_table;  /**< look up symbols by addr    */
};

/** djb hash - found at http://www.cse.yorku.ca/~oz/hash.html
 * tolower() call to make case insensitive.
 */

static int symbol_hash (const char* name) {
  unsigned char* str  = (unsigned char*) name;
  unsigned long  hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

  c = hash & 0x7FFFFFFF; /* keep 31 bits - avoid negative values */

  return c;
}

/** @todo implement this function */
sym_table_t* symbol_init (int table_size) {
	// Initialize symbol table
	sym_table_t *symTable = calloc(1, sizeof(sym_table_t));
	
	// Initialize hash table 
	symTable -> hash_table = calloc(table_size, sizeof(node_t*));

	// Initialize address table
	symTable -> addr_table = calloc(LC3_MEMORY_SIZE, sizeof(char));

	// Set table size
	symTable -> size = table_size;
	

return symTable;
}

/** @todo implement this function */
void symbol_add_unique (sym_table_t* symTab, const char* name, int addr) {
	// Make a copy of name
	char *nameCopy = strdup(name);
	// Calculate hash
	int symHash = (symbol_hash(nameCopy));
	int hashAddr = symHash % (symTab -> size);
	// New symbol
	symbol_t newSym;
	newSym.name = nameCopy;
	newSym.addr = addr;
	// Node exchange in linked list
	node_t* currentPtr = symTab -> hash_table[hashAddr];
	node_t* newNode = calloc(1, sizeof(node_t));
	newNode -> next = currentPtr;
	newNode -> hash = symHash; 
	newNode -> symbol = newSym;
	// Change old symbol to new
	symTab -> hash_table[hashAddr] = newNode;
	if(symTab -> addr_table[addr] != NULL){
		
	}
	else
	symTab -> addr_table[addr] = newSym.name;
}

/** @todo implement this function */
char* symbol_find_by_addr (sym_table_t* symTab, int addr) {
	// Return symbol at addr in the address table
	return symTab -> addr_table[addr];
}

/** @todo implement this function */
void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data) {
	// Loop through each entry in hash table
	for(int i = 0; i < symTab -> size; i++){
	node_t* currNode = symTab -> hash_table[i];
	// Visit each entry that is not NULL and use fnc
	while(currNode != NULL){
		node_t* tempNode = currNode;
		(*fnc)(&(tempNode -> symbol), data);
		currNode = currNode -> next;
	}
}
}

/** @todo implement this function */
struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index) {

  *hash = symbol_hash(name);
  return NULL;
}

/** @todo implement this function */
int symbol_add (sym_table_t* symTab, const char* name, int addr) {
  return 0;
}

/** @todo implement this function */
symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name) {
  return NULL;
}

/** @todo implement this function */
void symbol_reset(sym_table_t* symTab) {
}

/** @todo implement this function */
void symbol_term (sym_table_t* symTab) {
}

