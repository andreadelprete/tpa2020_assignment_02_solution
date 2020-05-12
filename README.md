# tpa2020_assignment_02
Secondo compito del corso "Tecniche di Programmazione Avanzata" del Dipartimento di Ingegneria Industriale, anno accademico 2019/20.

Questo compito si concentra sulla programmazione ad oggetti in C++.
In questa repository lo studente può già trovare i file `CMakeLists.txt` (da non modificare), i file `.cpp` vuoti da riempire (cartella `src`), i file header `.h` parzialmente implementati (cartella `include`) ed i file contenenti gli unit test (cartella `test`). 

## Uso dei file header
Nei file header sono già presenti delle dichiarazioni parziali delle classi da implementare.
A differenza del primo compito, in questo compito gli header sono praticamente completi.
Chiaramente lo studente è però libero di aggiungere metodi ed attributi a piacere, che potrebbero
semplificare l'implementazione delle classi.

## Uso dei test
Lo studente è incoraggiato a servirsi dei test per verificare che la sua implementazione delle funzioni sia corretta.
Se dei test falliscono allora significa che l'implementazione non è corretta.
Non è vero però il contrario: i test potrebbero passare tutti anche se l'implementazione contiene degli errori.
La responsabilità finale di giudicare se una funzione è implementata correttamente è dello studente, ed i test devono essere
visti solo come uno strumento di supporto a tale scopo.


# Descrizione del compito
Il compito si struttura in due parti. La seconda parte si serve della prima, quindi è necessario completare la prima parte, prima di poter lavorare sulla seguente.

Ecco alcune regole di base da seguire nello svolgimento del compito:
* Per rappresentare numeri reali si devono utilizzare variabili di tipo `double`. 
* Tutte le classi devono utilizzare allocazione di memoria dinamica per poter funzionare anche con dimensioni non note a tempo di compilazione. Particolare attenzione deve quindi essere posta alla gestione della memoria. 
* Controlli sulle dimensioni delle matrici/vettori devono essere implementati per assicurare la consistenza degli oggetti in ogni momento.
* Tutte le classi devono implementare costruttore, distruttore, costruttore di copia, operatore di assegnamento.


## Parte 1: LINEAR ALGEBRA
L'obiettivo di questa parte è sviluppare un piccolo libreria di algebra lineare, che servirà poi per lo sviluppo della Parte 2 del compito.

La libreria consiste principalmente in due classi: `Vector` e `Matrix`, entrambe classi derivate di `MatrixBase`. 
Le matrici devono essere salvate in memoria per riga (ordine [row-major](https://en.wikipedia.org/wiki/Row-_and_column-major_order)). 
In queste classi lo studente dovrà utilizzare:
* INCAPSULAMENTO: per assicurarsi che i dati degli oggetti non siano modificabili dall'esterno lasciando l'oggetto in uno stato inconsistente (ad es: modificando il puntatore alla memoria contenente i dati della matrice/vettore)
* EREDITARIETÀ: le classi `Vector` e `Matrix` dovranno certamente essere simili e condividere grossa parte del loro codice; per evitare di riscrivere lo stesso codice lo studente dovrà sfruttare l'ereditarietà.
* OPERATOR OVERLOADING: per rendere la libreria più facilmente utilizzabile, le operazioni tra vettori e matrici devono essere implementate tramite operatori come: =, +, *, -, +=, -=

## Parte 2: LINEAR DYNAMICAL SYSTEMS
L'obiettivo di questa parte è implementare una semplice libreria per la simulazione di sistemi dinamici lineari e controllori lineari, 
basata sulla libreria di algebra lineare della prima parte.

Le classi principali di questa parte sono: `Controller` e `Simulator`.

### Classe `Simulator`
Questa classe simula un sistema dinamico MIMO.
Il sistema MIMO ha una dinamica lineare tempo-invariante del tipo:
```
x[n+1] = A * x[n] + B * u[u]
```
dove
* `x[n]` è il vettore di stato del sistema all'istante n
* `u[n]` è il vettore di controllo del sistema all'istante n
* `x[n+1]` è il vettore di stato del sistema all'istante n+1
* `A` è la matrice di transizione di stato
* `B` è la matrice di controllo

La classe `Simulator` deve permettere di:
* leggere/scrivere le matrici A e B
* cambiare lo stato corrente del sistema
* simulare un passo del sistema dato il vettore di controllo


### Classe `Controller`
Questa classe implementa un controllore lineare del tipo:
```
u[n] = K * x[n]
```
dove
* `x[n]` è il vettore di stato del sistema all'istante n
* `u[n]` è il vettore di controllo del sistema all'istante n
* `K` è la matrice dei guadagni

La classe `Controller` deve permettere di:
* leggere/scrivere la matrice `K`
* calcolare il vettore di controllo `u` dato lo stato del sistema `x`

Si invita lo studente a leggere gli header file per maggiori dettagli.