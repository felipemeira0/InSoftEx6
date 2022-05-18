# Atividade 6 - Produtor e Consumidor

Nesta atividade, estudamos um buffet e comunicacao entre threads a threads, como produtores e consumidores. A buffet serve de um array de inteiros que os produtores se produzem e guardam um array e quando o buffet e cheio de inteiros, o produtor se param de produzir e aguarda o consumidor comsume, retirado o inteiro de um buffet array.

Neste codigo, comecamos com a entrada de quatro inteiros e apos a entrada, o terminal comeca imprimido aleatoriamente o que os produtores e consumidores funcionassem, produzido e consumido varios posicoes de um buffet.

## Explicando o Codigo

Esse codigo funciona um array de buffet, com valor comecando com 0, que esta vazio, e mais de 0 caso possui. Por exemplo:

```
|0|3|5|0| -> | |3|5| | -- um array de buffet com 4 numeros
```

Esse codigo possui seis funcoes:

- main() - O funcao que pode o programa ser executado, initializando os variaveis e criando e executando os threads para ambas, produtores e consumidores.
- producer() - Um funcao de thread para os produtores. Incluem o loop infinito para produzir os numeros e salvar para o buffet caso nao tenha cheio. Para verificar se o buffet nao esta cheio, usa-se o funcao checkbu() que retorna o numero. Caso retorna 1, o produtor nao produza numero com o buffet cheio.
- consumer() - Um funcao de thread para os consumidores. Incluem o loop infinito para pegar os numeros de um array de buffet. Para evitar o consumo com o buffet vazio, usam-se o funcao checkbu() tambem para que se retorna o numero 1, o consumidor nao consuma.
- produce() - Um funcao que produz numeros caso o buffet nao esta cheio, com valor obtenho da formula.
- consume() - Um funcao que consume numeros caso o buffet nao esta vazio, e o variavel com valor retornado apos consumo e 'cint'.
- checkbu() - Um funcao que verifica se o buffet esta vazio ou cheio. Retorna 1 se o buffet estiver cheio ou vazio e retorna 0 caso contrario.

E oito variaveis:

- int *barr - Um array de buffet que guarda numeros, comecando com 0. Se o numero de um posicao especificado esta em zero, significa que o posicao especificado esta vazio.
- int ppos - Um inteiro que pode ser usado para o posicao para os produtores produzem o numero caso o posicao (com esse variavel) estiver vazio.
- int cpos - Um inteiro que pode ser usado para o posical para os consumidores consumem o numero caso o posicao (com esse variavel) possui numero.
- int apos - Um inteiro usado para semaforos e executacao de ambas threads, consumidores e produtores.
- int pr - Um inteiro que e um numero de produtores.
- int co - Um inteiro que e um numero de consumidores.
- int n - Um numero inteiro que pode ser usado para calcular a formula dentro do funcao do produtor.
- int bu - Um numero inteiro que possui numeros de um array do buffet.

## Passo

Primeiro, dar o Makefile abrindo o terminal e, com o PATH com esse codigo, digite 'make' para compilar o codigo e criar o aplicativo 'bin' que e um binario para execucao da programa. Apos o compilacao, digite 'make run' para executar o codigo e digite quatro numeros se quiser como por exemplo:

```C
4 3 6 5
```

e a saida e

```
Produtor 3 produzindo 1 na posicao 1
Produtor 3 produzindo 3 na posicao 2
Produtor 3 produzindo 7 na posicao 4
Consumidor 3 consumindo 1 na posicao 1
Produtor 3 produzindo 5 na posicao 3
Consumidor 3 consumindo 3 na posicao 2
Consumidor 3 consumindo 5 na posicao 3
Produtor 3 produzindo 9 na posicao 0
Produtor 3 produzindo 1 na posicao 1
Produtor 3 produzindo 3 na posicao 2
...
...
...
```

Nota: As linhas podem ser aleatorios dependo do execucao de threads de produtores e consumidores.

Essa programa perece ter loop infinito. Para interromper esta programa, pressone os dois teclas, o Ctrl e C para interrompter o programa, finalizando o execucao.

Para remover o execucao que e binario, digite 'make clean' para limpar.

## Conclusao

Para este codigo, estudamos o comunicacao entre threads a threads via semaforos. Neste programa, durante o executacao do programa, comunicando entre produtores e consumidos, raramente pode ocorrer o deadlock.