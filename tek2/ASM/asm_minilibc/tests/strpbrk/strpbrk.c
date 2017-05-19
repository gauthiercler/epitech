#include	<string.h>
#include	<stdio.h>

int	main(void)
{
  char	*ptr;

  char *s1 = strdup("string");
  char *s2 = strdup("r");
  
  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));

  free(s2);s2 = strdup("zz");
  
  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));

  free(s2);s2 = strdup("dkkdt");
  
  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));
 
  free(s2);s2 = strdup("fkefeifekifeikzeergdsdzdz");
  
  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));

  free(s2);s2 = strdup("aze");

  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));

  free(s2);s2 = strdup("djjjdddjdjdjdjdjdjdjdjdjdjdjjd");
  
  ptr = strpbrk(s1, s2);
  printf("Ptr => %c\n", (ptr ? *ptr : 48));


  return (0);
}
