#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
int is_prime(int n);
void swap(int *a,int *b);   
void reverse_str(char *str);
void sort_bubble(int a[],int N);
void sort_count(int a[],int n,int max);
void Fibonacci(int n,int a[]);
struct Node* create_node(int data);
void insert_head(struct Node **head, int data);
void print_node(struct Node *head);
void free_node(struct Node *head);
int delete_head(struct Node **head);
void insert_end(struct Node **head, int data);
void reverse_node(struct Node **head);
void delete_value(struct Node **head, int value);

struct Node//全局结构体：函数内不能用局部结构体
{
    int data;
    struct Node *next;
};

int main(void)//主函数：测试各个函数
{
    /*  
    char str[]="Hello World!";//字符串反转（hello world）
    printf("原字符串为：%s\n",str);
    reverse_str(str);
    printf("反转后字符串为：%s\n",str);

    int Num;//质数判断
    scanf("%d",&Num);
    if (is_prime(Num)==1)
        printf("Num是质数");
    else
        printf("Num不是质数");

    const int N=10;//冒泡排序（随机成绩单）
    srand(time(NULL));
    int grade[N];
    for (int i = 0; i < N; i++)
    {
        grade[i]=rand()%101;
        printf("gride[%d]=%d\n",i,grade[i]);        
    }
    printf("\n\n");
    sort_bubble(grade,N);
    for (int i = 0; i < N; i++)
    {
        printf("grade=%d\n",grade[i]);
    }
       
    const int N=10;//计数排序(随机成绩单) 
    srand(time(NULL));
    int grade[N];
    for (int i = 0; i < N; i++)
    {
        grade[i]=rand()%101;
        printf("gride[%d]=%d\n",i,grade[i]);        
    }
    sort_count(grade,N,101);
    printf("\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("grade[%d]=%d\n",i,grade[i]);
    }
*/  



    system("pause");
    return 0;
}

void reverse_str(char *str)//颠倒字符串
{
    char *a,*b,temp;
    a=&str[0];
    b=&str[0];
    //a、b都从头开始
    while (*b!='\0')//找到字符串结尾/0
        b++;
    b--;//b指向最后一个字符(/0只占一个位置)
    while (a < b)//只有当a在b左侧时交换
    {
        temp=*a;
        *a=*b;
        *b=temp;
        a++;//a右移
        b--;//b左移
    }       
}

void Fibonacci(int n,int a[])//斐波那契数列 
{
    if (n<4)
    {
        printf("输入错误");
        return;
    }    
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for (int i=3;i<n; i++) {
        a[i]=a[i-1]+a[i-2];
    }
}

int is_prime(int a)//质数判断
{
    if (a<=1)//>=2的数才有可能是质数
    {
        printf("输入错误");
        return 0;
    }   
    for (int i = 2; i <= sqrt(a); i++)
    {  
        if (a%i==0)
        {
            return 0;
        }            
    }
    return 1;
}

void swap(int *a,int *b)//交换两个数
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort_bubble(int a[],int N)//冒泡排序
{
    for (int i = 0; i < N-1; i++)//外层n-1次
    {
        int flag=0;//交换标志位
        for (int j = 0; j < N-1-i; j++)//内层n-1-i次：外层每完成一次，就有一个数被排好序
        {
            if (a[j]>a[j+1])
            {   
                swap(&a[j],&a[j+1]);
                flag=1;//有交换发生
            }    
        }
        if (flag==0)//内层无交换，说明排序已完成
            break;     
    }
}

void sort_count(int a[],int size,int max)//计数排序：函数内定义的数组的长度必须为常量,用堆解决
{
    int *temp;//定义一个指针，指向堆上的数组
    temp=calloc((max+1),sizeof(int));//给指针分配内存，数组长度为max+1，元素类型为int
    if (temp==NULL) 
    {
        printf("Error");
        return;
    }
    for (int i = 0; i < size; i++)//计每个数出现的次数
        temp[a[i]]++;
    int n=0;//a数组的下标
    for (int i = 0; i < max+1; i++)//根据次数重新赋值
    {
        while(temp[i]>0)//重复的数赋多次
        {
            a[n]=i;
            n++;
            temp[i]--;
        }
    }
    free(temp);//释放堆内存    
}

struct Node* create_node(int data)//新建链表节点：返回一个一级指针，指向堆上的结构体
{
    struct Node *newNode;//定义一个结构体类型的指针，指针里是新节点地址
    newNode=(struct Node*)malloc(sizeof(struct Node));//给指针分配内存
    if (newNode==NULL)
    {
        printf("Error");
        return NULL;
    }   
    newNode->data=data;//用指针指向data，给节点赋值
    newNode->next=NULL;//用指针指向next（下个节点的地址），下个节点地址为NULL
    return newNode;
}

void insert_head(struct Node **head, int data)//在原先的链表的头插入新节点：要修改一级指针myList的值(堆上结构体的地址)，用二级指针
{
    struct Node *newNode=create_node(data);//新建节点
    newNode->next=*head;//把原有节点接到新节点后面
    *head=newNode; //把新节点变成头节点
}

void print_node(struct Node *head)//打印链表：用一级指针访问结构体data
{
    int i=0;//计数：第i个节点
    struct Node *temp;//临时指针：不修改head
    temp=head;
    while (temp!=NULL)//没到结尾就继续
    {
        printf("链表第%d个data为%d\n",i,temp->data);
        temp=temp->next;//下一个节点
        i++;//计数+1
    } 
}

void free_node(struct Node *head)//释放链表：要释放一级指针myList，传入一级指针
{
    struct Node *now,*next;//定义现在要释放的和下一个要释放的
    now=head;
    while (now!=NULL)
    {
        next=now->next;//释放现在的前，先找到下一个的地址
        free(now);
        now=next;//准备释放下一个
    }
}

int delete_head(struct Node **head)//删除头节点：要修改一级指针myList的值(堆上结构体的地址)，用二级指针
{
    if (*head==NULL)//如果链表是空的，不继续
    {
        printf("Error");
        return 0;
    }
    struct Node *temp;//临时一级指针
    int data;//临时存data
    temp=*head;//临时一级指针存储要删除的节点
    data=temp->data;//保存要删除节点的data
    *head=temp->next;//修改删除后的第一个节点为头
    free(temp);//释放要删除的节点
    return data;
}

void insert_end(struct Node **head, int data)//在原先的链表的结尾插入新节点：如果链表为空，就要修改一级指针myList的值(堆上结构体的地址)，用二级指针；如果链表不为空，只需要用一级指针访问成员next
{
    struct Node *newNode=create_node(data);//新节点
    struct Node *temp;//临时一级指针
    temp=*head;
    if (temp==NULL)//如果链表为空
    {
        *head=newNode;//相当于插入到链表的头
        return;
    }
    while (temp->next!=NULL)//如果链表不为空，找到最后一个节点
    {
        temp=temp->next;
    }
    temp->next=newNode;//把新节点接到最后一个节点后面
}

void reverse_node(struct Node **head)//反转链表：要修改一级指针myList的值(堆上结构体的地址)，用二级指针
{
    struct Node *before,*now,*then;
    before=NULL;
    now=*head;
    while (now!=NULL)
    {
        then=now->next;//先保存下个节点地址
        now->next=before;//修改当前节点的next指向前一个节点
        before=now;//后移
        now=then;//后移
    }
    *head=before;//修改头节点
    /*先保存下个节点地址，再修改当前节点的next指向前一个节点，最后后移；
    如果先保存下个节点地址，再修改修改当前节点next指向后一个节点地址，最后后移
    则最后一步then=NULL，无法再保存下一个节点*/
}

void delete_value(struct Node **head, int value)
{
    if (*head==NULL)
    {
        return;
    }
    struct Node *now,*then;
    now=*head;
    then=now->next;
    while (now->data==value)
    {
        delete_head(head);
        if (*head==NULL)
        {
            return;
        }
        now=*head;
        then=now->next;
    }
    while (then!=NULL)
    {
        if (then->data==value)
        {
            now->next=then->next;
            free(then);
            then=now->next;
        }
        else
        {
            now=now->next;
            then=then->next;
        }
    }
}