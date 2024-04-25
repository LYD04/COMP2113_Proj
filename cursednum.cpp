#include "cursednum.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;

//To check if the choice of the player is out of range(lb,ub)
void validnum(int& s,int a, int b){
    while(s<a||s>b){
        cout<<"*****INVALID INPUT. TRY AGAIN.*****"<<endl;
        cin>>s;
    }
}


//To modify the lower and upper boundary according to the player's and the antagonist's choice
void modifybound(int curnum, int call, int& lb,int& ub){
    if(call>curnum){
        ub = call-1;
    }else if(call<curnum){
        lb = call+1;
    }
}

bool cursednum() {

    //VARIABLES             
    int call = -1;                    //The call on the number from both player and the antagonist 
    int turn = -1;                    //Indicator of whose turn is it
    int ub = 100;                     //Upper boundary
    int lb = 0;                       //Lower boundary              
    srand(time(NULL));                //Reinitializing
    int curnum = rand()%101;          //Generating the cursed number  
    while(call!=curnum){
        if(turn==-1){
            cout<<"*****IT'S YOUR TURN. PLEASE INPUT A NUMBER BETWEEN "<<lb<<" AND "<<ub<<"*****"<<endl;
            cin>>call;
            validnum(call,lb,ub);
            turn*=-1;
        }else if(turn==1){
            cout<<"*****IT'S YOUR TURN, Riddler. PLEASE INPUT A NUMBER BETWEEN "<<lb<<" AND "<<ub<<"*****"<<endl;
            call = lb+rand()%(ub-lb+1); //The antagonist picks a number randomly from the new boundary 
	    cout << "\033[32m";
            cout<<"I picked "<<call<<"."<<endl;
	    cout << "\033[0m";
            turn*=-1;
        }
        modifybound(curnum, call, lb, ub);
    }

    cout << "" << endl;
    cout << "The cursed number was " << curnum << "." << endl;
    //RESULTS
    if(turn==-1){
        return true;
    }
    else if(turn==1){
        return false;
    }
   return false;
        
}
