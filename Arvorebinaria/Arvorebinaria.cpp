#include <iostream>
using namespace std;

//ÁRVORE BINÁRIA 

struct cliente
{S
    string nome;
    string telefone;
    int cpf;
};
struct cel
{
    int cpf;
    struct cliente conteudo;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;
typedef no *arvore;
void inserir(arvore &r, cliente c)
{
    if (r == NULL)
    {
        r = new no;
        r->conteudo = c;
        r->cpf = c.cpf;
        r->esq = NULL;
        r->dir = NULL;
    }
    else
    {
        if (c.cpf < r->cpf)
            inserir(r->esq, c);
        else
            inserir(r->dir, c);
    }
}

//Pré-ordem ou raiz esquerda direita
void red(arvore r)
{
    if (r != NULL)
    {
        cout << "-" << r->cpf;
        red(r->esq);
        red(r->dir);
    }
}

//Pós-ordem ou Esquerda direita raiz
void edr(arvore r)
{
    if (r != NULL)
    {
        edr(r->esq);
        edr(r->dir);
        cout << "-" << r->cpf;
    }
}

// In-ordem ou Varedura esqueda raiz direita -- em ordem crescente
void erd(arvore r)
{
    if (r != NULL)
    {
        erd(r->esq);
        cout << "-" << r->cpf;
        erd(r->dir);
    }
}

//Varedura esqueda raiz direita -- em ordem decrescente
void dre(arvore r)
{
    if (r != NULL)
    {
        dre(r->dir);
        cout << "-" << r->cpf;
        dre(r->esq);
    }
}
//Árvore
int altura(arvore r)
{
    if (r == NULL)
        return -1;
    else
    {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he > hd)
            return he + 1;
        else
            return hd + 1;
    }
}
int procurar(arvore r)
{
    int busca;
    busca = r->cpf;
    return busca;
    
}

int main()
{
    struct cliente v[] = {{"pedro", "555-555", 801},
     {"salinas", "555-555", 47},
     {"cecilia", "555-555", 408},
     {"fernando", "555-555", 104},
     {"Paulista", "555-555", 250}};
    int memoria;
    arvore r;
    r = NULL;
   
    

    inserir(r, v[0]);
    inserir(r, v[1]);
    inserir(r, v[2]);
    inserir(r, v[3]);
    inserir(r, v[4]);
    
    cout << "\nPre-ordem ou Raiz/Esquerda/Direita:" << endl;
    red(r);
    cout << "\nPos-ordem ou Esquerda/Direita/Raiz:" << endl;
    edr(r);
    cout << "\nIn-ordem crescente ou Esquerda/Raiz/Direita:" << endl;
    erd(r);
    cout << "\nOrdem decrescente ou Direita/Raiz/Esquerda:" << endl;
    dre(r);
    cout << "\nAltura da arvore: " << endl;
    cout << altura(r);
    cout << endl << "Busca\n";
    memoria = procurar(r);
    for (int i = 0; i < 5;i++)
    {
        if (memoria == v[i].cpf)
        {
            cout << "CPF chave\nNome:" << v[i].nome << "\nTelefone: " << v[i].telefone << "\nCPF: " << v[i].cpf<<endl;
        }
    }
    system("pause");
}