#ifndef FUNCION_CONTADOR_H_INCLUDED
#define FUNCION_CONTADOR_H_INCLUDED

int contador(int dado[6], int puntaje) {
    //El vector acumulador cuenta la cantidad de veces que se repite un numero en el dado cada posicion de el 0 al 5 le corresponde a un numero de dado.
    //EJ: si hay dos dados con el numero 1, entonces el indice 0 de acumulador va a ser 2, ya que el indice 0 corresponde al numero 1 y es 2 ya que
    //    este numero se repite 2 veces
    int acumulador[6] = {0, 0, 0, 0, 0, 0}, result = 0, mult = 0;
    bool escalera = true;

    for(int i = 0; i < 6; i++) { //Este bucle sirve para 
        switch(dado[i]) {
            case 1:
                acumulador[0] += 1;
                break;

            case 2:
                acumulador[1] += 1;
                break;

            case 3:
                acumulador[2] += 1;
                break;

            case 4:
                acumulador[3] += 1;
                break;

            case 5:
                acumulador[4] += 1;
                break;

            case 6:
                acumulador[5] += 1;
                break;
        }
    }

    for (int i = 0; i < 6; i++) { //Si un numero se repite 2 veces o mas, quiere decir que no hay escalera, por lo tanto la variable escalera se cambia a false y si no, se queda en true.
        if(acumulador[i] > 1) {
            escalera = false;
            i = 6;
        }
    }

    for (int i = 0; i <= 5; i++) {
        if (acumulador[i] < 3) { //Verifica si el dado es menor a 3, si es menor, se suma a la variable result.
            result += dado[i];
        }
        if (acumulador[i] > 2 && acumulador[i] < 6 && i + 1 > mult) { //Si un numero se repite de 3 a 5 veces, lo guarda en la variable mult y si encuentra otro numero mas grande, guarda el mas grande.
            mult = i + 1;
        }
        if (acumulador[i] == 6 && acumulador[i] != acumulador[5]) { //Si un numero que no sea el 6 se repite 6 veces, retorna ese numero multiplicado por 50 sumado a tu puntaje
            return ((i + 1) * 50) + puntaje;
        }
    }

    if (escalera) { //Si escalera es true, te devuelve 500 (Osea ganas automaticamente)
        return 500;
    }
    else if (acumulador[5] == 6) { //Si hay 6 dados de numero 6, la funcion retorna 0, por lo tanto perdiste todos tus puntos.
        return 0;
    }
    else if (mult != 0) { //Si la variable "mult" no es 0, significa que hay un numero que se repite de 3 a 5 veces. Entonces te devuelve ese numero multiplicado por 10 sumado a tu puntaje.
        return mult * 10 + puntaje;
    }
    else { //Si no se cumple ninguna condicion, entonces te retorna la variable "result" (Todos los numeros sumados) sumado a tu puntaje.
        return result + puntaje;
    }
}

#endif // FUNCION_CONTADOR_H_INCLUDED
