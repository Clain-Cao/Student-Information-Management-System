/*由于总分可能有重复,所测试数据并不大,所以用了stable排序算法,归并排序 */
void Sum_merge(vector<student> &A,int left,int mid,int right);
void Sum_mergeSort(vector<student> &A,int left,int right);
void Sum_Sort_Print(vector<student> &T)
{
	if(T.empty()){//若T容器元素为0,返回
		cout<<"Not data"<<endl;
		Print(5,1,"returning");
		return;
	}
	for(int i=0;i<T.size();i++){
		T[i].Soe_Sum();//调用类的函数算出总分 
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
	student c1;//定义一个类型 
	c1.SetBa(x,x);//调用类中初始化函数去初始化c1中的name,snum 
	c1.Soe_Sum(3000);
	L[n1]=R[n2]=c1;//在链表L,R末尾设置一个哨兵,使得L,R到末尾停止 
	for(int k=left;k<right;k++){
		if(L[i].vi_sum()<=R[j].vi_sum()){//调用vi_sum()函数去访问每个学生中的sum 
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}
