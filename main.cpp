//
//  main.cpp
//  Josephus
//
//  Created by DuanYujia on 1/25/15.
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

#include <iostream>
#include "Josephus.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int M,N;
    Josephus Jose;
    cout<< "Welcome to Josephus Promblem. "<< endl;
    cout<< "Please input M for passing times:" <<endl;
    cin >> M;
    cout<< "Please input N for number of people:" << endl;
    cin >> N;
    if (M <0 || N<1) {
        cout<< "M must not smaller than 0, and N must not smaller than 1!" <<endl;
        return -1;
    }

    Jose.createJose(N);
    cout <<"There are" << N <<"people. The order of people:"<<endl;
    Jose.printJose();
    cout <<"The order of quit the game:"<<endl;
    Jose.deleteJose(M,N);


    return 0;
}
