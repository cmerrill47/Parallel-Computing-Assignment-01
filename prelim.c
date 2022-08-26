#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

  char hostName = gethostname();

  printf("Hostname: %s\n", hostName);
  return 0;
}
