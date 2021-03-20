#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main(int argc, char**argv){

	setlocale(LC_ALL, "Portuguese");

	FILE *f;
	Endereco e;
	int aux=0;
	long tamArquivo, posicao, prim, ult, meio;

	if(argc != 2){
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
 
	f = fopen("cep_ordenado.dat","r");
	fseek(f,0,SEEK_END);
	tamArquivo = ftell(f);
	prim = 0;
	ult = (tamArquivo/sizeof(Endereco))-1;
	rewind(f);
	
	while (strncmp(argv[1],e.cep,8)!=0){
		meio = (prim+ult)/2;
        aux++;

        fseek(f, sizeof(Endereco) * meio, SEEK_SET);
        fread(&e, sizeof(Endereco), 1, f);
        
            if (strncmp(argv[1],e.cep,8)>0){
                prim = meio + 1;
            }else if (strncmp(argv[1],e.cep,8)<0){
                ult = meio - 1;
            } if (strncmp(argv[1],e.cep,8)==0){
                printf("\n%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			    break;
            }	
			if(aux>20){
				printf("CEP não existe");
				break;
			}
		}
	printf("Total Lido: %d\n", aux);
	fclose(f);
}   