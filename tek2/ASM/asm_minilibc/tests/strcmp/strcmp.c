#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int		returnV = 0;

void		switchString(char *p, char *str)
{
  if (p) {free(p);}
  p = strdup(str);
}

void		evalStrcmp(char *s1, char *s2)
{
  returnV = strcmp(s1, s2);
}

int		testStrcmp(void)
{
  char		*stringA = strdup("stringA");
  char		*stringZ = strdup("stringZ");

  evalStrcmp(stringA, stringZ);
  printf("SameSize ; First Lower : %s\n", (returnV == -25) ? "OK" : "KO");
  printf("Val : %d\n", returnV);
  switchString(stringA, "stringZ");
  evalStrcmp(stringA, stringZ);
  printf("SameSize ; Equal: %s\n", (returnV == 0) ? "OK" : "KO");
  switchString(stringZ, "stringA");
  evalStrcmp(stringA, stringZ);
  printf("SameSize ; Second Lower : %s\n", (returnV == 25) ? "OK" : "KO");
  printf("Val : %d\n", returnV);

  
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
  printf("Val : %d\n", returnV);
  
  free(stringA);
  free(stringZ);
  return (0);
}

int		main(void)
{
  testStrcmp();
  return (0);
}
