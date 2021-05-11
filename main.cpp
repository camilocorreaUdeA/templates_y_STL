// E J E M P L O :
/*
Diseñe e implemente una función que tenga como parametro de entrada una frase (cadena de texto)
y retorne la palabra de esa frase que tenga la mayor cantidad de letras repetidas. Si no hay palabras
con letras repetidas entonces debe retornar la palabra "cero". La frase debe estar conformada por
una palabra por lo menos, pero en general, deben ser varias palabras separadas por espacios.

Bienvenido al mundo  -> Bienvenido
Me gusta programar en C++ -> programar
Hola amigos -> cero
*/

/*
Solucion:
1. Separar las palabras
2. Contar las ocurrencias de cada letra en la palabra
3. Registrar cual es la palabra con más letras repetidas
4. Retornar esa palabra registrada
*/

#include<iostream>
#include<string>
#include<istream>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

template<typename T, typename V>
pair<T,V> obtenerParConMayorValor(const map<T,V>& p){
    return *max_element(p.begin(),p.end(),[](const pair<T,V>& p1, const pair<T,V>& p2){return p1.second < p2.second;});
}

string palabraConMasLetrasRepetidas(string str){
    istringstream ss(str);
    string palabra;
    map<string, map<char,int>> cuentaLetrasPalabraFrase;

    while(ss >> palabra){
        for(auto letra : palabra)
            cuentaLetrasPalabraFrase[palabra][letra]++;
    }

    auto maxRepeticionActual = 1;
    string palabraActual;

    for(auto palabra : cuentaLetrasPalabraFrase){
        auto parMasRepeticiones = obtenerParConMayorValor(palabra.second);
        if(parMasRepeticiones.second > maxRepeticionActual){
            maxRepeticionActual = parMasRepeticiones.second;
            palabraActual = palabra.first;
        }
    }

    if(maxRepeticionActual == 1)
        return "cero";

    return palabraActual;
}

int main(){
    cout<<"Ingrese una frase: "<<endl;
    string frase;
    getline(cin, frase);
    cout<<palabraConMasLetrasRepetidas(frase)<<endl;
    return 0;
}


