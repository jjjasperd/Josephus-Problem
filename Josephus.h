//
//  Josephus.h
//  Josephus
//
//  Created by DuanYujia on 1/28/15.
//  Copyright (c) 2015 DuanYujia. All rights reserved.
//
//The Josephus problem is the following game: N people, numbered 1 to N, are sitting
//in a circle. Starting at person 1, a hot potato is passed. After M passes, the person
//holding the hot potato is eliminated, the circle closes ranks, and the game continues
//with the person who was sitting after the eliminated person picking up the
//hot potato. The last remaining person wins. Thus, if M = 0 and N = 5, players
//are eliminated in order, and player 5 wins. If M = 1 and N = 5, the order of
//elimination is 2, 4, 1, 5.
//

#ifndef Josephus_Josephus_h
#define Josephus_Josephus_h

#include<iostream>


using namespace std;
struct Node{
    int num;
    Node *next;
};

class Josephus{
private:
    // list<int> Jose;
    Node *first;
    Node *p;
public:
    Josephus(){
        first = new Node;
        first -> num = 1;
        first ->next =first;
    };
    void createJose(int N);
    void printJose();
    //void Josephusring(int N,int M);
    void deleteJose(int M, int N);
    Node *getJose(){return first;}
};

void Josephus::createJose(int N){
    Node *s =first ;
    s = first->next;
    for (int i=2; i<=N; ++i) {
        Node *q = new Node;
        q->num = i;
        q->next = first;
        s->next =q;
        s=q;
    }
}

void Josephus::printJose(){
    cout << first->num <<" ";
    Node *q = first->next;
    while ( q != first) {
        cout << q->num <<" ";
        q = q->next;
    }
    cout <<endl;
}

void Josephus::deleteJose(int M, int N){
    Node *q = nullptr, *s =nullptr; //q for the pre of p, s for each time the first one to pass
    int Nleft = N;
    s=first;
    //cout<<p->num <<endl;
    if (M > 0) {
        while (Nleft != 1) {
            //cout<< "1"<<endl;
            p = s;
            for (int i = 1; i <= M; ++i) {
                q = p;
                p = p->next;
                s = p->next;
            }
            cout << p->num << " ";
            if (p->next !=NULL){
                q->next = p->next;
            }
            else{
                q->next = first;
            }
            
            delete p;
            
            --Nleft;
        }
        cout<<endl;
        //cout << q->next->num<<" ";
    }
    else {
        while (Nleft !=1) {
            p =s;
            s=p->next;
            cout<< p->num <<" ";
            delete p;
            
            --Nleft;
        }
        cout<<endl;
        //   p= p->next;
        
    }
    p=p->next;
    cout <<"Number "<< p->num << " win!";
    
}

#endif
