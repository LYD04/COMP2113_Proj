#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include "cursednum.h"
#include <thread>
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

bool isprime(int num){
    bool prime = false;
    for( int i=1 ; i<=num ; ++i){
        prime*=-1;
    }
}

//To provide information for the player in the middle of the game and affect the player's decision-making
void hint(int curnum,int hintnumber, bool real){
    if(real)
    {
        switch(hintnumber)
        {
            case 0:
                if(curnum%2==0)
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is an even number |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }else
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is an odd number  |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }
                break;
            case 1: 
                int factor_count = 0;
                for(int i=1 ; i<=curnum ; ++i)
                {
                    if(curnum%i==0)
                    {
                        factor_count+=1;
                    }
                }
                if( factor_count == 2)
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is a prime number |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }
                else
                {
                    cout<<" ___________________________________"<<endl;
                    cout<<"|               HINT                |"<<endl;
                    cout<<"|                                   |"<<endl;
                    cout<<"|     It is a composite number      |"<<endl;
                    cout<<"|                                   |"<<endl;
                    cout<<"|___________________________________|"<<endl;
                }
                break;
        }

    }else
    {
        switch(hintnumber)
        {
            case 0:
                if(curnum%2==0)
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is an odd number  |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }else
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is an even number |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }
                break;
            case 1: 
                int factor_count = 0;
                for(int i=1 ; i<=curnum ; ++i)
                {
                    if(curnum%i==0)
                    {
                        factor_count+=1;
                    }
                }
                if( factor_count == 2)
                {
                    cout<<" ___________________________________"<<endl;
                    cout<<"|               HINT                |"<<endl;
                    cout<<"|                                   |"<<endl;
                    cout<<"|     It is a composite number      |"<<endl;
                    cout<<"|                                   |"<<endl;
                    cout<<"|___________________________________|"<<endl;
                }
                else
                {
                    cout<<" ______________________"<<endl;
                    cout<<"|         HINT         |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"| It is a prime number |"<<endl;
                    cout<<"|                      |"<<endl;
                    cout<<"|______________________|"<<endl;
                }
                break;
        }

    }
}

bool cursednum() {

    //VARIABLES             
    int call = -1;                    //The call on the number from both player and the antagonist 
    int turn = -1;                    //Indicator of whose turn is it (1=ridder's turn, -1= the player's turn)
    int ub = 100;                     //Upper boundary
    int lb = 0;                       //Lower boundary              
    srand(time(NULL));                //Reinitializing
    int curnum = rand()%101;          //Generating the cursed number  
    cout<<"Riddler: ";
	cout<< "\033[32m";
    cout<<"Let me give you a \"hint\", Batman. BeLIEve it or not! "<<endl;
    cout<< "\033[0m";
    hint(curnum,rand()%2,rand()%2);
    while(call!=curnum){
        if(turn==-1){
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"*****IT'S YOUR TURN. PLEASE INPUT A NUMBER BETWEEN "<<lb<<" AND "<<ub<<"*****"<<endl;
            cin>>call;
            validnum(call,lb,ub);
            turn*=-1;
        }else if(turn==1){
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"*****IT'S YOUR TURN, Riddler. PLEASE INPUT A NUMBER BETWEEN "<<lb<<" AND "<<ub<<"*****"<<endl;
            call = lb+rand()%(ub-lb+1); //The antagonist picks a number randomly from the new boundary 
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"DA: ";
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
