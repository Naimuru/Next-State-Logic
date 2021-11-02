#include <iostream>
#include <string>
using namespace std;

int input;
string output;

enum state {S0,S1,S2,S3,S4};
state presentState,nextState;

void setup();
void loop();


int main()
{
    setup();
    while(true){
        loop();
    }

    return 0;
}

void setup(){
    presentState=S0; //Nos define el estado inicial
    output="R,B";
    cout<<"Present State = "<<presentState<<" , ";
    cout<<"output = "<<output<<endl;
}

void loop(){
    cout<<"input? :";
    cin>>input;
    
    //Next State Logic (NSL) Se define cada entrada a un estado siguiente
    switch(presentState){
        case S0:
            if(input==4) nextState = S1;
            else if (input==5) nextState = S2;
            else if (input==6) nextState = S3;
            else nextState=S0;
            break;
        case S1:
            if(input==2) nextState = S4;
            else nextState=S1;
            break;
        case S2:
            if(input==7) nextState = S4;
            else nextState=S2;
            break;
        case S3:
            if(input==3) nextState = S2;
            else nextState=S3;
            break;
        case S4:
            if(input==1) nextState = S0;
            else nextState=S4;
            break;    
    }
    
    //state register  (SR) Nos actualiza el siguiente estado
    presentState=nextState;
    
    //Output Logic (OL) Observamos el Output de cada estado
    switch(presentState){
        case S0:
            output="R,B";
            break;
        case S1:
            output="G,Y";
            break;
        case S2:
            output="G";
            break;
        case S3:
            output="Y";
            break;
        case S4:
            output="R,B,G,Y";
            break;    
    }
    
    cout<<"Present State = "<<presentState<<" , ";
    cout<<"Output = "<<output<<endl;
    
}