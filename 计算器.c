
#include<iostream>
#include<Windows.h>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
struct User
{
	char UserName[20];
	char PassWord[20];
};
class Student
{
public:
	char name[10];
	char specialty[20];
	char sex[10];
	int age;
	char number[20];
	int score;
	Student *next;
};
class List
{
public:
	Student *Head;
	int sum;
	List()
	{
		Head=NULL;
		sum=0;
	}
	~List()
	{
		if(sum>0)
		{
			Student *sDelete=Head;
			Student *sTmp=NULL;
			for(int i=0;i<sum;i++)
			{
				sTmp=sDelete->next;
				delete sDelete;
				sDelete=sTmp;
			}
			sum=0;
			sDelete=NULL;
			sTmp=NULL;
		}

	}
	Student* MoveTrail(List*li);
	void Stu_Start(List*li);
	void Stu_Login(List*li);
	void Stu_Register(List*li);
	void First_Menu(List*li);
	void Stu_Out(List*li);
	void OutOfNumber(List*li);
	void OutOfName(List*li);
	void OutAll(List*li);
	void Stu_Arrangement(List*li);
	void Stu_Polish(List*li);
	void Stu_Delete(List*li);
	void Stu_First_Add(List*li);
	void Stu_Add(Student*stu,List*li);

};
void List::Stu_Start(List*li)
	{
		SYSTEMTIME time;
		GetLocalTime(&time);
		printf("                 |===========================================|               \n");
		printf("                 |              %d-%d-%d %d:%d:%d            |              \n",time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond);
		printf("                 |                                           |               \n");
		printf("                 |                 1. ��½                   |               \n");
		printf("                 |                                           |               \n");
		printf("                 |                 2. ע��                   |               \n");
		printf("                 |                                           |               \n");
		printf("                 |                 3. �˳�                   |               \n");
		printf("                 |                                           |               \n");
		printf("                 |                                           |               \n");
		printf("                 |===========================================|               \n");
		printf("�����빦������:");
		int a;
		scanf("%d",&a);
		getchar();
		if(a==1) li->Stu_Login(li);
		if(a==2) li->Stu_Register(li);
		if(a==3) exit(0);
	}
Student* List::MoveTrail(List*li)
	{
		Student *sTmp=li->Head;
		for(int i=1;i<sum;i++)
			sTmp=sTmp->next;
		return sTmp;
	}
void List::Stu_Login(List*li)
{
	ifstream in("d:\\data.dat");
	if(!in)
	{
		cout<<"can not open!\n";
		return ;
	}
	struct User us;
	in.read((char*)&us,sizeof(User));
	char paa[20],naa[20];
	cout<<"�������û�����";
	cin>>naa;
	cout<<"���������룺";
	cin>>paa;
	if(strcmp(us.UserName,naa)==0&&strcmp(us.PassWord,paa)==0)
		{
			cout<<"                                  ��½�ɹ���"<<endl;
			li->First_Menu(li);
	    }
	else
		{
			cout<<"                              ��½ʧ�ܣ������µ�½������"<<endl;
			li->Stu_Start(li);
		}
	in.close();

}
void List::Stu_Register(List*li)
{
	ofstream out("d:\\data.dat");
	if(!out)
	{
		cout<<"can not open!\n";
		return ;
	}
	struct User us;
	cout<<"�������û�����";
	cin>>us.UserName;
	cout<<"���������룺";
	cin>>us.PassWord;
	//out.write(na,strlen(na));
	//out.write(pa,strlen(pa));
	out.write((char*)&us,sizeof(User));
	out.close();
    li->Stu_Start(li);

}
void List::First_Menu(List*li)
{
	cout<<"           =========================================================        "<<endl;
	cout<<"           |               ��ӭ��½ѧ����Ϣ����ϵͳ                |        "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           |     1.ѧ����Ϣ¼��             2.ѧ����Ϣ��ʾ         |        "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           |     3.ѧ���ɼ�����             4.ѧ����Ϣ�޸�         |         "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           |     5.ѧ����Ϣɾ��             0.�˳�����ϵͳ         |        "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           |                                                       |        "<<endl;
	cout<<"           =========================================================       "<<endl;
	int a;
	cout<<"�����빦�����֣�";
	cin>>a;
	switch(a)
	{
	case 1:li->Stu_First_Add(li);break;
	case 2:li->Stu_Out(li);break;
	case 3:li->Stu_Arrangement(li);break;
	case 4:li->Stu_Polish(li);break;
	case 5:li->Stu_Delete(li);break;
	case 0:exit(0);
	}
}
void List::Stu_Out(List*li)
{
	cout<<"                          1.����������ʾ\n"<<endl;
	cout<<"                          2.����ѧ����ʾ\n"<<endl;
	cout<<"                          3.ȫ����ʾ\n"<<endl;
	int b;
	cout<<"�����빦�����֣�";
	cin>>b;
	if(b==1) li->OutOfName(li);
	if(b==2) li->OutOfNumber(li);
	if(b==3) li->OutAll(li);
}
void List::OutOfName(List*li)
{
	cout<<"������������";
	char na[20];
	cin>>na;
	Student*sTmp=li->Head;
	for(int i=0;i<sum;i++)
	{
		if(strcmp(sTmp->name,na)==0)
		{
			cout<<"����       ѧ��           �Ա�     ����        רҵ      ����"<<endl;
			cout<<sTmp->name<<"     "<<sTmp->number<<"       ";
			cout<<sTmp->sex<<"       "<<sTmp->age<<"       "<<sTmp->specialty<<"      "<<sTmp->score<<endl;
		}
		sTmp=sTmp->next;
	}
	li->First_Menu(li);
}
void List::OutOfNumber(List*li)
{
	cout<<"������ѧ�ţ�";
	char nu[20];
	cin>>nu;
	Student*sTmp=li->Head;
	for(int i=0;i<sum;i++)
	{
		if(strcmp(sTmp->number,nu)==0)
		{
			cout<<"����       ѧ��           �Ա�     ����        רҵ      ����"<<endl;
			cout<<sTmp->name<<"     "<<sTmp->number<<"       ";
			cout<<sTmp->sex<<"       "<<sTmp->age<<"       "<<sTmp->specialty<<"      "<<sTmp->score<<endl;
		}
		sTmp=sTmp->next;
	}
	li->First_Menu(li);
}
void List::OutAll(List*li)
{
	if(sum==0)
	{
		cout<<"ϵͳ�����κ�ѧ����Ϣ��"<<endl;
		li->First_Menu(li);
	}
	else
	{
		cout<<"����       ѧ��           �Ա�     ����        רҵ      ����"<<endl;
		Student*sTmp=li->Head;
		for(int i=0;i<sum;i++)
		{
			//cout<<"����       ѧ��           �Ա�       ����        רҵ        ����"<<endl;
			cout<<sTmp->name<<"     "<<sTmp->number<<"       ";
			cout<<sTmp->sex<<"       "<<sTmp->age<<"       "<<sTmp->specialty<<"      "<<sTmp->score<<endl;
			sTmp=sTmp->next;
		}
		li->First_Menu(li);
	}

}
void List::Stu_Arrangement(List*li)
{
	Student*stu=Head,s[100],stemp;
	int i=0;
	for(;stu;stu=stu->next)
	{
		s[i++]=*stu;
	}
	int index;
	for(int k=0;k<i-1;k++)
	{
		index=k;
		for(int j=k+1;j<i;j++)
		{
			if(s[j].score>s[index].score)
				index=j;
		}
		if(index!=k)
		{
			stemp=s[k];
			s[k]=s[index];
			s[index]=stemp;
		}
	}
	cout<<"�Ƿ���ʾ������Ϣ(y/n)?";
	char pan;
	cin>>pan;
	if(pan=='y')
	{
		cout<<"����       ѧ��           �Ա�     ����        רҵ      ����"<<endl;
		for(int m=0;m<i;m++)
		{
			cout<<s[m].name<<"     "<<s[m].number<<"       ";
			cout<<s[m].sex<<"       "<<s[m].age<<"       "<<s[m].specialty<<"      "<<s[m].score<<endl;
		}
		li->First_Menu(li);
	}
	else
		li->First_Menu(li);
}
void List::Stu_Polish(List*li)
{
	do
	{
		Student *stu=li->Head;
		cout<<"                  1.��ѧ���޸�                  2.�������޸�"<<endl;
		cout<<"�����빦�����֣�";
		int a;
		cin>>a;
		if(a==1)
		{
			int sign=0;
			do
			{
				cout<<"������ѧ�ţ�";
				char num[20];
				cin>>num;
				for(;stu;)
				{
					if(strcmp(stu->number,num)==0)
						{
							sign=1;
							break;
						}
					else
						stu=stu->next;
				}
				if(sign==0)
				{
					cout<<"�������ѧ���������������룡\n";
					stu=li->Head;
				}
				else break;
			}while(sign==0);

			do
			{
				cout<<"      =============================================================== \n";
				cout<<"     |          1.����           2.ѧ��             3.�Ա�            | \n";
				cout<<"     |                                                                | \n";
				cout<<"     |          4.����           5.רҵ             6.����            | \n";
				cout<<"     ================================================================ \n";

				cout<<"�����������޸ĵ����ݣ�";
				int aa;
				cin>>aa;
				if(aa==1)
				{
					cout<<"�������µ�������";
					char na[20];
					cin>>na;
					strcpy(stu->name,na);
				}
				if(aa==2)
				{
					cout<<"�������µ�ѧ�ţ�";
					char nn[20];
					cin>>nn;
					strcpy(stu->number,nn);
				}
				if(aa==3)
				{
					cout<<"�������µ��Ա�";
					char se[10];
					cin>>se;
					strcpy(stu->sex,se);
				}
				if(aa==4)
				{
					cout<<"�������µ����䣺";
					int ag;
					cin>>ag;
					stu->age=ag;

				}
				if(aa==5)
				{
					cout<<"�������µ�רҵ��";
					char sp[20];
					cin>>sp;
					strcpy(stu->specialty,sp);
				}
				if(aa==6)
				{
					cout<<"�������µķ�����";
					int sc;
					cin>>sc;
					stu->score=sc;


				}
				cout<<"�Ƿ�����޸Ĵ�ѧ����Ϣ(y/n)?";
				char chh;
				cin>>chh;
				if(chh=='n')
					break;
			}while(1);


		}
		if(a==2)
		{
			int sign1=0;
			do
			{
				cout<<"������������";
				char num1[20];
				cin>>num1;
				for(;stu;)
				{
					if(strcmp(stu->name,num1)==0)
						{
							sign1=1;
							break;
						}
					else
						stu=stu->next;
				}
				if(sign1==0)
				{
					cout<<"�������ѧ���������������룡\n";
					stu=li->Head;
				}
				else break;
			}while(sign1==0);

			do
			{
				cout<<"      =============================================================== \n";
				cout<<"     |          1.����           2.ѧ��             3.�Ա�            | \n";
				cout<<"     |                                                                | \n";
				cout<<"     |          4.����           5.רҵ             6.����            | \n";
				cout<<"     ================================================================ \n";


				cout<<"�����������޸ĵ����ݣ�";
				int aa1;
				cin>>aa1;
				if(aa1==1)
				{
					cout<<"�������µ�������";
					char na1[20];
					cin>>na1;
					strcpy(stu->name,na1);
				}
				if(aa1==2)
				{
					cout<<"�������µ�ѧ�ţ�";
					char nn1[20];
					cin>>nn1;
					strcpy(stu->number,nn1);
				}
				if(aa1==3)
				{
					cout<<"�������µ��Ա�";
					char se1[10];
					cin>>se1;
					strcpy(stu->sex,se1);
				}
				if(aa1==4)
				{
					cout<<"�������µ����䣺";
					int ag1;
					cin>>ag1;
					stu->age=ag1;

				}
				if(aa1==5)
				{
					cout<<"�������µ�רҵ��";
					char sp1[20];
					cin>>sp1;
					strcpy(stu->specialty,sp1);
				}
				if(aa1==6)
				{
					cout<<"�������µķ�����";
					int sc1;
					cin>>sc1;
					stu->score=sc1;


				}
				cout<<"�Ƿ�����޸Ĵ�ѧ����Ϣ(y/n)?";
				char chh1;
				cin>>chh1;
				if(chh1=='n')
					break;
			}while(1);
		}
		cout<<"�Ƿ�����޸�����ѧ����Ϣ(y/n)?";
		char hc1;
		cin>>hc1;
		if(hc1=='n')
			break;
	}while(1);
		li->First_Menu(li);
}
void List::Stu_Delete(List*li)
{
	Student *stu=li->Head,*stmp=NULL;
	int sign=0,count=0;
	char pp;
	do
	{
		stu=li->Head;

		cout<<"          1.��ѧ��ɾ��     2.������ɾ��      3.ɾ��ȫ����Ϣ\n ";
		cout<<"�����빦�����֣�";
		int a;
		cin>>a;
		if(a==1)
		{
			do
			{
				count=0;
				stu=li->Head;
				cout<<"������ѧ�ţ�";
				char nu[20];
				cin>>nu;
				for(;stu;)
				{
					count++;
					if(strcmp(stu->number,nu)==0)
					{
						sign=1;
						break;
					}
					else
					{
						stmp=stu;
						stu=stu->next;
					}
				}
				if(sign==0)
					cout<<"�������ѧ���������������룡\n";
			}while(sign==0);
			if(count>1&&count<li->sum)
			{
				stmp->next=stu->next;
				li->sum--;
				delete stu;
			}
			if(count==1)
			{
				li->Head=stu->next;
				li->sum--;
				delete stu;
			}
			if(count==li->sum)
			{
				stmp->next=NULL;
				delete stu;
				li->sum--;
			}

		}
		if(a==2)
		{
			do
			{
				count=0;
				stu=li->Head;
				cout<<"������������";
				char na[20];
				cin>>na;
				for(;stu;)
				{
					count++;
					if(strcmp(stu->name,na)==0)
					{
						sign=1;
						break;
					}
					else
					{
						stmp=stu;
						stu=stu->next;
					}
				}
				if(sign==0)
					cout<<"������������������������룡\n";
			}while(sign==0);
			if(count>1&&count<li->sum)
			{
				stmp->next=stu->next;
				li->sum--;
				delete stu;
			}
			if(count==1)
			{
				li->Head=stu->next;
				li->sum--;
				delete stu;
			}
			if(count==li->sum)
			{
				stmp->next=NULL;
				delete stu;
				li->sum--;
			}
		}
		if(a==3)
		{
			li->~List();
			li->First_Menu(li);
		}
		cout<<"�Ƿ����ɾ��(y/n)?";
		cin>>pp;
	}while(pp=='y');
	li->First_Menu(li);

}
void List::Stu_First_Add(List*li)
{
	cout<<"������ѧ����Ϣ��������-ѧ��-�Ա�-����-רҵ-������\n";
	Student*stu=new Student;
	stu->next=NULL;
	cin>>stu->name>>stu->number>>stu->sex>>stu->age>>stu->specialty>>stu->score;
	li->Stu_Add(stu,li);
	do
	{
		cout<<"�Ƿ�������루y/n��?";
		char ch;
		getchar();
		cin>>ch;
		if(ch=='y')
			li->Stu_First_Add(li);
		else
			{
			    li->First_Menu(li);
			    break;
			}

	}while(1);

}
void List::Stu_Add(Student*stu,List*li)
{
	if(sum==0)
		li->Head=stu;
	else
	{
		Student*sTrail=MoveTrail(li);
		sTrail->next=stu;
	}
	sum++;
}
int main()
{
	List li;
	li.Stu_Start(&li);


	return 0;
}




