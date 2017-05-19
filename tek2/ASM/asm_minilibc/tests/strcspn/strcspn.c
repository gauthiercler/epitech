int main(void)
{
  char *s1 = strdup("hello");
  char *s2 = strdup("l");
  printf("%s - %s --> %llu\n", s1, s2, strcspn(s1, s2));
  free(s1);s1=strdup("this is my string");
  free(s2);s2=strdup("nzddde");
  printf("%s - %s --> %llu\n", s1, s2, strcspn(s1, s2));
  free(s1);s1=strdup("asm is great");
  free(s2);s2=strdup("ezfzaadda");
  printf("%s - %s --> %llu\n", s1, s2, strcspn(s1, s2));
  return (0);
}
