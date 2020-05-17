void add_info(vector<student> &per,const string &filename){
	if(per.empty()){
		cout<<"you need to create students'info"<<endl;
		Sleep(1.1*sec);
		Print(4,1,"returning");
		return;
	}
here:
	student stu;//定义student类 
	string Name;//(动态字符串数组)
	string Snum;//(动态字符串数组)
	Print(4);
	cout<<"input stu name.After confirmation,It'll not be changed(eg.Xiao Ming) :";
	getchar();
	getline(cin,Name,'\n');//输入名字,空格键结束输入; 
	cout<<"input snum(After confirmation,It'll not be changed) :";
	cin>>Snum;//输入学号 
	int K;
	for(K=0;K<per.size()&&Snum!=per[K].vi_snum()&&Snum!=per[K].vi_na();K++);//K<per容器中元素个数并且姓名和学号不等于每一个;功能为学生信息查重 
	if(K!=per.size()){//K不等于per中元素个数 
		cout<<"Error : Student information has already existed"<<endl
			<<"-------------------------------"<<endl
			<<"|    1---try again            |"<<endl
			<<"|    2---return to main page  |"<<endl
			<<"-------------------------------"<<endl;
		int P;
		cout<<"input number :";
		cin>>P;
		switch(P){
			case 1:goto here;break;
			case 2:return;
		} 
	}
	cout<<"input sex(B or G) :"; 
	cin>>stu.sex;//输入性别 
	int Score[5];
	cout<<"input 5 scores(20 20 20 20 20)"<<endl;
	for(int i=0;i<5;i++){
		cin>>stu.score[i];
	}
	stu.SetBa(Name,Snum);//调用student类里面的初始化函数对stu里面的name和snum进行赋值 
	cout<<"Input date of birth(eg.2018 01 02) :";
	cin>>stu.YR>>stu.M>>stu.D;//printf 
	per.push_back(stu);//将输入完信息的学生存进per容器末尾; 
	cout<<"loading";
	for(int i=0;i<6;i++){
		Sleep(sec);
		cout<<".";
		if(i==5) cout<<endl; 
	}
	fstream infile(filename.c_str(),ios::app);//以写和不清空文件的形式打开文件名为filename的文件 
	getline(infile,Name,'\n');
	infile<<" "<<stu.sex<<" "<<Snum<<" ";//这里的infile类似fprintf 
	infile<<stu.YR<<" "<<stu.M<<" "<<stu.D<<" ";
	for(int i=0;i<5;i++){
		infile<<stu.score[i]<<" ";
	}
	infile<<endl;//向文件读入回车 
	cout<<"added successfully"<<endl;
	infile.close(); //关闭文件 
}
