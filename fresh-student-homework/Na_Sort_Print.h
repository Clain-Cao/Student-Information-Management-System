/*由于名字可能有重复,所测试数据并不大,所以用了stable排序算法,归并排序 */
void Na_merge(vector<student> &A,int left,int mid,int right,vector<student> &B,vector<student> &C);
void Na_mergeSort(vector<student> &A,int left,int right,vector<student> &B,vector<student> &C);
void Na_Sort_Print(vector<student> &T)
{
	if(T.empty()){
		cout<<"Error : Not data"<<endl;
		Print(5,1,"returning");
		return;
	}
	vector<student> L(1000),R(1000);//定义两个容器,并且每个申请1000*student结点的空间*/
	Na_mergeSort(T,0,T.size(),L,R);
	Print_all(T);//调用自定义函数显示全部 
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
	student c1;//定义一个类型 
	c1.SetBa(x,x);//调用类中初始化函数去初始化c1中的name,snum
	B[n1]=C[n2]=c1;//在链表L,R末尾设置一个哨兵,使得L,R到末尾停止
	for(int k=left;k<right;k++){
		if(B[i]<=C[j]){//运算符<=被重载,相当于strcmp(B[i],j[i]),以ASCII码表中字符的位置为准 
			A[k]=B[i++];
		}else{
			A[k]=C[j++];
		}
	}
}
