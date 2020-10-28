# threads-semaphore

● O Problema do Barbeiro Sonolento: A analogia do problema usa como
cenário uma barbearia. A barbearia possui: a cadeira do barbeiro e uma
sala de espera para os clientes com um número limitado de lugares. Ao
finalizar o corte de cabelo de um cliente, o barbeiro: libera o cliente e vai até
a sala de espera para ver se tem algum cliente esperando. Se há cliente
esperando, traz um deles para cortar o cabelo. Se não há clientes
esperando, o barbeiro volta para a cadeira de corte para dormir. Quando um
cliente chega à barbearia: o cliente olha o que o barbeiro está fazendo. Se o
barbeiro estiver dormindo, ele o acorda e senta na cadeira. Se o barbeiro
estiver trabalhando, o cliente volta para a sala de espera. Se houver cadeira
disponível na sala de espera, o cliente senta e aguarda a sua vez. Se não
houver cadeira disponível na sala de espera, o cliente vai embora.

● Implemente uma solução para este problema. Utilize semáforos para a
sincronização das threads.

Para compilar: gcc -pthread  -o barbeiro  barbeiro.c
Para executar: ./barbeiro
