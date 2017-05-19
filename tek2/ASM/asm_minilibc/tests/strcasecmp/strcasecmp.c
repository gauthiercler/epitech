int main(void)
{

  printf("Ret : %d\n", strcasecmp("toto", "titi"));
  printf("Ret : %d\n", strcasecmp("TOTO", "TITI"));
  printf("Ret : %d\n", strcasecmp("TOTO", "titi"));
  printf("Ret : %d\n", strcasecmp("aaaZa", "aaaza"));
  printf("Ret : %d\n", strcasecmp("aaaZa", "aaafdfa"));
  return (0);
}
