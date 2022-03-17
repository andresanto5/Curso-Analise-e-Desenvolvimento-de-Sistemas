#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ALTURA 20
#define LARGURA 20

void MoveEsquerda(int px);
void MoveDireita(int px);
void MoveCima(int py);
void MoveBaixo(int py);
void ImprimeMapa(int px, int py);
void ImprimeMeta(int px, int py);
void LimiteTabuleiro(int px, int py);
void Mutacao(char a);

int px, py;
char ordem, mutacao;
int continua=1;

int main(void) 
{
	
	srand(time(NULL));
	px=(rand()% (20 - 0+1) + 0);
	py=(rand()% (20 - 0+1) + 0);
	
	ImprimeMapa(px, py);
	while (continua) {
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
				break;
			case 'm': case 'M':
				ImprimeMeta(px, py);
				while((ordem=='m')||(ordem=='M'))
				{
					Mutacao(ordem);
				}
				
		}
		
		cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
		LimiteTabuleiro(px,py);
	}
	return 1;
}

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
			ordem='a';
			continua=0;
			break;
		break;
	}
}