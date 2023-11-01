#include <iostream>
#include "rlutil.h"

using namespace std;

int main(){
    int cantjug;
    char p1[0], p2[0];
    cout<<"Bienvenido a ";
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"QUINIENTOS O ESCALERA"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"Ingrese la cantidad de jugadores: ";
    cin>>cantjug;

    switch(cantjug){
    case 1:cout<<endl;
           cout<<"------------------------------"<<endl;
           rlutil::setColor(rlutil::BLUE);
           cout<<"Ingrese nombre del jugador: "<<endl;
           cin>>p1;
           rlutil::setColor(rlutil::WHITE);
           cout<<"------------------------------"<<endl;
           cout<<endl;
           rlutil::anykey();
           rlutil::cls();
           ;break;

    case 2:cout<<endl;
           cout<<"------------------------------"<<endl;
           rlutil::setColor(rlutil::BLUE);
           cout<<"Ingrese nombre del jugador 1: "<<endl;
           cin>>p1;
           rlutil::setColor(rlutil::WHITE);
           cout<<endl;
           rlutil::setColor(rlutil::GREEN);
           cout<<"Ingrese nombre del jugador 2: "<<endl;
           cin>>p2;
           rlutil::setColor(rlutil::WHITE);
           cout<<"------------------------------"<<endl;
           cout<<endl;
           rlutil::anykey();
           rlutil::cls();
           ;break;
    default:cout<<endl;
            rlutil::setColor(rlutil::RED);
            cout<<"ERROR 418"<<endl;
            rlutil::setColor(rlutil::WHITE);
            return 0;
            ;break;
    }
    cout<<"Hola "<<p1<<endl;
    cout<<"Hola "<<p2<<endl;
    return 0;
}
