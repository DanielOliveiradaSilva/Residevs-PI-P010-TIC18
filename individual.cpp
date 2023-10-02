#include <iostream>
#include <iomanip>
#include <string>
#include <vector> 

using namespace std;

int main (void)
{
    /* Etapa 1. Elabore um sistema que solicite um limite de alunos N e, em seguida, os nomes e as notas de cada um dos alunos (2 notas para cada). 
    Utilize vectors para os nomes (strings) e para as notas (float). Não permita que sejam inseridos mais do que N estudantes */

    unsigned int limite_alunos = 0;
    vector<string> nomes_alunos;
    vector< vector<float> > notas_alunos;

    cout << "Limite de alunos: ";
    cin >> limite_alunos;

    for ( unsigned int i = 0; i < limite_alunos; i++ ) 
    {
        string nome;
        float nota1, nota2;

        cout << "=== ALUNO " << i+1 << " ===" << endl; 
        cout << "Nome: ";
        
        cin.ignore();
        getline(cin, nome);
        
        nomes_alunos.push_back(nome);

        bool flag;

        do {
            cout << "Notas: ";
            cin >> nota1 >> nota2;

            flag = false;

            if ( (nota1 < 0 || nota1 > 10) || (nota2 < 0 || nota2 > 10) ) 
            {
                cout << "Aviso: Favor inserir notas entre 0.0 e 10.0." << endl;
                flag = true;
                
            }
        } while (flag);

        notas_alunos.push_back( {nota1, nota2} );   
    }

    cout << endl;

    /* Etapa 4. O programa deve listar o resultado fila dos alunos com suas respectivas notas e médias, indicando para cada aluno 
    se está aprovado (média >= 7) ou reprovado (média < 7) */

   for ( unsigned int i = 0; i < limite_alunos; i++ ) 
    {
        float nota1 = notas_alunos[i][0];
        float nota2 = notas_alunos[i][1];
        float media = (nota1 + nota2) / 2;
        string situacao = media >= 7 ? "APROVADO" : "REPROVADO";

        cout << "============================================================================" << endl;
        cout << "ALUNO " << setw(16) << "NOTA 1" << setw(16) << "NOTA 2" << setw(16) << "MÉDIA" << setw(16) << "SITUAÇÃO" << endl;
        cout << nomes_alunos[i] << setw(16) << nota1 << setw(16) << nota2 << setw(16) << media << setw(16) << situacao << setw(16) << endl;
    }


    return 0;
}