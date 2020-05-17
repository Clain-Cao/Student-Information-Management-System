#include<fstream>
#include<cstdio>
using namespace std;
string create_info(vector<student> &per)//返回类型为string(动态字符串数组)类型 
{
	system("cls");
	if(!per.empty()){//如果per表空,即per里面元素个数为0,则执行if里面内容(元素个数是指学生数) 
		cout<<"Error : The data has already existed.no need to create"<<endl;
		Sleep(1.1*sec);//window.h中的停顿函数 
		Print(4,1,"returning");
		string filename;
		filename="null";
		return filename;//返回filename的内容 
	}
	cout<<"*************create_info*************"<<endl;
	cout<<"--------------------------------------"<<endl;
    cout<<"|   1---Input data from the keyboard  |"<<endl;
    cout<<"|   2---Read data from a file         |"<<endl;
	cout<<"--------------------------------------"<<endl;
	int N;
	cout<<"input number in front of the operation :";
	cin>>N;//类似于scanf 
	string filename;//定义string类型 
	if(N==1){//手动输入数据 
		filename="stu_info.txt";//文本文件名字 
		fstream infile(filename.c_str(),ios::out);//将filename文件清空,用写的方式打开filename文件 
		if(!infile){
			cerr<<"Error : the file has been created to record the data"<<endl;//cerr是向屏幕输出错误信息; 
		}//如果没有找到,则报错并且新建一个名为filename的文本文件,用来记录信息 
		int cnt;
		cout<<"input number of student :";
		cin>>cnt;
		for(int i=0;i<cnt;i++){
			getchar();
			cout<<i+1<<" student :"<<endl;
			student stu;//定义了一个student类的stu对象,类似定义结构体 
			string Name;
			cout<<"input stu name.After confirmation,It'll not be changed(eg.Xiao Ming) :";
			getline(cin,Name,'\n');//类似于gets,按回车结束输入 
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
			stu.SetBa(Name,Snum);//调用类里面自定义的初始化函数 
			cout<<"Input date of birth(eg.2018 01 02) :";
			cin>>stu.YR>>stu.M>>stu.D;//从键盘输入年,月,日 
			infile<<stu.vi_na()<<endl<<stu.sex<<" "<<stu.vi_snum()<<" ";//向filename文件中输入信息和空格,这里的infile类似于fprintf 
			infile<<stu.YR<<" "<<stu.M<<" "<<stu.D<<" ";//infile类似于fprintf
			for(int i=0;i<5;i++){
				infile<<stu.score[i];
				if(i!=4) infile<<" ";//infile类似于fprintf
			}
			per.push_back(stu);//向per容器中按先后顺序放入一个student类型(类似于放一个结构体)
			Name.clear();//清空Name里面的元素
		}
		infile.close();//关闭filename文件;
	}
	else if(N==2){//从文件读入数据 
		cout<<"input file name :";
		cin>>filename;//输入文件名及文件所在的计算机中的地址,不输入地址默认为同一目录下 
		fstream outfile(filename.c_str(),ios::in);//用读的方式打开文件
		if(!outfile){//若找不到文件,则返回主页面并返回一个字符串; 
			cerr<<"Error : Not Found,input number in front of the operation"<<endl;
			Sleep(1.5*sec);
			cout<<"Returning to the main page"<<endl;
			Print(5);
			return "null";
		}
		while(outfile.tellg()!=EOF){//读指针没有到文件末尾时,执行循环 
			student stu;//定义student类 
			string Na;char sex;
			string snum;//动态字符数组 
			int score[5];
			getline(outfile,Na,'\n');//从文件中读取字符串到Na中 
			outfile>>stu.sex>>snum;//从文件中读取数据中,类似于fscanf 
			outfile>>stu.YR>>stu.M>>stu.D;//从文件中读取数据中,类似于fscanf 
			stu.SetBa(Na,snum);//调用初始化函数来初始化stu对象里面的name和snum 
			for(int i=0;i<5;i++){
				outfile>>stu.score[i];//读入5个成绩,类似于fscanf 
			}
			per.push_back(stu);//完成从文件中一个学生信息的读入,并将这个学生信息放入per容器里面 
		}
		outfile.close();//关闭文件 
	}
	Print(7,1);
	cout<<"Initialization success"<<endl;//输出初始化成功 
	Sleep(sec);//停顿函数 
	return filename;//返回文件名 
}
