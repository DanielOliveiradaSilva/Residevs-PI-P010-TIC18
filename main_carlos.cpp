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

void cabecalhoAluno();
bool inserirAluno(vector<Aluno> &alunos, int &limite, Aluno aluno);
void interfaceAluno(vector<Aluno> &alunos);
void cabecalhoListar();
int listarAlunos(vector<Aluno> &alunos);
void menu();
int sair();
void systemClear();
void systemPause();
void systemPauseAndClear();

#define MEDIA_APROVACAO 7

int main(void) {
    menu();
    cout << endl;
    return 0;
}

void menu() {
    vector<Aluno> alunos;
    int opcao;

    do
    {
        systemClear();
        cout << "------------------------------------------------------------" << endl;
        cout << "\tSistema de controle de notas de estudantes" << endl;
        cout << "------------------------------------------------------------" << endl << endl;
        
        cout << "[ 1 ] Inserir aluno\n[ 2 ] Listar alunos\n[ 0 ] Sair\n" << endl;
        cout << "Selecione uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                interfaceAluno(alunos);
                break;

            case 2:
                listarAlunos(alunos);
                break;

            case 0:
                sair();
                break;
            
            default:
                cout << "\nOpção inválida!\n";
                systemPause();
                break;
        }
    } while (opcao != 0);
}

void cabecalhoAluno() {
    cout << "------------------------------------------------------------" << endl;
    cout << "\t\t\tInserir alunos" << endl;
    cout << "------------------------------------------------------------" << endl << endl;
}

void interfaceAluno(vector<Aluno> &alunos) {
    Aluno aluno;
    int limite = 0;
    char opcao;
    int tamanhoAtual = -1;
    bool alunoInserido = false;

    do
    {
        systemClear();
        cabecalhoAluno();

        if (tamanhoAtual < limite)
        {
            cout << "\nDeseja inserir um aluno (s/n)? ";
            cin >> opcao;
            systemClear();
            cabecalhoAluno();
        }
        
        if (tamanhoAtual < limite && (opcao == 's' || opcao == 'S'))
        {
            if (tamanhoAtual <= 0)
            {
                cout << "\n\nInforme um limite de alunos: ";
                cin >> limite;
                systemClear();
                cabecalhoAluno();
            }

            cout << "\n\nDigite o nome do Aluno: ";
            cin.ignore();
            getline(cin, aluno.nome);
            systemClear();
            cabecalhoAluno();

            cout << "\nDigite a nota 1: ";
            cin >> aluno.nota1;
            systemClear();
            cabecalhoAluno();

            cout << "\nDigite a nota 2: ";
            cin >> aluno.nota2;
            systemClear();
            cabecalhoAluno();
            
            alunoInserido = inserirAluno(alunos, limite, aluno); 
            tamanhoAtual = alunos.size();

            if (alunoInserido)
            {
                cout << "\n\nAluno adicionado com sucesso.\n";
                systemPauseAndClear();
            }
            else 
            {
                cout << "\n\nFalha ao inserir aluno.\n";
                systemPauseAndClear();
            }
        }
        
    } while (tamanhoAtual < limite && (opcao == 's' || opcao == 'S'));

    if (tamanhoAtual >= limite)
    {
        cabecalhoAluno();
        cout << "\n\nLimite de alunos alcançado.\n";
        systemPauseAndClear();
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

void cabecalhoListar() {
    cout << "------------------------------------------------------------" << endl;
    cout << "\t\t\tListar alunos" << endl;
    cout << "------------------------------------------------------------" << endl << endl;
}

int listarAlunos(vector<Aluno> &alunos) {
    int tamanho = alunos.size();
    string situacao;

    systemClear();
    cabecalhoListar();

    if (tamanho > 0)
    {
        cout << "Nome\t\tNota 1\tNota 2\tMédia\tsituação" << endl;
        for (Aluno aluno : alunos)
        {
            situacao = aluno.media >= MEDIA_APROVACAO ? "APROVADO" : "REPROVADO";
            cout << aluno.nome << "\t\t" << aluno.nota1 << "\t" << aluno.nota2 << "\t" << aluno.media << "\t" << situacao << endl;
        }
    }
    else
    {
        cout << "\nNenhum dado encontrado\n";
    }

    systemPauseAndClear();
    return 0;
}

int sair() {
    cout << "\nFinalizando programa...";
    systemPauseAndClear();
    return 0;
}

void systemClear() {
    #if __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    #if __linux__
        cin.ignore();
    #else
        cin.sync();
    #endif
    cin.get();
}

void systemPauseAndClear() {
    systemPause();
    systemClear();
}