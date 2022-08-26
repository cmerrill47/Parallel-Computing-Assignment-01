#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char host[256];
  char *IP;
  struct hostent *host_entry;
  int hostname;
  hostname = gethostname(host, sizeof(host)); // find the host name

  printf("Hostname: %s\n", hostname);
  return 0;
}
