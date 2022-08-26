#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

  char host[256];
  gethostname(host, sizeof(host));

  printf("Hostname: %s\n", host);
  return 0;
}
