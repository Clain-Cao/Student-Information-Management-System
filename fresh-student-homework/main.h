#include<windows.h>
using namespace std;//可以理解为固定格式 
string	vi_na();//函数声明； 
int snum();//函数声明； 
class student{//一个类,类似于结构体但于结构体不同 
	protected://保护性成员,只允许被类里面函数或带有friend的函数访问 
		int sum;
	private://私有成员只允许被类里面的函数或者带有friend函数访问 
		string name;
		string snum;
	public://公有成员,相当于struct里面的变量,public中变量能被外部函数修改,外部函数即非类里面的函数 
		char sex;
		int YR,M,D;//年月日 
		int score[5];
		const string vi_snum(){return snum;}//用来访问私有成员的接口函数 
		const string vi_na(){return name;}//用来访问私有成员的接口函数 
		SetBa(string x,string s){
			name=x;
			snum=s;
		}//私有成员初始化函数 
		Soe_Sum(int N){sum=N;}//访问保护成员Sum的接口函数 
		Soe_Sum(){int n=0;for(int i=0;i<5;i++) n+=score[i];sum=n;}//接口函数,算出总分并赋值给sum 
		const int vi_sum(){return sum;}//常量函数,不能被修改 
		friend bool operator <(const student &T,const student &V);//友元函数，能访问类里面的私有成员(private) 
		friend bool operator <=(const student &T,const student &V);//友元函数，能访问类里面的私有成员(private) 
};
void Print(int cnt,int S=1,string x="loading")//参数为string类(类似动态字符数组),int类 
{
	cout<<x;
	for(int i=0;i<cnt;i++){
		Sleep(S*sec);//Sleep为windows.h里面的函数 
		cout<<".";
		if(i==cnt-1) cout<<endl; 
	}
}
bool operator <(const student &T,const student &V)//重载运算符 < ,使运算符 < 具有更多功能 
{
	if(T.name<V.name) return true;//重载内容;相当于strcmp(T.name,V.name) 
	else return false;
}
bool operator <=(const student &T,const student &V)//同上 
{
	if(T.name<=V.name) return true;
	else return false;
}
