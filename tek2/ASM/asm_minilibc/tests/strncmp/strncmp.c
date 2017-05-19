#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int		returnV = 0;

void		switchString(char *p, char *str)
{
  if (p) {free(p);}
  p = strdup(str);
}

void		evalStrncmp(char *s1, char *s2, int bytes)
{
  returnV = strncmp(s1, s2, bytes);
}

int		testStrncmp(void)
{
  char		*stringA = strdup("stringA");
  char		*stringZ = strdup("stringZ");

  evalStrncmp(stringA, stringZ, 1);
  printf("SameSize ; First Lower : %s\n", (returnV == 0) ? "OK" : "KO");
  printf("Val : %d\n", returnV);
  switchString(stringA, "stringZaaa");
  evalStrncmp(stringA, stringZ, 4);
  printf("SameSize ; Equal: %s\n", (returnV == 0) ? "OK" : "KO");
  switchString(stringZ, "stringAaaa");
  evalStrncmp(stringA, stringZ, 9);
  printf("SameSize ; Second Lower : %s\n", (returnV == 25) ? "OK" : "KO");
  printf("Val : %d\n", returnV);

  /*  
  switchString(stringA, "string");
  evalStrcmp(stringA, stringZ);
  printf("First shorter ; Equal: %s\n", (returnV == -65) ? "OK" : "KO");
  switchString(stringA, "hello");
  printf("Val : %d\n", returnV);
  evalStrcmp(stringA, stringZ);
  printf("First shorter ; Smaller: %s\n", (returnV == -11) ? "OK" : "KO");
  printf("Val : %d\n", returnV);
  switchString(stringA, "z");
  evalStrcmp(stringA, stringZ);
  printf("First shorter ; Bigger: %s\n", (returnV == 7) ? "OK" : "KO");
  printf("Val : %d\n", returnV);

  switchString(stringA, "stringAAAAAAAA");
  evalStrcmp(stringA, stringZ);
  printf("First longer ; Bigger: %s\n", (returnV == 65) ? "OK" : "KO");
  printf("Val : %d\n", returnV);*/
  
  free(stringA);
  free(stringZ);
  return (0);
}

int		main(void)
{
  testStrncmp();
  return (0);
}
