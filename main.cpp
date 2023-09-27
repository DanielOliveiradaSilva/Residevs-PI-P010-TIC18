#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura https://drive.google.com/file/d/1DOSEwaityLckkWh3SqNXxnqVoSlRgQBL/view?usp=sharing
struct Aluno{
   string nome;
   double nota1;
   double nota2;
   double media;
};

void listarDados(const vector<Aluno> &alunos);//lista nome, nota1, nota2. Mais pode ser implementado para listar media.
void inserirAluno(vector<Aluno> &alunos);
void calcularMedia(vector<Aluno>&alunos); //A ideia era usar para inseri a medias de todos os alunos.Mais ṕode ser implementado ou criado outra função para media individual por exemplo. 
int buscarAluno(vector<Aluno>&alunos, string nome);//retona o indice do aluno
void alterarAluno(vector<Aluno>&alunos);//Precisa atualizar a media quando atualizar a nota? Devo criar uma função para isso?
void exluirAluno(vector<Aluno> &alunos);//Precisa reordenar? Mesmo que eu exluia uma valor de uma lista ordenada ela continua ordenada. A esta está ordenada antes de excluir? 
void bubblesort(vector<Aluno> &alunos);//ordenar em ordem lexografica.

int main(){
    //Fluxograma do algortimo  https://drive.google.com/file/d/1hmIH267o7IIGC-jx0_fUVAD5jitPDvvV/view

    vector<Aluno> alunos;
    Aluno novo_aluno;
    //---------------Primeiro Aluno----------------
    novo_aluno.nome = "Daniel Oliveira da Silva";
    novo_aluno.nota1 = 8.3;
    novo_aluno.nota2 = 7.4;
    novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
    alunos.push_back(novo_aluno);//inserção.
    //--------------------Fim---------------------

    //---------------Segunto Aluno----------------
    novo_aluno.nome = "Leonardo Garcia";
    novo_aluno.nota1 = 9.3;
    novo_aluno.nota2 = 8.4;
    novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
    alunos.push_back(novo_aluno);//inserção.
    //--------------------Fim---------------------

    //---------------Terceiro Aluno---------------
    novo_aluno.nome = "Lorena Andrade";
    novo_aluno.nota1 = 9.8;
    novo_aluno.nota2 = 6.4;
    novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
    alunos.push_back(novo_aluno);//inserção.
    //--------------------Fim--------------------

    //---------------Quarto Aluno----------------
    novo_aluno.nome = "Lorena Andrade";
    novo_aluno.nota1 = 9.8;
    novo_aluno.nota2 = 6.4;
    novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
    alunos.push_back(novo_aluno);//inserção.
    //--------------------Fim---------------------

    return 1;
}

void inserirAluno(vector<Aluno> &alunos){
       
    Aluno novo_aluno;
    cout << "Digite o nome do Aluno:\n";
    cin.ignore(); // Limpar o buffer de entrada antes de ler a linha completa
    getline(cin, novo_aluno.nome);//para ler o nome completo do Aluno, permitindo espaços. 
    cout << "Digite a nota 1: ";
    cin >> novo_aluno.nota1;
    cout << "Digite a nota 2: ";
    cin >> novo_aluno.nota2;
    alunos.push_back(novo_aluno);
      
}