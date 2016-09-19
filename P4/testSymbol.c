/*
 * testSymbol.c - testDriver for the functions of symbol.h
 *
 * "Copyright (c) 2012 by Fritz Sieker."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright notice
 * and the following two paragraphs appear in all copies of this software,
 * that the files COPYING and NO_WARRANTY are included verbatim with
 * any distribution, and that the contents of the file README are included
 * verbatim as part of a file named README with any distribution.
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
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

/** @mainpage cs270 Programming Assignment - Symbol Table 
 *  \htmlinclude "symbol.html"
 */

/** @file testSymbol.c
  * @brief Driver to test functions of symbol.c (do not modify)
  *
  * @details This is a driver program to test the functions of symbol.c
  * The program accepts a series of commands and executes those commands one at
  * a time. To understand the usage, type the command <code>help</code>. This
  * will give a brief description of each command and its parameters. Each
  * command and its parameters are on a single line separated by whitespace.
  * <p>
  * @author: Fritz Sieker
  */

/** Maximum length of command line processed */
#define MAX_LINE_LENGTH 128

/** Delimiter used separate tokens on line - used by strtok() */
const char *delim = " \t";

/** Print a usage statement describing how program is used */
static void help() {
  puts("Usage: testSymbol <size>\n");
  puts("enter commands from keyboard, one per line:");
  puts("quit/exit         - terminates program");
  puts("                    (calls symbol_term)");
  puts("add name address  - prints OK on success, Duplicate on failure");
  puts("                    (calls symbol_add)");
  puts("addu name address - prints OK");
  puts("                    (calls symbol_add_unique)");
  puts("count             - prints count of names/addresses");
  puts("                    uses function pointers");
  puts("                    (calls symbol_iterate)");
  puts("get name          - prints NULL or name/address");
  puts("                    (calls symbol_find_by_name)");
  puts("label address     - prints NULL or name associated with address");
  puts("                    (calls symbol_find_by_addr)");
  puts("list              - prints all names/addresses");
  puts("                    uses function pointers");
  puts("                    (calls symbol_iterate)");
  puts("search name       - prints NULL or name/address and hash/index");
  puts("                    (calls symbol_search)");
  puts("reset             - resets symbol table and address table");
  puts("                    (calls symbol_reset)");
}

/** Print a usage statement describing how program is used, and exits */
static void usage() {
  help();
  exit(1);
}

/** get the next token from the input
 *  @return the token, or exit with error
 */
static char* nextToken () {
  char* tok = strtok(NULL, delim);
  if (! tok)
    usage();
  return tok;
}

/** Get an integer from the input
 *  @return the value, or exit with error
 */
static int nextInt() {
  char* junk;
  char* tok = nextToken();
  return (int) strtol(tok, &junk, 0);
}

/** Example of a call back function called via symbol_iterate()
 */
static void countSymbols (symbol_t* sym, void *data) {
  int* ip = (int*) data;
  *ip = *ip + 1;
}

/** Another example of a call back function called via symbol_iterate()
 */
static void printResult(symbol_t* sym, void* data) {
  FILE* f = (FILE*) data;

  if (! sym)
    fprintf(f, "NULL\n");
  else
    fprintf(f, "name:%s addr:%d\n", sym->name, sym->addr);
}

/** Entry point of the program
 * @param argc count of arguments, will always be at least 1
 * @param argv array of parameters to program argv[0] is the name of
 * the program, so additional parameters will begin at index 1.
 * @return 0 the Linux convention for success.
 */
int main (int argc, char* argv[]) {
  char line[MAX_LINE_LENGTH];
  int  count, addr;
  char *cmd, *name;
  sym_table_t* symTab;

  if (argc != 2)
    usage();

  symTab = symbol_init(atoi(argv[1]));

  while (fgets(line, sizeof(line), stdin) != NULL) {
    char *cr = strchr(line ,'\n'); /* get rid of trailing \n, if any */

    if (cr)
      *cr = '\0';

    cmd = strtok(line, delim);

    if (! cmd)
      continue;

    if (strcmp(cmd, "add") == 0) {
      name = nextToken();
      addr = nextInt();
      fprintf(stderr, "%s\n", (symbol_add(symTab, name, addr) ? "OK" : "Duplicate"));
    } else if (strcmp(cmd, "addu") == 0) {
      name = nextToken();
      addr = nextInt();
      symbol_add_unique(symTab, name, addr);
      fprintf(stderr, "OK\n");
    }
    else if (strcmp(cmd, "count") == 0) {
      count = 0;
      symbol_iterate(symTab, countSymbols, &count);
      fprintf(stderr, "symbol count: %d\n", count);
    }
    else if ((strcmp(cmd, "exit") == 0) || (strcmp(cmd, "quit") == 0)) {
      break;
    }
    else if (strcmp(cmd, "get") == 0) {
      name = nextToken();
      printResult(symbol_find_by_name(symTab, name), stdout);
    }
    else if (strcmp(cmd, "help") == 0) {
      help();
    }
    else if (strcmp(cmd, "label") == 0) {
      addr = nextInt();
      fprintf(stderr, "label at addr %d '%s'\n", addr,
             symbol_find_by_addr(symTab, addr));
    }
    else if (strcmp(cmd, "list") == 0) {
      symbol_iterate(symTab, printResult, stdout);
    }
    else if (strcmp(cmd, "reset") == 0) {
      symbol_reset(symTab);
    }
    else if (strcmp(cmd, "search") == 0) {
      int hash, index;
      name              = nextToken();
      struct node* node = symbol_search(symTab, name, &hash, &index);
      fprintf(stderr, "symbol '%s' hash: %d index: %d is %s in symbol table\n", name,
             hash, index, (node ? "" : "NOT"));
    }
    else {
      help();
    }
  }

  symbol_term(symTab); /* can check for memory leaks now */

  return 0;
}
