#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
int isPrime(int n);
void swap(int *a,int *b);   
void reverseStr(char *str);
void sort_count(int a[],int n,int max);
void Fibonacci(int n,int a[]);

int main(void)
{
    /*  
    字符串反转（hello world）
    char str[]="Hello World!";
    printf("原字符串为：%s\n",str);
    reverseStr(str);
    printf("反转后字符串为：%s\n",str);

    质数判断
    int Num;
    scanf("%d",&Num);
    if (isPrime(Num)==1)
        printf("Num是质数");
    else
        printf("Num不是质数");

    冒泡排序（随机成绩单）
    const int N=10;
    srand(time(NULL));
    int grade[N];
    for (int i = 0; i < N; i++)
    {
        grade[i]=rand()%101;
        printf("gride[%d]=%d\n",i,grade[i]);        
    }
    printf("\n\n");
    for (int i = 0; i < N-1; i++)
    {
        int flag=1;
        for (int j = 0; j < N-1-i; j++)
        {
            if (grade[j]>grade[j+1])
            {   
                swap(&grade[j],&grade[j+1]);
                flag=0;
            }      
        }
        if (flag==1)
            break;          
    }
    for (int i = 0; i < N; i++)
    {
        printf("grade=%d\n",grade[i]);
    }
    
    计数排序(随机成绩单) 
    const int N=10;
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
    #include <stdio.h>


    int n;
    scanf("%d",&n);
    for (int i=0; i<=n; i++) {
        if (i%4==0) {
            continue;
        }
        printf("%d\n",i);
    }


      
    system("pause");
    return 0;
}

void reverseStr(char *str)//颠倒字符串
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

int isPrime(int a)//质数判断
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

void sort_count(int a[],int size,int max)//计数排序(手动清零)：函数内定义的数组的长度必须为常量
{
    int temp_a[max+1],b=0;
    for (int i = 0; i < max+1; i++)//手动清零数组
        temp_a[i]=0;  
    for (int i = 0; i < size; i++)//计每个数出现的次数
        temp_a[a[i]]++;
    for (int i = 0; i < max+1; i++)//根据次数重新赋值
    {
        while(temp_a[i]>0)//重复的数赋多次
        {
            a[b]=i;
            b++;
            temp_a[i]--;
        }
    }    
}