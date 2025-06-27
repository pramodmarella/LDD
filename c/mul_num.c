#include <stdio.h>

int main() {
    int a = 5; 
    int b = 10; 
    int result = 0;

    for (int i = 0; i < 32; i++) {
        //if (b & (1 << i)) {
          if(b>>i&1){
	  int term = a << i;
            result = result - ((~term) - (-1)); 
        }
    }

    printf("Multiplication Result = %d\n", result);
    return 0;
}

