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
int ask;
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
        pnew=create();//���ͤ@�ӷs���`�I(���̤j�p�Ƨ�)
        if(head==NULL || head->data > pnew->data)
        { //head���a�γ�@node�ɪ��Ȥj����s�W��node����
            pnew->next=head; //�snode��next���Vhead�ҫ���node
            head=pnew; //head���V�snode
            continue; //���X�A�^��W����while
        }
        p1=head; //p1���V�Ĥ@��node
        p2=head->next; //p2���V�ĤG��node
        while(p2!=NULL) //p2�S���a��
        {
            if(p2->data>pnew->data)//��p2��node�Ȥj��snode���Ȯ�
            {
                pnew->next=p2;//�snode��next���Vp2
                p1->next=pnew;//p1��next���V�snode
                break; //���_�e�@��while
            }
                p1=p2; //p1�Mp2�P�ɰ���
                p2=p2->next;
        }
        p1->next=pnew; //��p2���a�ɡAp1��next��������snode
    }
    if(ask==2) //ask==2�ɡA����R���ʧ@
    {
        printf("��J�n�R�����ƭ�>");//�ϥΪ̿�J�Q�R������
        scanf("%d",&del); //����del�x�s�_��
        if(head==NULL) //�����S��node�����L�X���s�b
        {
            printf("%d���s�b",del);
            continue; //���^�W��while
        }
        p1=head; //p1���V�Ĥ@��node
        p2=head->next; //p2���V�ĤG��node
        if(p1->data==del) //��Ĥ@��node���ȵ�����R����node��
        {
            head=p2; //head�������Vp2(�ĤG��node)
            free(p1); //����Ĥ@��node���Ŷ�
            continue; //���^�~��while
        }
        while(p2!=NULL) //p2�S���a��
        {
            if(p2->data==del)//��p2�ȵ�����R������
            {
                p1->next=p2->next;//p1��next�������Lp2��p2��next
                free(p2); //����p2���Ŷ�
                break; //���_��while
            }
            p1=p2; //p1,p2�P�ɰ���
            p2=p2->next;
        }
        printf("%d���s�b!!!",del);//p2���a�ɦL�X���s�b
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
    temp=(struct node *)malloc(sizeof(struct node));//temp���V�@�ӷs�Ŷ�
    temp->data=n; //�s�Ŷ�����data�ȵ���n
    temp->next=NULL; //next���a
    return temp; //�Ǧ^temp�ҫ��V����}
}
