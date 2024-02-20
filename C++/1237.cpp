#include <iostream>
#include <utility>
#include <string>

using namespace std;


int compararTextos(pair<string, string>);

int main(){
    while(true){
        pair<string, string> textos;
        getline(cin, textos.first);
        getline(cin, textos.second);

        cout << compararTextos(textos) << endl;
    }
}

void consumir(){

}

int compararTextos(pair<string, string> textos){
    int tamAtual = 0;
    int tamMax = 0;
    int posA=0;
    int posB=0;
    while ( (posA <= textos.first.size() - 1) || (posA <= textos.first.size() - 1) ){
        if (textos.first[posA] == textos.second[posB]){
            if (posA <= textos.first.size() - 1)
                posA++;
            if (posB <= textos.second.size() - 1)
                posB++;
            tamAtual++;
            if (tamMax < tamAtual){
                tamMax = tamAtual;
            }
        }
        else{
            if (posB < textos.second.size() - 1)
                posB++;
            else{
                posB = 0;
                posA++;
            }
            tamAtual = 0;
            
        }
        
    }
    return tamMax;

}