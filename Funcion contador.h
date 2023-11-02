#ifndef FUNCION_CONTADOR_H_INCLUDED
#define FUNCION_CONTADOR_H_INCLUDED
int contador(int dado[6], int puntaje){
    int acumulador[6]={0,0,0,0,0,0}, result=0, mult=0;
    bool escalera=true;
    for(int i=0;i<=5;i++){
        switch(dado[i]){
            case 1:
                acumulador[0]+=1;
                ;break;
            case 2:
                acumulador[1]+=1;
                ;break;
            case 3:
                acumulador[2]+=1;
                ;break;
            case 4:
                acumulador[3]+=1;
                ;break;
            case 5:
                acumulador[4]+=1;
                ;break;
            case 6:
                acumulador[5]+=1;
                ;break;
        }
    }
     for(int i=0;i<=5;i++){
        if(acumulador[i]>1){
            escalera=false;
        }
    }
    for(int i=0;i<=5;i++){
        if(acumulador[i]<3){
            result+=dado[i];
        }
        if(acumulador[i]>2 && acumulador[i]<6 && dado[i]>mult){
            mult=dado[i];
        }
        if(acumulador[i]==6 && acumulador[i]!=acumulador[5]){
            return dado[i]*50+puntaje;
        }
    }

    if(escalera){
        return 500;
    }
    else if(acumulador[5]==6){
        return 0;
    }
    else if(mult!=0){
        return mult*10+puntaje;
    }
    else{
        return result+puntaje;
        }
    }

#endif // FUNCION_CONTADOR_H_INCLUDED
