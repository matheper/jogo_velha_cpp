#include <iostream>
#include <cstdlib>

using namespace std;

char tabuleiro[3][3];

void limpaTela()
{
    //system("cls"); // windows
    system("clear"); //Linux
}

void desenha()
{
    limpaTela();
    cout << "\n\nJogo da Velha \n\n";
    cout << "Jogador 1 (O) - Jogador 2 (X)" << "\n\n";
    cout << "     |     |     " << "\n";
    cout << "  " << tabuleiro[0][0] <<"  |  " << tabuleiro[0][1] <<"  |  " << tabuleiro[0][2] << "   \n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << tabuleiro[1][0] <<"  |  " << tabuleiro[1][1] <<"  |  " << tabuleiro[1][2] << "   \n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << tabuleiro[2][0] <<"  |  " << tabuleiro[2][1] <<"  |  " << tabuleiro[2][2] << "   \n";
    cout << "     |     |     " << "\n";
}



int main ()
{
    //inicializa variaveis
    int i=0, j=0, contador=0;
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

    desenha();
    
    while(contador < 9){
        //quem esta jogando
        if(contador%2) cout << "Jogador 2: " << "\n";
        else cout << "Jogador 1: " << "\n";
        //qual a posicao
        cout << "Digite linha: ";
        cin >> i;
        cout << "Digite coluna: ";
        cin >> j;
        
        //estao dentro do tabuleiro
        if( ( i>=0 && i <= 2 ) && ( j >=0 && j <= 2 ) && ( tabuleiro[i][j] == ' ' ) ){
            //a posicao esta vazia
            if(tabuleiro[i][j]==' '){
                //qual o jogador, para inserir qual o simbolo deste
                if(contador%2) tabuleiro[i][j]='X';
                else tabuleiro[i][j]='O';
                contador++;
            }
            
            //verifica se o jogador 1 ganhou
            if((tabuleiro[0][0]=='O' && tabuleiro[0][1]=='O' && tabuleiro[0][2]=='O')||
               (tabuleiro[1][0]=='O' && tabuleiro[1][1]=='O' && tabuleiro[1][2]=='O')||
               (tabuleiro[2][0]=='O' && tabuleiro[2][1]=='O' && tabuleiro[2][2]=='O')||
               (tabuleiro[0][0]=='O' && tabuleiro[1][0]=='O' && tabuleiro[2][0]=='O')||
               (tabuleiro[0][1]=='O' && tabuleiro[1][1]=='O' && tabuleiro[2][1]=='O')||
               (tabuleiro[0][2]=='O' && tabuleiro[1][2]=='O' &&tabuleiro [2][2]=='O')||
               (tabuleiro[0][0]=='O' && tabuleiro[1][1]=='O' && tabuleiro[2][2]=='O')||
               (tabuleiro[0][2]=='O' && tabuleiro[1][1]=='O' && tabuleiro[2][0]=='O'))
            {
                cout<<"\n\a\t\tJogador 1, VOCE VENCEU!!!\n";
                break;
            }
            //verifica se o jogador 2 ganhou
            if((tabuleiro[0][0]=='X' && tabuleiro[0][1]=='X' && tabuleiro[0][2]=='X')||
               (tabuleiro[1][0]=='X' && tabuleiro[1][1]=='X' && tabuleiro[1][2]=='X')||
               (tabuleiro[2][0]=='X' && tabuleiro[2][1]=='X' && tabuleiro[2][2]=='X')||
               (tabuleiro[0][0]=='X' && tabuleiro[1][0]=='X' && tabuleiro[2][0]=='X')||
               (tabuleiro[0][1]=='X' && tabuleiro[1][1]=='X' && tabuleiro[2][1]=='X')||
               (tabuleiro[0][2]=='X' && tabuleiro[1][2]=='X' && tabuleiro[2][2]=='X')||
               (tabuleiro[0][0]=='X' && tabuleiro[1][1]=='X' && tabuleiro[2][2]=='X')||
               (tabuleiro[0][2]=='X' && tabuleiro[1][1]=='X' && tabuleiro[2][0]=='X'))
            {
                cout<<"\n\n\n\n\a\t\tJogador 2, VOCE VENCEU!!!\n";
                break;
            } 
            
            //em caso de empate
            if((tabuleiro[0][0]!=' ' && tabuleiro[0][1]!=' ' && tabuleiro[0][2]!=' ')&&
               (tabuleiro[1][0]!=' ' && tabuleiro[1][1]!=' ' && tabuleiro[1][2]!=' ')&&
               (tabuleiro[2][0]!=' ' && tabuleiro[2][1]!=' ' && tabuleiro[2][2]!=' '))
            {
                cout<<"\n\n\n\n\a\t\tOcorreu um empate!!\n";
                break;
            } else {
                //caso contrario desenha a tela
                desenha();
            }
            
        }else{
            continue;
        }
        

        
    }
}
