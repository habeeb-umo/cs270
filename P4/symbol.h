#ifndef __SYMBOL_H__
#define __SYMBOL_H__

/*
 * "Copyright (c) 2014 by Fritz Sieker."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright notice
 * and the following two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE TO ANY PARTY FOR DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE AUTHOR
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE AUTHOR SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS"
 * BASIS, AND THE AUTHOR NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
 * UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 */

/** @file symbol.h
 *  @brief Defines the interface to symbol.c functions (do not modify)
 *  @details This file defines the interface to a C file symbol.c that
 *  you will complete.
 *  <p>
 *  In this implementation, you will learn about dynamic memory management using
 *  malloc/free. You will also learn about function pointers (callback
 *  functions).
 */

/** Suggested size, 997 is a prime (primes reduce hashing collisions) */
#define SYM_TAB_SIZE 997

/** This defines an opaque type. The actual contents of the structure are hidden
 *  in the implementation and only a pointer to this structure is used
 *  externally to this file. A pointer to an opaque structure is sometimes
 *  referred to as a handle.
 */

typedef struct sym_table sym_table_t;

/** The symbol_find methods return a pointer to this data structure. It
represents.
 */

typedef struct symbol {
    char* name; /**< the name of the symbol */
    int   addr; /**< symbol's address in the LC3 memory */
} symbol_t;

/** Defines the signature of a callback function (also known as a function
 *  pointer). This is how languages such as Java and C++ do <b>dynamic</b>
 *  binding (i.e. figure out which function to call). Recall that in Java, the
 *  code <code>obj.equals(object)</code> will call one of possibly many
 *  different methods depending on the actual type of <code>obj</code>. This
 *  is because the method <b>.equals()</b> may be <b>overridden</b>.
 *  <p>
 *  In the LC3, dynamic binding is based on the <b>JSRR</b> opcode. With this
 *  opcode, the address of the routine to call is stored in a register and can
 *  be changed at runtime. Compare this to a <b>JSR nameOfRoutine</b> opcode 
 *  which specifies what routine to call from the label that follows it. Thus, 
 *  the address is fixed at <b>assembly</b> time. 
 *  <p>
 *  This is used in the <code>symbol_iterate</code> function.
 *  @param sym - pointer to a symbol
 *  @param data - a pointer to some data that the function might need.
 */
typedef void (*iterate_fnc_t)(symbol_t* sym, void* data);

/** Create a new symbol table and return a pointer to it. This function is a
 *  constructor for a symbol table. It should initialize all members of a
 *  dynamically allocated sym_table_t structure:
 *  <ul>
 *  <li><code>hash_table</code> must be set to point to a dynamically allocated
 *    array of linked list heads (<code>node_t</code> pointers). The size of the
 *    array depends on the <code>table_size</code> parameter. All heads in the
 *    hash table must be initialized to NULL.</li>
 *  <li><code>addr_table</code> must be set to point to a dynamically allocated
 *    array of strings (<code>char</code> pointers). The size of the array is
 *    LC3_MEMORY_SIZE which is a constant that defines the number of addresses
 *    that the LC3 processor can address. All entries must be initialized to
 *    NULL.</li>
 *  <li><code>size</code> must be set to the size of the hash table.</li>
 *  </ul>
 *  @param table_size - the size of the hash table.
 *  @return a pointer to the dynamically allocated symbol table structure.
 */ 
sym_table_t* symbol_init (int table_size);

/** Add a symbol to the hash table assumming that it is not a name duplicate
 *  (i.e., there is no other symbol in the hash table with the same name). The
 *  symbol name should also be added to the <code>addr_table</code> at
 *  index = <code>addr</code>. It is possible that there is already a name at 
 *  that address in <code>addr_table</code>. In this case, the
 *  <code>addr_table</code> entry must be left unchanged.
 *  @param symTab - pointer to the symbol table
 *  @param name - the name of the symbol
 *  @param addr - the address of the symbol
 */
void symbol_add_unique (sym_table_t* symTab, const char* name, int addr);

/** Find a name by its address. The lookup should be performed in the
 *  <code>addr_table</code>.
 *  @param symTab - pointer to the symbol table
 *  @param addr - an LC3 address
 *  @return the <b>label</b> at that address or NULL if no symbol is
 *  associated with the address. 
 */
char* symbol_find_by_addr (sym_table_t* symTab, int addr);

/** This function calls another function for every node in the symbol table.
 *  Please refer to the assignment instructions for the order in which symbols
 *  <u>must</u> be visited. The function to be called must be called through
 *  the function pointer <code>fnc</code>.
 *  @param symTab - pointer to the symbol table
 *  @param fnc - pointer to the function to be called on every element
 *  @param data - any additional information to be passed on to
 *  <code>fnc</code> directly. The called function will cast this to whatever
 *  type was actually passed.
 */
void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data);

/** This function is a useful support function for the
 *  <code>symbol_add()</code> and <code>symbol_find_by_name()</code> functions.
 *  It searches for a node in the hash table whose symbol's name matches the
 *  name passed to the function. The search must be performed in a case
 *  insensitive manner.
 *  @param symTab - pointer to the symbol table
 *  @param name - the name of the symbol
 *  @param hash - this function must obtain the hash value of the
 *  <code>name</code> parameter and return it through this pointer 
 *  @param index - this function must obtain the index in which the symbol being
 *  searched for is expected to be in the hash table and must return it through
 *  this pointer 
 *  @return  a pointer to the node that contains the symbol being searched for
 *  or NULL if the symbol was not found.
 */
struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index);

/** Add a symbol to the hash table only if it is not a name duplicate. If
 *  another symbol with the same name already exists in the symbol table, an 
 *  error code is returned. The symbol name should also be added to the 
 *  <code>addr_table</code> at index = <code>addr</code>. It is possible that
 *  there is already a name at that address in <code>addr_table</code>. In this 
 *  case, the <code>addr_table</code> entry must be left unchanged. Consider
 *  using the <code>symbol_search()</code> and <code>symbol_add_unique()</code>
 *  functions. When detecting duplicates, you must ignore case. For example,
 *  symbols AB and ab are considered duplicates.
 *  @param symTab - pointer to the symbol table
 *  @param name - the name of the symbol
 *  @param addr - the address of the symbol
 *  @return 1 if the symbol is not a name duplicate and was added, 0 if the
 *  symbol is a name duplicate.
 */
int symbol_add (sym_table_t* symTab, const char* name, int addr);

/** Find a symbol by its name. The search must be case insensitive.
 *  @param symTab - pointer to the symbol table
 *  @param name - the symbol's name
 *  @return  a pointer to the symbol or NULL if the symbol was not found
 */
symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name);

/** Remove all the symbols from the symbol table. This involves:
 *  <ul>
 *  <li>Freeing all dynamically allocated memory associated with all nodes and
 *    strings</li>
 *  <li>Resetting all the heads in the hash table to NULL</li>
 *  <li>Resetting all the entries in the <code>addr_table</code> to NULL</li>
 *  </ul>
 *  There must not be memory leaks after calling this function. After this call,
 *  the opaque symbol table pointer is still valid and, new symbols may be added
 *  to the symbol table.
 *  @param symTab - pointer to the symbol table
 */
void symbol_reset (sym_table_t* symTab);

/** Remove all symbols from the symbol table, and free all allocated memory.
 *  This function is a destructor for a symbol table. Consider using the
 *  <code>symbol_reset()</code> function and then free the remaining memory.
 *  There must not be any memory leaks. Test it with Valgrind. Running it with
 *  the <code>\-\-leak\-check=yes</code> option must output the following two
 *  lines:
 *  <p><code>All heap blocks were freed -- no leaks are possible</code></p>
 *  <p><code>ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from
 *    0)</code><p>
 *  After executing this function, the opaque pointer to the symbol table is no 
 *  longer valid.
 */
void symbol_term(sym_table_t* symTab);

#endif /* __SYMBOL_H__ */

