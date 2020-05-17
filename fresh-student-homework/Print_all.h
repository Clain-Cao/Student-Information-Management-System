#include<iomanip>
#include<cstdlib>//兼容了stdlib.h 
#include<cstdio>//兼容了stdio.h 
void Print_all(vector<student> &T)//类似于传T容器的首地址(有数组与链表的特性),功能为 
{
	if(T.empty()){//若T容器元素个数为0 
		cout<<"there is no students' information"<<endl;
		Sleep(1.1*sec);//window.h中的停顿函数 
		Print(4,1,"returning");
		return;
	}
	cout<<"-----------------------------------"<<endl//<<endl为输出空格
		<<"| Please select the output format |"<<endl
		<<"-----------------------------------"<<endl
		<<"|        1---Simple mode          |"<<endl
		<<"|        2---Classic mode         |"<<endl
		<<"-----------------------------------"<<endl;
//以下为两种不同的输出方式 
here:
	cout<<"input number :";
	int E;
	cin>>E;
	if(E==1){
		printf("\tName\t  Snum       sex  year  month  day  CN\tMath  English  Science  PE\n");
		for(int i=0;i<T.size();i++){
			cout.width(13);////设置宽度为13
			cout<<T[i].vi_na();////调用类里面访问私有成员name的接口函数 
			cout.width(15);
			cout<<T[i].vi_snum();////调用类里面访问私有成员snum的接口函数 
			printf("  %c   %3d   %02d    %02d   ",T[i].sex,T[i].YR,T[i].M,T[i].D);//头文件cstdio 
			for(int j=0;j<5;j++){
				printf("%02d\t",T[i].score[j]);
			}
			cout<<endl;//输出空格 
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
		for(int j=0;j<5;j++){//枚举类型CN,Math.... 
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
			if(j==4) cout<<"|"<<endl;//输出空格 
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
	system("pause");//系统库函数中的函数 
}
