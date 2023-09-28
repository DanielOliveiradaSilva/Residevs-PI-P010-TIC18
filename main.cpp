#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#define TRACO "-----------------------------------------------------------------------------"
using namespace std;

// Estrutura https://drive.google.com/file/d/1DOSEwaityLckkWh3SqNXxnqVoSlRgQBL/view?usp=sharing
struct Aluno{
   string nome;
   double nota1;
   double nota2;
   double media;
};
void inserirAluno(vector<Aluno> &alunos, int nAluno);//Insere um aluno e suas notas
void listarAlunos(vector<Aluno> alunos);//lista nome, nota1, nota2. Mais pode ser implementado para listar media.
void calcularMedia(vector<Aluno>&alunos); //A ideia era usar para inseri a medias de todos os alunos.Mais ṕode ser implementado ou criado outra função para media individual por exemplo. 
int buscarAluno(vector<Aluno>&alunos);//retona o indice do aluno
void alterarAluno(vector<Aluno>&alunos);//Precisa atualizar a media quando atualizar a nota? Devo criar uma função para isso?
void excluirAluno(vector<Aluno> &alunos);//Precisa reordenar? Mesmo que eu exluia uma valor de uma lista ordenada ela continua ordenada. A esta está ordenada antes de excluir? 
void bubblesort(vector<Aluno> &alunos);//ordenar em ordem lexografica.
void incluirParaTeste(vector<Aluno> &alunos);//Função que insere alguns alunos e suas notas
int main(){
    //Fluxograma do algortimo  https://drive.google.com/file/d/1hmIH267o7IIGC-jx0_fUVAD5jitPDvvV/view
    char resposta;
    int quantidadeMaxima;
    int quantidadeAlunos = 0;
    bool continuar;
    vector <Aluno> alunos;
    
    cout << "Defina a quantidade máxima de alunos: "<< endl;
    cin >> quantidadeMaxima;

    do
    {
        if (quantidadeAlunos < quantidadeMaxima){
            quantidadeAlunos++;
            inserirAluno(alunos, quantidadeAlunos);
            cout << "Deseja cadastrar mais alunos? (s para Sim): " << endl;
            cin >> resposta;

           if(resposta=='s' || resposta=='S')
                continuar=true;    
            else{

                // //Utilizei essa sequencia para realizar testes
               // incluirParaTeste(alunos);

                cout << TRACO << endl;
                cout << "Ordem que foi inserido:" << endl;
                cout << TRACO << endl;
                listarAlunos(alunos);
                bubblesort(alunos);

                cout << TRACO << endl;
                cout << "Ordenado:" << endl;
                cout << TRACO << endl;
                listarAlunos(alunos);

                cout << TRACO << endl;
                cout << "Excluir aluno";
                cout << TRACO << endl;
                excluirAluno(alunos);
                cout << TRACO << endl;
                listarAlunos(alunos);


                // //Utilizei essa sequencia para realizar testes
                continuar=false;
                break;
            }   
        }
        else{
            cout << "Ops! Não será possivel continuar. O limite máximo de alunos cadastrados foi atingido." << endl;
            continuar=false;
            break;
        }
       

    } while (continuar);

    return 0;
}

void inserirAluno(vector<Aluno> &alunos, int nAluno){
    Aluno novoAluno;
    string nome;
    double nota1;
    double nota2;

    do
    {
        cout << "Digite o nome do aluno " << nAluno << ":" << endl;
        cin.ignore();
        getline(cin, nome);
    } while (nome=="");

    cout << "Digite a nota 1: " << endl;
    cin >> nota1;
    cout << "Digite a nota 2: " << endl;
    cin >> nota2;

    novoAluno.nome = nome;
    novoAluno.nota1 = nota1;
    novoAluno.nota2 = nota2;
    alunos.push_back(novoAluno);
}
void listarAlunos(const vector<Aluno> alunos){
    cout << TRACO << endl;
    cout << left << setw(40) << "NOME" << setw(16) << "NOTA 1"  << setw(16) << "NOTA 2"  << endl;
    cout << TRACO << endl;
    for (const Aluno &aluno : alunos) 
        cout << left << setw(40) << aluno.nome << setw(16) << setprecision(2) << aluno.nota1  << setw(16)  << setprecision(2) << aluno.nota2  << endl;
    
    cout << TRACO << endl;
    cout << endl; 
}

void bubblesort(vector<Aluno> &alunos){
    int quantosAlunos = alunos.size();
    int resultado;
    string nome1, nome2;
    Aluno aux;
    for (int i = 0; i < quantosAlunos - 1; i++){
        for (int j = 0; j < quantosAlunos - i - 1; j++){
            nome1 = alunos[j].nome;
            nome2 = alunos[j+1].nome;
            resultado = nome2.compare(nome1);

            if (resultado < 0) {
                //se aluno do nome2 é menor do que  aluno do nome1
                //troca
                aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }
}
// // void incluirParaTeste(vector<Aluno> &alunos){
//     Aluno novo_aluno;
//     //---------------Primeiro Aluno----------------
//     novo_aluno.nome = "Daniel Oliveira da Silva";
//     novo_aluno.nota1 = 8.3;
//     novo_aluno.nota2 = 7.4;
//     novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
//     alunos.push_back(novo_aluno);//inserção.
//     //--------------------Fim---------------------

//     //---------------Segunto Aluno----------------
//     novo_aluno.nome = "Leonardo Garcia";
//     novo_aluno.nota1 = 9.3;
//     novo_aluno.nota2 = 8.4;
//     novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
//     alunos.push_back(novo_aluno);//inserção.
//     //--------------------Fim---------------------

//     //---------------Terceiro Aluno---------------
//     novo_aluno.nome = "Lorena Andrade";
//     novo_aluno.nota1 = 9.8;
//     novo_aluno.nota2 = 6.4;
//     novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
//     alunos.push_back(novo_aluno);//inserção.
//     //--------------------Fim--------------------

//     //---------------Quarto Aluno----------------
//     novo_aluno.nome = "Carlos Andre";
//     novo_aluno.nota1 = 8.8;
//     novo_aluno.nota2 = 7.4;
//     novo_aluno.media = (novo_aluno.nota1 + novo_aluno.nota2)/2;
//     alunos.push_back(novo_aluno);//inserção.
//     //--------------------Fim---------------------

// }

int buscarAluno(vector<Aluno>&alunos){

    string nome_aluno;
    
    cout << "Insira o nome do aluno que deseja localizar: ";
    cin.ignore();
    getline(cin, nome_aluno);

    for(int i = 0; i < alunos.size() ; i++ ){
        if(nome_aluno == alunos[i].nome){
            cout << "Aluno encontrado!" << endl;
            return i;
        } 

    }
cout << "Aluno não encontrado." << endl;
return -1;
}

void excluirAluno(vector<Aluno> &alunos){

    int indice = buscarAluno(alunos);

    if (indice != -1){
        alunos.erase(alunos.begin() + indice);
        cout << "Aluno removido com sucesso!" << endl;
    } else {
        cout << "Aluno não encontrado, portanto nenhum aluno foi removido." << endl;
    }

}

