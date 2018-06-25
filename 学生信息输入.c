#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
struct list *next;
int num;
char name[30];
int age;
char sex;
char subject[50];
int classroom;
}
user;

void insert(user *h);
void edit(user *h);
void del(user *h);
void S_byName(user *h);
void S_byNum(user *h);
void display(user *h);

int main()
{
    int flag;
    user *head=(user *)malloc(sizeof(user));
    head->next=NULL;
    while(1)
    {
		printf("*****************************\n");
        printf("*1�����ѧ����Ϣ            * \n");
        printf("*2���޸�ѧ����Ϣ            * \n");
        printf("*3��ɾ��ѧ����Ϣ            * \n");
        printf("*4������ѧ��������Ϣ        * \n");
        printf("*5������ѧ�Ų�ѯ��Ϣ        * \n");
        printf("*6��ͳ��ȫ��ѧ����Ϣ        * \n");
        printf("*7���˳�                    * \n");
		printf("*****************************\n");

        printf("��ѡ��");
        scanf("%d",&flag);
        if(flag==1)
            insert(head);
        else if(flag==2)
            edit(head);
        else if(flag==3)
            del(head);
        else if(flag==4)
            S_byName(head);
        else if(flag==5)
             S_byNum(head);
        else if(flag==6)
            display(head);
        else if(flag==7)
            return 0;
        else
            printf("��������������ѡ��\n");
    }
}
void insert(user *h)
{
    user *p=(user *)malloc(sizeof(user));
    p->next=h->next;
    h->next=p;
    printf("������ѧ��ѧ�ţ�");
    scanf("%d",&p->num);
    printf("������ѧ��������");
    scanf("%s",p->name);
    printf("������ѧ�����䣺");
    scanf("%d",&p->age);
    printf("������ѧ���Ա�");
    scanf("%x",&p->sex);

    printf("������ѧ��רҵ��");
    scanf("%s",p->subject );
    printf("������ѧ���༶��");
    scanf("%d",&p->classroom );
    printf("ѧ����Ϣ��ӳɹ���%d %s %d %x %s %d\n",p->num,p->name,p->age,p->sex, p->subject,p->classroom);
}
void edit(user *h)
{
    int num;
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ�޸�ѧ����ѧ�ţ�");
    scanf("%d",&num);
    while(lh)
    {
        if(num == lh->num)
        {
            flag=1;
            printf("������ѧ��ѧ�ţ�");
            scanf("%d",&lh->num);
            printf("������ѧ��������");
            scanf("%s",lh->name);
            printf("������ѧ�����䣺");
            scanf("%d",&lh->age);
            printf("������ѧ���Ա�");
            scanf("%x",&lh->sex);
            printf("������ѧ��רҵ��");
            scanf("%s",lh->subject );
            printf("������ѧ���༶��");
            scanf("%d",&lh->classroom );
            printf("ѧ����Ϣ��ӳɹ���%d %s %d %x %s %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�鲻����ѧ��\n\n");
}
void S_byName(user *h)
{
    char name[30];
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ���ҵ�ѧ��������");
    scanf("%s",name);
    while(lh)
    {
        if(strcmp(name,lh->name)==0)
        {
            flag=1;
            printf("ѧ����ϢΪ��%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject, lh->classroom);
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("ѧ��������\n\n");
}
void S_byNum(user *h)
{
    int num;
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ���ҵ�ѧ�ţ�");
    scanf("%d",&num);
    while(lh)
    {
        if(num == lh->num)
        {
            flag=1;
             printf("ѧ����Ϣ:%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�Ҳ���ƥ���ѧ��\n\n");
}
void display(user *h)
{
    user *lh=h->next;
    int i=1;
    while(lh)
    {
        printf("��%d���û���Ϣ:%d %s %d %x %s   %d\n",i,lh->num,lh->name,lh->age,lh->sex, lh->subject ,lh->classroom );
        lh=lh->next;
        i++;
    }
    printf("\n");
}
void del(user *h)
{
    int num;
    int flag=0;
    user *lh=h;
    printf("����Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%d",&num);
    while(lh->next)
    {
        if(num == lh->next->num)
        {
            flag=1;
            printf("ɾ��ѧ���ɹ���%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            lh->next=lh->next->next;
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("ѧ��������\n\n");
}
