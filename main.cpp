#include <iostream>
#include <time.h>

using namespace std;

int CalcularLongitud(char cadena[]);
void Problema2();
bool Problema3();
void Problema4();
void Problema5(int num, char *arreglo);
void Problema6();
void Problema7();
void Problema8();

int main()
{
    //srand(time(NULL));
    //Problema2();

    //cout<<Problema3();

    //Problema4();

    /*//Aqui comienza el problema 5
    int num=0;
    cout<<"Ingrese el numero: "<<endl;
    cin>>num;
    char arreglo[5];
    Problema5(num, arreglo);//Hay que ponerle un & que significa la dirección de eso
    cout<<arreglo;
    //Aqui termina el problema 5*/

    //Problema6();

    //Problema7();

    Problema8();
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
    char arreglo[5];//El arreglo debe ser de 200
    char cr;
    char letras;

    for(int i=0; i<5; i++){
        letras = 65 +rand()%(91-65);
        arreglo[i] = letras;
    }
    cout<<arreglo<<endl;
    //Aquí agregar la segunda parte, donde cuente cuantas veces hay una letra
    for(int i=0; i<sizeof(arreglo); i++){
        int cont=0;
        cr=arreglo[i];
        for(int j=0; j<sizeof(arreglo); j++){
            if(arreglo[j]==cr){
                cont +=1;
            }
        }
        cout<<cr<<": "<<cont<<endl;
    }

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
    char cadena[5];//Esto va en el main
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
        arreglo[k]= digitos[j] + 48;//El profe dijo que hay que ponerle siempre el *
        k++;
    }
}

void Problema6(){
    char cadena[20];
    char nuevaCadena[20];
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
    cout<<"Original: "<<cadena<<". En mayuscula: "<<nuevaCadena<<"."<<endl;
}

void Problema7(){
    char palabra[10];
    cout<<"Ingrese la palabra: "<<endl;
    cin>>palabra;
    int len=sizeof(palabra)/sizeof(palabra[0]);//tamaño del arreglo

    cout<<"Original: "<<palabra;
    for(int i =0; i<len; i++){//Recorrer todo el arreglo
        int j=i+1;//Verificar si el elemento actual está repetido y solose busca a la derecha del arreglo
        while(j<len){
            if(palabra[i]==palabra[j]){//Significa que si hay un elemento repetido
                for(int k=j; k<len-1; k++){
                    palabra[k]=palabra[k+1];
                }
                len--;//se le resta una casilla del arreglo por ese elemento repetido
            }
            else{
                j++;//Si no hay repetidos, simplemente pasa al siguiente elemento
            }
        }
    }

    cout<<". Sin repetidos: "<<palabra<<endl;

}

void Problema8(){
    char original[10];
    char texto[10];
    char numeros[10];
    char ele;
    cout<<"Ingrese la cadena: "<<endl;
    cin>>original;
    for(int i=0; i<CalcularLongitud(original); i++){
        ele = original[i];
        if((ele>=65 && ele<=90) || (ele>=97 && ele<=122)){
            texto[i]=ele;
        }
        else{//DUDA:Necesariamente no tiene que ser numero los demas caracteres, entonces hay que hacer 2 condiciones
            numeros[i-1]=ele;
        }
    }
    cout<<"Original:"<<original<<endl;
    cout<<"Texto:"<<texto<<"."<<"Numero:"<<numeros<<endl;

}


















