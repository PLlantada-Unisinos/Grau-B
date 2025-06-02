/******************************************************************************

    Trabalho Grau B: Sistema para Gerenciamento de Cinema
    
[] O trabalho do Grau B consiste em desenvolver um sistema para gerenciamento de reservas de assentos de um
cinema. 

A. Ao iniciar o programa, será solicitado ao usuário informar o valor do ingresso, a quantidade de fileiras
(linhas) e quantos assentos por fileira (colunas) o cinema comporta. ✔

B. Com esses dados, deve-se criar uma matriz para gerenciar as reservas. Cada posição dessa matriz representa um assento, que deve armazenar a idade e o
sexo do ocupante.

C. O programa deve ser todo estruturado com funções. O código fonte deve estar corretamente indentado e
comentado.

Menu:
O programa deverá conter um menu com as seguintes funcionalidades:

1. Carregar dados: usuário informa o nome do arquivo que contém o registro das reservas e o programa
atualiza a matriz com os dados lidos do arquivo;

2. Consultar situação de um assento: usuário informa o assento (letra da linha e número da coluna) e o
programa retorna se está liberado ou reservado. Caso esteja reservado, retornar o sexo e a idade do
ocupante, seguido do valor pago de acordo com a idade;

3. Fazer reservas de “n” assentos: “n” assentos na mesma fileira, a partir de um assento informado pelo
usuário. Caso não existam “n” assentos disponíveis a partir do assento informado, avisar o usuário e não
fazer nenhuma reserva. Não deve permitir sobreposição de assentos previamente reservados. A cada
assento a ser reservado, solicitar o sexo e a idade do ocupante;

4. Liberar reserva de “n” assentos: na mesma fileira, a partir de um assento informado;

5. Visualizar mapa do cinema: mostrar o mapa do cinema em formato tabular, com os assentos liberados
representados por “·” e os reservados representados por um “X”;

6. Salvar dados: usuário informa o nome do arquivo e o programa salva as reservas;

1. Listagem apresentando as informações das reservas do cinema (assento, sexo, idade, valor);
2. Quantidade total de assentos do cinema, divididos entre liberados e reservados;
3. Quantidade de reservas, dividido por sexo;
4. Gráfico e quantidade de pagantes inteira (18 a 59 anos) e meia entrada (crianças e adolescentes 0 a 17 anos
e idosos 60 anos ou mais). Mostrar as 3 classificações, com quantidades, percentuais e valor arrecadado por
faixa. Mostrar também a receita total;

*******************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

struct ingresso {
    
    string local;
    
    int idade;
    
    char sexo;
    
};


int main()
{
    ingresso ocupante;
    
    ocupante.local = "B6";
    ocupante.idade = 20;
    ocupante.sexo = 'F';
    
    int cinemaL;
    int cinemaC;
    
    int grade;
    
    int contador_linha;
    int contador_coluna;
    
ofstream saida;

saida.open("Teste.txt.");


saida<<ocupante.local << ";" << ocupante.idade << ";" <<  ocupante.sexo;

saida.close();
    
    float val_ingres;
    
    cout<<"Digite o valor do ingresso: ";
    cin>>val_ingres;
    
    cout<<endl<<"Quantas Fileiras Tera o Cinema? ";
    cin>> contador_linha;
    cout<<"E Quantas Colunas (Assentos por Fileira)? ";
    cin>> contador_coluna;

cout<<endl<<"Area do Cinema:\n"<<endl;

    
    for (grade = 1; grade != contador_coluna + 1; grade++) {
        
        cout<<"\t[ "<<grade<<" ]";
    }
    
    
    
cout<<"\n";
    for (cinemaL = 1; cinemaL != contador_linha + 1; cinemaL++) {
        
        switch(cinemaL) {
        
        case 1: cout<<"A";
        break;
        
        case 2: cout<<"B";
        break;
        
        case 3:  cout<<"C";
        break;
        
        case 4: cout<<"D";
        break;
        
        case 5: cout<<"E";
        break;
        
        case 6: cout<<"F";
        break;
        
        case 7: cout<<"G";
        break;
        
        case 8: cout<<"H";
        break;
        
        case 9: cout<< "I";
        break;
        
        case 10: cout<< "J";
        break;
        
        case 11: cout<<"K";
        break;
        
        case 12: cout<<"L";
        break;
        
        case 13: cout<<"M";
        break;
        
        case 14:  cout<<"N";
        break;
        
        case 15: cout<< "O";
        break;
        
        case 16: cout<< "P";
        break;
        
        case 17: cout<< "Q";
        break;
        
        case 18: cout<<"R";
        break;
        
        case 19: cout<<"S";
        break;
        
        case 20: cout<<"T";
        break;
        
        case 21: cout<< "U";
        break;
        
        case 22: cout<< "V";
        break;
        
        case 23: cout<<"W";
        break;
        
        case 24: cout<< "X";
        break;
        
        case 25: cout<<"Y";
        break;
        
        case 26: cout<<"Z";
        break;
        }
        
            for (cinemaC = 0; cinemaC < contador_coluna; cinemaC++) {
                
                cout<<"\t[ O ]";
                
            }
            
        cout<<endl;
    }

    return 0;
}