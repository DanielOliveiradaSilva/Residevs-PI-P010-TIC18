#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno{
   string nome;
   double nota1;
   double nota2;
   double media;
};

bool inserirAluno(vector<Aluno> &alunos, int &limite, Aluno aluno);
void interfaceAluno(vector<Aluno> &alunos);

int main(){
    vector<Aluno> alunos;

    interfaceAluno(alunos);

    cout << endl;
    return 0;
}

void interfaceAluno(vector<Aluno> &alunos) {
    Aluno aluno;
    int limite = 0;
    char opcao;
    int tamanhoAtual = -1;
    bool alunoInserido = false;

    do
    {
        if (tamanhoAtual < limite)
        {
            cout << "\n\nDeseja inserir um aluno (s/n)? ";
            cin >> opcao;
        }
        
        if (tamanhoAtual < limite && (opcao == 's' || opcao == 'S'))
        {
            if (tamanhoAtual <= 0)
            {
                cout << "\n\nInforme um limite de alunos: ";
                cin >> limite;
            }

            cout << "\n\nDigite o nome do Aluno: ";
            cin.ignore();
            getline(cin, aluno.nome);

            cout << "\nDigite a nota 1: ";
            cin >> aluno.nota1;

            cout << "\nDigite a nota 2: ";
            cin >> aluno.nota2;
            
            alunoInserido = inserirAluno(alunos, limite, aluno); 
            tamanhoAtual = alunos.size();

            if (alunoInserido)
            {
                cout << "\n\nAluno adicionado com sucesso.\n";
            }
            else 
            {
                cout << "\n\nFalha ao inserir aluno.\n";
            }
        }
        
    } while (tamanhoAtual < limite && (opcao == 's' || opcao == 'S'));

    if (tamanhoAtual >= limite)
    {
        cout << "\n\nLimite de alunos alcançado.\n";
    }
}

bool inserirAluno(vector<Aluno> &alunos, int &limite, Aluno aluno) {
    bool alunoInserido = false;
    int tamanho = alunos.size();

    if (tamanho < limite && aluno.nome != "" && aluno.nota1 >=0 && aluno.nota2 >= 0)
    {
        aluno.media = (aluno.nota1 + aluno.nota2) / 2;
        alunos.push_back(aluno);
        alunoInserido = true;
    }

    return alunoInserido;
}