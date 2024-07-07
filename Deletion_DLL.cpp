#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node*next,*prev; 
  
  Node(int data,Node*next,Node*prev){
      this->data=data; 
      this->next=next;
      this->prev=prev;
  }
   Node(int data){
      this->data=data; 
      next=NULL;
      prev=NULL;
  }
};

//converting array to LL 
Node* converrtArrLL(vector<int>& arr){
    Node*head = new Node(arr[0]) ; 
    Node*temp= head ;
    int n = arr.size();
    for(int i=1;i<n;i++){
        Node* curr= new Node(arr[i],NULL,temp) ; 
        temp->next=curr;
        temp=temp->next; 
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

int lengthOfList(Node*head){
     Node*temp=head;
     int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    return length;
}

//DELETING THE HEAD OF DLL 
Node* deleteHead(Node*head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*temp=head; 
    head=head->next; 
    head->prev=NULL;
    temp->next=NULL;
    free(temp); //free the heap memory 
    return head; 
}

//DELETING THE TAIL OF DLL 
Node* deleteTail(Node*head){
    if(head==NULL || head->next==NULL) return NULL; //edge cases
    Node*tail=head; 
    while(tail->next){
        tail=tail->next;
    }
    Node* newTail = tail->prev ; 
    tail->prev=NULL;
    newTail->next=NULL;
    delete(tail); //free the heap memory 
    return head; 
}

//DELETING KTH NODE  , K -> [1,LENGTH OF DLL]
Node* deleteKthNode(Node*head,int k){
    if(head==NULL) return NULL;
    
    if(k==1){
       return deleteHead(head) ; 
    }
    if(k==lengthOfList(head)){
       return deleteTail(head) ;
    }
    int pos=1; 
    Node*temp=head;
    while(pos!=k){
        pos++;
        temp=temp->next;
    }
    Node*prevNode=temp->prev,*nextNode=temp->next; 
    prevNode->next=nextNode; 
    nextNode->prev=prevNode;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp ; 
    return head; 
}

//DELETING NODE -> NODE CAN'T BE THE HEAD OF DLL
void deleteNode(Node*temp){
    if(temp==NULL) return;

    Node*prevNode=temp->prev,*nextNode=temp->next; 
    //at tail 
    if(nextNode==NULL){
        prevNode->next=NULL;
        temp->prev=NULL;
        delete temp ; 
        return;
    }
  /*  //We cant delete head node in dll in this case too much if else needed than to modify head of main function 
  if(prevNode==NULL){
        if(temp->next==NULL) return;
        Node*temp2=temp; 
        temp=temp->next; 
        temp->prev=NULL;
        temp2->next=NULL;
        free(temp2); //free the heap memory 
        return;
    }
    */
    prevNode->next=nextNode; 
    nextNode->prev=prevNode;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp ; 
}

int main() {
	  vector<int>arr={1,2,3,4,5}; 
      Node*head= converrtArrLL(arr); 
     traversal(head);
      
    //  head=deleteHead(head);
   //   traversal(head);
      
   //   head=deleteTail(head);
   //   traversal(head);
      
 //       head=deleteKthNode(head,4);
 //       traversal(head);
 
 //        head=deleteNode(head,4);
  //      traversal(head);

         deleteNode(head->next);
          traversal(head);
}
