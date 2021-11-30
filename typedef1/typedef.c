#include <stdio.h>

typedef unsigned char BYTE;
  
int main(int argc, char const *argv[])
{
    BYTE b1, b2;
    b1 = 'c\n';
    printf("%c ", b1);
    return 0;
}