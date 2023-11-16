#include <iostream>
#include "rlutil.h"
#include "Funcion contador.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

//Funcion que recibe el vector "dado" de la funcion main, genera 6 numeros aleatoreios y los reemplaza por cada indice del vector.
int tirarDados(int dado[6]) {
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        dado[i] = 1 + (rand() % 6);
    }
    return 0;
}

//FUNCION "GENERAR DADOS": Recibe como parametro un int para posteriormente verificar que numero es entre 1-6 y dependiendo del resultado hace un cout
//de el numero de dado correspondiente y ademas de un color especifico.
void generarDado(int numero) {
    //Variable para generar un cuadrado en caracteres ASCII
    char C = 254;

    if(numero == 1) { //Condicional para asignar un color al dado dependiendo de su numero.
        rlutil::setColor(rlutil::RED);
    }
    else if (numero == 2) {
        rlutil::setColor(rlutil::YELLOW);
    }
    else if (numero == 3) {
        rlutil::setColor(rlutil::GREEN);
    }
    else if (numero == 4) {
        rlutil::setColor(rlutil::BLUE);
    }
    else if (numero == 5) {
        rlutil::setColor(rlutil::LIGHTMAGENTA);
    }
    else if (numero == 6) {
        rlutil::setColor(rlutil::MAGENTA);
    }

    switch (numero) { //switch que verifica el valor del dado y luego hace un cout de dicho dado
        case 1:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl
                 << C << C << C << C << " " << " " << C << C << C << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        case 2:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        case 3:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << " " << " " << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << C << C << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        case 4:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        case 5:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << "  " << C << C << C << C << endl
                 << C << " " << " " << C << C << C << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        case 6:
            cout << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << "  " << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl
                 << C << " " << " " << C << "  " << C << " " << " " << C << endl
                 << C << C << C << C << C << C << C << C << C << C << endl;
            break;
        default:
            break;
    }

    cout<<endl<<endl;
}


int main(){

    int cantjug, dado[6], puntaje1 = 0, puntaje2 = 0;
    char p1[256], p2[256];
    cout<<"==================================="<<endl;
    cout<<"Bienvenido a ";
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"QUINIENTOS O ESCALERA"<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"Ingrese la cantidad de jugadores: ";
    cin>>cantjug;
    cout<<"==================================="<<endl;

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
        break;

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
        break;

        default:cout<<endl;
            rlutil::setColor(rlutil::RED);
            cout<<"ERROR: ingrese una cantidad de jugador valida (Entre 1 y 2)."<<endl;
            rlutil::setColor(rlutil::WHITE);
            return 0;
        break;
    }
    //Aca comienza el juego (musica dramatica)
    int ronda = 0, lanz = 3, lanz2 = 3, l;

    while(puntaje1 < 500 && puntaje2 < 500) {
        ronda++;
        rlutil::setColor(rlutil::BLUE);
        cout<<"=========================================="<<endl;
        cout<<"RONDA NUMERO "<<ronda<<endl<<endl;
        if (cantjug == 2) {
            cout<<"Turno de "<<p1<<endl;
        }
        cout<<"Presione cualquier tecla para proseguir..."<<endl;
        cout<<"=========================================="<<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        rlutil::cls();

        //Turno del primer jugador
        for (l = 1; l <= 3; l++){
            if (puntaje1 < 500) {
                cout<<"-----------------------------------------------"<<endl;
                cout<<"Lanzamiento "<< l <<endl;
                cout<<"Presione cualquier tecla para arrojar los dados..."<<endl;
                cout<<"-----------------------------------------------"<<endl;
                rlutil::anykey();

                tirarDados(dado);
                
                for (int i = 0; i < 6; i++) { // Este bucle itera sobre los dados y ejecuta la funcion generarDado que muestra por consola cada dado
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

                puntaje1 = contador(dado, puntaje1);
                cout<<"---------------------------------------"<<endl;
                cout<<"Puntaje total de "<<p1<<": "<<puntaje1<<endl;
                cout<<"---------------------------------------"<<endl;
                rlutil::anykey();
                rlutil::cls();
            }
            else {
                lanz = l - 1;
                cout<<"FELICIDADES has superado los 500 puntos en el lanzamiento "<< lanz <<" de la ronda "<<ronda<<endl;
                rlutil::anykey();
                rlutil::cls();
                l = 4;
            }
        }

        if (cantjug == 2 ) {
            //Turno del segundo jugador
            rlutil::setColor(rlutil::RED);
            cout<<"=========================================="<<endl;
            cout<<"RONDA NUMERO "<<ronda<<endl<<endl;
            cout<<"Turno de "<<p2<<endl;
            cout<<"Presione cualquier tecla para proseguir..."<<endl;
            cout<<"=========================================="<<endl;
            rlutil::setColor(rlutil::WHITE);
            rlutil::anykey();
            rlutil::cls();
            for(l=1;l<=3;l++) {
                if(puntaje2 < 500) {
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"Lanzamiento "<<l<<endl;
                    cout<<"Presione cualquier tecla para arrojar los dados..."<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    rlutil::anykey();

                    tirarDados(dado);

                    for (int i = 0; i < 6; i++) {
                        switch (dado[i]) {
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
                    rlutil::cls();
                }
                else {
                    lanz2 = l - 1;
                    cout<<"FELICIDADES has superado los 500 puntos en el lanzamiento "<<lanz2<<" de la ronda "<<ronda<<endl;
                    rlutil::anykey();
                    rlutil::cls();
                    l = 4;
                }
            }
        }

        if (cantjug == 2) {
            cout<<"========================="<<endl;
            cout<<"RONDA: "<<ronda<<endl;
            cout<<"PUNTOS DE "<<p1<<": "<<puntaje1<<endl;
            cout<<"PUNTOS DE "<<p2<<": "<<puntaje2<<endl<<endl;
            cout<<"Presione para continuar..."<<endl;
            cout<<"========================="<<endl;
            rlutil::anykey();
            rlutil::cls();
        }
        else {
            cout<<"========================="<<endl;
            cout<<"RONDA: "<<ronda<<endl;
            cout<<"PUNTOS DE "<<p1<<": "<<puntaje1<<endl;
            cout<<"Presione para continuar..."<<endl;
            cout<<"========================="<<endl;
            rlutil::anykey();
            rlutil::cls();
        }
    }

    if (cantjug == 2) {
        if (puntaje1 >= 500 && puntaje2 >= 500) { // Caso en que los dos jugadores superen los 500 en la misma ronda.
            if (lanz < lanz2) {
                rlutil::setColor(rlutil::YELLOW);
                cout<<"EL GANADOR ES "<<p1<<endl;
                rlutil::setColor(rlutil::WHITE);
            }
            else if (lanz2 < lanz) {
                rlutil::setColor(rlutil::YELLOW);
                cout<<"EL GANADOR ES "<<p2<<endl;
                rlutil::setColor(rlutil::WHITE);
            }
            else {
                cout<<"Se llego a empate... �revancha?"<<endl;
            }
        }
        else if (puntaje1 >= 500) {
            rlutil::setColor(rlutil::YELLOW);
            cout<<"EL GANADOR ES "<<p1<<endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else if (puntaje2 >= 500) {
            rlutil::setColor(rlutil::YELLOW);
            cout<<"EL GANADOR ES "<<p2<<endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else {
            rlutil::setColor(rlutil::RED);
            cout<<"¡Uh oh! Hubo un percanse inesperado. Consulte a su programador de confianza."<<endl;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    else if(cantjug == 1 && puntaje1 >= 500) {
        rlutil::setColor(rlutil::YELLOW);
        cout<<"FELICIDADES "<<p1<<" GANASTE EN QUINIENTOS O ESCALERA"<<endl<<"Invita a un amigo para jugar el modo 2 jugadores y mas diversion!!!"<<endl;
        rlutil::setColor(rlutil::WHITE);
    }
    return 0;
}
