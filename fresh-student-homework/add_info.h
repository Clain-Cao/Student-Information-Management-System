void add_info(vector<student> &per,const string &filename){
	if(per.empty()){
		cout<<"you need to create students'info"<<endl;
		Sleep(1.1*sec);
		Print(4,1,"returning");
		return;
	}
here:
	student stu;//����student�� 
	string Name;//(��̬�ַ�������)
	string Snum;//(��̬�ַ�������)
	Print(4);
	cout<<"input stu name.After confirmation,It'll not be changed(eg.Xiao Ming) :";
	getchar();
	getline(cin,Name,'\n');//��������,�ո����������; 
	cout<<"input snum(After confirmation,It'll not be changed) :";
	cin>>Snum;//����ѧ�� 
	int K;
	for(K=0;K<per.size()&&Snum!=per[K].vi_snum()&&Snum!=per[K].vi_na();K++);//K<per������Ԫ�ظ�������������ѧ�Ų�����ÿһ��;����Ϊѧ����Ϣ���� 
	if(K!=per.size()){//K������per��Ԫ�ظ��� 
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
	cin>>stu.sex;//�����Ա� 
	int Score[5];
	cout<<"input 5 scores(20 20 20 20 20)"<<endl;
	for(int i=0;i<5;i++){
		cin>>stu.score[i];
	}
	stu.SetBa(Name,Snum);//����student������ĳ�ʼ��������stu�����name��snum���и�ֵ 
	cout<<"Input date of birth(eg.2018 01 02) :";
	cin>>stu.YR>>stu.M>>stu.D;//printf 
	per.push_back(stu);//����������Ϣ��ѧ�����per����ĩβ; 
	cout<<"loading";
	for(int i=0;i<6;i++){
		Sleep(sec);
		cout<<".";
		if(i==5) cout<<endl; 
	}
	fstream infile(filename.c_str(),ios::app);//��д�Ͳ�����ļ�����ʽ���ļ���Ϊfilename���ļ� 
	getline(infile,Name,'\n');
	infile<<" "<<stu.sex<<" "<<Snum<<" ";//�����infile����fprintf 
	infile<<stu.YR<<" "<<stu.M<<" "<<stu.D<<" ";
	for(int i=0;i<5;i++){
		infile<<stu.score[i]<<" ";
	}
	infile<<endl;//���ļ�����س� 
	cout<<"added successfully"<<endl;
	infile.close(); //�ر��ļ� 
}
