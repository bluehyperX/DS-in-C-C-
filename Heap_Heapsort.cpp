/*
1. Heap is a data structure which is *always complete binary tree* and (for max heap) parent is always
more than its children or (for min heap) parent is always less than its children.

2. It is always implemented using array.

3. Parent of i = floor((i-1)/2)
    Left child of i = (2*i)+1
    Right child of i = (2*i)+2

4. Heap uses level order traversing (BFS).

5. Uses heapify to build heap from an array.

6. Used as Priority Queue. Insertions at next leaf and deletion from root.

7. Use of Heap - Huffman Coding, Shortest Path, Min Spanning tree, Selection problem

8. Heap Sort uses heap to sort an array.
*/

#include <iostream>
using namespace std;

class Heap{
private:
    int A[100];
    int n=0;
public:
    
    void print(int A[], int n){
        for (int i=0; i<n; i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }

    void print(){
        for (int i=0; i<n; i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void Heapify (int A[], int i, int n){ //A is array, i is index at which heapify is called, n is no.of elements in heap
        int l = 2*i+1; //left child address
        int r = 2*i+2; //right child address
        int max = i; //to store the index of max element. Set it to i by default
        if (l<n && A[max]<A[l]) max = l; //check if the left child is in the array (index less than #elem), if yes then find maximum b/w max and left child. By default max is parent.
        if (r<n && A[max]<A[r]) max = r; //check if the right child is in the array, if yes then find maximum b/w max and right child. We are finding the max between parent and its 2 children. 
        if (max!=i) { //if parent is not max then
            swap(&A[i],&A[max]); //swap the max child with the parent 
            Heapify(A,max,n); //call heapify for the max element. We need to check the subtree for any violation of heap and also correct for the same.
        }
    }
    //Time Complexity of Heapify = Depend on max no.of swapping which in turn depends on height of tree. 
    //Height of tree is given as O(log n). Hence Time Complexity of Heapify = O(log n). 

    /* Explaination in Hindi - Pehle left and right child nikalo ith index ka and max variable me i store kro.
    Fir check kro ki left child present h ya nhi aur agar h toh use compare kro parent ke saath. Jo maximum h
    uska index max variable me store kro. Fir same kaam right child ke liye kro. Agar max me jo index stored
    h wo parent ke index ke barabar nhi h toh parent ko usse swap kro aur fir max me jo index stored h uske
    liye heapify call kro.
    */

    void BuildHeap (int A[], int n){
        for (int i=(n-2)/2 ; i>=0; i--){
            Heapify(A,i,n); //call heapify for every parent node of the tree to rearrange them into a heap
        }
    }
    //Time Complexity of BuildHeap = O(n)

    /* Explaination in Hindi - Pehle kitne elements h count kro. Fir last element ka parent nikalo 
    i.e (n-1)th index ka parent. Fir har parent node ke liye heapify call kro till root node.
    */

    void Insert(int key){
        n=n+1; //increase the size of heap
        int i = n-1;
        A[i]=key; //insert the key at the next leaf node
        //print(A,n);
        while (i>0){
            int p = (i-1)/2;
            if (A[i]>A[p]) swap(&A[i],&A[p]);
            i=p;
        }
        //print(A,n);
    }
    //Time Complexity = O(log n)

    /* Explaination in Hindi - Pehle heap ka size increase kro. Fir last node pe key ko insert kro.
    i.e (n-1)th index pe. Fir uske parent node ke liye heapify call kro till root node.
    */

    int Delete(){
        int element = A[0]; //store the root element
        A[0]=A[n-1]; //swap root and the last leaf node
        n=n-1; //reduce the size of heap
        Heapify(A,0,n); //call heapify for the root in the reduced heap
        return element; 
    }
    //Time Complexity = O(log n)

    /* Explaination in Hindi - Pehle root element ko store kro. Fir root me last leaf ki value store kro.
    Fir heap ka size decrease kro. Fir uske root node ke liye heapify call kro reduced heap ke liye.
    */

    void HeapSort(int A[], int n){
        BuildHeap(A,n); //create heap from the array
        for (int i=n-1; i>0; i--){ //one by one extract element from the heap. 
            //cout<<"index: "; printf("%d \n",i);
            swap(&A[0],&A[i]); //swap the first and last node of the heap i.e place the largest element at the back
            //cout<<"swap: \n"; print(A,n);
            Heapify(A,0,i); //call heapify for the root in the reduced heap
            //cout<<"heapify: \n"; print(A,n);
            //printf("\n");
        }
        cout<<"\nThe sorted array is ";
        print(A,n);
    }
    //Time Complexity = O(n*log n)

    /* Explaination in Hindi - Pehle us array se heap build kro. Fir ek loop chalao jisme har iteration ke 
    baad heap ka size decrease ho. Us loop ke andar root aur last leaf ki value swap kro. Fir uske root
    node ke liye heapify call kro reduced heap ke liye. Hum chahte h ki har iteration ke baad root element
    jo ki largest h wo last me chale jaye array ke and baki bache elements wapas heap ban jaye.
    */

};


int main(){
    Heap h;
    h.Insert(20);
    h.Insert(15);
    h.Insert(12);
    h.Insert(23);
    h.Insert(54);
    h.Insert(9);
    int y=h.Delete();
    h.print();
    printf("%d \n",y);
    int arr[7]={12,69,85,45,10,9,14};
    cout<<"The array is ";
    h.print(arr,7);
    h.BuildHeap(arr,7);
    cout<<"The heap is ";
    h.print(arr,7);
    h.HeapSort(arr,7);
    return 0;
}