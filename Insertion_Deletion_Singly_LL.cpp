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
int lengthOfList(Node*head){
     Node*temp=head;
     int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    return length;
}
//DELETING THE HEAD OF LL 
Node* deleteHead(Node*head){
    if(head==NULL) return NULL;
    Node*temp=head; 
    head=head->next; 
    free(temp); //free the heap memory 
    return head; 
}

//DELETING THE TAIL OF LL 
Node* deleteTail(Node*head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*temp=head; 
    while(temp->next->next){
        temp=temp->next;
    }
    delete(temp->next); //free the heap memory 
    temp->next=NULL;
    return head; 
}

//DELETING KTH NODE 
Node* deleteKthNode(Node*head,int k){
    if(head==NULL) return NULL;
    if(k==1){
        return deleteHead(head);
    }
    if(k==lengthOfList(head)){
        return deleteTail(head);
    }
    Node*temp=head,*prev=NULL; 
    int pos=0;
    while(temp){
        pos++;
        if(pos==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next; 
    }

    return head; 
}

//DELETING NODE ON BASIS OF VALUE -> FIRST POSITION NODE DELETED 
Node* deleteNode(Node*head,int value){
    if(head==NULL) return NULL;
    if(head->data==value){
        return deleteHead(head);
    }
    Node*temp=head,*prev=NULL; 
    while(temp){
        if(temp->data==value){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next; 
    }

    return head; 
}

//INSERTION AT HEAD 
Node* insertionAtHead(Node*head,int value){
    Node*temp=new Node(value,head) ; 
   // head=temp; 
  //  return head;
   return temp;
}

//INSERTION AT TAIL 
Node* insertionAtTail(Node*head,int value){
    //edge case 
    if(head==NULL){
        return insertionAtHead(head,value);
    }
    Node*temp=new Node(value,NULL) ; 
    Node*dummy=head; 
    while(dummy->next){
        dummy=dummy->next;
    }
    dummy->next=temp;
   return head;
}

//INSERTION AT KTH POS  , K -> [1,LENGTH OF LL ]
Node* insertionAtKthPos(Node*head,int k,int value){
    //edge case 
    if(head==NULL){
        if(k==1){
            return insertionAtHead(head,value);
        }
        else return NULL; //return any thing any msg or other thing 
    }
    if(k==1){
            return insertionAtHead(head,value);
    }
    Node*temp=head,*prev=NULL; 
    int pos=0; 
    //method-1
  /*  while(temp){
        pos++;
        if(pos==k){
            prev->next=new Node(value,temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    */
    //method-2
    while(temp){
        pos++;
        if(pos==k-1){
            Node*dummy=new Node(value,temp->next);
            temp->next=dummy;
            break;
        }
        temp=temp->next;
    }
   return head;
}

//INSERTION OF NODE BEFORE VALUE X

Node*insertionBeforeX(Node*head,int value,int x){
     //edge case 
    if(head==NULL){
        return NULL; //not possible to insert only before x 
    }
    if(head->data==x){
            return insertionAtHead(head,value);
    }
    Node*temp=head; 
    bool present=false; 
    while(temp->next){
        if(temp->next->data==x){
            Node*dummy=new Node(value,temp->next);
            temp->next=dummy;
            present=true;
            break;
        }
        temp=temp->next;
    }
    if(present==false) return NULL;
   return head;
}
int main() {
      vector<int>arr={1,2,3,4,5}; 
      Node*head= converrtArrLL(arr); 
    // cout<<head->data;
      traversal(head);
      
  //    head = deleteHead(head) ; 
 //     traversal(head) ;
    
 //    head = deleteTail(head) ; 
 //     traversal(head) ;
      
 //      head = deleteKthNode(head,3) ; 
//      traversal(head) ;

  //     head = deleteNode(head,1) ; 
 //      traversal(head) ;
       
  //     head = insertionAtHead(NULL,10) ; 
  //   traversal(head) ;
 
   //  head = insertionAtTail(head,100) ; 
  //     traversal(head) ;
     
  //    head = insertionAtKthPos(head,5,100) ; 
 //     traversal(head) ;
 
 
      head = insertionBeforeX(head,100,1) ; 
       traversal(head) ;
}
