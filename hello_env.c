#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#define ARRLEN(aa) (sizeof(aa)/sizeof(aa[0]))

/* 
 * Load OSv .so file immediately
 */
asm(".pushsection .note.osv-mlock, \"a\"; .long 0, 0, 0; .popsection");

void print_env(char **env) {
  char **ch;
  int ii=0;
  printf("ENV /*--------------------------\n");
  for(ch=env; *ch != NULL; ch++, ii++) {
    printf("ENV %02d %s\n", ii, *ch);
  }
  printf("ENV --------------------------*/\n");
}

//int main(int argc, char **argv, char **env)
extern char **environ;
int main(int argc, char **argv)
{
  printf("In hello_env.c main.\n");
  printf(" argc %d\n", argc);
  int ii;
  for(ii=0; ii<argc; ii++) {
    printf(" argv[%d] = %s\n", ii, argv[ii]);
  }
  print_env(environ);
  return 0;
}
