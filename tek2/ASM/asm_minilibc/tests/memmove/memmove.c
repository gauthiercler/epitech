int main(void)
{
  char *mem = (char *) malloc(10);
  char *string = strdup("azerty");

  memset(mem, 0, 10);
  memcpy(mem, string, strlen(string));
  free(string);
  printf("Ret of strcmp memcpy =>  %d\n", strcmp("azerty", mem));
  printf("Mem : %s\n", mem);
  memmove(mem + 4, mem, 5);
  printf("Mem after memmove : %s\n", mem);
  printf("Ret of strcmp memmove =>  %d\n", strcmp("azerazert", mem));
  return (0);
}
