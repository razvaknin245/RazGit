#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) 
{
  if(size<64)
  {
      return 0;
  } 
  return -1;
}
int testing(int argc, char **argv) 
{
    char *buffer = calloc(64, sizeof(*buffer));

    if (!buffer) {
        printf("Allocation failed\n");
        return -1;
    }

    strcpy(buffer,argv[1]);

    printf("%s\n", buffer);
    
    return 0;
}
