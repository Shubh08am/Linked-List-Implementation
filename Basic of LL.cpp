#include <bits/stdc++.h>
using namespace std;
//linked list is not in a contiguous memory location
//size can be increased at any location 
//starting point of ll is head 
//using heap memory 
//uses-> in stack/queue implementation 
//real life -> in browser , doubly ll 
//self define objects -> c++ -> struct and classes 

//store pointer to memory location  -> int * 


class Node{
  public:
  int data; 
  Node*next; 
  Node(int data1,Node*next1){
      data=data1; 
      next=next1;
  }
  Node(int data1){
      data=data1; 
      next=NULL;
  }
};

//converting array to LL 
Node* converrtArrLL(vector<int>& arr){
    Node*head = new Node(arr[0]) ; 
    Node*mover= head ;
    int n = arr.size();
    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i]) ; 
        mover->next=temp; 
        mover=mover->next; //mover=temp; 
    }
    return head;
}
//traversal in LL 
void traversal(Node*head){
    Node*temp=head; 
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main() {
      vector<int>arr={1,2,3,4,5}; 
      Node*head= converrtArrLL(arr); 
    //  cout<<head->data;
      traversal(head);
}
