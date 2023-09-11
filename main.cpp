#include <iostream>
#include <stdlib.h>

using namespace std;

int CalcularLongitud(char cadena[]);
void Problema2();
bool Problema3();
void Problema4();
void Problema5(int num, char *arreglo);
void Problema6();

int main()
{
    //Problema2();
    //cout<<Problema3();
    //Problema4();
    //Aqui comienza el problema 5
    //int num=0;
    //cout<<"Ingrese el numero: "<<endl;
    //cin>>num;
    //char arreglo[num];
    //Problema5(num, arreglo);
    //cout<<arreglo;
    //Aqui termina el problema 5
    //Problema6();
    return 0;
}


int CalcularLongitud(char cadena[]){
    int len=0;
    for(int i=0;cadena[i]!='\0';i++)
    {
        len++;
    }
    return len;

}

void Problema2(){
    char arreglo[200];
    char letras;

    for(int i=0; i<200; i++){
        letras = 65 +rand()%(91-65);
        arreglo[i] = letras;
    }
    cout<<arreglo<<endl;
    //Aquí agregar la segunda parte, donde cuente cuantas veces hay una letra
}

bool Problema3(){
    char cadena1[10];//Hay que pasarlo al main
    char cadena2[10];//Hay que pasarlo al main
    cout<<"Ingrese la primer cadena: "<<endl;//Hay que pasarlo al main
    cin>>cadena1;//Hay que pasarlo al main
    cout<<"Ingrese la segunda cadena: "<<endl;//Hay que pasarlo al main
    cin>>cadena2;//Hay que pasarlo al main
    if(CalcularLongitud(cadena1) == CalcularLongitud(cadena2)){
        for(int i=0; i<CalcularLongitud(cadena1); i++){
            if(cadena1[i] == cadena2[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return false;
    }
}

void Problema4(){
    //Dejarlo solo como función y pasarle la cadena como parámetro
    char cadena[10];//Esto va en el main
    int nuevo=0;
    cout<<"Ingrese la cadena: "<<endl;//Esto va en el main
    cin>>cadena;//Esto va en el main

    for(int i=0; cadena[i]!='\0'; i++){
        nuevo = cadena[i] - 48;
        cout<<nuevo;
    }

}

void Problema5(int num, char *arreglo){
    int i=0;
    int k=0;
    int digitos[10];

    while(num>0){
        digitos[i] = num%10;
        num = num/10;
        i++;
    }

    for(int j=i-1; j>=0; j--){
        arreglo[k]= digitos[j] + 48;
        k++;
    }
}

void Problema6(){
    char cadena[10];
    char nuevaCadena[10];
    cout<<"Ingrese la cadena: "<<endl;
    cin>>cadena;

    for(int i=0; i<sizeof(cadena); i++){
        char caracter= cadena[i];
        if((caracter>=65 && caracter<=90) || (caracter>=97 && caracter<=122)){
            if(caracter>=97){
                caracter-=32;
                nuevaCadena[i] = caracter;
            }
            else{
                nuevaCadena[i] = caracter;
            }
        }
        else{
            nuevaCadena[i] = caracter;
        }
    }
    cout<<nuevaCadena<<endl;
}






















