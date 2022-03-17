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
void ImprimeMapa(int px, int py, int pw, int pz);
void ImprimeMeta(int px, int py);
void LimiteTabuleiro(int px, int py);
void Mutacao(char a);
void PlayToKill(int px, int py, int pw, int pz);

int px, py, pw, pz;
char ordem, mutacao;
int continua=1;

int main(void) 
{
	
	srand(time(NULL));
	
	px=(rand()%(19-0+1)+0);
	py=(rand()%(19-0+1)+0);
	if(px>=9)
	{
		while(pw>=9)
			pw=(rand()%(19-0+1)+0);
	}
	else if(pw<=9)
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
		else if(pw<=9)
		{
			while(pw<=9)
				pw=(rand()%(19-0+1)+0);
		}
		pz=(rand()%(19-0+1)+0);
	}
	
	ImprimeMapa(px, py, pw, pz);
	while (continua) {
		ordem=getchar();
		system("clear");

		switch (ordem) 
		{
			case 'a': case 'A':
				MoveEsquerda(px);
				ImprimeMapa(px, py, pw, pz);
				break;
			case 'd': case 'D':
				MoveDireita(px);
				ImprimeMapa(px, py, pw, pz);
				break;
			case 'w': case 'W':
				MoveCima(py);
				ImprimeMapa(px, py, pw, pz);
				break;
			case 's': case 'S':
				MoveBaixo(py);
				ImprimeMapa(px, py, pw, pz);
				break;
			case 'q': case 'Q':
				continua=0;
				break;
			case 'm': case 'M':
				ImprimeMapa(px, py, pw, pz);
				while((ordem=='m')||(ordem=='M'))
				{
					Mutacao(ordem);
				}
				break;
			case 'k': case 'K':
				PlayToKill(px, py, pw, pz);
				continua=0;
				break;
				
				
		}
		
		cout<<ordem<<" "<<px<<" "<<py<<" "<<"\n";
		LimiteTabuleiro(px,py);
	}
	return 1;
}

void ImprimeMapa(int px, int py, int pw, int pz)
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
							cout<<"%";
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
			ImprimeMapa(px, py, pw, pz);
			break;
		case 'q': case 'Q':
			ordem='a';
			continua=0;
			break;
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
			ImprimeMapa(px, py, pw, pz);
			cout<<"\n";
		}
		while(px>pw)
		{
			px--;
			system("clear");
			ImprimeMapa(px, py, pw, pz);
			cout<<"\n";
		}
		while(px<pw)
		{
			px++;
			system("clear");
			ImprimeMapa(px, py, pw, pz);
			cout<<"\n";
		}
		while(py>pz)
		{
			py--;
			system("clear");
			ImprimeMapa(px, py, pw, pz);
			cout<<"\n";
		}
		while(py<pz)
		{
			py++;
			system("clear");
			ImprimeMapa(px, py, pw, pz);
			cout<<"\n";
		}
	}
}