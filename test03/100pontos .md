% Aluno *JOÃO VITOR LOPES DE FARIAS*, MatrÃ­cula *180020251*

# Enunciados
 - https://moj.naquadah.com.br/contests/bcr-FSO-2020_2-avaliacao-3/prova.pdf
.
# QuestÃ£o 1
Não, esta rotina  deve sempre estar na memória principal, caso isso não ocorra, não será possível realizar a transferência de uma página para a memória principal (pag in)
.
# QuestÃ£o 2
## Item A
### Subitem 1
001 0000 0000 0111
.
### Subitem 2
011 0000 1010 0000
.
### Subitem 3
110 0000 0000 0101
.
### Subitem 4
page fault
.
### Subitem 5
010 0000 0000 0000
.
## Item B
O esquema de paginação pode apresentar fragmentação interna, por conta das páginas possuírem tamanho de fixo, quando uma página não está completamente ocupada, o espaço livre acaba não sendo utilizada
.
# QuestÃ£o 3
Não é viável, porque em cada acesso à memória seria necessário a participação do sistema operacional. Desta forma, para qualquer manipulação da memória seria preciso que o processo que está executando no processador saísse para que o sistema operacional entrasse, de tal forma que o desempenho seria bastante afetado
.
# QuestÃ£o 4
## Item A
funcao_A
.
## Item B
Por conta que na funcao_B a cada iteração do laço interno será necessário acessar uma página diferente da memória. Desta forma, acarretará TLB miss e quadro miss em todas as consultas, demandando muito mais do disco do que a funcao_A
.