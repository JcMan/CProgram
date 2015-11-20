/*首届面      by  明明
学生的等级    by  狙击
学号排序      by  晨曦

以上内容有所修改

学生管理系统已经基本制作完成，
一共10的选项，9个功能选项，
参与的人数较少，群主时间有限，
若是有不足之处可以自己更正，
因为时间的问题，主要完成的是主要核心的内容，
没有增加一些对于非法输入的处理，
也就是程序的健壮性没有处理，
大家可以添加一些if之类的处理一下

剩余内容是屌丝群主所写
有错误和不足可以指出
这是第一次尝试，希望以后大家可以多多合作
（运行环境是vc6.0）
还有就是操作步骤的问题，比如你不操作0选项其他选项无用，
还有你不排序不能插入，还有些类似的问题需要注意*/


//今天改了点错误的逻辑，外加了一些功能,还没对非法输入









#include <time.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define N 200

struct Student
{
   float score;
   char name[20];
   int number;
   int grade;
};

int pass_w(char *pw,struct tm *ptrr);
void mima(char *p,int len,char *pp,int lenn);
void zhui_jia(struct Student *p);
void updata(struct Student *p);
void scort_t(struct Student *p,int b);
void insert(struct Student *p);
void dele(struct Student *p);
void scort(struct Student *p,int b);
void *_mallocaa(int lenn);
void deng_ji(struct Student *p,int b);
void init(struct Student *p,int b);
void show(struct Student *p,int b);
int i,count=0;

int main(void)

{



struct tm *ptr;


char passok[10]={"meiric"};
char password[10]={0};
int len,length;
struct Student *array;
int chio1,chio2;

time_t lt;
lt =time(NULL);
ptr=localtime(&lt);
//goto(1,70);




pa:
	//char passok[10]={"kushan"};
	//char password[10]={0};
	//char passok[10]={"kushan"};

    mima(passok,10,password,10);
	pass_w(password,ptr);
	if(strcmp(password,passok)!=0)
	goto pa;


//printf("\n\n\n\n");

   system("cls");
   do
   {
    printf("\t╔══════════════════════════════╗\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                欢迎登陆学生成绩管理系统                    ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║0.选择最大存储学生数字        1.学生成绩录入                ║\n");
    printf("\t║2.学生成绩显示                3.显示学生成绩等级            ║\n");
    printf("\t║4.学生信息排序                5.追加学生信息                ║\n");
    printf("\t║6.学生信息修改                7.删除学生信息                ║\n");
    printf("\t║8.按照学号插入                9.退出                        ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t║                                                            ║\n");
    printf("\t╚══════════════════════════════╝\n");
	printf("%d年:",ptr->tm_year+1900);
    printf("%d月:",ptr->tm_mon+1);
    printf("%d日:",ptr->tm_mday);
    printf("%d时:",ptr->tm_hour);
    printf("%d分:",ptr->tm_min);
    printf("%d秒",ptr->tm_sec);
    printf("\t请选择功能并输入对应数字：");
    scanf("%d",&chio1);
/*while(1)
{
    if(chio1!=0&&chio1!=1&&chio1!=2&&chio1!=3&&chio1!=4&&chio1!=5)
{
printf("数字输入错误，请重新输入数字：");
scanf("%d",&chio1);
}
}*/
switch(chio1)
{
   case 0:{
             printf("请输入学生的个数:\n");
             scanf("%d",&len);
             array=(struct Student*)_mallocaa(len);
		  }
     break;

case 1:{
           printf("请输入想初始化学生个数:\n");
           scanf("%d",&length);
           init(array,length);
	   }
    break;


case 2:show(array,length);break;
case 3:deng_ji(array,count);break;
case 4:{
             	printf("\n**********************************************\n");
    		    printf("\t1.按学号排序\n");
    		    printf("\t2.按分数排序");
    		    printf("\n**********************************************\n");
    	     	printf("\t\t\t请选择并输入对应数字：");
			    scanf("%d",&chio2);
			    switch(chio2)
				{
				    case 1 :scort(array,count);
					       break;

				    case 2 :scort_t(array,count);
					      break;

				}

	   }
	break;
case 5:zhui_jia(array);break;
case 6:updata(array);break;
case 7:dele(array);break;
case 8:insert(array);break;
case 9:
	free(array);
	return 0;


     /*case 1 :
     break;

     case 2 :
     break;

     case 3 :*/
}
   }while(1);

/*printf("请输入学生的个数:\n");
scanf("%d",&len);
array=(struct Student*)_mallocaa(len);*/

/*printf("请输入想初始化学生个数:\n");
scanf("%d",&length);
init(array,length);*/
//show(array,length);
return 0;
}
void* _mallocaa(int lenn)
{
     return (void*)malloc(sizeof(struct Student)*lenn);
}

void init(struct Student *p,int b)
{
    for(i=0;i<b;i++)
	{
// printf("请输入学生姓名\n");
// scanf("%s",&(p->name));
//printf("请输入学生分数\n");
// scanf("%f",&(p[i].score));
     printf("请输入学生姓名:");
     scanf("%s",&(p[i].name));
     printf("请输入学生学号:");
     scanf("%d",&(p[i].number));
     printf("请输入学生年级:");
     scanf("%d",&(p[i].grade));
     printf("请输入学生分数:");
     scanf("%f",&(p[i].score));
        printf("\n\n");
//p++;
     count++;
	}
   return;
}
void show(struct Student *p,int b)
{
for(i=0;i<b;i++)
{
printf("\n学生姓名%s:",p->name);
printf("\n学生年级%d:",p->grade);
printf("\n学生成绩%3.2f:",p->score);
printf("\n学生学号%d:",p->number);
p++;
}
printf("\n\n当前存有学生信息个数：%d\n",count);
return;
}
void deng_ji(struct Student *p,int b)
{
	int num,flag=1;
	printf("请输入想输出等级的学号：");
    scanf("%d",&num);
	for(i=0;i<b&&flag;i++)
	{
		if(p[i].number==num)
		{


            if(p[i].score>90 && p[i].score<=100)
               printf(" 学号为%d的学生成绩等级是 A\n",num);
           else if(p[i].score>80 && p[i].score<=90)
               printf("学号为%d的学生成绩等级是 B\n",num);
           else if(p[i].score>80 && p[i].score<=90)
                printf("学号为%d的学生成绩等级是 C\n",num);
           else if(p[i].score>70 && p[i].score<=80)
                printf("学号为%d的学生成绩等级是 D\n",num);
           else if(p[i].score>=60 && p[i].score<=70)
			    printf("学号为%d的学生成绩等级是 E\n",num);
           else
               printf("学生的成绩不在60至100范围内\n",num);
		   //flag=0;
		   break;
     }
		//p++;
      // return;
	}
return;
}
void scort(struct Student *p,int b)
{
   int j;

   struct Student temp;
   for(i=0;i<b-1;i++)
      for(j=0;j<b-1-i;j++)
         {
          if(p[j].number > p[j+1].number)
             {
              temp= p[j] ;
              p[j] = p[j+1];
              p[j+1]= temp ;
             }
         }
  printf("按照学号排序后：\n");
  for(i=0;i<b;i++)
  {
        printf("分数-->%3.2f",p[i].score);
        printf("姓名-->%s",p[i].name);
        printf("学号-->%d",p[i].number);
        printf("年级-->%d",p[i].grade);
		printf("\n\n");
  }

}
void dele(struct Student *p)
{
	int num,flag=1,j;
	printf("请输入想删除学生的学号：");
    scanf("%d",&num);
	for(i=0;i<count&&flag;i++)
	{
		if(p[i].number==num)
		{
			for(j=i;j<count;j++)
				p[j]=p[j+1];
				flag=0;
				count--;
				break;

		}
		//count--;


	}
	printf("删除后:\n\n");
	for(i=0;i<count;i++)
  {
        printf("分数-->%3.2f",p[i].score);
        printf("姓名-->%s",p[i].name);
        printf("学号-->%d",p[i].number);
        printf("年级-->%d",p[i].grade);
		printf("\n\n");
	}
	return;
}
void insert(struct Student *p)
{
	int num,flag=1,j;
	printf("请输入想插入学生的学号：");
    scanf("%d",&num);
	for(i=0;i<count&&flag;i++)
	{
		if(p[i].number>num)
		{
			for(j=count-1;j>=i;j--)
			{
				p[j+1]=p[j];
			}
			/*printf("请输入要插入学生姓名:");
            scanf("%s",&(p[i].name));
            printf("请输要插入入学生学号:");
            scanf("%d",&(p[i].number));
            printf("请输要插入入学生年级:");
            scanf("%d",&(p[i].grade));
            printf("请输要插入入学生分数:");
            scanf("%f",&(p[i].score));
            printf("\n\n");
			count++;
			flag=0;*/
			break;
		}
	}
	printf("请输入要插入学生姓名:");
    scanf("%s",&(p[i].name));
    printf("请输要插入入学生学号:");
    scanf("%d",&(p[i].number));
    printf("请输要插入入学生年级:");
    scanf("%d",&(p[i].grade));
    printf("请输要插入入学生分数:");
    scanf("%f",&(p[i].score));
    printf("\n\n");
    count++;

	for(i=0;i<count;i++)
	{
        printf("分数-->%3.2f",p[i].score);
        printf("姓名-->%s",p[i].name);
        printf("学号-->%d",p[i].number);
        printf("年级-->%d",p[i].grade);
		printf("\n\n");
	}
	return;
}
void scort_t(struct Student *p,int b)
{
   int j;

   struct Student temp;
   for(i=0;i<b-1;i++)
      for(j=0;j<b-1-i;j++)
         {
          if(p[j].score > p[j+1].score)
             {
              temp= p[j] ;
              p[j] = p[j+1];
              p[j+1]= temp ;
             }
         }
  printf("按照分数排序后：\n");
  	for(i=0;i<count;i++)
  {
        printf("分数-->%3.2f",p[i].score);
        printf("姓名-->%s",p[i].name);
        printf("学号-->%d",p[i].number);
        printf("年级-->%d",p[i].grade);
		printf("\n\n");


  }

}
void updata(struct Student *p)
{
	int num,flag=1;
	/*int e,g;
	float f;
	char c1[20];*/
	printf("请输入想修改学生的学号：");
    scanf("%d",&num);
	for(i=0;i<count&&flag;i++)
	{
		if(p[i].number==num)
		{
			printf("请输要修改学生学号:");
            scanf("%d",&(p[i].number));
		    printf("请输入要修改学生姓名:");
			scanf("%s",&(p[i]).name);
		    printf("请输要修改学生分数:");
			scanf("%f",&(p[i].score));
		    printf("请输要修改学生年级:");
			scanf("%d",&(p[i].grade));
			//flag=0;
			/*printf("请输要修改学生学号:");
            scanf("%d",&e);
		    printf("请输入要修改学生姓名:");
			scanf("%s",&c1);
		    printf("请输要修改学生分数:");
			scanf("%f",&f);
		    printf("请输要修改学生年级:");
			scanf("%d",&g);
			flag=0;*/
			break;
		}


}
	/*p[i].number=e;
    p[i].score=f;
    p[i].grade=g;
    strcpy(p[i].name,c1);*/
	printf("该学生信息修改后：\n");
	printf("分数-->%3.2f",p[i].score);
    printf("姓名-->%s",p[i].name);
    printf("学号-->%d",p[i].number);
    printf("年级-->%d",p[i].grade);
    printf("\n");
		return;
}
void zhui_jia(struct Student *p)
{
            printf("请输要追加学生学号:");
            scanf("%d",&(p[count].number));
		    printf("请输入要追加学生姓名:");
			scanf("%s",&(p[count]).name);
		    printf("请输要追加学生分数:");
			scanf("%f",&(p[count].score));
		    printf("请输要追加学生年级:");
			scanf("%d",&(p[count].grade));
			count++;
			printf("追加后:\n\n");
			for(i=0;i<count;i++)
			{
                   printf("分数-->%3.2f",p[i].score);
                   printf("姓名-->%s",p[i].name);
                   printf("学号-->%d",p[i].number);
                   printf("年级-->%d",p[i].grade);
	               printf("\n\n");
			}
				return ;
}
void mima(char *p,int len,char *pp,int lenn)
{
    strcpy(p,"meiric");
	strcpy(pp,"0");
}

int pass_w(char *pw,struct tm *ptrr)
  {

    int code=0;


    printf("\n%d年:",ptrr->tm_year+1900);
    printf("%d月:",ptrr->tm_mon+1);
    printf("%d日:",ptrr->tm_mday);
    printf("%d时:",ptrr->tm_hour);
    printf("%d分:",ptrr->tm_min);
    printf("%d秒",ptrr->tm_sec);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\nPlease Enter password:");
    while(1)
    {
    pw[code]=getch();
    if(pw[code]==13)
     break;
    else

    printf("*");
    code++;
   }
   pw[code]='\0';
return 0;
}
