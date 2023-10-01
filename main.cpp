#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Estrutura que armazenará o nome e as 2 notas solicitados na Questão 1º
struct Aluno
{
    string nome;
    float nota1;
    float nota2;
};

void inserir(vector<Aluno> &alunos);
void listarResultado(vector<Aluno> &alunos);
// void bubbleSort(vector<Aluno> &lista);
// int buscarAluno(const string nome, vector<Aluno> &lista);
// void removerAluno(const string &nome, vector<Aluno> &lista);
// void alterarNota(const string &nome, vector<Aluno> &lista, float novaNota1, float novaNota2);

int main()
{

    int n = 0;
    char confirmar = 's';
    vector<Aluno> alunos;

    cout << "Quantidade de alunos:";
    cin >> n;

    do
    {
        if (alunos.size() < n)
        { // não permite que seja inserido mais que n-1 estudantes

            inserir(alunos); // pedindo o nome as notas e já ordenando.
        }
        else
        {
            cout << "Capacidade maxima de alunos registrado!" << endl;
        }
        cout << "\nDeseja incluir mais alunos s/n :"; // permitindo a inclusão de novos alunos
        cin >> confirmar;                             // permitindo a inclusão de novos alunos

    } while (confirmar == 's' || confirmar == 'S'); // permitindo a inclusão de novos alunos

    listarResultado(alunos);
}

// void alterarNota(string &nome, vector<Aluno> &alunos, float novaNota1, float novaNota2)
// {
//     int posicao = buscarAluno(nome, alunos);

//     if (posicao != -1)
//     {
//         alunos[posicao].nota1 = novaNota1;
//         alunos[posicao].nota2 = novaNota2;
//         cout << "Notas do Aluno " << nome << " alteradas com sucesso." << endl;
//     }
//     else
//     {
//         cout << "Aluno " << nome << " não encontrado na alunos." << endl;
//     }
// }
// void removerAluno(string &nome, vector<Aluno> &alunos) {
//     int posicao = buscarAluno(nome, alunos);

//     if (posicao != -1) {
//         alunos.erase(alunos.begin() + posicao); // Remove o Aluno da posição encontrada
//         cout << "Aluno " << nome << " removido com sucesso." << endl;
//     } else {
//         cout << "Aluno " << nome << " não encontrado na alunos." << endl;
//     }
// }

void listarResultado(vector<Aluno> &alunos)
{
    cout << "\nLista de Alunos:\n";
    string mensagem;
    int posicao = 1;
    for (const Aluno &a : alunos)
    {
        cout << "Aluno"
             << "-" << posicao << endl;
        cout << "Nome: " << a.nome << endl;
        cout << "Nota1: " << setprecision(2) << a.nota1 << endl;
        cout << "Nota2: " << setprecision(2) << a.nota1 << endl;
        cout << "Media: " << setprecision(2) << (a.nota1 + a.nota2) / 2 << endl;
        cout << "Situação: ";
        mensagem = ((a.nota1 + a.nota2) / 2 >= 7) ? "Aprovado" : "Reprovado";
        cout << mensagem << endl;

        posicao++;
    }
}

// int buscarAluno(string nome, vector<Aluno> &alunos){
//     int quantidade = alunos.size();

//     for (int i = 0; i < quantidade ; i++){
//        if (nome == alunos[i].nome){
//          return i;
//        }

//     }
//     return -1;
// }

// void inserir(vector<Aluno> &alunos){

//     Aluno novo_aluno;

//     cout << "Digite o nome do Aluno:\n";
//     cin.ignore(); // Limpar o buffer de entrada antes de ler a linha completa
//     getline(cin, novo_aluno.nome);//para ler o nome completo do Aluno, permitindo espaços.
//     cout << "Digite a nota 1: ";
//     cin >> novo_aluno.nota1;
//     cout << "Digite a nota 2: ";
//     cin >> novo_aluno.nota2;
//     alunos.push_back(novo_aluno);

// }

// void bubbleSort(vector<Aluno> &alunos) { //ordena alunos;
//     int n = alunos.size();
//     bool trocou;

//     do {
//         trocou = false;

//         for (int i = 0; i < n - 1; i++) {
//             if (alunos[i].nome > alunos[i + 1].nome) {
//                 swap(alunos[i], alunos[i + 1]);
//                 trocou = true;
//             }
//         }
//     } while (trocou);
// }
