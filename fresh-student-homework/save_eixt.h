void save_eixt(vector<student> &T,string filename)
{
	fstream infile(filename.c_str(),ios::out);//以写和清空filename方式打开filename 
	if(!infile){//若没有打开文件,输出错误信息 
		cerr<<"Open file error"<<endl;
		return;
	}
	for(int i=0;i<T.size();i++){//在这个for中,infile类似fprintf 
			infile<<T[i].vi_na()<<endl<<T[i].sex<<" "<<T[i].vi_snum()<<" ";
			infile<<T[i].YR<<" "<<T[i].M<<" "<<T[i].D<<" ";
			for(int j=0;j<5;j++){
				infile<<T[i].score[j];
				if(j!=4) infile<<" ";
			}
	}
	infile.close();//关闭文件 
	Print(8,0.7);
	cout<<"Withdraw from success"<<endl;
	Sleep(1.5*sec);
	exit(0);//退出系统 
}
