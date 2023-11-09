#include <iostream>
#include "rlutil.h"
#include "Funcion contador.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
//Numeros aleatorios
int tirarDados(int dado[6]){
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        dado[i]=1+(rand()%6);
    }
    return 0;
}
//Darle forma a los dados
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
                if(numero == 1){rlutil::setColor(rlutil::MAGENTA);}
                else if(numero == 2){rlutil::setColor(rlutil::GREEN);}
                else if(numero == 3){rlutil::setColor(rlutil::RED);}
                else if(numero == 4){rlutil::setColor(rlutil::LIGHTCYAN);}
                else if(numero == 5){rlutil::setColor(rlutil::BROWN);}
                else if(numero == 6){rlutil::setColor(rlutil::BLUE);}
                    else{rlutil::setColor(rlutil::CYAN);}

                cout<<static_cast<char>(254);
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int contador(int[6]);

int main(){

    int cantjug, dado[6], puntaje1=0, puntaje2=0;
    char p1[256], p2[256];
    cout<<"Bienvenido a ";
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"QUINIENTOS O ESCALERA"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"Ingrese la cantidad de jugadores: ";
    cin>>cantjug;

    //cantidad de jugadores
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
    //Aca comienza el juego (musica dramatica)
    int ronda=0, lanz=3, lanz2=3, l;
    while(puntaje1<500 && puntaje2<500){
            ronda++;
            cout<<"=========================================="<<endl;
            cout<<"RONDA NUMERO "<<ronda<<endl<<endl;
            cout<<"Turno de "<<p1<<endl;
            cout<<"Presione cualquier tecla para proseguir..."<<endl<<endl;
            cout<<"=========================================="<<endl;
            rlutil::anykey();
            rlutil::cls();

            //Turno del primer jugador
            for(l=1;l<=3;l++){
                    if(puntaje1<500){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"Lanzamiento "<<l<<endl;
                cout<<"Presione cualquier tecla para arrojar los dados..."<<endl;
                cout<<"-----------------------------------------------"<<endl;
                rlutil::anykey();

                tirarDados(dado);

                for (int i = 0; i < 6; i++){
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
                        rlutil::setColor(rlutil::WHITE);
                    }

                    puntaje1=contador(dado, puntaje1);
                    cout<<"---------------------------------------"<<endl;
                    cout<<"Puntaje total de "<<p1<<": "<<puntaje1<<endl;
                    cout<<"---------------------------------------"<<endl;
                    rlutil::anykey();
                    rlutil::cls();}
                    else{
                        lanz=l-1;
                        cout<<"FELICIDADES has superado los 500 puntos en el lanzamiento "<<lanz<<" de la ronda "<<ronda<<endl;
                        rlutil::anykey();
                        rlutil::cls();
                        l=4;
                    }
                    }

                    //Turno del segundo jugador
                cout<<"=========================================="<<endl;
                cout<<"RONDA NUMERO "<<ronda<<endl<<endl;
                cout<<"Turno de "<<p2<<endl;
                cout<<"Presione cualquier tecla para proseguir..."<<endl<<endl;
                cout<<"=========================================="<<endl;
                rlutil::anykey();
                rlutil::cls();
                     for(l=1;l<=3;l++){
                            if(puntaje2<500){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"Lanzamiento "<<l<<endl;
                cout<<"Presione cualquier tecla para arrojar los dados..."<<endl;
                cout<<"-----------------------------------------------"<<endl;
                rlutil::anykey();

                tirarDados(dado);

                for (int i = 0; i < 6; i++){
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
                        rlutil::setColor(rlutil::WHITE);
                    }

                    puntaje2=contador(dado, puntaje2);
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"Puntaje de total de "<<p2<<": "<<puntaje2<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    rlutil::anykey();
                    rlutil::cls();}
                    else{
                        lanz2=l-1;
                        cout<<"FELICIDADES has superado los 500 puntos en el lanzamiento "<<lanz2<<" de la ronda "<<ronda<<endl;
                        rlutil::anykey();
                        rlutil::cls();
                        l=4;
                    }
                    }
    cout<<"========================="<<endl;
    cout<<"RONDA: "<<ronda<<endl;
    cout<<"PUNTOS DE "<<p1<<": "<<puntaje1<<endl;
    cout<<"PUNTOS DE "<<p2<<": "<<puntaje2<<endl<<endl;
    cout<<"Prsione para continuar..."<<endl;
    cout<<"========================="<<endl;
    rlutil::anykey();
    rlutil::cls();
    }

    if(puntaje1>=500 && puntaje2>=500){
        if(lanz<lanz2){
            cout<<"EL GANADOR ES "<<p1<<endl;
        }
        else if(lanz2<lanz){
            cout<<"EL GANADOR ES "<<p2<<endl;
        }
        else{
            cout<<"Se llego a empate"<<endl;
        }
    }
    else if(puntaje1>=500){
         cout<<"EL GANADOR ES "<<p1<<endl;
    }
    else if(puntaje2>=500){
         cout<<"EL GANADOR ES "<<p2<<endl;
    }
    else{
        rlutil::setColor(rlutil::RED);
        cout<<"HTTPS STATUS CODE 418"<<endl;
        rlutil::setColor(rlutil::WHITE);

    }
    return 0;
}
