//�e���𻼰j�m��
#include <stdio.h>
int main(){
int n;
int i=0;
printf("�п�J�M���ӼơG");
scanf("%d",&n);
printf("\n�}�l�h���G\n");
towers(n,'A','B','C',&i);
printf("����%d�ӮM���@��%d�ӨB�J",n,i);

}
void towers(int n,char X,char Y,char Z,int *Pri){
*Pri=*Pri+1;

if(n==1){
    printf("�M�� 1 �q %C �W���ʨ� %C �W\n", X, Z);
    return ;
}

else {
    towers(n-1,X,Z,Y,Pri);
    printf("�M�� %d �q %C �W���ʨ� %C �W\n",n, X, Z);
    towers(n-1,Y,X,Z,Pri);

}



}

