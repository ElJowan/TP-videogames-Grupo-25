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

void generarDado(int numero) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if(numero == 1 && ((j == 4 || j == 5) && i == 2)) {
                cout<<" ";
            } 
            else if (numero == 2 && ((i == 1 && (j == 7 || j == 8)) || (i == 3 && (j == 1 || j == 2)))) {
                cout<<" ";
            }
            else if (numero == 3 && (((i == 1 && (j == 7 || j == 8)) || (i == 3 && (j == 1 || j == 2))) || ((j == 4 || j == 5) && i == 2))) {
                cout<<" ";
            }
            else if (numero == 4 && (((i == 1 || i == 3) && (j == 7 || j == 8)) || ((i == 1 || i == 3) && (j == 1 || j == 2)))) {
                cout<<" ";
            }
            else if (numero == 5 && ((((i == 1 || i == 3) && (j == 7 || j == 8)) || ((i == 1 || i == 3) && (j == 1 || j == 2))) || ((j == 4 || j == 5) && i == 2))) {
                cout<<" ";
            }
            else if(numero == 6 && ((i == 1 && (j == 1 || j == 2 || j == 4 || j == 5 || j == 7 || j == 8)) || (i == 3 && (j == 1 || j == 2 || j == 4 || j == 5 || j == 7 || j == 8)))) {
                cout<<" ";
            }
            else {
                numero == 1 ? rlutil::setColor(rlutil::MAGENTA) : 
                numero == 2 ? rlutil::setColor(rlutil::GREEN) :
                numero == 3 ? rlutil::setColor(rlutil::RED) :
                numero == 4 ? rlutil::setColor(rlutil::LIGHTCYAN) :
                numero == 5 ? rlutil::setColor(rlutil::BROWN) :
                numero == 6 ? rlutil::setColor(rlutil::BLUE) : rlutil::setColor(rlutil::CYAN);

                cout<<static_cast<char>(254);
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
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
        switch (dado[i])
        {
        case 1:
            generarDado(1);
            break;
        case 2:
            generarDado(2);
            break;
        case 3:
            generarDado(3);
            break;
        case 4:
            generarDado(4);
            break;
        case 5:
            generarDado(5);
            break;
        case 6:
            generarDado(6);
            break;

        default:
            break;
        }
    }
    

    cout<<contador(dado, 0);
    return 0;
}
