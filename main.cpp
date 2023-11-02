#include <iostream>
#include "rlutil.h"
#include "Funcion contador.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int tirarDados(int dado[6]){
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        dado[i]=1+(rand()%6);
    }
    return 0;
}

int contador(int[6]);

int main(){
    int cantjug, dado[6], puntaje1, puntaje2;
    char p1[256], p2[256];
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
    
    tirarDados(dado);

    for (int i = 0; i < 6; i++)
    {
        cout<<dado[i]<<endl;
    }
    

    cout<<contador(dado, 0);
    return 0;
}
