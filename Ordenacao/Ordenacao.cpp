#include <iostream>

#define MaxTam 100000

using namespace std;

typedef long ChaveTipo;
typedef struct Item
{
    ChaveTipo Chave;
    /* outros componentes */
} Item;

typedef int Indice;
typedef Item Vetor[MaxTam + 1];
Vetor A;
Indice i, n;
int cont = 0, conq = 0, coni = 0;
//Seleção
void Selecao(Item *A, Indice *n)
{
    Indice i, j, Min;
    Item aux;
    for (i = 1; i <= *n - 1; i++)
    {
        Min = i;
        for (j = i + 1; j <= *n; j++)
        {
            cont++;
            if (A[j].Chave > A[Min].Chave)
            {
                Min = j;
                
            }
        }
        aux = A[Min];
        A[Min] = A[i];
        A[i] = aux;
        
    }
}
//Metodo Inserção
void Insercao(Item *A, Indice *n)
{
    Indice i, j;
    Item aux;
    for (i = 2; i <= *n; i++)
    {
        aux = A[i];
        j = i - 1;
        A[0] = aux; /* sentinela */
        while (aux.Chave > A[j].Chave)
        {
            A[j + 1] = A[j];
            j--;
            coni++;
        }
        A[j + 1] = aux;
    }
}
//Metódo Shellsort
void Shellsort(Item *A, Indice *n)
{
    int i, j;
    int h = 1;
    Item aux;
    do
        h = h * 3 + 1;
    while (h < *n);
    do
    {
        h /= 3; // h = h/3;
        for (i = h + 1; i <= *n; i++)
        {
            aux = A[i];
            j = i;
            while (A[j - h].Chave > aux.Chave)
            {
                A[j] = A[j - h];
                j -= h;
                if (j <= h)
                    goto L999;
            }
        L999:
            A[j] = aux;
        }
    } while (h != 1);
}
//Partição
void Particao(Indice Esq, Indice Dir, Indice *i, Indice *j, Item *A)

{
    Item aux, w;
    *i = Esq;
    *j = Dir;
    aux = A[(*i + *j) / 2]; /* obtem o pivo x */
    do
    {
        while (aux.Chave < A[*i].Chave)
            (*i)++;
        while (aux.Chave > A[*j].Chave)
            (*j)--;
        if (*i <= *j)
        {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}
//Ordenação
void Ordena(Indice Esq, Indice Dir, Item *A)
{
    Indice i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j)
    {
        Ordena(Esq, j, A);
        conq++;
    }
    if (i < Dir)
    {
        Ordena(i, Dir, A);
        conq++;
    }
}
//QuickSorte
void QuickSort(Item *A, Indice *n)
{
    Ordena(1, *n, A);
}
/*--Entra aqui a funcao Refaz do Programa 4.9 --*/
void Refaz(Indice Esq, Indice Dir, Item *A)
{
    Indice i = Esq;
    int j;
    Item x;
    j = i * 2;
    x = A[i];
    while (j <= Dir)
    {
        if (j < Dir)
        {
            if (A[j].Chave < A[j + 1].Chave)
                j++;
        }
        if (x.Chave >= A[j].Chave)
            goto L999;
        A[i] = A[j];
        i = j;
        j = i * 2;
    }
L999:
    A[i] = x;
}
/*--Entra aqui a funcao Constroi do Programa 4.10--*/
void Constroi(Item *A, Indice *n)
{
    Indice Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1)
    {
        Esq--;
        Refaz(Esq, *n, A);
    }
}




void Heapsort(Item *A, Indice *n)
{
    Indice Esq, Dir;
    Item x;
    Constroi(A, n); /* constroi o heap */
    Esq = 1;
    Dir = *n;
    while (Dir > 1)
    { /* ordena o vetor */
        x = A[1];
        A[1] = A[Dir];
        A[Dir] = x;
        Dir--;
        Refaz(Esq, Dir, A);
    }
}
void Imprime(Item *V, Indice *n)
{
    for (i = 1; i <= *n; i++)
        cout << V[i].Chave << " ";
    cout << endl;
}
void Copia(Item *Fonte, Item *Destino, Indice *n)
{
    for (i = 1; i <= *n; i++)
        Destino[i] = Fonte[i];
}
void Testa(Item *V, Indice *n)
{
    for (i = 2; i <= *n; i++)
    {
        if (V[i].Chave > V[i - 1].Chave)
        {
            cout << "ERRO: ";
            Imprime(V, n);
            return;
        }
    }
    cout << "OK: ";
    Imprime(V, n);
}
int main(int argc, char *argv[])

{
    Vetor B;
    int n = 20; /*Tamanho do arranjo a ser ordenado*/
    int i ;
    for (i = 1; i <= n; i++)
        A[i].Chave = i;

    Copia(A, B, &n);

    cout << "Desordenado : ";
    Imprime(A, &n);

    cout << "Selecao   ";
    Selecao(B, &n);
    cout << "\ncontador:" << cont << endl;
    Imprime (B, &n);
    //Testa(B, &n);
    Copia(A, B, &n);

    cout << "Insercao  ";
    Insercao(B, &n);
    cout << "\nContador: " << coni << endl;
    Testa(B, &n);
    Copia(A, B, &n);

    cout << "Shellsort ";
    Shellsort(B, &n);
    Testa(B, &n);
    Copia(A, B, &n);

    cout << "Quicksort ";
    QuickSort(B, &n);
    cout << "\nContador: " << conq << endl;
    Testa(B, &n);
    Copia(A, B, &n);

    cout << "Heapsort  ";
    Heapsort(B, &n);
    Testa(B, &n);
    Copia(A, B, &n);
    system("pause");
    return 0;
}