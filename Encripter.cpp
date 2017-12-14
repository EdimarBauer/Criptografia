#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const string param = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&*()-_=+[]{}~^;:.,<>/?|Á« ";

int posicao(char c){

    for (int i = 0; i < param.length(); i++){
        if (param[i] == c)
            return i;
    }

    printf("Caracter %c invalido\n", c);
    system("pause");

    return 0;
}

string encriptar(string chave){

    string entrada;
    puts("Digite o texto");
    getline(cin, entrada);

    int j = 0;
    string result = "";
    for (int i = 0; i < entrada.length(); i++){
        result += param[(posicao(entrada[i]) + posicao(chave[j]) ) % param.length()];
        if (++j == chave.length()) j = 0;
    }

    return result;
}

string desencriptar(string chave){

    puts("Digite o texto encriptado");
    string entrada;
    getline(cin, entrada);

    int j = 0;
    string result = "";
    for (int i = 0; i < entrada.length(); i++){
        int pos = posicao(entrada[i]) - posicao(chave[j]);
        if (++j == param.length()) j = 0;
        if (pos < 0) pos += param.length();
        result += param[pos];
    }

    return result;
}

string trocarChave(){

    puts("Digite a nova chave");
    string entrada;
    getline(cin ,entrada);

    return entrada;
}

int main(){

    string chave = "Digite aqui sua chave";
    string s;
    char c, d;

    while(1){
        puts("1: Encriptar\n2: Desencriptar\n3: Trocar chave");
        do{
            cin >> c;
        }while(c != '1' and c != '2' and c != '3');
        scanf("%c", &d);

        string s;
        switch(c){
        case '1':
            s = encriptar(chave);
            break;
        case '2':
            s = desencriptar(chave);
            break;
        case '3':
            s = trocarChave();
        }

        cout << s << "\n\n";
    }
}
