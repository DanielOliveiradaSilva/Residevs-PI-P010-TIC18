#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno{
    string nome;
    float nota1;
    float nota2;
};

vector<Aluno> alunos;
// cin.ignore(); // Limpar o buffer de entrada antes de ler a linha completa
// getline(cin, novo_aluno.nome);//para ler o nome completo do Aluno, permitindo espaços.



int main(){
    
    int limite_alunos;
    Aluno aluno;

        cout << "Insira o limite de alunos: ";
        cin >> limite_alunos;


    for(int i = 0; i < limite_alunos; i++){

        cout << "Insira o nome do aluno " << i+1 << ": ";
        cin.ignore();
        getline(cin, aluno.nome);

        cout << "Insira a nota [1] do aluno: ";
        cin >> aluno.nota1;

        cout << "Insira a nota [2] do aluno: ";
        cin >> aluno.nota2;
    }

 return 0;
}