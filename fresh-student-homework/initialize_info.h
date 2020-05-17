#include<fstream>
#include<cstdio>
using namespace std;
string create_info(vector<student> &per)//��������Ϊstring(��̬�ַ�������)���� 
{
	system("cls");
	if(!per.empty()){//���per���,��per����Ԫ�ظ���Ϊ0,��ִ��if��������(Ԫ�ظ�����ָѧ����) 
		cout<<"Error : The data has already existed.no need to create"<<endl;
		Sleep(1.1*sec);//window.h�е�ͣ�ٺ��� 
		Print(4,1,"returning");
		string filename;
		filename="null";
		return filename;//����filename������ 
	}
	cout<<"*************create_info*************"<<endl;
	cout<<"--------------------------------------"<<endl;
    cout<<"|   1---Input data from the keyboard  |"<<endl;
    cout<<"|   2---Read data from a file         |"<<endl;
	cout<<"--------------------------------------"<<endl;
	int N;
	cout<<"input number in front of the operation :";
	cin>>N;//������scanf 
	string filename;//����string���� 
	if(N==1){//�ֶ��������� 
		filename="stu_info.txt";//�ı��ļ����� 
		fstream infile(filename.c_str(),ios::out);//��filename�ļ����,��д�ķ�ʽ��filename�ļ� 
		if(!infile){
			cerr<<"Error : the file has been created to record the data"<<endl;//cerr������Ļ���������Ϣ; 
		}//���û���ҵ�,�򱨴����½�һ����Ϊfilename���ı��ļ�,������¼��Ϣ 
		int cnt;
		cout<<"input number of student :";
		cin>>cnt;
		for(int i=0;i<cnt;i++){
			getchar();
			cout<<i+1<<" student :"<<endl;
			student stu;//������һ��student���stu����,���ƶ���ṹ�� 
			string Name;
			cout<<"input stu name.After confirmation,It'll not be changed(eg.Xiao Ming) :";
			getline(cin,Name,'\n');//������gets,���س��������� 
			cout<<"input sex(B or G) :"; 
			cin>>stu.sex;
			string Snum;
			int Score[5];
			cout<<"input 5 scores"<<endl;
			for(int i=0;i<5;i++){
				cin>>stu.score[i];
			}
			cout<<"input snum(After confirmation,It'll not be changed) :";
			cin>>Snum;
			stu.SetBa(Name,Snum);//�����������Զ���ĳ�ʼ������ 
			cout<<"Input date of birth(eg.2018 01 02) :";
			cin>>stu.YR>>stu.M>>stu.D;//�Ӽ���������,��,�� 
			infile<<stu.vi_na()<<endl<<stu.sex<<" "<<stu.vi_snum()<<" ";//��filename�ļ���������Ϣ�Ϳո�,�����infile������fprintf 
			infile<<stu.YR<<" "<<stu.M<<" "<<stu.D<<" ";//infile������fprintf
			for(int i=0;i<5;i++){
				infile<<stu.score[i];
				if(i!=4) infile<<" ";//infile������fprintf
			}
			per.push_back(stu);//��per�����а��Ⱥ�˳�����һ��student����(�����ڷ�һ���ṹ��)
			Name.clear();//���Name�����Ԫ��
		}
		infile.close();//�ر�filename�ļ�;
	}
	else if(N==2){//���ļ��������� 
		cout<<"input file name :";
		cin>>filename;//�����ļ������ļ����ڵļ�����еĵ�ַ,�������ַĬ��ΪͬһĿ¼�� 
		fstream outfile(filename.c_str(),ios::in);//�ö��ķ�ʽ���ļ�
		if(!outfile){//���Ҳ����ļ�,�򷵻���ҳ�沢����һ���ַ���; 
			cerr<<"Error : Not Found,input number in front of the operation"<<endl;
			Sleep(1.5*sec);
			cout<<"Returning to the main page"<<endl;
			Print(5);
			return "null";
		}
		while(outfile.tellg()!=EOF){//��ָ��û�е��ļ�ĩβʱ,ִ��ѭ�� 
			student stu;//����student�� 
			string Na;char sex;
			string snum;//��̬�ַ����� 
			int score[5];
			getline(outfile,Na,'\n');//���ļ��ж�ȡ�ַ�����Na�� 
			outfile>>stu.sex>>snum;//���ļ��ж�ȡ������,������fscanf 
			outfile>>stu.YR>>stu.M>>stu.D;//���ļ��ж�ȡ������,������fscanf 
			stu.SetBa(Na,snum);//���ó�ʼ����������ʼ��stu���������name��snum 
			for(int i=0;i<5;i++){
				outfile>>stu.score[i];//����5���ɼ�,������fscanf 
			}
			per.push_back(stu);//��ɴ��ļ���һ��ѧ����Ϣ�Ķ���,�������ѧ����Ϣ����per�������� 
		}
		outfile.close();//�ر��ļ� 
	}
	Print(7,1);
	cout<<"Initialization success"<<endl;//�����ʼ���ɹ� 
	Sleep(sec);//ͣ�ٺ��� 
	return filename;//�����ļ��� 
}
