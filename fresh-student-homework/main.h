#include<windows.h>
using namespace std;//�������Ϊ�̶���ʽ 
string	vi_na();//���������� 
int snum();//���������� 
class student{//һ����,�����ڽṹ�嵫�ڽṹ�岻ͬ 
	protected://�����Գ�Ա,ֻ���������溯�������friend�ĺ������� 
		int sum;
	private://˽�г�Աֻ����������ĺ������ߴ���friend�������� 
		string name;
		string snum;
	public://���г�Ա,�൱��struct����ı���,public�б����ܱ��ⲿ�����޸�,�ⲿ��������������ĺ��� 
		char sex;
		int YR,M,D;//������ 
		int score[5];
		const string vi_snum(){return snum;}//��������˽�г�Ա�Ľӿں��� 
		const string vi_na(){return name;}//��������˽�г�Ա�Ľӿں��� 
		SetBa(string x,string s){
			name=x;
			snum=s;
		}//˽�г�Ա��ʼ������ 
		Soe_Sum(int N){sum=N;}//���ʱ�����ԱSum�Ľӿں��� 
		Soe_Sum(){int n=0;for(int i=0;i<5;i++) n+=score[i];sum=n;}//�ӿں���,����ֲܷ���ֵ��sum 
		const int vi_sum(){return sum;}//��������,���ܱ��޸� 
		friend bool operator <(const student &T,const student &V);//��Ԫ�������ܷ����������˽�г�Ա(private) 
		friend bool operator <=(const student &T,const student &V);//��Ԫ�������ܷ����������˽�г�Ա(private) 
};
void Print(int cnt,int S=1,string x="loading")//����Ϊstring��(���ƶ�̬�ַ�����),int�� 
{
	cout<<x;
	for(int i=0;i<cnt;i++){
		Sleep(S*sec);//SleepΪwindows.h����ĺ��� 
		cout<<".";
		if(i==cnt-1) cout<<endl; 
	}
}
bool operator <(const student &T,const student &V)//��������� < ,ʹ����� < ���и��๦�� 
{
	if(T.name<V.name) return true;//��������;�൱��strcmp(T.name,V.name) 
	else return false;
}
bool operator <=(const student &T,const student &V)//ͬ�� 
{
	if(T.name<=V.name) return true;
	else return false;
}
