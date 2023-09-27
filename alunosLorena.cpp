#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

struct Aluno{
   string nome;
   float nota1;
   float nota2;
};

int main() {
    srand(time(0));

    char resposta;
    int quantidadeMaxima;
    int n = 0;
    bool continuar;

    string nome;
    float nota1, nota2;
    vector <Aluno> alunos;
    
    cout << "Defina a quantidade máxima de alunos: "<< endl;
    cin >> quantidadeMaxima;

    do
    {
        if (n < quantidadeMaxima){
            n++;
            do
            {
                cout << "Digite o nome do aluno " << n << ":" << endl;
                cin.ignore();
                getline(cin, nome);

            } while (nome=="");

            cout << "Digite a nota 1: " << endl;
            cin >> nota1;
            cout << "Digite a nota 2: " << endl;
            cin >> nota2;

            alunos.push_back({nome, nota1, nota2});

            cout << "Deseja cadastrar mais alunos? (s/n): " << endl;
            cin >> resposta;

            if(resposta=='n' || resposta=='N'){
                continuar=false;
                break;
            }
            else{
                continuar=true;
            }
        }
        else{
            cout << "Ops! Não será possivel continuar."
            << " O limite máximo de alunos cadastrados foi atingido." << endl;
            continuar=false;
            break;
        }
       

    } while (continuar);


  
    return 0;
}

   