#include<iomanip>
#include<cstdlib>//������stdlib.h 
#include<cstdio>//������stdio.h 
void Print_all(vector<student> &T)//�����ڴ�T�������׵�ַ(�����������������),����Ϊ 
{
	if(T.empty()){//��T����Ԫ�ظ���Ϊ0 
		cout<<"there is no students' information"<<endl;
		Sleep(1.1*sec);//window.h�е�ͣ�ٺ��� 
		Print(4,1,"returning");
		return;
	}
	cout<<"-----------------------------------"<<endl//<<endlΪ����ո�
		<<"| Please select the output format |"<<endl
		<<"-----------------------------------"<<endl
		<<"|        1---Simple mode          |"<<endl
		<<"|        2---Classic mode         |"<<endl
		<<"-----------------------------------"<<endl;
//����Ϊ���ֲ�ͬ�������ʽ 
here:
	cout<<"input number :";
	int E;
	cin>>E;
	if(E==1){
		printf("\tName\t  Snum       sex  year  month  day  CN\tMath  English  Science  PE\n");
		for(int i=0;i<T.size();i++){
			cout.width(13);////���ÿ��Ϊ13
			cout<<T[i].vi_na();////�������������˽�г�Աname�Ľӿں��� 
			cout.width(15);
			cout<<T[i].vi_snum();////�������������˽�г�Աsnum�Ľӿں��� 
			printf("  %c   %3d   %02d    %02d   ",T[i].sex,T[i].YR,T[i].M,T[i].D);//ͷ�ļ�cstdio 
			for(int j=0;j<5;j++){
				printf("%02d\t",T[i].score[j]);
			}
			cout<<endl;//����ո� 
		}
	}
	else if(E==2){
		for(int i=0;i<T.size();i++){
		cout<<i+1<<"th information :"<<endl
			<<"  Name :"<<T[i].vi_na()<<endl
			<<"  Sex  :"<<T[i].sex<<endl
			<<"  Snum :"<<T[i].vi_snum()<<endl;
		cout<<"  birth :";
		cout<<setfill('0')<<setw(2)<<T[i].YR<<" "
			<<T[i].M<<" "
			<<T[i].D<<" "<<endl;
			cout<<"  five score :"<<endl;
			cout<<"--------------------------------------------------"<<endl;
		for(int j=0;j<5;j++){//ö������CN,Math.... 
			switch(j){
				case CN:cout<<"| Chinese ";break;
				case Math:cout<<"|   Math  ";break;
				case Eng:cout<<"| English ";break;
				case Sci:cout<<"| Science ";break;
				case PE:cout<<"|    PE   ";break;
			}
			if(j==4) cout<<"|"<<endl;
		}
		cout<<"---------------------------------------------------"<<endl;
		for(int j=0;j<5;j++){
			printf("| %5d   ",T[i].score[j]);
			if(j==4) cout<<"|"<<endl;//����ո� 
		}
		cout<<"---------------------------------------------------";
		cout<<endl;
		}
	}
	else{
		cout<<"error,reenter"<<endl;
		Sleep(sec);
		goto here;
	}
	//cout<<"input Enter button to return.please";
	system("pause");//ϵͳ�⺯���еĺ��� 
}
