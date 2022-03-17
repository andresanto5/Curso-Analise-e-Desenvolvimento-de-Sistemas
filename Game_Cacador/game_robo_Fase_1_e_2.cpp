//Definindo as bibliotecas
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

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

//Declarando as variáveis pois as funções lá em baixo precisam delas
int px, py, pw, pz, fase, continua=1;
char mutacao, ordem;
bool ligar=true;

//Função main
using namespace std;
int main(void)
{
	srand(time(NULL));//Semente para números aleatórios
	
	while(ligar)//Liga e desliga o jogo
	{
		cout<<"\n\t\tEm qual fase você gostaria de jogar?\n\n";
		cout<<"Digite:\n1 para a fase 1\n2 para a fase 2\n3 para desligar o jogo\n\n";
		cin>>fase;//O número vai ser armazenado na variável fase
		continua=1;//Para continuar a escolher qual fase quer jogar
		system("clear");//Limpar a tela
		while(fase==1)
		{
			px=(rand()% (19 - 0+1) + 0);
			py=(rand()% (19 - 0+1) + 0);
			
			ImprimeMapa(px, py);
			while (continua)//Enquanto continua for igual a 1 o jogo continua
			{
				ordem=getchar();
				system("clear");
				
				switch (ordem) 
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
					case 'q': case 'Q':
						continua=0;
						fase=0;
						break;
					case 'm': case 'M':
						ImprimeMeta(px, py);
						while((ordem=='m')||(ordem=='M'))
						{
							Mutacao(ordem);
						}
						break;
				}
				
				cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
				LimiteTabuleiro(px,py);
			}
		}
		while(fase==2)
			{
				px=(rand()%(19-0+1)+0);
				py=(rand()%(19-0+1)+0);
				if(px>=9)
					{
						while(pw>=9)
							pw=(rand()%(19-0+1)+0);
					}
				else if(px<=9)
					{
						while(pw<=9)
							pw=(rand()%(19-0+1)+0);
					}
				pz=(rand()%(19-0+1)+0);
				while((px==9)&&(py>=3))
					{
						px=(rand()%(19-0+1)+0);
						py=(rand()%(19-0+1)+0);
						if(px>=9)
							{
								while(pw>=9)
									pw=(rand()%(19-0+1)+0);
							}
						else if(px<=9)
							{
								while(pw<=9)
									pw=(rand()%(19-0+1)+0);
							}
						pz=(rand()%(19-0+1)+0);
					}
				
				ImprimeMapaFase2(px, py, pw, pz);
				while (continua) {
					ordem=getchar();
					system("clear");
					
					switch (ordem) 
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
						case 'q': case 'Q':
							continua=0;
							fase=0;
							break;
						case 'k': case 'K':
							PlayToKill(px, py, pw, pz);
							break;
					}
					
					cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
					LimiteTabuleiro(px,py);
				}
			}
		if(fase==3)
		{
			cout<<"\nJogo Desligado\n";
			ligar=false;
		}
	}
}

//Funções utilizadas
void ImprimeMapa(int px, int py)
{
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
}
void ImprimeMapaFase2(int px, int py, int pw, int pz)
{
	int x, y, z, w;
	
	for(y=0;y<ALTURA;y++)
		{
			for(x=0;x<LARGURA;x++)
				{
					if((px==x)&&(py==y))
						{
							cout<<"@";
						}
					else if((pw==x)&&(pz==y))
						{
							cout<<"$";
						}
					else if((x==9)&&(y>=3))
						{
							cout<<"I";
						}
					else
						{
							cout<<"+";
						}
				}
			cout<<"\n";
		}
}
void ImprimeMeta(int px, int py)
{
	int x, y;
	for(y=0;y<ALTURA;y++)
		{
			for(x=0;x<LARGURA;x++)
				{
					if((px==x)&&(py==y))
						{
							cout<<"$";
						}
					else
						{
							cout<<"+";
						}
				}
			cout<<"\n";
		}
}

void LimiteTabuleiro(int px, int py)
{
	if(!(px>0 || px<LARGURA-1 || py>0 || py<ALTURA-1))
		{
			cout<<"LIMITE DO TABULEIRO!! \n";
		}
}
void MoveEsquerda(int x)
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
void MoveDireita(int x)
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
void MoveCima(int y)
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
void MoveBaixo(int y)
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
void Mutacao(char a)
{
	mutacao=getchar();
	system("clear");
	switch (mutacao) 
	{
		case 'a': case 'A':
			MoveEsquerda(px);
			ImprimeMeta(px, py);
			break;
		case 'd': case 'D':
			MoveDireita(px);
			ImprimeMeta(px, py);
			break;
		case 'w': case 'W':
			MoveCima(py);
			ImprimeMeta(px, py);
			break;
		case 's': case 'S':
			MoveBaixo(py);
			ImprimeMeta(px, py);
			break;
		case 'm': case 'M':
			ordem='a';
			ImprimeMapa(px, py);
			break;
		case 'q': case 'Q':
			ordem='q';
			continua=0;
			fase=0;
			break;
	}
}
void PlayToKill(int px, int py, int pw, int pz)
{
	while ((px!=pw)&&(py!=pz)) 
		{
			while(py>=3)
				{
					py--;
					system("clear");
					ImprimeMapaFase2(px, py, pw, pz);
					cout<<"\n";
				}
			while(px>pw)
				{
					px--;
					system("clear");
					ImprimeMapaFase2(px, py, pw, pz);
					cout<<"\n";
				}
			while(px<pw)
				{
					px++;
					system("clear");
					ImprimeMapaFase2(px, py, pw, pz);
					cout<<"\n";
				}
			while(py>pz)
				{
					py--;
					system("clear");
					ImprimeMapaFase2(px, py, pw, pz);
					cout<<"\n";
				}
			while(py<pz)
				{
					py++;
					system("clear");
					ImprimeMapaFase2(px, py, pw, pz);
					cout<<"\n";
				}
				continua=0;
				fase=0;
		}
}