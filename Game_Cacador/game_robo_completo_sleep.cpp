//Definindo as bibliotecas
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 

//Definindo as constantes da matriz
#define ALTURA 20
#define LARGURA 20

//Declarando as funções
void MoveEsquerda(int px);
void MoveDireita(int px);
void MoveCima(int py);
void MoveBaixo(int py);
void ImprimeMapa(int px, int py);
void ImprimeMapaFase2(int px, int py, int pw, int pz);
void ImprimeMeta(int px, int py);
void LimiteTabuleiro(int px, int py);
void Mutacao(char a);
void PlayToKill(int px, int py, int pw, int pz);

//Declarando as variáveis pois as funções lá em baixo precisam delas também
int px, py, pw, pz, fase, continua=1;
char mutacao, ordem;
bool ligar=true;

//Função main
using namespace std;
int main(void)
{
	srand(time(NULL));//Semente para números aleatórios
	
	cout<<"\tSeja Bem-vindo ao jogo da Lívia e do Carlos\n";
	
	while(ligar)//Liga e desliga o jogo
	{
		cout << "\033[1;44m";//Abre o background color azul
		cout<<"\n\t\tEm qual fase você gostaria de jogar?\n\n";
		cout<<"\tDigite:\n\t1 para a fase 1\n\t2 para a fase 2\n\t3 para desligar o jogo\n\n";
		cin>>fase;//O número vai ser armazenado na variável fase
		continua=1;//Para continuar a escolher qual fase quer jogar
		system("clear");//Limpar a tela
		cout<<"\033[0m\n";//Fecha o background color azul
		while(fase==1)//Laço para a fase 1 enquanto a variável fase for igual a 1
		{
			px=rand()%19+0;//Localização do predador na horizontal (entre 0 e 19)
			py=rand()%19+0;//Localização do predador na vertical (entre 0 e 19)
			
			ImprimeMapa(px, py);
			while (continua)//Enquanto continua for igual a 1 o jogador continua dando os comandos
			{
				ordem=getchar();//Recebe os comandos do jogador
				system("clear");//Limpa a tela
				
				switch (ordem)//Executa o comando dado pelo jogador
				{
					case 'a': case 'A':
						MoveEsquerda(px);
						ImprimeMapa(px, py);
						break;
					case 'd': case 'D':
						MoveDireita(px);
						ImprimeMapa(px, py);
						break;
					case 'w': case 'W':
						MoveCima(py);
						ImprimeMapa(px, py);
						break;
					case 's': case 'S':
						MoveBaixo(py);
						ImprimeMapa(px, py);
						break;
					case 'm': case 'M'://Metamorfose
						ImprimeMeta(px, py);
						while((ordem=='m')||(ordem=='M'))
						{
							Mutacao(ordem);
						}
						break;
					case 'q': case 'Q'://Sair da fase 1
						continua=0;
						fase=0;
						break;
				}
				
				cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
				LimiteTabuleiro(px,py);
			}
		}
		while(fase==2)//Laço para a fase 2 enquanto a variável fase for igual a 2
			{
				px=rand()%19+0;//Localização do predador na horizontal (entre 0 e 19)
				py=rand()%19+0;//Localização do predador na vertical (entre 0 e 19)
				if(px>=9)//Condição se o predador nascer do lado direito a presa nasca do lado esquerdo
					{
						while(pw>=9)//Enquanto a presa nascer do lado do predador ela não sai do laço
							pw=rand()%19+0;//Localização da presa na horizontal (entre 0 e 19)
					}
				else//Condição se o predador nascer do lado esquerdo a presa nasca do lado direito
					{
						while(pw<=9)//Enquanto a presa nascer do lado do predador ela não sai do laço
							pw=rand()%19+0;//Localização da presa na horizontal (entre 0 e 19)
					}
				pz=rand()%19+0;//Localização da presa na vertical (entre 0 e 19)
				while((px==9)&&(py>=3))//Laço para que o predador nem a presa nascer nas barreiras no mapa
					{
						//Se o predador nascer na barreira ele precisa nascer novamente
						px=rand()%19+0;
						py=rand()%19+0;
						if(px>=9)//Condição se o predador nascer do lado direito a presa nasca do lado esquerdo
							{
								while(pw>=9)//Enquanto a presa nascer do lado do predador ela não sai do laço
									pw=rand()%19+0;//Localização da presa na horizontal (entre 0 e 19)
							}
						else//Condição se o predador nascer do lado esquerdo a presa nasca do lado direito
							{
								while(pw<=9)//Enquanto a presa nascer do lado do predador ela não sai do laço
									pw=rand()%19+0;//Localização da presa na horizontal (entre 0 e 19)
							}
						pz=rand()%19+0;//Localização da presa na vertical (entre 0 e 19)
					}
				
				ImprimeMapaFase2(px, py, pw, pz);//Imprimir o mapa da fase 2
				while (continua)//Enquanto continua for igual a 1 o jogador continua dando os comandos
				{
					ordem=getchar();//Recebe os comandos do jogador
					system("clear");//Limpa a tela
					
					switch (ordem)//Executa o comando dado pelo jogador
					{
						case 'a': case 'A':
							MoveEsquerda(px);
							ImprimeMapaFase2(px, py, pw, pz);
							break;
						case 'd': case 'D':
							MoveDireita(px);
							ImprimeMapaFase2(px, py, pw, pz);
							break;
						case 'w': case 'W':
							MoveCima(py);
							ImprimeMapaFase2(px, py, pw, pz);
							break;
						case 's': case 'S':
							MoveBaixo(py);
							ImprimeMapaFase2(px, py, pw, pz);
							break;
						case 'k': case 'K'://Movimento especial para o predador rastrear a presa automaticamente
							PlayToKill(px, py, pw, pz);
							break;
						case 'q': case 'Q'://Sair da fase 2
							continua=0;
							fase=0;
							break;
					}
					cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
					LimiteTabuleiro(px,py);
				}
			}
		if(fase==3)//Opção para encerrar o jogo
		{
			cout << "\033[1;44m";
			cout<<"\nJogo Desligado. Até a próxima!\n";//Abre o background color azul
			ligar=false;//Quando ligar se torna falso o jogo desliga
			cout<<"\033[0m\n";//Fecha o background color azul
		}
	}
}

//Funções utilizadas
void ImprimeMapa(int px, int py)//Imprime o mapa da fase 1
{
	cout << "\033[1;40m";//Abre o background color preto
	int x, y;
	for(y=0;y<ALTURA;y++)
		{
			for(x=0;x<LARGURA;x++)
				{
					if((px==x)&&(py==y))
						{
							cout<<"@";
						}
					else
						{
							cout<<"+";
						}
				}
			cout<<"\n";
		}
	cout<<"\033[0m\n";//fecha o background color preto
}
void ImprimeMapaFase2(int px, int py, int pw, int pz)//Imprime o mapa da fase 2
{
	cout << "\033[1;41m";//Abre o background color vermelho
	int x, y, z, w;
	
	for(y=0;y<ALTURA;y++)
		{
			for(x=0;x<LARGURA;x++)
				{
					if((px==x)&&(py==y))//Condição para imprimir o predador
						{
							cout<<"@";
						}
					else if((pw==x)&&(pz==y))//Condição para imprimir a presa
						{
							cout<<"$";
						}
					else if((x==9)&&(y>=3))//Condição para imprimir a barreira
						{
							cout<<"I";//Barreira
						}
					else
						{
							cout<<"+";//restante do mapa
						}
				}
			cout<<"\n";
		}
	cout<<"\033[0m\n";//fecha o background color vermelho
}
void ImprimeMeta(int px, int py)//Função para a metamorfose do robô
{
	cout << "\033[1;45m";//Abre o background color magenta
	int x, y;
	for(y=0;y<ALTURA;y++)
		{
			for(x=0;x<LARGURA;x++)
				{
					if((px==x)&&(py==y))
						{
							cout<<"$";//Nova forma após a metamorfose
						}
					else
						{
							cout<<"+";//restante do mapa
						}
				}
			cout<<"\n";
		}
	cout<<"\033[0m\n";//fecha o background color magenta
}

void LimiteTabuleiro(int px, int py)//Função para informar o jogador o limite do tabuleiro
{
	//Se o robô quiser ultrapassar o limite (entre 0-19) ele avisará o limite
	if(!(px>0 || px<LARGURA-1 || py>0 || py<ALTURA-1))
		{
			cout<<"LIMITE DO TABULEIRO!! \n";
		}
}
void MoveEsquerda(int x)//Função para mover para a esquerda
{
	if(x>0)
		{
			px=x-1;
		}
	else
		{
			cout<<"LIMITE DO TABULEIRO!!\n";
		}
}
void MoveDireita(int x)//Função para mover para a direita
{
	if(x<LARGURA-1)
		{
			px=x+1;
		}
	else
		{
			cout<<"LIMITE DO TABULEIRO!!\n";
		}
}
void MoveCima(int y)//Função para mover para cima
{
	if(y>0)
		{
			py=y-1;
		}
	else
		{
			cout<<"LIMITE DO TABULEIRO!!\n";
		}
}
void MoveBaixo(int y)//Função para mover para baixo
{
	if(y<ALTURA-1)
		{
			py=y+1;
		}
	else
		{
			cout<<"LIMITE DO TABULEIRO!!\n";
		}
}
void Mutacao(char a)//Quando estiver na metamorfose imprimirá o mapa da metamorfose ao invés do mapa da fase 1
{
	mutacao=getchar();
	system("clear");
	switch (mutacao) 
	{
		case 'a': case 'A':
			MoveEsquerda(px);//Movimento do robô
			ImprimeMeta(px, py);//Mapa da metamorfose
			break;
		case 'd': case 'D':
			MoveDireita(px);//Movimento do robô
			ImprimeMeta(px, py);//Mapa da metamorfose
			break;
		case 'w': case 'W':
			MoveCima(py);//Movimento do robô
			ImprimeMeta(px, py);//Mapa da metamorfose
			break;
		case 's': case 'S':
			MoveBaixo(py);//Movimento do robô
			ImprimeMeta(px, py);//Mapa da metamorfose
			break;
		case 'm': case 'M':
			ordem='a';//Sair da metamorfose e voltar a forma anterior
			ImprimeMapa(px, py);//Mapa da metamorfose
			break;
		case 'q': case 'Q':
			ordem='q';//sair da função metamorfose
			continua=0;//sair do switch case
			fase=0;//sair da fase 1
			break;
	}
}
void PlayToKill(int px, int py, int pw, int pz)//Função para o predador rastrear a presa automaticamente
{
	while ((px!=pw)&&(py!=pz))//Laço para que o predador não pare até encontrar a presa
		{
			while(py>=3)//Laço para fazer o predador subir após a barreira
				{
					py--;
					system("clear");//Limpar a tela
					cout<<"Passos do Predador "<<px<<" "<<py<<"\n";//Passos que o predador realiza na matriz
					ImprimeMapaFase2(px, py, pw, pz);//Imprime mapa da fase 2
					nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);//tempo de 0.5 segundos
					
				}
			while(px>pw)//Laço para o predador chegar até a presa no eixo horizontal da direita para a esquerda
				{
					px--;//Andar para a esquerda
					system("clear");//Limpar a tela
					cout<<"Passos do Predador "<<px<<" "<<py<<"\n";//Passos que o predador realiza na matriz
					ImprimeMapaFase2(px, py, pw, pz);//Imprime mapa da fase 2
					nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);//tempo de 0.5 segundos
				}
			while(px<pw)//Laço para o predador chegar até a presa no eixo horizontal da esquerda para a direita
				{
					px++;//Andar para a direita
					system("clear");//Limpar a tela
					cout<<"Passos do Predador "<<px<<" "<<py<<"\n";//Passos que o predador realiza na matriz
					ImprimeMapaFase2(px, py, pw, pz);//Imprime mapa da fase 2
					nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);//tempo de 0.5 segundos
				}
			while(py>pz)//Laço para o predador chegar até a presa no eixo vertical de baixo para cima
				{
					py--;//Andar para cima
					system("clear");//Limpar a tela
					cout<<"Passos do Predador "<<px<<" "<<py<<"\n";//Passos que o predador realiza na matriz
					ImprimeMapaFase2(px, py, pw, pz);//Imprime mapa da fase 2
					nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);//tempo de 0.5 segundos
				}
			while(py<pz)//Laço para o predador chegar até a presa no eixo vertical de cima para baixo
				{
					py++;//Andar para baixo
					system("clear");//Limpar a tela
					cout<<"Passos do Predador "<<px<<" "<<py<<"\n";//Passos que o predador realiza na matriz
					ImprimeMapaFase2(px, py, pw, pz);//Imprime mapa da fase 2
					nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);//tempo de 0.5 segundos
				}
			cout<<"Fim de jogo\nO Predador (@) comeu a presa ($)\n";//Aviso de objetivo concluído
				continua=0;//sair do switch case
				fase=0;//sair da fase 2
		}
}