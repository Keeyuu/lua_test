#include<iostream>
#include<stdio.h>
void test(int n,int p1, int p2, int p3)
{
    if(n == 1)
        {
        printf("把盘子 从%d 移动到了%d\n",p1,p3);
        }
    else
    {
        test(n - 1, p1, p3, p2);
        printf("把盘子 从%d 移动到了%d\n", p1, p3);
        test(n - 1, p2, p1, p3);
    }
    
}


int main(int argc,char*argv[]){
     test((*(int*)argv[1]), 1, 2, 3);
}