/*�׽���      by  ����
ѧ���ĵȼ�    by  �ѻ�
ѧ������      by  ����

�������������޸�

ѧ������ϵͳ�Ѿ�����������ɣ�
һ��10��ѡ�9������ѡ�
������������٣�Ⱥ��ʱ�����ޣ�
�����в���֮�������Լ�������
��Ϊʱ������⣬��Ҫ��ɵ�����Ҫ���ĵ����ݣ�
û������һЩ���ڷǷ�����Ĵ���
Ҳ���ǳ���Ľ�׳��û�д���
��ҿ������һЩif֮��Ĵ���һ��

ʣ�������ǌ�˿Ⱥ����д
�д���Ͳ������ָ��
���ǵ�һ�γ��ԣ�ϣ���Ժ��ҿ��Զ�����
�����л�����vc6.0��
���о��ǲ�����������⣬�����㲻����0ѡ������ѡ�����ã�
�����㲻�����ܲ��룬����Щ���Ƶ�������Ҫע��*/


//������˵������߼��������һЩ����,��û�ԷǷ�����









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
    printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                ��ӭ��½ѧ���ɼ�����ϵͳ                    �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U0.ѡ�����洢ѧ������        1.ѧ���ɼ�¼��                �U\n");
    printf("\t�U2.ѧ���ɼ���ʾ                3.��ʾѧ���ɼ��ȼ�            �U\n");
    printf("\t�U4.ѧ����Ϣ����                5.׷��ѧ����Ϣ                �U\n");
    printf("\t�U6.ѧ����Ϣ�޸�                7.ɾ��ѧ����Ϣ                �U\n");
    printf("\t�U8.����ѧ�Ų���                9.�˳�                        �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�U                                                            �U\n");
    printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("%d��:",ptr->tm_year+1900);
    printf("%d��:",ptr->tm_mon+1);
    printf("%d��:",ptr->tm_mday);
    printf("%dʱ:",ptr->tm_hour);
    printf("%d��:",ptr->tm_min);
    printf("%d��",ptr->tm_sec);
    printf("\t��ѡ���ܲ������Ӧ���֣�");
    scanf("%d",&chio1);
/*while(1)
{
    if(chio1!=0&&chio1!=1&&chio1!=2&&chio1!=3&&chio1!=4&&chio1!=5)
{
printf("������������������������֣�");
scanf("%d",&chio1);
}
}*/
switch(chio1)
{
   case 0:{
             printf("������ѧ���ĸ���:\n");
             scanf("%d",&len);
             array=(struct Student*)_mallocaa(len);
		  }
     break;

case 1:{
           printf("���������ʼ��ѧ������:\n");
           scanf("%d",&length);
           init(array,length);
	   }
    break;


case 2:show(array,length);break;
case 3:deng_ji(array,count);break;
case 4:{
             	printf("\n**********************************************\n");
    		    printf("\t1.��ѧ������\n");
    		    printf("\t2.����������");
    		    printf("\n**********************************************\n");
    	     	printf("\t\t\t��ѡ�������Ӧ���֣�");
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

/*printf("������ѧ���ĸ���:\n");
scanf("%d",&len);
array=(struct Student*)_mallocaa(len);*/

/*printf("���������ʼ��ѧ������:\n");
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
// printf("������ѧ������\n");
// scanf("%s",&(p->name));
//printf("������ѧ������\n");
// scanf("%f",&(p[i].score));
     printf("������ѧ������:");
     scanf("%s",&(p[i].name));
     printf("������ѧ��ѧ��:");
     scanf("%d",&(p[i].number));
     printf("������ѧ���꼶:");
     scanf("%d",&(p[i].grade));
     printf("������ѧ������:");
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
printf("\nѧ������%s:",p->name);
printf("\nѧ���꼶%d:",p->grade);
printf("\nѧ���ɼ�%3.2f:",p->score);
printf("\nѧ��ѧ��%d:",p->number);
p++;
}
printf("\n\n��ǰ����ѧ����Ϣ������%d\n",count);
return;
}
void deng_ji(struct Student *p,int b)
{
	int num,flag=1;
	printf("������������ȼ���ѧ�ţ�");
    scanf("%d",&num);
	for(i=0;i<b&&flag;i++)
	{
		if(p[i].number==num)
		{


            if(p[i].score>90 && p[i].score<=100)
               printf(" ѧ��Ϊ%d��ѧ���ɼ��ȼ��� A\n",num);
           else if(p[i].score>80 && p[i].score<=90)
               printf("ѧ��Ϊ%d��ѧ���ɼ��ȼ��� B\n",num);
           else if(p[i].score>80 && p[i].score<=90)
                printf("ѧ��Ϊ%d��ѧ���ɼ��ȼ��� C\n",num);
           else if(p[i].score>70 && p[i].score<=80)
                printf("ѧ��Ϊ%d��ѧ���ɼ��ȼ��� D\n",num);
           else if(p[i].score>=60 && p[i].score<=70)
			    printf("ѧ��Ϊ%d��ѧ���ɼ��ȼ��� E\n",num);
           else
               printf("ѧ���ĳɼ�����60��100��Χ��\n",num);
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
  printf("����ѧ�������\n");
  for(i=0;i<b;i++)
  {
        printf("����-->%3.2f",p[i].score);
        printf("����-->%s",p[i].name);
        printf("ѧ��-->%d",p[i].number);
        printf("�꼶-->%d",p[i].grade);
		printf("\n\n");
  }

}
void dele(struct Student *p)
{
	int num,flag=1,j;
	printf("��������ɾ��ѧ����ѧ�ţ�");
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
	printf("ɾ����:\n\n");
	for(i=0;i<count;i++)
  {
        printf("����-->%3.2f",p[i].score);
        printf("����-->%s",p[i].name);
        printf("ѧ��-->%d",p[i].number);
        printf("�꼶-->%d",p[i].grade);
		printf("\n\n");
	}
	return;
}
void insert(struct Student *p)
{
	int num,flag=1,j;
	printf("�����������ѧ����ѧ�ţ�");
    scanf("%d",&num);
	for(i=0;i<count&&flag;i++)
	{
		if(p[i].number>num)
		{
			for(j=count-1;j>=i;j--)
			{
				p[j+1]=p[j];
			}
			/*printf("������Ҫ����ѧ������:");
            scanf("%s",&(p[i].name));
            printf("����Ҫ������ѧ��ѧ��:");
            scanf("%d",&(p[i].number));
            printf("����Ҫ������ѧ���꼶:");
            scanf("%d",&(p[i].grade));
            printf("����Ҫ������ѧ������:");
            scanf("%f",&(p[i].score));
            printf("\n\n");
			count++;
			flag=0;*/
			break;
		}
	}
	printf("������Ҫ����ѧ������:");
    scanf("%s",&(p[i].name));
    printf("����Ҫ������ѧ��ѧ��:");
    scanf("%d",&(p[i].number));
    printf("����Ҫ������ѧ���꼶:");
    scanf("%d",&(p[i].grade));
    printf("����Ҫ������ѧ������:");
    scanf("%f",&(p[i].score));
    printf("\n\n");
    count++;

	for(i=0;i<count;i++)
	{
        printf("����-->%3.2f",p[i].score);
        printf("����-->%s",p[i].name);
        printf("ѧ��-->%d",p[i].number);
        printf("�꼶-->%d",p[i].grade);
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
  printf("���շ��������\n");
  	for(i=0;i<count;i++)
  {
        printf("����-->%3.2f",p[i].score);
        printf("����-->%s",p[i].name);
        printf("ѧ��-->%d",p[i].number);
        printf("�꼶-->%d",p[i].grade);
		printf("\n\n");


  }

}
void updata(struct Student *p)
{
	int num,flag=1;
	/*int e,g;
	float f;
	char c1[20];*/
	printf("���������޸�ѧ����ѧ�ţ�");
    scanf("%d",&num);
	for(i=0;i<count&&flag;i++)
	{
		if(p[i].number==num)
		{
			printf("����Ҫ�޸�ѧ��ѧ��:");
            scanf("%d",&(p[i].number));
		    printf("������Ҫ�޸�ѧ������:");
			scanf("%s",&(p[i]).name);
		    printf("����Ҫ�޸�ѧ������:");
			scanf("%f",&(p[i].score));
		    printf("����Ҫ�޸�ѧ���꼶:");
			scanf("%d",&(p[i].grade));
			//flag=0;
			/*printf("����Ҫ�޸�ѧ��ѧ��:");
            scanf("%d",&e);
		    printf("������Ҫ�޸�ѧ������:");
			scanf("%s",&c1);
		    printf("����Ҫ�޸�ѧ������:");
			scanf("%f",&f);
		    printf("����Ҫ�޸�ѧ���꼶:");
			scanf("%d",&g);
			flag=0;*/
			break;
		}


}
	/*p[i].number=e;
    p[i].score=f;
    p[i].grade=g;
    strcpy(p[i].name,c1);*/
	printf("��ѧ����Ϣ�޸ĺ�\n");
	printf("����-->%3.2f",p[i].score);
    printf("����-->%s",p[i].name);
    printf("ѧ��-->%d",p[i].number);
    printf("�꼶-->%d",p[i].grade);
    printf("\n");
		return;
}
void zhui_jia(struct Student *p)
{
            printf("����Ҫ׷��ѧ��ѧ��:");
            scanf("%d",&(p[count].number));
		    printf("������Ҫ׷��ѧ������:");
			scanf("%s",&(p[count]).name);
		    printf("����Ҫ׷��ѧ������:");
			scanf("%f",&(p[count].score));
		    printf("����Ҫ׷��ѧ���꼶:");
			scanf("%d",&(p[count].grade));
			count++;
			printf("׷�Ӻ�:\n\n");
			for(i=0;i<count;i++)
			{
                   printf("����-->%3.2f",p[i].score);
                   printf("����-->%s",p[i].name);
                   printf("ѧ��-->%d",p[i].number);
                   printf("�꼶-->%d",p[i].grade);
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


    printf("\n%d��:",ptrr->tm_year+1900);
    printf("%d��:",ptrr->tm_mon+1);
    printf("%d��:",ptrr->tm_mday);
    printf("%dʱ:",ptrr->tm_hour);
    printf("%d��:",ptrr->tm_min);
    printf("%d��",ptrr->tm_sec);
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
