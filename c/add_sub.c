#include<stdio.h>
void main()
{
        int pos=31;
        int num,b=20;
        printf("enter the number\n");
        scanf("%d",&num);
//sum      num= num+ (~b+ 1 );
      num= num- (~b- 1 );
        printf("num==%d\n",num);
//      num=num|(num+1);
        for(pos=31;pos>=0;pos--)
        {
                printf("%d",num>>pos&1);
                if(pos%4==0)
                        printf("  ");
        }
        printf("\n");
}

