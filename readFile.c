#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    FILE *fPtr;//�ɮ׫���

    char s[100];//Ū���r���W��
    char k[50];//��J�r���W��

    scanf("%s",&k);//��LŪ��

    fPtr = fopen("test.txt", "r+");//�}���ɮר��o���СA�ó]���iŪ�g
    if (!fPtr) {
        printf("�ɮ׶}�ҥ���...\n");
        exit(1);
    }
    fseek(fPtr, 0, SEEK_END);//�N�r�����Ы���r������
    fputs(k,fPtr);//�q�r�����ݥ[�J�s�r��
    rewind(fPtr);//�N���в���r���e��
    while(fgets(s,sizeof(s), fPtr)!=NULL) {

        printf(s);
    }
    printf("\n");

    fclose(fPtr);

    return 0;
}

