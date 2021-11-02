#include <iostream>
#include <string>

using namespace std;

int input;
string output;

enum state {S0,S1,S2,S3,S4};
state presentState, nextState;

struct memWord{ //Different from an array, since a struct can hold various types of data
    
  string output;
  state nextState[8];
  
};

//ROM memory by assigning a matrix of 5 rows to it
memWord ROM[5];

void setup();
void loop();

int main(){
    setup();
    
    while(true){
        loop();
    }
    return 0;
}

void setup(){
    ROM[0]={"R,B",      {S0,S0,S0,S0,S1,S2,S3,S0}};
    ROM[1]={"G,Y",      {S1,S1,S4,S1,S1,S1,S1,S1}};
    ROM[2]={"G",        {S2,S2,S2,S2,S2,S2,S2,S4}};
    ROM[3]={"Y",        {S3,S3,S3,S2,S3,S3,S3,S3}};
    ROM[4]={"R,B,G,Y",  {S4,S0,S4,S4,S4,S4,S4,S4}};
    
    presentState=S0;
    output=ROM[presentState].output;
    
    cout<<"Present State = "<< presentState<<" , ";
    cout<<"Output = "<<output<<endl;
}

void loop(){
    cout<<"input? :";
    cin>>input;
    
    //next state selector
    nextState=ROM[presentState].nextState[input];
    
    //state register
    presentState=nextState;
    
    //outputs
    output=ROM[presentState].output;
    
    //info
     cout<<"Present State = "<< presentState<<" , ";
    cout<<"Output = "<<output<<endl;
    
}