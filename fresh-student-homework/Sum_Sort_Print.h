/*�����ֿܷ������ظ�,���������ݲ�����,��������stable�����㷨,�鲢���� */
void Sum_merge(vector<student> &A,int left,int mid,int right);
void Sum_mergeSort(vector<student> &A,int left,int right);
void Sum_Sort_Print(vector<student> &T)
{
	if(T.empty()){//��T����Ԫ��Ϊ0,����
		cout<<"Not data"<<endl;
		Print(5,1,"returning");
		return;
	}
	for(int i=0;i<T.size();i++){
		T[i].Soe_Sum();//������ĺ�������ܷ� 
	}
	vector<student> l(100),r(100);
	Sum_mergeSort(T,0,T.size());
	Print_all(T);
}
void Sum_mergeSort(vector<student> &A,int left,int right)
{
	if(left+1<right){
		int mid=(left+right)/2;
		Sum_mergeSort(A,left,mid);
		Sum_mergeSort(A,mid,right);
		Sum_merge(A,left,mid,right);
	}
}
void Sum_merge(vector<student> &A,int left,int mid,int right)
{
	vector<student> L(right+10),R(right+10);
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=A[left+i];
	for(int i=0;i<n2;i++) R[i]=A[mid+i];
	int i=0,j=0;
	string x="zzzzzz";
	student c1;//����һ������ 
	c1.SetBa(x,x);//�������г�ʼ������ȥ��ʼ��c1�е�name,snum 
	c1.Soe_Sum(3000);
	L[n1]=R[n2]=c1;//������L,Rĩβ����һ���ڱ�,ʹ��L,R��ĩβֹͣ 
	for(int k=left;k<right;k++){
		if(L[i].vi_sum()<=R[j].vi_sum()){//����vi_sum()����ȥ����ÿ��ѧ���е�sum 
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}
