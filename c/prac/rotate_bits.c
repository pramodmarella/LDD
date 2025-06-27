#include <stdio.h>
#define INT_BITS 32
#define ROTATE_LEFT(pos, data) ((data << pos)|(data >> (INT_BITS - pos)))
#define ROTATE_RIGHT(pos, data) ((data >> pos)|(data << (INT_BITS - pos)))
int main()
{
    int pos = 2; 
    int data = 32; 
    printf("%d Rotate Left by %d is ", data, pos);
    int d=ROTATE_LEFT(pos, data);
    for(int i=7;i>=0;i--)
	    printf("%d",d>>i&1);
	printf("\n");
	
    printf("%d Rotate Right by %d is ",data, pos);
    d=ROTATE_RIGHT(pos, data);
    for(int i=7;i>=0;i--)
	    printf("%d",d>>i&1);
	printf("\n");
    return 0;
}
