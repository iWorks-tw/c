#include <stdio.h>
void main(){
int i;
int *ptr;
i=10;
ptr=&i;
printf("i ���O�����}�O:%d  i=%d\n",&i,i);
printf("ptr �����e�O:%d  *ptr=%d\n",ptr,*ptr);
memA(ptr,&i);

printf("i ���O�����}�O:%d  i=%d\n",&i,i);
}
void memA(int mA,int  *mm){

printf("mA �����e�O:%d  \n",mA);
printf("mm �����e�O:%d  \n",mm);
printf("*mm �����e�O:%d  \n",*mm);
*mm=*mm+1;//���V�ӰO���骺���e�ƭ�+1
}
