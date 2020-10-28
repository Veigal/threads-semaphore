#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

char buffer;
sem_t acordaBarbeiro; // Declaração das variáveis
int cadeirasEsperaOcupadas = 0;
int barbeiroDormindo = 0;
int lugarVago = 3;

int geraNumeroAleatorio(int qtdValores) {
    time_t t;
    srand((unsigned) time(&t));
    return rand() % (qtdValores);
}

void *cadeiraBarbeiro() {
	while(1) {
        printf("Barbeiro vai verificar se há pessoas na sala de espera\n");
        if (lugarVago == 3){
            printf("Não há pessoas esperando na sala de espera, o barbeiro vai dormir\n");
		    barbeiroDormindo = 1;
		    sem_wait(&acordaBarbeiro);
                    barbeiroDormindo = 0;
            printf("O barbeiro é acordado\n");

        } else{
            printf("O barbeiro vai a sala de espera e chama o próximo cliente\n");
            lugarVago++;
        }
        
        printf("O barbeiro começa a cortar o cabelo do cliente\n");
        sleep(geraNumeroAleatorio(3) + 3);//3 a 5 segundos
        printf("O barbeiro termina de cortar o cabelo do cliente\n");
	}
}

void *salaEspera() {
	while(1) {
        sleep(geraNumeroAleatorio(1) + 1);//1 a 2 segundos
        printf("Cliente entrou na barbearia\n");
        if (lugarVago > 0 ){
            if (barbeiroDormindo){
                printf("O cliente chegou e o barbeiro está dormindo, ele ira acordar o barbeiro\n");
		        sem_post(&acordaBarbeiro);
            } else{
                lugarVago--;
                printf("O cliente está esperando na sala de espera, agora restam %d lugares vagos\n", lugarVago);
            }           
        } else{
            printf("Não havia lugar na sala de espera o cliente foi embora\n");
        }
	}
}


int main() {
	pthread_t t1, t2;
	sem_init (&acordaBarbeiro, 0, 0);

	(void) pthread_create(&t1, NULL, cadeiraBarbeiro, NULL);
	(void) pthread_create(&t2, NULL, salaEspera, NULL);
   	(void) pthread_join(t1, NULL);
	(void) pthread_join(t2, NULL);
    return 0;
}
