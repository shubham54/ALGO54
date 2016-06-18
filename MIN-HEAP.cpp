#include <bits/stdc++.h>

using namespace std;

void heapify(int A[],int i,int N)
{
    int left=2*i;
    int right=2*i+1;
    int small=i;
    if(left<=N && A[left]<A[i])
        small=left;
    else
        small=i;
    if(right<=N && A[right]<A[small])
        small=right;
    if(small!=i)
    {
        swap(A[small],A[i]);
        heapify(A,small,N);
    }
}

void min_heap(int A[],int N)
{
    for(int i=N/2;i>=1;i--)
        heapify(A,i,N);
}

void heap_sort(int A[],int N)
{
    int heap_size=N;
    min_heap(A,N);
    for(int i=N;i>=2;i--)
    {
        swap(A[1],A[i]);
        heap_size=heap_size-1;
        heapify(A,1,heap_size);
    }
}

int main()
{
    int N;
    cin>>N;
    int A[N+1];//1-based index
    for(int i=1;i<=N;i++)
        cin>>A[i];
    heap_sort(A,N);//descending sort
    for(int i=1;i<=N;i++)
        cout<<A[i]<<" ";
    return 0;
}

