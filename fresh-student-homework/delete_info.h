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
void delete_info(vector<student> &per)//ɾ��ѧ����Ϣ 
{
	if(per.empty()){//Ԫ�ظ���Ϊ�� 
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
//	getchar();//���ܼ�������Ļس� 
	cout<<"input the snum that needs to delete :";
	getline(cin,Snum,'\n');
	vector<student>::iterator it;//������,�����ڶ�����vector���һ��ָ��, �������ƶ��õ���++,-- 
	int i=0;
	for(;i<per.size();i++){
		if (Name==per[i].vi_na()&&Snum==per[i].vi_snum()){
			break;
		}
	}//ָ����ָѧ����ѧ������Ҫɾ��ѧ����Ϣ����ʱִ��ѭ�� 
	it=per.begin()+i;
	if(it==per.end()){//��ָ�뵽����ĩβ�ĺ�һλ,��û�ҵ� 
		cout<<"NameError : there is no student that needs to delete"<<endl;
		Print(4,1,"returning");
		return;
	}
	else{ 
		it=per.erase(it);//����vectorģ���е�erase����ɾ��it��ָ���ѧ������Ϣ 
		cout<<"delete sucessfully"<<endl;
		Sleep(1.2*sec);//window.h�е�ͣ�ٺ��� 
		Print(6,1,"returning");
	}
}

