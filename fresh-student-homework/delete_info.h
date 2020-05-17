void PrintStudent(vector<student> &per , int r)
{
	cout<<"  Name :"<<per[r].vi_na()<<endl
		<<"  Sex  :"<<per[r].sex<<endl
		<<"  Snum :"<<per[r].vi_snum()<<endl;
	cout<<"  birth :"<<per[r].YR<<" "<<per[r].M<<" "
		<<per[r].D<<" "<<endl;
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
		printf("| %5d   ",per[r].score[j]);
		if(j==4) cout<<"|"<<endl;
	}
	cout<<"---------------------------------------------------";
	cout<<endl;
}
void delete_info(vector<student> &per)//删除学生信息 
{
	if(per.empty()){//元素个数为空 
		cout<<"Not Valid Data"<<endl;
		Print(6,0.9); 
		return; 
	}
	getchar();
	string Name;
	string Snum; 
	cout<<"input the name that needs to delete :";
	getline(cin,Name,'\n');
	for(int r = 0 ;r<per.size();r++){
		if (Name == per[r].vi_na()){
			PrintStudent(per,r);
		}
	}
//	getchar();//接受键盘输入的回车 
	cout<<"input the snum that needs to delete :";
	getline(cin,Snum,'\n');
	vector<student>::iterator it;//迭代器,类似于定义了vector类的一个指针, 迭代器移动用的是++,-- 
	int i=0;
	for(;i<per.size();i++){
		if (Name==per[i].vi_na()&&Snum==per[i].vi_snum()){
			break;
		}
	}//指针所指学生和学号与所要删除学生信息不符时执行循环 
	it=per.begin()+i;
	if(it==per.end()){//若指针到容器末尾的后一位,则没找到 
		cout<<"NameError : there is no student that needs to delete"<<endl;
		Print(4,1,"returning");
		return;
	}
	else{ 
		it=per.erase(it);//调用vector模板中的erase函数删除it所指向的学生的信息 
		cout<<"delete sucessfully"<<endl;
		Sleep(1.2*sec);//window.h中的停顿函数 
		Print(6,1,"returning");
	}
}

