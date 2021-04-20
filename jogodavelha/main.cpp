#include <iostream>
//Jogo da velha - Completo
using namespace std;

void printM (char b[3][3])
{
       for(int m=0;m<3;m++)
    {
        for(int p=0;p<3;p++)
        {
            cout <<b[m][p];
            if(p==2)
              {
                cout << endl;
               }
        }
    }
}

int main()
{
    char tab[3][3];
    int a=0,b=0,posi2,posj2,possivel=0;
    system("cls");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tab[i][j]='-';
            cout <<tab[i][j];
            if(j==2)
              {
                cout << endl;
               }
         }
    }

    do{
    cout << "\nJogador x, onde deseja jogar?\n";
    cin >> a >> b;
    while (a>3|| a<0||b>3 || b<0)
    {
        cout << "Invalido\nJogador x, onde deseja jogar?\n";
        cin >> a >> b;
    }
    a=a-1;
    b=b-1;
    tab[a][b]='x';
    cout << tab[a][b]<<endl;


    printM(tab);

     if(tab[0][0]=='x'&&tab[1][1]=='x'&&tab[2][2]=='x'||tab[2][0]=='x'&&tab[1][1]=='x'&&tab[0][2]=='x'||tab[0][0]=='x'&&tab[0][1]=='x'&&tab[0][2]=='x'||tab[1][0]=='x'&&tab[1][1]=='x'&&tab[1][2]=='x'||tab[2][0]=='x'&&tab[2][1]=='x'&&tab[2][2]=='x'||tab[0][0]=='x'&&tab[1][0]=='x'&&tab[2][0]=='x'||tab[0][1]=='x'&&tab[1][1]=='x'&&tab[2][1]=='x'||tab[0][2]=='x'&&tab[1][2]=='x'&&tab[2][2]=='x')
    {
        cout << "O jogo acabou, x ganhou";
        break;
    }
    if(possivel==4)
    {
        cout << "Deu velha";
        break;
    }
     cout << "\nJogador o, onde deseja jogar?\n";
    cin >> posi2 >> posj2;
    while (posi2>3 || posi2<0||posj2>3 || posi2<0)
    {
        cout << "Invalido\nJogador x, onde deseja jogar?\n";
        cin >> posi2 >> posj2;
    }
    posi2=posi2-1;
    posj2=posj2-1;

    tab[posi2][posj2]='o';
    cout << tab[posi2][posj2]<<endl;

    printM(tab);
    if(tab[0][0]=='o'&&tab[1][1]=='o'&&tab[2][2]=='o'||tab[2][0]=='o'&&tab[1][1]=='o'&&tab[0][2]=='o'||tab[0][0]=='o'&&tab[0][1]=='o'&&tab[0][2]=='o'||tab[1][0]=='o'&&tab[1][1]=='o'&&tab[1][2]=='o'||tab[2][0]=='o'&&tab[2][1]=='o'&&tab[2][2]=='o'||tab[0][0]=='o'&&tab[1][0]=='o'&&tab[2][0]=='o'||tab[0][1]=='o'&&tab[1][1]=='o'&&tab[2][1]=='o'||tab[0][2]=='o'&&tab[1][2]=='o'&&tab[2][2]=='o')
    {
        cout << "O jogo acabou, bolinha venceu";
        break;
    }
    possivel++;

    } while(possivel<5);
}
