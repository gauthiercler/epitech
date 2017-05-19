#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int my_strcmp(char *value, char *cmp)
{
  int i;

  i = 0;
  while (value[i] != '\0')
    {
      if (value[i] != cmp[i])
	return (value[i] - cmp[i]);
      i++;
    }
  return (value[i] - cmp[i]);
}

int main(int ac, char **av)
{
  printf("%s - %s => %d\n", av[1], av[2], strcmp(av[1], av[2]));
  printf("%s - %s => %d\n", av[1], av[2], my_strcmp(av[1], av[2]));
  return (0);
}
