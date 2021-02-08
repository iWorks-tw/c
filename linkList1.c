#include<stdio.h>
#include<malloc.h>
struct node//node�����c�]��
{
int data;
struct node *next;
};
struct node *create();//�snode���ͤ��~���禡
int main(void)
{
int ask,check;
int del;
struct node *head,*pnew,*p1,*p2;
head=NULL;
ask=-1;

printf("����----Linked List----(�쵲��C)����\n");
while(ask!=0) //ask==0�ɵ����{��
{ //�]�߫��O
    printf("\n�����O:������J0�A�s�W��J1�A�R����J2�A�C�X��J3>");
    scanf("%d",&ask);
    if(ask<0 || ask>3) //�b���O���~�n�D�ϥΪ̭��s��J
    {
        printf("�Э��s��J!!!\n");
        continue;
    }
    if(ask==1) //ask==1�ɷs�W���
    {
        pnew=create();//���ͤ@�ӷs���`�I
        if(head==NULL )
        { //head���a

            head=pnew; //head���V�snode
            //pnew->next=NULL; //first node��next���VNULL
            continue; //���X�A�^��W����while
        }
        p1=head; //p1���V�Ĥ@��node
        p2=head->next; //p2���V�ĤG��node
        while(p2!=NULL) //p2�S���a��
        {

            p1=p2; //p1�Mp2�P�ɰ���

            p2=p2->next;


         }
        p1->next=pnew;
    }
    if(ask==2) //ask==2�ɡA����R���ʧ@
    {
        check=-1;//�Y�����n�R������ƴN�NCHECK�]��-1
        printf("��J�n�R�����ƭ�>");//�ϥΪ̿�J�Q�R������
        scanf("%d",&del); //����del�x�s�_��
        if(head==NULL) //�����S��node�����L�X���s�b
        {
            printf("%d���s�b",del);
            continue; //���^�W��while
        }
         if(head->data==del&&head->next==NULL) //�u���@��NODE�B�S�ŦX�n�R��������
        {
            free(head);//����HEAD�O����
            head=NULL;//�]����list
            check=1;//�]�����äw�R�����
            continue; //���^�W��while
        }

        p1=head; //p1���V�Ĥ@��node
        p2=head->next; //p2���V�ĤG��node


        while(p2!=NULL) //p2�S���a��
        {
             if(p1->data==del&&p1==head)//��p1�ȵ�����R�����ȥBp1�OHEAD
            {

                head=p2;//p2�]���shead
                free(p1); //����p1���Ŷ�
                check=1;//�]�����äw�R�����
                break; //���_��while
            }
            if(p2->data==del)//��p2�ȵ�����R������
            {
                p1->next=p2->next;//p1��next�������Lp2��p2��next,�R��P2�`�I
                free(p2); //����p2���Ŷ�
                check=1;//�]�����äw�R�����
                break; //���_��while
            }
            //�~����U�@�����
            p1=p2; //p1�Mp2�P�ɰ����A�]�w�U�@����Ʀ�}

            p2=p2->next;
        }

        if(check==-1){

         printf("%d���s�b!!!",del);//p2���a�ɦL�X���s�b
        }

    }
    if(ask==3) //ask==3����C�L
    {
        p1=head; //p1���V�Ĥ@��node
        while(p1!=NULL) //��p1���O�Ū�����
        {
            printf("%d\n",p1->data);//�L�X
            p1=p1->next; //����ĤG�Ӹ`�I
        }
    }
}
return(0);
}

struct node *create() //�s�`�I���ͤ��~���禡
{
    int n;
    struct node *temp; //�ŧi�@��temp����
    printf("��J�ƭ�>"); //�ϥΪ̿�J
    scanf("%d",&n); //�s�^n
    temp=(struct node *)malloc(sizeof(struct node));//�t�m�O����A��temp���V�@�ӷs�Ŷ�
    temp->data=n; //�s�Ŷ�����data�ȵ���n
    temp->next=NULL; //next���a
    return temp; //�Ǧ^temp�ҫ��V����}
}
