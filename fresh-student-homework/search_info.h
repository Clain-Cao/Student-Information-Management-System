void search_page();
void search_info(vector<student> &per)//������Ϣ 
{
	if(per.empty()){//��per����Ϊ�� 
		cout<<"Not Valid Data"<<endl;
		Print(6,0.8); 
		return; 
	}
	getchar();
out:
	search_page();
	int N;int i=0;
	cin>>N;//printf 
	getchar();
	if(N==1){
		string Snum;//��̬�ַ�����,����ѧ�� 
		cout<<"input the snum that needs to search :";
		getline(cin,Snum,'\n');//����Snum���س��������� 
		for(;i<per.size()&&Snum!=per[i].vi_snum();i++);//per.size()����Ԫ�ظ���,vi_snum()�Ƿ���snum�Ľӿں��� 
	}
	else if(N==2){
		string Name;//��̬�ַ�����,����ѧ��
		cout<<"input the name that needs to search :";
		getline(cin,Name,'\n');//����Name���س��������� 
		for(;i<per.size()&&Name!=per[i].vi_na();i++);
	}
	else if(N==3){
		cout<<"input Serial number(eg.1st->1,15th->15) :";
		int number;
		cin>>number;//scanf 
		i=number-1;
	}
	else{
		cout<<"Input Error"<<endl;//printf,<<endl����������س� 
		Sleep(2*sec);
		goto out;
	}
	if(i==per.size()){//i==per��Ԫ�ظ��� 
		cout<<"Error : Not Found"<<endl;
		Sleep(1.5*sec);
		cout<<"Returning to the main page"<<endl;
		Print(5);
		return ;
	}
	else{
		cout<<"  Name :"<<per[i].vi_na()<<endl
			<<"  Sex  :"<<per[i].sex<<endl
			<<"  Snum :"<<per[i].vi_snum()<<endl;
		cout<<"  birth :"<<per[i].YR<<" "<<per[i].M<<" "
			<<per[i].D<<" "<<endl;
			cout<<"  five score :"<<endl;
			cout<<"--------------------------------------------------"<<endl;
		for(int j=0;j<5;j++){
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
			printf("| %5d   ",per[i].score[j]);
			if(j==4) cout<<"|"<<endl;
		}
		cout<<"---------------------------------------------------";
		cout<<endl;
		system("pause"); 
		Sleep(1.5*sec);
		cout<<"Returning to the main page"<<endl;
		Print(5);
	}
}
void search_page()//�������� 
{
	cout<<"*******Search for stus' info********"<<endl
		<<"------------------------------------"<<endl
    	<<"  1---search by the school number"<<endl	 
    	<<"  2---search by Name"<<endl
		<<"  3---search by Serial number"<<endl//�������  
		<<"------------------------------------"<<endl;
	cout<<"input number :";
}
