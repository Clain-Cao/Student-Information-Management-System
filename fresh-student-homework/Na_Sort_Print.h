/*�������ֿ������ظ�,���������ݲ�����,��������stable�����㷨,�鲢���� */
void Na_merge(vector<student> &A,int left,int mid,int right,vector<student> &B,vector<student> &C);
void Na_mergeSort(vector<student> &A,int left,int right,vector<student> &B,vector<student> &C);
void Na_Sort_Print(vector<student> &T)
{
	if(T.empty()){
		cout<<"Error : Not data"<<endl;
		Print(5,1,"returning");
		return;
	}
	vector<student> L(1000),R(1000);//������������,����ÿ������1000*student���Ŀռ�*/
	Na_mergeSort(T,0,T.size(),L,R);
	Print_all(T);//�����Զ��庯����ʾȫ�� 
}
void Na_mergeSort(vector<student> &A,int left,int right,vector<student> &B,vector<student> &C)
{
	if(left+1<right){
		int mid=(left+right)/2;
		Na_mergeSort(A,left,mid,B,C);
		Na_mergeSort(A,mid,right,B,C);
		Na_merge(A,left,mid,right,B,C);
	}
}
void Na_merge(vector<student> &A,int left,int mid,int right,vector<student> &B,vector<student> &C)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) B[i]=A[left+i];
	for(int i=0;i<n2;i++) C[i]=A[mid+i];
	int i=0,j=0;
	string x="zzzzzz";
	student c1;//����һ������ 
	c1.SetBa(x,x);//�������г�ʼ������ȥ��ʼ��c1�е�name,snum
	B[n1]=C[n2]=c1;//������L,Rĩβ����һ���ڱ�,ʹ��L,R��ĩβֹͣ
	for(int k=left;k<right;k++){
		if(B[i]<=C[j]){//�����<=������,�൱��strcmp(B[i],j[i]),��ASCII������ַ���λ��Ϊ׼ 
			A[k]=B[i++];
		}else{
			A[k]=C[j++];
		}
	}
}
