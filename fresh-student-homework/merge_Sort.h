vector<student> L(100),R(100);
void merge(vector<student> &A,int left,int mid,int right);
void mergeSort(vector<student> &A,int left,int right)
{
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}
void merge(vector<student> &A,int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=A[left+i];
	for(int i=0;i<n2;i++) R[i]=A[mid+i];
	int i=0,j=0;
	string x="zzzzzz";
	student c1;
	c1.SetBa(x,x);
	L[n1]=R[n2]=c1;
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}

