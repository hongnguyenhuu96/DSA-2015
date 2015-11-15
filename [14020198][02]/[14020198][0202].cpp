#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Node{
private:
    int data;
    Node *link;
public:
    Node(){
    }
    Node(const int theData, Node* theLink) : data(theData), link(theLink){}
    void setData(const int& theData){
        this->data = theData;
    }
    void setLink(Node* theLink){
        link = theLink;
    }
    int getData(){
        return data;
    }
    Node* getLink(){
        return link;
    }
};


void headInsert(Node*& head, const int theData){
    head = new Node(theData, head);
}

void insert(Node* afterMe, const int theData){
    afterMe->setLink(new Node(theData, afterMe->getLink()));
}

void deleteNode(Node* before){
    Node *discard;
    discard = before->getLink();
    before->setLink(discard->getLink());
    delete discard;
}

void deleteFirstNode(Node*& head){
    Node *discard;
    discard = head;
    head = head->getLink();
    delete discard;
}

Node* search(Node* head, const int& target){
    Node* here = head;
    if (here == NULL){
        return NULL;
    }
    else{
        while (here->getData() != target && here->getLink() != NULL)
            here = here->getLink();
        if (here->getData() == target)
            return here;
        else
            return NULL;
    }
}

void show(Node *head){
    Node* p = head;
    while(p != NULL){
        cout << p->getData() << " ";
        p = p->getLink();
    }
    cout << endl;
}

void creatLinkList(Node* &head, string data){
    stringstream ss(data);
    Node* p;
    while(!ss.eof()){
        int temp;
        ss >> temp;
        if(ss){
            if(head == NULL){
                headInsert(head, temp);
                p = head;
            }
            else{
                insert(p, temp);
                p = p->getLink();
            }
        }
    }
}

int empty(Node* head){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int length(Node* head){
    int i = 0;
    Node *p = head;
    while(p != NULL){
        i++;
        p = p->getLink();
    }
    return i;
}

int element(Node* head, int i){
    int j = 0;
    Node *p = head;
    while(p != NULL){
        j++;
        if(j == i){
            break;
        }
        p = p->getLink();
    }
    return p -> getData();
}
// insert element x into position i
void insert(Node* &head, int i, int x){
    if(i == 1){
        headInsert(head, x);
    }else{
        Node* p = head;
        int j = 0;
        while(p != NULL){
            j++;
            if(j == i - 1){
                insert(p, x);
                break;
            }
            p = p->getLink();
        }
    }
    show(head);
}

void append(Node* head, int x){
    Node* p = head;
    if(p == NULL){
        headInsert(head, x);
    }
    else{
        while(p->getLink() != NULL){
            p = p->getLink();
        }
        insert(p, x);
    }
    show(head);
}

void deleteNode(Node* &head, int i){
    if(i == 1){
        deleteFirstNode(head);
    } else{
        Node* p = head;
        int j = 0;
        while(p != NULL){
            j++;
            if(j == i - 1){
                deleteNode(p);
                break;
            }
            p = p->getLink();
        }
    }
    show(head);
}
long sum(Node* head){
    long sum = 0;
    Node* p = head;
    while(p != NULL){
        sum += p->getData();
        p= p->getLink();
    }
    return sum;
}

int smallest(Node* head){
    Node *p = head;
    int min = head->getData();
    while(p != NULL){
        if(min > p->getData()){
            min = p->getData();
        }
        p = p->getLink();
    }
    return min;
}

int greatest(Node* head){
    Node *p = head;
    int max = head->getData();
    while(p != NULL){
        if(max < p->getData()){
            max = p->getData();
        }
        p = p->getLink();
    }
    return max;
}

void deleteOdd(Node* &head){
    int flag = 0;
    do{
        flag = 0;
        if(head == NULL) return;
        if((head->getData() % 2)!= 0){
            deleteFirstNode(head);
            flag = 1;
        }
    }while(flag);
    Node* p = head;
    if(p == NULL) return;
    while(p->getLink() != NULL){
        if(p->getLink()->getData() % 2 != 0){
            deleteNode(p);
        }else{
            p = p->getLink();
        }
    }
    show(head);
}

void execute(const char * fileName){
    ifstream file(fileName);
    string data;
    getline(file, data);
    Node* head = NULL;
    creatLinkList(head, data);
    int time;
    file >> time;
    for(int j = 0;  j < time; j++){
        char c;
        file >> c;
        int i, x;
        if(file)
        switch(c){
            case 'a': cout << empty(head) << endl; break;
            case 'b': cout << length(head) << endl; break;
            case 'c':
                file >> i;
                if(file)
                    cout << element(head, i)<< endl;
                break;
            case 'd':
                file >> i >> x;
                if(file)
                    insert(head, i, x);
                break;
            case 'e':
                file >> x;
                if(file)
                    append(head, x);
                break;
            case 'f':
                file >> i;
                if(file)
                    deleteNode(head, i);
                break;
            case 'g': cout << sum(head) << endl; break;
            case 'h': cout << smallest(head) << endl; break;
            case 'i': cout << greatest(head) << endl; break;
            case 'j':
                deleteOdd(head); break;
        }
    }
}

int main(){
    execute("numbers.txt");
}

