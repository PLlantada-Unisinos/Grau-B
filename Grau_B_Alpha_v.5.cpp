/******************************************************************************

    Trabalho Grau B: Sistema para Gerenciamento de Cinema

[] O trabalho do Grau B consiste em desenvolver um sistema para gerenciamento de reservas de assentos de um cinema.

A. Ao iniciar o programa, será solicitado ao usuário informar o valor do ingresso, a quantidade de fileiras
(linhas) e quantos assentos por fileira (colunas) o cinema comporta. ✔

B. Com esses dados, deve-se criar uma matriz para gerenciar as reservas. Cada posição dessa matriz representa um assento, que deve armazenar a idade e o sexo do ocupante. ✔?

C. O programa deve ser todo estruturado com funções. O código fonte deve estar corretamente indentado e comentado. ✔?

Menu:
O programa deverá conter um menu com as seguintes funcionalidades:

❌ 1. Carregar dados: usuário informa o nome do arquivo que contém o registro das reservas e o programa atualiza a matriz com os dados lidos do arquivo;

✔ 2. Consultar situação de um assento: usuário informa o assento (letra da linha e número da coluna) e o
programa retorna se está liberado ou reservado. Caso esteja reservado, retornar o sexo e a idade do
ocupante, seguido do valor pago de acordo com a idade;

✔3. Fazer reservas de “n” assentos: “n” assentos na mesma fileira, a partir de um assento informado pelo usuário.
Caso não existam “n” assentos disponíveis a partir do assento informado, avisar o usuário e não
fazer nenhuma reserva. Não deve permitir sobreposição de assentos previamente reservados. A cada
assento a ser reservado, solicitar o sexo e a idade do ocupante;

✔ 4. Liberar reserva de “n” assentos: na mesma fileira, a partir de um assento informado;

✔ 5. Visualizar mapa do cinema: mostrar o mapa do cinema em formato tabular, com os assentos liberados
representados por “·” e os reservados representados por um “X”;

✔ 6. Salvar dados: usuário informa o nome do arquivo e o programa salva as reservas;

✔ 1. Listagem apresentando as informações das reservas do cinema (assento, sexo, idade, valor);
✔? 2. Quantidade total de assentos do cinema, divididos entre liberados e reservados;
✔ 3. Quantidade de reservas, dividido por sexo;
✔? 4. Gráfico e quantidade de pagantes inteira (18 a 59 anos) e meia entrada (crianças e adolescentes 0 a 17 anos
e idosos 60 anos ou mais). Mostrar as 3 classificações, com quantidades, percentuais e valor arrecadado por
faixa. Mostrar também a receita total;

*******************************************************************************/

#include <iostream> //Usado para manipular o console
#include <fstream> //Usado para manipular arquivos
using namespace std;

struct ingresso {

    int idade = -1;

    char sexo;

};
//valores:

int menu; //Para definir se MENU é true ou false.
int choice; //Opções do Menu.
int choice2; //Opções de funcionalidade.

char Linha_Letra; //Letra da Linha
int Coluna_Nro; //Numero da Coluna
int Linha_Id; //Id da Linha (Z a A)
int Coluna_Id; //Id da Coluna(1 a Max)

int cinemaL; //Linhas do Cinema.
int cinemaC; //Colunas do Cinema.
int i; //Linhas da Matriz
int j; //Colunas da Matriz

int contador_linha; //Auto Explanatório.
int contador_coluna; //Auto Explanatório.
int grade; //Usado para numerar as Colunas.

int CSF; //contador do sexo feminino.
int CSM; //contador do sexo masculino.
int CTa; //contador do total de assentos.
float Cint; // contador da entrada inteira 1.
float Cint2; //conntador da entrada inteira 2;
float Cmei; //contador de meia entrada 1.
float Cmei2; //contador de meia entrada 2.
float profit; //Dinheiro ganho

ingresso** matriz; //Matriz de ingresso, onde cada posição representa um assento.

char text; //Character Chamado durante a ifstream (Display do Texto do Arquivo)

float val_ingres; //Preço do ingresso.
float val_ingres_meia;//Preço de meio ingresso.

ifstream arqEntrada; //nome da ifstream.

ofstream arqSaida; //nome do ofstream.
//______________________________________________________________________________



int main()
{
    cout << "Digite o valor do ingresso: "; //Solicita o valor do ingresso.
    cin >> val_ingres;
    val_ingres_meia = val_ingres / 2; //Valor da meia entrada imediatamente é definida como metade da inteira.

    cout << endl << "Quantas Fileiras Tera o Cinema (De Z a A)? ";
    cin >> contador_linha;

    cout << "E Quantas Colunas (Assentos por Fileira)? ";
    cin >> contador_coluna;

    CTa = contador_linha * contador_coluna;
    cout << "\n O numero total de assentos: " << CTa << endl;

    menu = true; //Define o menu como true, para inicializar um loop.

    arqSaida.open("Cinema.txt");

    while (menu == true) {

        matriz = new ingresso * [contador_linha];
        for (i = 0; i < contador_linha; i++) {
            matriz[i] = new ingresso[contador_coluna];
            for (j = 0; j < contador_coluna; j++) {
                matriz[i][j].idade = -1; // Todos os assentos são inicializados como livres
            }
        }

        //Menu recolocado para não causar erros.

        while (menu == true) {

            for (grade = 1; grade != contador_coluna + 1; grade++) {

                    cout << "\t[ " << grade << " ]";
                    arqSaida << "\t[ " << grade << "] ";
                }
                cout << endl;
                arqSaida << endl;

            for (i = 0; i < contador_linha; i++) {
                //Utilizado para formular as letras da matriz.

                switch (i) {
                case 25: cout << "[A]"; arqSaida << "[A]";
                    break;

                case 24: cout << "[B]"; arqSaida << "[B]";
                    break;

                case 23: cout << "[C]"; arqSaida << "[C]";
                    break;

                case 22: cout << "[D]"; arqSaida << "[D]";
                    break;

                case 21: cout << "[E]"; arqSaida << "[E]";
                    break;

                case 20: cout << "[F]"; arqSaida << "[F]";
                    break;

                case 19: cout << "[G]"; arqSaida << "[G]";
                    break;

                case 18: cout << "[H]"; arqSaida << "[H]";
                    break;

                case 17: cout << "[I]"; arqSaida << "[I]";
                    break;

                case 16: cout << "[J]"; arqSaida << "[J]";
                    break;

                case 15: cout << "[K]"; arqSaida << "[K]";
                    break;

                case 14: cout << "[L]"; arqSaida << "[L]";
                    break;

                case 13: cout << "[M]"; arqSaida << "[M]";
                    break;

                case 12: cout << "[N]"; arqSaida << "[N]";
                    break;

                case 11: cout << "[O]"; arqSaida << "[O]";
                    break;

                case 10: cout << "[P]"; arqSaida << "[P]";
                    break;

                case 9: cout << "[Q]"; arqSaida << "[Q]";
                    break;

                case 8: cout << "[R]"; arqSaida << "[R]";
                    break;

                case 7: cout << "[S]"; arqSaida << "[S]";
                    break;

                case 6: cout << "[T]"; arqSaida << "[T]";
                    break;

                case 5: cout << "[U]"; arqSaida << "[U]";
                    break;

                case 4: cout << "[V]"; arqSaida << "[V]";
                    break;

                case 3: cout << "[W]"; arqSaida << "[W]";
                    break;

                case 2: cout << "[X]"; arqSaida << "[X]";
                    break;

                case 1: cout << "[Y]"; arqSaida << "[Y]";
                    break;

                case 0: cout << "[Z]"; arqSaida << "[Z]";
                    break;
                }

                for (j = 0; j < contador_coluna; j++) {
                    if (matriz[i][j].idade == -1) {
                        cout << "\t[ O ]"; arqSaida << "\t[ O ]"; //Assentos livres são representados por "O"
                    }
                    else {
                        cout << "\t[ X ]"; arqSaida << "\t[ X ]"; //Assentos ocupados são representados por "X"
                        
                    }
                }
                cout << endl; arqSaida << endl;
            }
            arqSaida.close();

            cout << "Opções: \n 1 - Assento / 2 - Visualizar Assentos / 3 - Sair" << endl;
            cin >> choice;

            if (choice == 1) {

                choice2 = 1;

                while (choice2 == 1) {

                    arqSaida.open("Assentos.txt", ios::app); //Abre o arquivo antes de cada reserva.

                cout << "\nDigite a linha (EX: K): ";
                cin >> Linha_Letra;
                cout << "\nDigite a coluna (EX: 9): ";
                cin >> Coluna_Nro;

                Linha_Id = 'Z' - toupper(Linha_Letra); // Utilizado para converter a letra da linha para um numero ('Z' = 0, 'A' = 25).
                Coluna_Id = Coluna_Nro - 1; // Utilizado para converter os numeros da coluna para a matriz.

                    if (Linha_Id >= 0 && Linha_Id < contador_linha && Coluna_Id >= 0 && Coluna_Id < contador_coluna) {
                        if (matriz[Linha_Id][Coluna_Id].idade == -1) {
                            cout << "\nDigite Sua Idade: ";
                            cin >> matriz[Linha_Id][Coluna_Id].idade;
                            cout << "\nDigite seu Sexo: ";
                            cin >> matriz[Linha_Id][Coluna_Id].sexo;

                            arqSaida << "Assento reservado: " << Linha_Letra << Coluna_Nro << "; " << matriz[Linha_Id][Coluna_Id].idade << "; " << matriz[Linha_Id][Coluna_Id].sexo << endl;

                            arqSaida.close(); //Fecha o Arquivo após cada reserva.

                            arqSaida.open("Preço.txt");

                            if (matriz[Linha_Id][Coluna_Id].sexo == 'f' || matriz[Linha_Id][Coluna_Id].sexo == 'F') {

                                CSF++;

                            }
                            else if (matriz[Linha_Id][Coluna_Id].sexo == 'm' || matriz[Linha_Id][Coluna_Id].sexo == 'M') {

                                CSM++;

                            }

                            if (matriz[Linha_Id][Coluna_Id].idade < 18 || matriz[Linha_Id][Coluna_Id].idade > 59) {

                                cout << "\n Sua entrada é MEIA. O preço será: $" << val_ingres_meia << "\n \n";
                                Cmei++;

                            }
                            else {

                                cout << "\n Sua entrada é INTEIRA. O preço será: $" << val_ingres << "\n \n";
                                Cint++;

                            }

                            Cint2 = Cint * val_ingres;
                            Cmei2 = Cmei * val_ingres_meia;
                            profit = Cmei2 + Cint2;

                            //Calculo do total de dinheiro ganho, numero de mulheres, homens, entradas inteiras e meias.

                            arqSaida << "Preço do Ingresso Inteiro: $" << val_ingres << "\n";
                            arqSaida << "Preço do Meio Ingresso: $" << val_ingres_meia << "\n";
                            arqSaida << "Total de dinheiro ganho: $" << profit;
                            
                            arqSaida << "\n"<<endl;
                            
                            arqSaida << "Número de Mulheres: " << CSF << "\n";
                            arqSaida << "Número de Homens: " << CSM << "\n";
                            arqSaida << "Número de Inteiras: " << Cint << "\n";
                            arqSaida << "Número de Meias: " << Cmei << "\n";

                            arqSaida.close();
                        }
                        else {
                            cout << "Assento já reservado!\n";
                        }
                    }
                    else {
                        cout << "Assento inválido!\n";
                    }

                    cout << "\n Gostaria de Reservar Outro Assento? (1 - Sim / 2 - Não) \n";
                    cin >> choice2;
                }
            }


            if (choice == 2) {
                arqEntrada.open("Assentos.txt."); //Abre o arquivo para visualização dos assentos

                //Escrita à tela do arquivo

                arqEntrada.get(text);

                while (!arqEntrada.eof()) {
                    cout << text;
                    arqEntrada.get(text);
                }
                arqEntrada.close(); cout << endl; //Fecha "Assentos.txt"

                arqEntrada.open("Preço.txt"); //Abre o arquivo para visualização dos preços

                arqEntrada.get(text);

                while (!arqEntrada.eof()) {
                    cout << text;
                    arqEntrada.get(text);
                }
                arqEntrada.close(); cout << endl; //Fecha "Preço.txt"

            }
            else if (choice == 3) {
                cout << "\nSaindo do programa";
                arqSaida.open("Assentos.txt", ios::trunc); //Retira a data de "Assentos.txt" do arquivo e programa ao termina-lo
                arqSaida.close();
                
                return 0;
            }
        }

    }
}
