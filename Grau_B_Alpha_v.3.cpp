/******************************************************************************

    Trabalho Grau B: Sistema para Gerenciamento de Cinema
    
[] O trabalho do Grau B consiste em desenvolver um sistema para gerenciamento de reservas de assentos de um cinema. 

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
    
    char local[2]; 
    
    int idade;
    
    char sexo;
    
};
//valores:

int menu; //Para definir se MENU é true ou false.
int choice; //Opções do Menu.

int cinemaL; //Linhas do Cinema.
int cinemaC; //Colunas do Cinema.
    
int contador_linha; //Auto Explanatório.
int contador_coluna; //Auto Explanatório.
int grade; //Usado para numerar as Colunas.

ingresso ocupante; //O Ingresso em si.

float val_ingres; //Preço do ingresso.

ofstream arqSaida; //nome do ofstream.

int valor_ocupante1 = (int)ocupante.local[0] - 90; //Metódo de checar o valor na grade do cinema.

int valor_ocupante2 = (int)ocupante.local[1] - 49; //Metódo de checar o valor na grade do cinema.
//__________________________________________________
void A_Cinema() {
        for (grade = 1; grade != contador_coluna + 1; grade++) {
        
        cout<<"\t[ "<<grade<<" ]";
        arqSaida<<"\t[ "<<grade<<" ]";
    }

arqSaida<<endl;
cout<<endl<<endl;
    for (cinemaL = 26; cinemaL != 26 - contador_linha; cinemaL--) {
        
        switch(cinemaL) {
        
        case 1: cout<<"[A]"; arqSaida<<"[A]";
        break;
        
        case 2: cout<<"[B]"; arqSaida<<"[B]";
        break;
        
        case 3: cout<<"[C]"; arqSaida<<"[C]";
        break;
        
        case 4: cout<<"[D]"; arqSaida<<"[D]";
        break;
        
        case 5: cout<<"[E]"; arqSaida<<"[E]";
        break;
        
        case 6: cout<<"[F]"; arqSaida<<"[F]";
        break;
        
        case 7: cout<<"[G]"; arqSaida<<"[G]";
        break;
        
        case 8: cout<<"[H]"; arqSaida<<"[H]";
        break;
        
        case 9: cout<<"[I]"; arqSaida<<"[I]";
        break;
        
        case 10: cout<<"[J]"; arqSaida<<"[J]";
        break;
        
        case 11: cout<<"[K]"; arqSaida<<"[K]";
        break;
        
        case 12: cout<<"[L]"; arqSaida<<"[L]";
        break;
        
        case 13: cout<<"[M]"; arqSaida<<"[M]";
        break;
        
        case 14:  cout<<"[N]"; arqSaida<<"[N]";
        break;
        
        case 15: cout<<"[O]"; arqSaida<<"[O]";
        break;
        
        case 16: cout<<"[P]"; arqSaida<<"[P]";
        break;
        
        case 17: cout<<"[Q]"; arqSaida<<"[Q]";
        break;
        
        case 18: cout<<"[R]"; arqSaida<<"[R]";
        break;
        
        case 19: cout<<"[S]"; arqSaida<<"[S]";
        break;
        
        case 20: cout<<"[T]"; arqSaida<<"[T]";
        break;
        
        case 21: cout<<"[U]"; arqSaida<<"[U]";
        break;
        
        case 22: cout<<"[V]"; arqSaida<<"[V]";
        break;
        
        case 23: cout<<"[W]"; arqSaida<<"[W]";
        break;
        
        case 24: cout<<"[X]"; arqSaida<<"[X]";
        break;
        
        case 25: cout<<"[Y]"; arqSaida<<"[Y]";
        break;
        
        case 26: cout<<"[Z]"; arqSaida<<"[Z]";
        break;
        }
        
            for (cinemaC = 0; cinemaC < contador_coluna; cinemaC++) {
//cout<<valor_ocupante1<<" "<<valor_ocupante2;
                if (cinemaC == valor_ocupante2 && valor_ocupante1 == 0) { cout<<"\t[ X ]"; arqSaida<<"\t[ X ]"; }
                else { cout<<"\t[ O ]"; arqSaida<<"\t[ O ]"; } 
                
            }
        cout<<endl;
        valor_ocupante1++;
        arqSaida<<endl;
    }
    arqSaida.close();
    }

//______________________________________________________________________________

int main()
{
        cout<<"Digite o valor do ingresso: ";
    cin>>val_ingres;
    
        cout<<endl<<"Quantas Fileiras Tera o Cinema? ";
    cin>> contador_linha;
    
    
        cout<<"E Quantas Colunas (Assentos por Fileira)? ";
    cin>> contador_coluna;
    
    A_Cinema();

while (menu = true) {
    cout<<endl;
    
    cout<<"Menu de opções:\n 1: Agendar um Ingresso .\n 2: Sair .\n";
    cin>>choice;
    
    while (choice != 1 && choice != 2) { "Não existe essa opção, lembre-se que: \n 1: Agendar um Ingresso .\n 2: Sair .\n"; cin>>choice; }

if (choice == 1) {

    cout<<"\n Digite o local (EX: K9): ";
    cin>>ocupante.local;
    
    cout<<"\n Digite Sua Idade: ";
    cin>>ocupante.idade;
    
    cout<<"\n Digite seu Sexo: ";
    cin>>ocupante.sexo;

arqSaida.open("Teste.txt2.");

arqSaida<<ocupante.local << ";" << ocupante.idade << ";" <<  ocupante.sexo;


cout<<endl;


arqSaida.close();

arqSaida.open("Cinema.txt.");

int valor_ocupante1 = (int)ocupante.local[0] - 90;

int valor_ocupante2 = (int)ocupante.local[1] - 49;

arqSaida<<endl<<"Area do Cinema: \n" << endl;

    for (grade = 1; grade != contador_coluna + 1; grade++) {
        
        cout<<"\t[ "<<grade<<" ]";
        arqSaida<<"\t[ "<<grade<<" ]";
    }

arqSaida<<endl;
cout<<"\n";

cout<<endl;

    for (cinemaL = 26; cinemaL != 26 - contador_linha; cinemaL--) {
        
        switch(cinemaL) {
        
        case 1: cout<<"[A]"; arqSaida<<"[A]";
        break;
        
        case 2: cout<<"[B]"; arqSaida<<"[B]";
        break;
        
        case 3: cout<<"[C]"; arqSaida<<"[C]";
        break;
        
        case 4: cout<<"[D]"; arqSaida<<"[D]";
        break;
        
        case 5: cout<<"[E]"; arqSaida<<"[E]";
        break;
        
        case 6: cout<<"[F]"; arqSaida<<"[F]";
        break;
        
        case 7: cout<<"[G]"; arqSaida<<"[G]";
        break;
        
        case 8: cout<<"[H]"; arqSaida<<"[H]";
        break;
        
        case 9: cout<<"[I]"; arqSaida<<"[I]";
        break;
        
        case 10: cout<<"[J]"; arqSaida<<"[J]";
        break;
        
        case 11: cout<<"[K]"; arqSaida<<"[K]";
        break;
        
        case 12: cout<<"[L]"; arqSaida<<"[L]";
        break;
        
        case 13: cout<<"[M]"; arqSaida<<"[M]";
        break;
        
        case 14: cout<<"[N]"; arqSaida<<"[N]";
        break;
        
        case 15: cout<<"[O]"; arqSaida<<"[O]";
        break;
        
        case 16: cout<<"[P]"; arqSaida<<"[P]";
        break;
        
        case 17: cout<<"[Q]"; arqSaida<<"[Q]";
        break;
        
        case 18: cout<<"[R]"; arqSaida<<"[R]";
        break;
        
        case 19: cout<<"[S]"; arqSaida<<"[S]";
        break;
        
        case 20: cout<<"[T]"; arqSaida<<"[T]";
        break;
        
        case 21: cout<<"[U]"; arqSaida<<"[U]";
        break;
        
        case 22: cout<<"[V]"; arqSaida<<"[V]";
        break;
        
        case 23: cout<<"[W]"; arqSaida<<"[W]";
        break;
        
        case 24: cout<<"[X]"; arqSaida<<"[X]";
        break;
        
        case 25: cout<<"[Y]"; arqSaida<<"[Y]";
        break;
        
        case 26: cout<<"[Z]"; arqSaida<<"[Z]";
        break;
        }
        
            for (cinemaC = 0; cinemaC < contador_coluna; cinemaC++) {
//cout<<valor_ocupante1<<" "<<valor_ocupante2;
                if (cinemaC == valor_ocupante2 && valor_ocupante1 == 0) { cout<<"\t[ X ]"; arqSaida<<"\t[ X ]"; }
                else { cout<<"\t[ O ]"; arqSaida<<"\t[ O ]"; } 
                
            }
        cout<<endl;
        valor_ocupante1++;
        arqSaida<<endl;
    }
    arqSaida.close();

}

else if (choice == 2) {
    menu = false;
    cout<<"\n \t Obrigado, Volte Sempre!";
    return 0;
} //Choice = 2 / Saida

}


} //Int Main !