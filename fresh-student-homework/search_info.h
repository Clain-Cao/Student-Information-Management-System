void search_page();
void search_info(vector<student> &per)//搜索信息 
{
	if(per.empty()){//若per容器为空 
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
		string Snum;//动态字符数组,查找学号 
		cout<<"input the snum that needs to search :";
		getline(cin,Snum,'\n');//输入Snum，回车结束输入 
		for(;i<per.size()&&Snum!=per[i].vi_snum();i++);//per.size()返回元素个数,vi_snum()是访问snum的接口函数 
	}
	else if(N==2){
		string Name;//动态字符数组,查找学号
		cout<<"input the name that needs to search :";
		getline(cin,Name,'\n');//输入Name，回车结束输入 
		for(;i<per.size()&&Name!=per[i].vi_na();i++);
	}
	else if(N==3){
		cout<<"input Serial number(eg.1st->1,15th->15) :";
		int number;
		cin>>number;//scanf 
		i=number-1;
	}
	else{
		cout<<"Input Error"<<endl;//printf,<<endl类似于输出回车 
		Sleep(2*sec);
		goto out;
	}
	if(i==per.size()){//i==per的元素个数 
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
void search_page()//搜索界面 
{
	cout<<"*******Search for stus' info********"<<endl
		<<"------------------------------------"<<endl
    	<<"  1---search by the school number"<<endl	 
    	<<"  2---search by Name"<<endl
		<<"  3---search by Serial number"<<endl//序号搜索  
		<<"------------------------------------"<<endl;
	cout<<"input number :";
}
