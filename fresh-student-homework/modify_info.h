void modi_page();
void modify_info(vector<student> &per)//修改信息 
{
	if(per.empty()){//若per容器中元素个数为0; 
		cout<<"Error : Not Valid Data"<<endl;
		Print(6,0.8);
		return;
	}
	getchar();
	string Name;//动态字符串数组 
	cout<<"input the name that needs to be modified :";
	getline(cin,Name,'\n');//输入name,空格结束 
	int i=0;
	for(;i<per.size()&&Name!=per[i].vi_na();i++);//查找要修改的学生 
	if(i==per.size()){//如果i等于元素个数,则没找到 
		cout<<"Error : Not Found"<<endl;
		Sleep(1.5*sec);
		cout<<"Returning to the main page"<<endl;
		Print(5);
		return;
	}
	Print(5,1.5);
	modi_page();
	int N;
	while(cin>>N){//类似while(~scanf.....) 
		switch(N){
			case 1:
				char sex;
				cout<<"input sex :";
				cin>>sex;
				per[i].sex=sex;
				break;
			case 2:
				int year;
				cout<<"input year :";
				cin>>year;
				per[i].YR=year;
				break;
			case 3:
				int month;
				cout<<"input month :";
				cin>>month;
				per[i].M=month;
				break;
			case 4:
				int Day;
				cout<<"input Day :";
				cin>>Day;
				per[i].D=Day;
				break; 
			case 5:
				cout<<"input integer(1.CN 2.Math 3.Eng 4.Sci 5.PE) :";
				int x;
				cin>>x;
				int number;
				cout<<"Enter number :";
				cin>>number;
				switch(x-1){
					case CN:per[i].score[CN]=number;break; 
					case Math:per[i].score[Math]=number;break;
					case Eng:per[i].score[Eng]=number;break;
					case Sci:per[i].score[Sci]=number;break;
					case PE:per[i].score[PE]=number;break;
				}
				break;
			case 6:Print(5);return;
			default :cout<<"Input is incorrect,input again"<<endl;
		}
		Print(5);
		cout<<"modify sucessfully"<<endl;
		modi_page();
	}
	
}
void modi_page()
{
	cout<<"====================="<<endl
		<<"  1--sex  2--year "<<endl
		<<"  3-month 4--Day"<<endl
		<<"  5-score 6-exit"<<endl
		<<"====================="<<endl;
	cout<<"input number :";
}
