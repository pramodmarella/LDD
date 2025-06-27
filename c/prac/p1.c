#include<stdio.h>
#include<string.h>
#include<malloc.h>

int make_equal (char* T, char* S) {
    // Write your code here
    if(strcmp(S,T)==0)
    return 1;
    
    int i,j,k,l;
    for(l=0;S[l];l++);
    for(i=0,j=l-1;i<j;i++,j--)
    {
   	k=S[i];
	S[i]=S[j];
	S[j]=k;
    }
    if(strcmp(S,T)==0)
    return 1;
}

int main() {
    char* T = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", T);
    char* S = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", S);

    int out_ = make_equal(T, S);
    if(out_ == 1)
    printf("YES\n");
    else
    printf("NO\n");
}

