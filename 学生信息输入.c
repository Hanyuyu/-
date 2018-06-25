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
        printf("*1、添加学生信息            * \n");
        printf("*2、修改学生信息            * \n");
        printf("*3、删除学生信息            * \n");
        printf("*4、根据学生姓名信息        * \n");
        printf("*5、根据学号查询信息        * \n");
        printf("*6、统计全部学生信息        * \n");
        printf("*7、退出                    * \n");
		printf("*****************************\n");

        printf("请选择：");
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
            printf("输入有误，请重新选择\n");
    }
}
void insert(user *h)
{
    user *p=(user *)malloc(sizeof(user));
    p->next=h->next;
    h->next=p;
    printf("请输入学生学号：");
    scanf("%d",&p->num);
    printf("请输入学生姓名：");
    scanf("%s",p->name);
    printf("请输入学生年龄：");
    scanf("%d",&p->age);
    printf("请输入学生性别：");
    scanf("%x",&p->sex);

    printf("请输入学生专业：");
    scanf("%s",p->subject );
    printf("请输入学生班级：");
    scanf("%d",&p->classroom );
    printf("学生信息添加成功：%d %s %d %x %s %d\n",p->num,p->name,p->age,p->sex, p->subject,p->classroom);
}
void edit(user *h)
{
    int num;
    int flag=0;
    user *lh=h->next;
    printf("输入要修改学生的学号：");
    scanf("%d",&num);
    while(lh)
    {
        if(num == lh->num)
        {
            flag=1;
            printf("请输入学生学号：");
            scanf("%d",&lh->num);
            printf("请输入学生姓名：");
            scanf("%s",lh->name);
            printf("请输入学生年龄：");
            scanf("%d",&lh->age);
            printf("请输入学生性别：");
            scanf("%x",&lh->sex);
            printf("请输入学生专业：");
            scanf("%s",lh->subject );
            printf("请输入学生班级：");
            scanf("%d",&lh->classroom );
            printf("学生信息添加成功：%d %s %d %x %s %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("查不到该学生\n\n");
}
void S_byName(user *h)
{
    char name[30];
    int flag=0;
    user *lh=h->next;
    printf("输入要查找的学生姓名：");
    scanf("%s",name);
    while(lh)
    {
        if(strcmp(name,lh->name)==0)
        {
            flag=1;
            printf("学生信息为：%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject, lh->classroom);
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("学生不存在\n\n");
}
void S_byNum(user *h)
{
    int num;
    int flag=0;
    user *lh=h->next;
    printf("输入要查找的学号：");
    scanf("%d",&num);
    while(lh)
    {
        if(num == lh->num)
        {
            flag=1;
             printf("学生信息:%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("找不到匹配的学生\n\n");
}
void display(user *h)
{
    user *lh=h->next;
    int i=1;
    while(lh)
    {
        printf("第%d条用户信息:%d %s %d %x %s   %d\n",i,lh->num,lh->name,lh->age,lh->sex, lh->subject ,lh->classroom );
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
    printf("输入要删除的学生学号：");
    scanf("%d",&num);
    while(lh->next)
    {
        if(num == lh->next->num)
        {
            flag=1;
            printf("删除学生成功：%d %s %d %x %s   %d\n",lh->num,lh->name,lh->age,lh->sex, lh->subject , lh->classroom );
            lh->next=lh->next->next;
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("学生不存在\n\n");
}
