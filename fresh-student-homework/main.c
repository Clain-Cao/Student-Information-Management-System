/*C++中cin>>类似scanf,cout<<类似于printf，endl类似于回车换行*/ 
#include<iostream>//c++头文件  
#include<vector>
#include<string>
#include<windows.h>
#define sec 1000
enum{CN,Math,Eng,Sci,PE};//枚举类型 
#include"main.h"
#include"initialize_info.h"
#include"add_info.h"
#include"Print_all.h"
#include"modify_info.h" 
#include"search_info.h"
#include"delete_info.h"
#include"Na_Sort_Print.h"
#include"Sum_Sort_Print.h"
#include"save_eixt.h"
using namespace std;//相当于c++固定格式 
void main_page(vector<student> &T);
int main()
{
	vector<student> per;//兼有链表与数组的特性的容器； 
	cout<<"Welcome to the Student management system"<<endl;
	Sleep(2*sec);
	system("cls");
	main_page(per);
	cout<<"input number :";
	string filename;//string相当于动态字符串数组 
	long int N;
	cin>>N;
	do{
		switch(N){
			case 1:
				system("cls");
				filename=create_info(per);
				if(filename=="null") filename.clear();//清空filename里面内容 
				system("cls");
				break;
			case 2:system("cls");add_info(per,filename);system("cls");break;
			case 3:system("cls");Print_all(per);system("cls");break;
			case 4:system("cls");modify_info(per);system("cls");break;
			case 5:system("cls");search_info(per);system("cls");break;
			case 6:system("cls");delete_info(per);system("cls");break;
			case 7:system("cls");Na_Sort_Print(per);system("cls");break;
			case 8:system("cls");Sum_Sort_Print(per);system("cls");break; 
			case 9:system("cls");save_eixt(per,filename);system("cls");break;
			default :	cout<<"Error : Input is incorrect,please reenter"<<endl;
					 	Sleep(1.5*sec);
						cout<<"Returning to the main page"<<endl;
						Print(5);	
					 	system("cls");
		}
		Sleep(0.1*sec);//window.h头文件里面的停顿函数 
		main_page(per);
		cout<<"input number :";
	}while(cin>>N);
	return 0;
}
void main_page(vector<student> &T)//c++中带&为引用,相当于传入首地址 
{
	cout<<"========================================"<<endl
		<<"       Student management system        "<<endl
		<<"========================================"<<endl; 
	cout<<"  1---initialize_info  2---add_stu_info"<<endl
		<<"  3---Browse_info      4---modify_info"<<endl
		<<"  5---search_info      6---delete_info"<<endl
		<<"  7---Na_Sort_Print    8---Sum_Sort_Print"<<endl    
		<<"  9---save_and_exit    Student Total :"<<T.size()<<endl 
		<<"========================================"<<endl;
} 
