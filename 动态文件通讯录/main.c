#include"contact.h"
F* look(F*p,int n)
{
    char name[NAME];
    scanf("%s",name);
    while(n)
    {
        if(strcmp(name,p->name)==0)
           break;
        else
        {
            p=p->next;
        }
        n--;
    }
    if(n==0)
        {
        printf("不存在该联系人\n");
        return NULL;
        }
    else
        return p;
}
char*shi()
{
    char arr[10];
    printf("是否再次进行该操作（是/否）：");
    while(1)
    {
        scanf("%s",arr);
        if(strcmp(arr,"否")==0)
            return "否";
        else if(strcmp(arr,"是")==0)
            return "是";
        else
            printf("非法输入\n");
            return "0";
    }

}
void wn(F*now)
{
        printf("请输入姓名：");
        scanf("%s",now->name);
        printf("请输入年龄：");
        scanf("%s",now->age);
        printf("请输入性别：");
        scanf("%s",now->sex);
        printf("请输入电话：");
        scanf("%s",now->tele);
        printf("请输入地址：");
        scanf("%s",now->addr);
        now->next=NULL;
}
void del(F*p,int n)
{
    char arr[6];
    while(1)
    {
    printf("请输入要删除信息的人的姓名\n");
    p=look(p,n);
    if(p!=NULL)
    {
    printf("%-20s  %-5s  %-4s  %-12s  %-30s\n","姓名","性别","年龄","电话","地址");
    printf("请输入要删除的信息：");
    scanf("%s",arr);
    if(strcmp(arr,"姓名")==0)
    {
        strcpy(p->name," ");
        printf("删除成功\n");
    }
    else if(strcmp(arr,"性别")==0)
    {
        strcpy(p->sex," ");
        printf("删除成功\n");
    }
    else if(strcmp(arr,"年龄")==0)
    {
        strcpy(p->age," ");
        printf("删除成功\n");
    }
    else if(strcmp(arr,"电话")==0)
    {
        strcpy(p->tele," ");
        printf("删除成功\n");
    }
    else if(strcmp(arr,"地址")==0)
    {
        strcpy(p->addr," ");
        printf("删除成功\n");
    }
    else
    {
        printf("无效输入\n");
    }
    }
    if(strcmp(shi(),"否")==0)
        {
            sys();
            break;
        }
    }
}
void sys()
{
    Sleep(1000);
    system("cls");
    system("pause");
}
void change(F*p,int n)
{
    char arr[6];
    while(1)
    {
    printf("请输入要修改信息的人的姓名\n");
    p=look(p,n);
    if(p!=NULL)
    {
    printf("%-20s  %-5s  %-4s  %-12s  %-30s\n","姓名","性别","年龄","电话","地址");
    printf("请输入要修改的信息：");
    scanf("%s",arr);
    if(strcmp(arr,"姓名")==0)
    {
        printf("请输入修改后的姓名:");
        scanf("%s",p->name);
        printf("修改成功\n");
    }
    else if(strcmp(arr,"性别")==0)
    {
        printf("请输入修改后的性别：");
        scanf("%s",p->sex);
        printf("修改成功\n");
    }
    else if(strcmp(arr,"年龄")==0)
    {
        printf("请输入修改后的年龄：");
        scanf("%s",p->age);
        printf("修改成功\n");
    }
    else if(strcmp(arr,"电话")==0)
    {
        printf("请输入修改后的电话：");
        scanf("%s",p->tele);
        printf("修改成功\n");
    }
    else if(strcmp(arr,"地址")==0)
    {
        printf("请输入修改后的地址：");
        scanf("%s",p->addr);
        printf("修改成功\n");
    }
    else
    {
        printf("无效输入\n");
        while(getchar()!='\n')
        {
            ;
        }
    }
    }
    if(strcmp(shi(),"否")==0)
     {
         sys();
         break;
     }
    }
}
void show(F*p,int n)
{
    printf("%-20s  %-5s  %-4s  %-12s  %-30s\n","姓名","性别","年龄","电话","地址");
    while(n--)
    {
        printf("%-20s  %-5s  %-4s  %-12s  %-30s\n",p->name,p->sex,p->age,p->tele,p->addr);
        p=p->next;
    }
    system("pause");
    system("cls");
}
void search(F*p,int n)
{
    printf("请输入查询人的姓名：");
    p=look(p,n);
    if(p!=NULL)
    {
    printf("%-20s  %-5s  %-4s  %-12s  %-30s\n","姓名","性别","年龄","电话","地址");
    printf("%-20s  %-5s  %-4s  %-12s  %-30s\n",p->name,p->sex,p->age,p->tele,p->addr);
    system("pause");
    system("cls");
    }
    else
        sys();
}
void freeall(F*p)
{
    F*tmp;
    while(p->next!=NULL)
    {
        tmp=p->next;
        free(p);
        p=tmp;
    }
    free(p);
}
void add(F*p,int *n)
{
    if(*n==0)
    {
        wn(p);
        printf("添加成功\n");
        (*n)++;
        sys();
    }
    else
    {
        while(p->next!=NULL)
        p=p->next;
        p->next=(F*)malloc(sizeof(F));
        if(p->next==NULL)
        {
            printf("%s\n",strerror(errno));
            sys();
        }
        else
        {
            wn(p->next);
            printf("添加成功\n");
            (*n)++;
            sys();
        }
    }
}
void dell(F**p,int*n)
{
    F*tmp,*pl,*pp;
    pp=*p;
    printf("请输入要删除的联系人姓名\n");
    tmp=look(*p,*n);
    if(tmp!=NULL)
    {
        if(*p==tmp)
    {
        if(*n==1)
        {
            printf("删除成功\n");
            (*n)--;
        }
        else
        {
            tmp=(*p)->next;
            free(*p);
            *p=tmp;
            printf("删除成功\n");
            (*n)--;
        }
    }
    else
    {
        while(pp->next!=tmp)
        pp=pp->next;
        pl=tmp->next;
        free(tmp);
        pp->next=pl;
        printf("删除成功\n");
        (*n)--;
    }
    }
    sys();
}
void save(F*p)
{
    FILE* pf=fopen("通讯录.txt","w");
    if(pf==NULL)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        fprintf(pf,"%-20s  %-5s  %-4s  %-12s  %-30s\n","姓名","性别","年龄","电话","地址");
        while(p!=NULL)
        {
            fprintf(pf,"%-20s  %-5s  %-4s  %-12s  %-30s\n",p->name,p->sex,p->age,p->tele,p->addr);
            p=p->next;
        }
        fclose(pf);
        pf=NULL;
    }
}
