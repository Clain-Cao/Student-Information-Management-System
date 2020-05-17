#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	fstream infile("C:\Users\’≈ÕÆ°£\Desktop\stu_info.txt",ios::out|ios::in);
	if(!infile){
		cerr<<"error";
		exit(0);
	}
	for(int i=0;i<100;i++){
		string na;
		string snum;
		student S;
		for(int j=0;j<11;j++){
			char c;
			c='a'+rand()%26;
			if(j%5==0&&j!=0) c=' ';
			na.push_back(c);	
		}
		infile<<na<<endl;
		char v='B';
		for(int j=0;j<13;j++){
			char C;
			C='0'+rand()%10;
			snum.push_back(C);
		}
		S.YR=rand()%9999+1;
		S.M=rand()%11+1;
		S.D=rand()%30+1;
		for(int k=0;k<5;k++){
			S.score[k]=rand()%100;
		}
		infile<<v<<" "<<snum<<" "<<S.YR<<" "<<S.M<<" "<<S.D<<" ";
		for(int j=0;j<5;j++){
			infile<<S.score[j];
			if(j==4) infile<<" ";
		}
	}
	infile.close();
	cout<<"Initialization success"<<endl;
	return 0;
}
