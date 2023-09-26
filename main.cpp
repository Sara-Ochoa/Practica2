#include <iostream>
#include <time.h>
#include <map>

using namespace std;
map<char, int> romanos;

void MenuPrincipal();
int CalcularLongitud(char cadena[]);
void Problema1();
void Problema2();
bool Problema3();
int Problema4();
void Problema5(int num, char *arreglo);
void Problema6();
void Problema7();
void Problema8();
void Problema9();
void Problema10();
int Rom_Ara(char num[]);
int Potencia(int base, int exp);

int main()
{
    int opcion=1;
    while(opcion!=0){
        MenuPrincipal();
        cin>>opcion;
        switch (opcion) {
        case 1:
            Problema1();
            break;
        case 2:
            srand(time(NULL));
            Problema2();
            //Hay que arreglar que no se repitan las letras ya impresas
            break;
        case 3:
        {
            int valor = Problema3();
            if(valor==1){
                cout<<"Las dos cadenas son iguales"<<endl;
            }
            else{
                cout<<"Las dos cadenas son diferentes"<<endl;
            }
            break;
        }
        case 4:
        {
            int numero=Problema4();
            cout<<"Ahora vamos a multiplicar ese numero por dos."<<endl;
            cout<<"El resultado es: "<<numero*2<<endl;

            break;
        }
        case 5:
        {
            int num=0;
            cout<<"Ingrese el numero: "<<endl;
            cin>>num;
            char arreglo[5];
            Problema5(num, arreglo);//Hay que ponerle un & que significa la dirección de eso
            cout<<arreglo;
            break;
        }
        case 6:
            Problema6();
            break;
        case 7:
            Problema7();
            break;
        case 8:
            Problema8();
            break;
        case 9:
            Problema9();
            break;
        case 10:
            Problema10();
            break;
        default:
            if(opcion!=0)
                cout<<"La opcion no valida"<<endl;
            break;
        }
    }
    return 0;
}

void MenuPrincipal(){
    cout<<endl;
    cout<<"*********** Menu practica 2 ***********"<<endl;
    cout<<endl;
    cout<<"Seleccione una opcion del 1 al 10"<<endl;
    cout<<endl;
}


int CalcularLongitud(char cadena[]){
    int len=0;
    for(int i=0;cadena[i]!='\0';i++)
    {
        len++;
    }
    return len;

}

void Problema1(){
    int cantidad=0;
    int billetesModenas[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int num=0;
    cout<<"Ingrese la cantidad: ";
    cin>>cantidad;
    for (int i=0;i<10; i++)
    {
        num=cantidad/billetesModenas[i];
        cantidad %=billetesModenas[i];
        cout<<billetesModenas[i]<<": "<<num<<endl;
    }

    cout<<"Faltante: "<<cantidad<<endl;
}




void Problema2(){
    char arreglo[200];//El arreglo debe ser de 200
    char cr;
    char letras;

    for(int i=0; i<200; i++){
        letras = 65 +rand()%(91-65);
        arreglo[i] = letras;
    }
    cout<<arreglo<<endl;
    for(int i=0; i<CalcularLongitud(arreglo); i++){
        int cont=0;
        cr=arreglo[i];
        for(int j=0; j<CalcularLongitud(arreglo); j++){
            if(arreglo[j]==cr){
                cont +=1;
            }
        }
        cout<<cr<<": "<<cont<<endl;
    }

}

bool Problema3(){
    char cadena1[10];
    char cadena2[10];
    cout<<"Ingrese la primer cadena: "<<endl;
    cin>>cadena1;
    cout<<"Ingrese la segunda cadena: "<<endl;
    cin>>cadena2;
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

int Problema4(){
    char cadena[10];
    int nuevo=0;
    int num=0;
    cout<<"Ingrese la cadena: "<<endl;
    cin>>cadena;

    for(int i=0; cadena[i]!='\0'; i++){
        nuevo = cadena[i] - 48;
        num = num * 10;
        num += nuevo;
    }
    return num;
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
    int i, j,k=0;
    cout<<"Ingrese la cadena: "<<endl;
    cin>>original;

    while(i<sizeof(original)-1){
        ele=original[i];
        if(ele>=49 && ele<=57){
            numeros[j]=ele;
            j++;
        }
        else{
            texto[k]=ele;
            k++;
        }
        i++;
    }

    cout<<"Original: "<<original<<"."<<endl;
    cout<<"Texto: "<<texto<<". Numero: "<<numeros<<"."<<endl;

}

void Problema9(){
    char cadena[10];
    int nuevo=0;
    int num=0;
    int numero=0;
    int suma=0;
    cout<<"Ingrese la cadena: "<<endl;
    cin>>cadena;
    cout<<"Ingrese el numero para las separaciones: "<<endl;
    cin>>numero;

    for(int i=0; cadena[i]!='\0'; i++){
        nuevo = cadena[i] - 48;
        num = num * 10;
        num += nuevo;
    }

    int divisor=Potencia(10, numero);

    while(num>0){
        suma += num% divisor;
        num = num/divisor;
    }
    cout<<"Orignal: "<<cadena<<". Suma: "<<suma<<"."<<endl;
}


int Potencia(int base, int exp){
    int x=1;
    for(int i=0; i<exp; i++){
        x *= base;
    }
    return x;
}


void Problema10(){
    romanos['I']=1;
    romanos['V']=5;
    romanos['X']=10;
    romanos['L']=50;
    romanos['C']=100;
    romanos['D']=500;
    romanos['M']=1000;
    char num[10];

    cout<<"Ingrese los numeros romanos (M-D-C-L-X-V-I): "<<endl;
    cin>>num;
    cout<<"El numero ingresado fue: "<<num<<" Que corresponde a: "<<Rom_Ara(num)<<endl;
}

int Rom_Ara(char num[]){
    int resFinal=0;
    int tamano= sizeof(num);

    for(int i=0; i<tamano; i++){
        if(i+1<tamano && romanos[num[i]] < romanos[num[i+1]]){ //IV
            resFinal += (romanos[num[i+1]] - romanos[num[i]]); //5-1 = 4
            i++;
        }
        else{
            resFinal +=romanos[num[i]];
        }
    }
    return resFinal;
}


///////////////////////////////////////////////////////////////////////////////////////7
//COGIDOS EN ARDUINO


//PUNTO 1
/*
long billetesModenas[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
long cantidad=0;
char caracteres[10];
int num=0;
int nuevo=0;


void setup()
{
  Serial.begin(9600);
  Serial.println("Ingrese la cantidad: ");
}

void loop()
{
  if(Serial.available()>0){
    while(Serial.available()){
        Serial.readBytesUntil('\n', caracteres, 10);
    }
    Serial.println(caracteres);

    for(int i=0; caracteres[i]!='\0'; i++){
        nuevo = caracteres[i] - 48;
        cantidad = cantidad * 10;
        cantidad += nuevo;
    }

    for (int i=0;i<10; i++)
    {
        num=cantidad/billetesModenas[i];
        cantidad %=billetesModenas[i];
        Serial.print(billetesModenas[i]);
        Serial.print(": ");
        Serial.print(num);
        Serial.println();
    }

    Serial.print("Faltante: ");
    Serial.print(cantidad);
  }
}
*/


//PUNTO 6
/*
char cadena[20];
char nuevaCadena[20];

void setup()
{
    Serial.begin(9600);
    Serial.println("Ingrese la cadena: ");
}

void loop()
{
    if(Serial.available()>0){
        for(int i=0; i<sizeof(cadena); i++){
        cadena[i]='\0';
        }
        while(Serial.available()){
            Serial.readBytesUntil('\n', cadena, 20);
        }
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
        Serial.print("Original: ");
        Serial.print(cadena);
        Serial.print(". En mayuscula: ");
        Serial.print(nuevaCadena);
        Serial.println();
    }
}
*/

//PUNTO 10
/*
int valor[10];
char num[10];
int tamano=sizeof(num);

void setup()
{
  Serial.begin(9600);
  Serial.println("Ingrese los numeros romanos (M-D-C-L-X-V-I): ");
}

void loop()
{
  if(Serial.available()>0){
    int resFinal=0;
    while(Serial.available()){
        Serial.readBytesUntil('\n', num, 10);
    }

    for(int i=0; i<tamano; i++){
      if(num[i]=='I'){
        valor[i]=1;
      }
      if(num[i]=='V'){
        valor[i]=5;
      }
      if(num[i]=='X'){
        valor[i]=10;
      }
      if(num[i]=='L'){
        valor[i]=50;
      }
      if(num[i]=='C'){
        valor[i]=100;
      }
      if(num[i]=='D'){
        valor[i]=500;
      }
      if(num[i]=='M'){
        valor[i]=1000;
      }
    }

    for(int i=0; i<tamano; i++){
      if(i==tamano-1){
        resFinal += valor[i];
      }
      else{
        if(valor[i] >= valor[i+1]){
            resFinal += valor[i];
        }
        else{
            resFinal -= valor[i];
        }
      }
    }


    Serial.print("El numero ingresado fue: ");
    Serial.print(num);
    Serial.print(" Que corresponde a: ");
    Serial.print(resFinal);
    Serial.println();

  }
}
*/








