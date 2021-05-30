#include <iostream>
#include <bits/stdc++.h>


using namespace std;
struct Node{

int value;
Node **next;

Node(int level, int value){
 next = new Node * [level + 1];
  for(int i=0;i<level+1;i++){
        next[i]=0;
        }
    this->value = value;
}

};

class skipList{

Node *head;
int  Max_level;
float p;

public:

   skipList(int Max_level){

         this->Max_level=Max_level;
         p=0.5;
        head = new Node(Max_level, -1);
}


int randomLevel(){

    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while(r < p && lvl < Max_level){
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
}

void Insert(int value){

Node *x = head;
Node *update[Max_level];

for(int i=0;i<Max_level;i++){
    update[i]=0;
}

for (int i = Max_level;i >= 0;i--){
    while (x->next[i] != NULL && x->next[i]->value < value){
            x = x->next[i];
        }

        update[i] = x;
}

int num=randomLevel();
Node* newnode=new Node(num,value);

for(int i=0;i<=num;i++){
    newnode->next[i] = update[i]->next[i];
    update[i]->next[i] = newnode;
}

}


void Search(int key){

Node *current = head;

for(int i = Max_level; i >= 0; i--){

while(current->next[i] &&current->next[i]->value < key){
    current = current->next[i];
}
}
      current = current->next[0];

    if(current->value == key)
        cout<<"Found key: "<<key<<"\n";
else{
        cout<<" Not Found key: "<<key<<"\n";

}

}

void display(){


    for(int i=0;i<Max_level;i++){

        Node *node = head->next[i];
        if(node!=0){
        cout << "Level " << i << ": ";
        }

        while(node != NULL){
            cout<<node->value<<" ";
            node = node->next[i];
        }

        cout<<"\n";
    }
}



};

int main()
{
    srand((unsigned)time(0));
    cout<<"Build tree with 3 level"<<endl;
    cout<<"-----------------------------------"<<endl;

   skipList lst(3);

lst.Insert(2);
lst.Insert(16);
lst.Insert(10);
lst.Insert(15);
lst.Insert(34);
lst.Insert(8);
cout<<"Display all element in tree: "<<endl;
cout<<"-----------------------------------"<<endl;
lst.display();
cout<<"search for 12: ";
lst.Search(12);
cout<<"search for 34: ";
lst.Search(34);


    return 0;
}
