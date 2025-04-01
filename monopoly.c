#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define saldo_iniziale 1000 /* definisco il saldo iniziale dei giocatori */

typedef enum {svago, zone, aziende, giochi} tipo_casella; /* dichiaro i tipi di caselle */

typedef struct casella /* creo la struttura casella */
{
        char proprietario[20];
        int numero;
        int rendita;
        int valore;
        int tipo;
        char nome[20];
        struct  casella *next;
} casella;

typedef struct giocatore /* creo la struttura giocatore */
{
        char nome[20];
        int saldo;
        int numero_casella;
        struct  giocatore *next;
        struct casella *pinG;
} giocatore;

int rand_dadi() /* funzione per generare il lancio di due dadi */
{
        int p, s, c, i;
        
        srand(time(0));

        p=rand()%6+1; /*primo dado*/
        s=rand()%6+1; /*secondo dado*/

        c=p+s; /*somma dei dadi per la posizione del giocatore*/
        
        printf("\nE' uscito il numero: %d\nPremi [ENTER] per continuare.", c); /* scrivo il numero appena uscito dai dadi */
        while(getchar()!='\n');
        
        return c;
}

void rand_gioco(giocatore *g) /* funzione per le caselle "giochi". passo i seguenti dati: puntatore al giocatore attuale */
{
        int a, i, s;
        
        srand(time(0));

        a=rand()%2; /*numeri random da 0 a 1 -> 0 = perdita, 1 = vincita */
        
        s=rand()%10*10; /*calcolo il valore della perdita/vincita*/

        if(a==0)
        {
            printf("\nHai perso %d euro.\n", s);
            g->saldo=g->saldo-s; /* aggiorno il saldo del giocatore in caso di perdita */
        }
        else
        {
            printf("\nHai vinto %d euro.\n", s); 
            g->saldo=g->saldo+s; /* aggiorno il saldo del giocatore in caso di vincita */
        }

}

giocatore *genera_giocatori(int num,giocatore *pin) /* genero la lista giocatori. passo i seguenti dati: numero dei giocatori, puntatore all'inizio della lista giocatori */
{
    giocatore *g, *pfin;
    int i;
    char name[20];
    
        for(i=1;i<num+1;i++)
        {
                g=(giocatore*)malloc(sizeof(giocatore)); /* alloco memoria per l'inserimento dei giocatori */
                printf("Inserisci il nome del giocatore %d: ", i);
                scanf("\n%20[^\n]", name); /* con questo scanf posso scrivere nome e cognome senza avere problemi di "space" (barra spaziatrice) */
                if(pin==NULL)
                {
                        pin=g;
                        pfin=g;
                }
                else
                {
                        pfin->next=g;
                        pfin=g;
                }
                strcpy(g->nome, name); /* alloco il nome del giocatore */
                g->next=NULL; /* il puntatore al successivo punta a NULL */
                g->saldo=saldo_iniziale; /* alloco il saldo iniziale nel saldo del giocatore */
                g->numero_casella=1; /* alloco il giocatore nella casella START */
                g->pinG=NULL;
        }
        pfin->next=pin; /* il puntatore all'ultimo giocatore puntera' al primo giocatore */
        return pin;
}

giocatore *cancella_giocatore(giocatore *g,giocatore *pin) /* funzione per cancellare un giocatore dalla lista in caso di (saldo <= 0). passo i seguenti dati: puntatore al giocatore attuale, puntatore all'inizio della lista giocatori */
{
                giocatore *fin, *prec;

                fin=pin;
                while(fin->next!=pin) /* cerco l'ultimo giocatore */
                {
                        fin=fin->next;
                }
                prec=pin;
                while(prec->next!=g) /* cerco il giocatore precedente a quello da eliminare */
                {
                        prec=prec->next;
                }
                if(g==pin) /* se il giocatore da cancellare e' in prima posizione, spostiamo il suo puntatore a quello successivo e l'ultimo al secondo della lista */
                {
                        pin=pin->next;
                        fin->next=pin;
                }
                else /* se il giocatore da eliminare non e' in prima posizione, spostiamo il puntatore del suo precedente al giocatore successivo */
                {
                        prec->next=g->next;
                }
        return pin;
}

void nome_caselle(char nc[][20], int tc[])
{
        strcpy(nc[0],"Start");
		tc[0]=0;
		    
        strcpy(nc[1],"Giampilieri");
        tc[1]=1;
        
        strcpy(nc[2],"Pesca");
        tc[2]=0;
        

        strcpy(nc[3],"Briga marina");
        tc[3]=1;
        
        
        strcpy(nc[4],"Fermata n.2");
        tc[4]=0;
        
        
        strcpy(nc[5],"Galati");
        tc[5]=1;
        
        
        strcpy(nc[6],"Enel");
        tc[6]=2;
        
        
        strcpy(nc[7],"Mili marina");
        tc[7]=1;
        
        
        strcpy(nc[8],"Tremestieri");
        tc[8]=1;
        
        
        strcpy(nc[9],"Slot machine");
        tc[9]=3;
        
        
        strcpy(nc[10],"Santa Lucia");
        tc[10]=1;
        
        
        strcpy(nc[11],"Villa dante");
        tc[11]=0;
        
        
        strcpy(nc[12],"Contesse");
        tc[12]=1;
        
        
        strcpy(nc[13],"San. Filippo");
        tc[13]=1;
        
        
        strcpy(nc[14],"Fermata n.12");
        tc[14]=0;
        
        
        strcpy(nc[15],"Gazzi");
        tc[15]=1;
        
        
        strcpy(nc[16],"Caronte");
        tc[16]=2;
        
        
        strcpy(nc[17],"Mangialupi");
        tc[17]=1;
        
        
        strcpy(nc[18],"Cumia");
        tc[18]=1;
        
        
        strcpy(nc[19],"Bingo");
        tc[19]=3;
        
        
        strcpy(nc[20],"Bordonaro");
        tc[20]=1;
        
        
        strcpy(nc[21],"Stadio");
        tc[21]=0;
        
        
        strcpy(nc[22],"Gravitelli");
        tc[22]=1;
        
        
        strcpy(nc[23],"Giostra");
        tc[23]=1;
        
        
        strcpy(nc[24],"Fermata n. 20");
        tc[24]=0;
        
        
        strcpy(nc[25],"San Licandro");
        tc[25]=1;
        
        
        strcpy(nc[26],"San Michele");
        tc[26]=1;
        
        
        strcpy(nc[27],"Baby park");
        tc[27]=0;
        
        
        strcpy(nc[28],"Annunziata");
        tc[28]=1;
        
        
        strcpy(nc[29],"Poker");
        tc[29]=0;
        
        
        strcpy(nc[30],"Paradiso");
        tc[30]=1;
        
        
        strcpy(nc[31],"Pace");
        tc[31]=1;
        
        
        strcpy(nc[32],"ATM");
        tc[32]=2;
        
        
        strcpy(nc[33],"Sant'Agata");
        tc[33]=1;
        
        
        strcpy(nc[34],"Fermata n. 34");
        tc[34]=0;
        
        
        strcpy(nc[35],"Lago");
        tc[35]=0;
        
        
        strcpy(nc[36],"Ganzirri");
        tc[36]=1;
        
        
        strcpy(nc[37],"Spiaggia");
        tc[37]=0;
        
        
        strcpy(nc[38],"Liberty Lines");
        tc[38]=2;
        
        
        strcpy(nc[39],"Torre Faro");
        tc[39]=1;
        

        
}

casella* genera_casella(char nc[][20],int tc[]) /* funzione per generare le caselle. passo i seguenti valori: vettore nomi caselle e vettore tipo caselle */
{
	casella *pin=NULL;
	casella *p, *pfin;
	int v,r,i;
	v=0;
	r=0;
	for(i=1;i<41;i++)
	{
		p=(casella*)malloc(sizeof(casella));
		if(pin==NULL) /* se la lista è vuota, inizializzo la lista */
		{
			pin=p;
			pfin=p;
            pfin->next=NULL;
		}
		else
		{
			pfin->next=p;
			p->next=NULL;
            pfin=p;
		}
		p->numero=i; /* numero casella */
		strcpy(p->nome,nc[i-1]); /* nome casella */
		p->tipo=tc[i-1]; /* tipo casella */
		strcpy(p->proprietario, ""); /* nome proprietario */
		if(p->tipo==1||p->tipo==2) /* controllo il tipo (se zona o azienda) */
		{
			v=v+10; /* incremento valore */
			r=r+2; /* incremento rendita */
			p->valore=v;
			p->rendita=r;
		}
		else /* altrimenti (se svago o giochi) */
		{
			p->valore=0;
			p->rendita=0;
		}
	}
	return pin; /* ritorno il puntatore all'inizio della lista caselle */
}

void azione(int num_casella,giocatore *g, casella *pinc, giocatore *pin) /* funzione per il controllo del tipo di casella e lo svolgimento del gioco. passo i seguenti dati: numero della casella, puntatore al giocatore attuale, puntatore all'inizio della lista caselle, puntatore all'inizio della lista giocatori */
{
    int i=num_casella;
    char c;
    casella *cas, *temp, *temp2;
    cas=pinc;

	while(cas!=NULL) /* controllo se la lista non e' vuota */
    {
        if(num_casella!=cas->numero) /* faccio una ricerca della casella */
    	{
        	cas=cas->next;
		}
		else
		{
			break;
		}
	}
    switch(cas->tipo) /* in base al tipo della casella svolgo diverse funzioni */
    {
        case 0: /* casella di tipo: svago */
                printf("Hai vinto un turno di pausa relax.\n\nPremi [ENTER] per continuare.\n");
                getchar();
                break;
                
        case 1: /* casella di tipo: zone */
                if(strcmp(cas->proprietario,"")==0) /* controlla se non c'e' nessun proprietario nella casella */
                {
                    printf("\nLa zona %s non appartiene a nessuno.\nIl valore e': %d\nLa rendita e': %d\n", cas->nome, cas->valore, cas->rendita); /* stampa i dati della casella: nome, valore e rendita */
                    
                    if(g->saldo>=cas->valore) /* controllo se il saldo disponibile del giocatore e' sufficiente per acquistare la zona */
                    {
                        printf("\nPremi [s] per acquistare.\nPremi [ENTER] per non acquistare.\n");
                        scanf("%c", &c);
                        if(c=='S'||c=='s') /* acquisto della zona */
                        {
                            g->saldo=g->saldo-cas->valore; /* aggiorno il saldo del giocatore che ha acquistato*/
                            strcpy(cas->proprietario, g->nome); /* modifica del proprietario nella casella attuale */
                            if(g->pinG==NULL) /* se la lista delle proprieta' è vuota, aggiungo la prima proprieta' */
                            {
                                g->pinG=(casella*)malloc(sizeof(casella));
                                strcpy(g->pinG->proprietario, g->nome);
                                g->pinG->next=NULL;
                                g->pinG->numero=cas->numero;
                                g->pinG->rendita=cas->rendita;
                                g->pinG->valore=cas->valore;
                                strcpy(g->pinG->nome, cas->nome);
                            }
                            else /* altrimenti, continuo ad aggiungere proprieta' */ 
                            {
                                temp2=(casella*)malloc(sizeof(casella));
                                temp=g->pinG;    
                                while(temp->next!=NULL)
                                {
                                    temp=temp->next;
                                }
                                temp->next=temp2;
                                temp2->next=NULL;
                                strcpy(temp2->proprietario, g->nome);
                                temp2->numero=cas->numero;
                                temp2->rendita=cas->rendita;
                                temp2->valore=cas->valore;
                                strcpy(temp2->nome, cas->nome);
                            }
                                
                            printf("\nLa zona e' stata acquistata.\n");
                            getchar();
                            
                        }
                        else
                        {
                            printf("\nLa zona non e' stata acquistata.\n");
                            getchar();
                            
                        }
                    }
                        
                    else
                    {
                        printf("\nNon hai abbastanza saldo per acquistare la zona.\n");
                    }
                }
                else /* se la zona e' gia' di proprietà, si controlla il proprietario e, se e' diverso dal giocatore attuale si procede con l'aggiornamento del saldo */
                {                    
                    if(strcmp(cas->proprietario, g->nome)!=0) /* controllo se il giocatore attuale e' diverso dal proprietario della casella */
                    {
                        g->saldo=g->saldo-cas->rendita; /* aggiorno il saldo del giocatore attuale in base alla rendita della casella */
                        giocatore *temp=pin;
                        int trovato=0;
                        
                            do /* avvio una ricerca del proprietario della casella */
                            {
                                if(strcmp(cas->proprietario, temp->nome)==0)
                                {
                                    trovato=1;
                                }
                                else
                                {
                                    temp=temp->next;
                                }
                            }
                            while(trovato==0);
                            temp->saldo=temp->saldo+cas->rendita; /* aggiorno il saldo del proprietario della casella */
                            printf("\nLa zona %s appartiene a %s.\nLa rendita e' %d.", cas->nome, cas->proprietario, cas->rendita);
                    }
                    else
                    {
                    	printf("\nLa zona %s e' gia' di tua appartenenza.\n", cas->nome, cas->proprietario, cas->rendita);
					}
                            
                }
                printf("\n\nPremi [ENTER] per continuare.\n");
                getchar();
                break;
                    
            case 2: /* casella di tipo: aziende */
                if(strcmp(cas->proprietario,"")==0) /* controlla se non c'e' nessun proprietario nella casella */
                {
                        printf("\nL'azienda %s non appartiene a nessuno.\nIl valore e': %d\nLa rendita e': %d\n", cas->nome, cas->valore, cas->rendita); /* stampa di dati della casella: nome, valore e rendita */
                        if(g->saldo>=cas->valore) /* controllo se il saldo disponibile del giocatore e' sufficiente per acquistare la zona */
                        {
                                printf("\nPremi [s] per acquistare.\nPremi [ENTER] per non acquistare.\n");
                                scanf("%c", &c);
                                if((c=='S')||(c=='s')) /* acquisto dell'azienda */
                                {
                                    g->saldo=g->saldo-cas->valore; /* aggiorno il saldo del giocatore che ha acquistato*/
                                    strcpy(cas->proprietario, g->nome); /* modifica del proprietario nella casella attuale */
                                    if(g->pinG==NULL) /* se la lista delle proprieta' è vuota, aggiungo la prima proprieta' */
                                    {
                                        g->pinG=(casella*)malloc(sizeof(casella));
                                        strcpy(g->pinG->proprietario, g->nome);
                                        g->pinG->next=NULL;
                                        g->pinG->numero=cas->numero;
                                        g->pinG->rendita=cas->rendita;
                                        g->pinG->valore=cas->valore;
                                        strcpy(g->pinG->nome, cas->nome);
                                    }
                                    else /* altrimenti, continuo ad aggiungere proprieta' */
                                    {
                                        temp2=(casella*)malloc(sizeof(casella));
                                        temp=g->pinG;    
                                        while(temp->next!=NULL)
                                        {
                                            temp=temp->next;
                                        }
                                        temp->next=temp2;
                                        temp2->next=NULL;
                                        strcpy(temp2->proprietario, g->nome);
                                        temp2->numero=cas->numero;
                                        temp2->rendita=cas->rendita;
                                        temp2->valore=cas->valore;
                                        strcpy(temp2->nome, cas->nome);
                             
                                        printf("\nL'azienda e' stata acquistata.\n");
                                        getchar();
                                    }
                                }
                                else
                                {
                                    printf("\nL'azienda non e' stata acquistata.\n");
                                    getchar();
                                }                               
                        }
                        else
                        {
                            printf("\nNon hai abbastanza saldo per acquistare l'azienda\n");
                        }
                }
                else /* se l'azienda e' gia' di proprietà, si controlla il proprietario e, se e' diverso dal giocatore attuale si procede con l'aggiornamento del saldo */
                {
                        
                        if(strcmp(cas->proprietario, g->nome)!=0) /* controllo se il giocatore attuale e' diverso dal proprietario della casella */
                        {
                                g->saldo=g->saldo-cas->rendita; /* aggiorno il saldo del giocatore attuale in base alla rendita della casella */
                                giocatore *temp=pin;
                                int trovato=0;
                        
                            do /* avvio una ricerca del proprietario della casella */
                            {
                                if(strcmp(cas->proprietario, temp->nome)==0)
                                {
                                    trovato=1;
                                }
                                else
                                {
                                    temp=temp->next;
                                }
                            }
                            while(trovato==0);
                            temp->saldo=temp->saldo+cas->rendita; /* aggiorno il saldo del proprietario della casella */
                            printf("\nL'azienda %s appartiene a %s.\nLa rendita e' %d.", cas->nome, cas->proprietario, cas->rendita);
                        }
                        else
                        {
                        	printf("\nLa zona %s e' gia' di tua appartenenza.\n", cas->nome, cas->proprietario, cas->rendita);
						}                           
                }
                printf("\nPremi [ENTER] per continuare.\n");
                getchar();
                break;
                    
            case 3: /* casella di tipo: giochi */
                printf("Sei in una sala giochi!\n");
                rand_gioco(g); /* chiamo la funzione rand_gioco */
                printf("\nPremi [ENTER] per continuare.\n");
                getchar();
                break;
    }
}
    
void tabella(giocatore *pin,casella *pinc, giocatore *corr, int t) /* funzione per stampare la tabella in rempo reale, passo alla funzione i seguenti dati: puntatore alla lista giocatori, puntatore alla lista caselle, puntatore al giocatore attuale, numero dei due dati appena lanciati */
{
        giocatore *gioc;
        casella *cas;
        gioc=pin;
        int trovato=0;              
                
        //system("clr"); /* cancello la schermata per avere sempre la tabella aggiornata */
        printf("\n\t\t\t\t\t | MONOPOLY |\n");
        printf("\t _______________________________________________________________________________\n");
        printf("\t|\t%-20s %-10s %-20s %-5s \t\t|\n","","","","");
        printf("\t|\t%-20s %-10s %-20s %-5s \t\t|\n","Giocatore","Pos.","Casella","Saldo");
        printf("\t|\t%-20s %-10s %-20s %-5s \t\t|\n","","","","");
            
        do /* inserisco i giocatori all'interno della tabella */
        { 
            cas=pinc;

            while(cas!=NULL && trovato==0)
            {
                if(gioc->numero_casella!=cas->numero)
                {
                                
                    cas=cas->next;
                }
                else
                {
                    trovato=1;
                }
            }
            printf("\t|\t%-20s %-10d %-20s %-5d \t\t|\n",gioc->nome,gioc->numero_casella,cas->nome,gioc->saldo);
            gioc=gioc->next;
            trovato=0;
        }
        while(gioc!=pin);
                
        printf("\t|\t%-20s %-10s %-20s %-5s \t\t|\n","","","","");
        printf("\t|-------------------------------------------------------------------------------|\n");
                
        if(t!=0) /* stampa del giocatore in gioco, al primo avvio del gioco non ci saranno dadi lanciati, non appena il primo giocatore li lancia, la tabella si aggiornera' */
        {
            printf("\t| Giocatore in gioco: %-20s \t\t E' uscito il numero: %-2d|\n", corr->nome, t);
        }
        else
        {
            printf("\t| Giocatore in gioco: %-20s \t\t\t\t\t|\n", corr->nome);
        }
        printf("\t -------------------------------------------------------------------------------\n");
}

int menu()
{
            int t;
            //system("clr");
            printf("\t\t ------------------------------------- \n");
            printf("\t\t|             MONOPOLY                |\n");
            printf("\t\t|  Premi [1] per iniziare la partita. |\n");
            printf("\t\t|  Premi [0] per uscire.              |\n");
            printf("\t\t ------------------------------------- \n");
            scanf("%d", &t);
            return t;
}

int num_giocatori()
{
    int u;
    do
    {
        printf("Numero di giocatori? "); /* chiedo il numero di giocatori della partita */
        scanf("%d", &u);
                        
        if((u!=2)&&(u!=3)&&(u!=4)) /* faccio un controllo sull'inserimento del numero dei giocatori */
        {
            printf("2,3 o 4 giocatori.\n"); /* nel caso l'utente inserisse un valore diverso da 2, 3 o 4.. codice d'errore e nuovo inserimento */
            while(getchar()!='\n');
        }
    }
    while((u<2)||(u>4));
    return u;
}

void salva_lista(char nomef[10],giocatore *pin) /* funzione per salvare la lista giocatori. passo i seguenti dati: file player, puntatore all'inizio della lista giocatori */
{
    int n;
    FILE *pfile;
	FILE *pfileP;
    giocatore *p;
    casella *temp;
    char nomeFileP[20];
    pfile=fopen(nomef,"w+b"); /* apro il file player in scrittura (binario)*/
    if (pfile==NULL) /* controllo se il file esiste */
    {
        printf("\nErrore impossibile creare il file!");
        getchar();
    }
    else
    {
        p=pin;
        
        do /* salvo i giocatori insieme ai loro dati */
        {
            fwrite(p,sizeof(giocatore),1,pfile); /* trascrivo il giocatore uno alla volta */
			 if (p->pinG!=NULL)
			 {
				strcpy(nomeFileP,"");
				strcpy(nomeFileP,p->nome) ;
				strcat(nomeFileP,".bin");
	  			pfileP=fopen(nomeFileP,"w+b") ;
				temp=p->pinG;

				while(temp!=NULL)
				{
	    			fwrite(temp,sizeof(casella),1,pfileP);
	    			temp=temp->next;
				}
				fclose(pfileP);
			 }
			 p=p->next;
        }
        while(p!=pin);
    }
    fclose(pfile); /* chiusura del file */
 }
 
giocatore* carica_lista(char nomef[10]) /* funzione per caricare la lista giocatore nella partita da riprendere (dopo un'uscita da una partita non finita). passo i seguenti dati: file player. */
{
    FILE *pfile, *pfileP;
    giocatore *pin, *p,*punta;
    pin=NULL;
    p=NULL;
    casella *temp,*cas;
        char nomeFileP[20];
    
    pfile=fopen(nomef,"r+b"); /* apro il file player in scrittura (binario)*/
    
    if (pfile!=NULL) /* controllo se il file esiste */
    {
        while (!feof(pfile)) /* apro il file e creo la lista cominaciando ad allocare dinamicamente memoria ed aggiungo i giocatori uno alla volta */
        {
            p=(giocatore*)malloc(sizeof(giocatore));
            fread(p,sizeof(giocatore),1,pfile);

            if(!feof(pfile))
            {
                if (pin==NULL)
                {
                    pin=p;
                    p->next=pin;
                }
                else
                {
                    punta=pin;
                    while (punta->next!=pin)
                    {
                        punta=punta->next;
                    }
                    punta->next=p;
                    p->next=pin;
                }
                
            }
			if (p->pinG!=NULL) //esiste il file con le proprietà
			{
				strcpy(nomeFileP,"");
				strcpy(nomeFileP,p->nome) ;
				strcat(nomeFileP,".bin");
				pfileP=fopen(nomeFileP,"r+b"); /* apro il file caselle in scrittura (binario)*/
				if (pfileP==NULL) /* controllo se il file esiste */
				{
					printf("\nErrore impossibile aprire il file proprieta giocatore! %s",nomeFileP);
					getchar();
				}
				else
				{   
					p->pinG=NULL;
					printf("\nApertura file: %s",nomeFileP);
					while (!feof(pfileP))
					{
						temp=(casella*)malloc(sizeof(casella));

            			fread(temp,sizeof(casella),1,pfileP);

						if(!feof(pfileP))
						{

					        if (p->pinG==NULL)
					        {
					            p->pinG=temp;
					            temp->next=NULL;
					        }
					        else
					        {
					            cas=p->pinG;
					            while (cas->next!=NULL)
					            {
					                cas=cas->next;
					            }
					            cas->next=temp;
					            temp->next=NULL;
					        }
						}            						
					}
					fclose(pfileP);
				}
	   		}      		
    	}
    	fclose(pfile);
	}	
    else
    {
        printf("Impossibile aprire il file %s",nomef);
    }
    return pin;
}

void salva_caselle(char nomef[10],casella *cpin) /* funzione per salvare la lista caselle. passo i seguenti dati: file caselle, puntatore all'inizio della lista caselle */
{
    int n;
    FILE *pfile;
    casella *p;
    pfile=fopen(nomef,"w+b"); /* apro il file caselle in scrittura (binario)*/
    if (pfile==NULL) /* controllo se il file esiste */
    {
        printf("\nErrore impossibile creare il file!");
        getchar();
    }
    else
    {
        p=cpin;
        
        do /* salvo le caselle insieme ai loro dati */
        {
        fwrite(p,sizeof(casella),1,pfile); /* trascrivo la casella una alla volta */
        p=p->next;
        }
        while(p!=NULL);
    }
    fclose(pfile); /* chiusura del file */
 }

casella* carica_caselle(char nomef[10]) /* funzione per caricare la lista caselle nella partita da riprendere (dopo un'uscita da una partita non finita). passo i seguenti dati: file caselle. */
{
    FILE *pfile;
    casella *pin, *p,*punta;
    pin=NULL;
    p=NULL;
    
    pfile=fopen(nomef,"r+b"); /* apro il file caselle in scrittura (binario)*/
    if (pfile!=NULL) /* controllo se il file esiste */
    {
        while (!feof(pfile)) /* apro il file cominaciando ad allocare dinamicamente memoria ed aggiungo i giocatori uno alla volta */
        {
            p=(casella*)malloc(sizeof(casella));
            fread(p,sizeof(casella),1,pfile);

            if(!feof(pfile))
            {
                if (pin==NULL)
                {
                    pin=p;
                    p->next=NULL;
                }
                else
                {
                    punta=pin;
                    while (punta->next!=NULL)
                    {
                        punta=punta->next;
                    }
                    punta->next=p;
                    p->next=NULL;
                }
            }
        }
        fclose(pfile); /* chiudo il file */
    }
    else
    {
        printf("Impossibile aprire il file %s",nomef);
        getchar();
    }
    return pin;
}

void play(int e, int n, giocatore *head, casella *cpin, giocatore *g) /* funzione in cui si svolge tutto il gioco. passo i seguenti valori: numero del menu', numero giocatori, puntatore all'inizio della lista giocatori, puntatore all'inizio della lista caselle, puntatore giocatore attuale */
{
        int dadi=0;
        int ciclo=0;
        char ch;
        char nome[20];
        casella *temp;
        
        switch(e)
        {
            case 0:
                break;
            case 1:                      
                while(n>1) /* il gioco continua finche' nella lista rimane un solo giocatore */
                {

                        tabella(head,cpin,g,dadi); /* chiamo la funzione tabella (stampo la tabella) */
                        if((ciclo!=0) && (g==head)) /* se la partita e' appena stata salvata, do la possibilita' di uscire dalla partita senza perdere i dati della partita */
                        {
                            printf("\n%s\n-Premi [ENTER] per lanciare i dadi.\n-Premi [0 -> ENTER] per interrompere la partita.\n-Premi [1 -> ENTER] per vedere le tue proprieta'.\n", g->nome);
                        }
                        else
                        {
                            printf("\n%s\n-Premi [ENTER] per lanciare i dadi.\n-Premi [1 -> ENTER] per vedere le tue proprieta'\n", g->nome);
                        }
                
                        if(ciclo==0) /* per non incombere a problemi dati dal getchar (doppio invio) faccio eseguire questo ciclo solo all'inizio */
                        {
                            ch=getchar();
                            ciclo=1;
                        }
                        ch=getchar();
                        
                        if(ch=='0') /* se il giocatore, alla possibilita' di uscire, preme 0, la partita si chiude */
                        {
                            exit(0);
                        }
                        
                        if(ch=='1') /* se il giocatore, preme 1, stampa le proprieta' acquistate */
                        {
                            if(g->pinG!=NULL)
                            {
                                temp=g->pinG;
                                printf(" ----------------------------------------------------------");
                                printf("\n| %-20s \t%-10s \t%-10s \t%-10s |\n", "NOME:", "NUMERO:", "RENDITA:", "VALORE:");

								while(temp!=NULL)
                                {
                                printf("| %-20s \t%-10d \t%-10d \t%-10d |\n", temp->nome, temp->numero, temp->rendita, temp->valore);
                                    temp=temp->next;
                                }
                                printf(" ----------------------------------------------------------\n");
                                printf("Premi [ENTER] per lanciare i dadi.");
                                ch=getchar();
                            }
                            else
                            {
                                printf("\nNessuna proprieta'.\nPremi [ENTER] per lanciare i dadi.");
                                ch=getchar();
                            }
                            while(getchar()!='\n');
                        }
                                                
                        dadi=rand_dadi(); /* chiamo la funzione rand_dadi per generare i dadi */            
                        g->numero_casella=g->numero_casella+dadi; /* aggiorno la posizione del giocatore in gioco con il relativo numero uscito dai dati */

                        if(g->numero_casella>40) /* se si e' arrivati alla fine delle caselle, sottraggo 39 per ricominciare dall'inizio delle caselle, senza perdere la posizione effettiva */
                        {
                                g->numero_casella=g->numero_casella-40;
                        }
                
                        tabella(head,cpin,g,dadi); /* chiamo la funzione tabella per stampare la tabella aggiornata */
                        azione(g->numero_casella, g, cpin, head); /* in base alla casella in cui e' arrivato il giocatore, compie le diverse azioni (zona, azienda, svago, giochi) */

                        if(g->saldo<=0) /* non appena il giocatore raggiunge il saldo 0 o inferiore, viene cancellato dalla lista giocatore ed e' ufficialmente fuori dal gioco */
                        {
                                head=cancella_giocatore(g, head);
                                n=n-1;
                        }
                        
                        tabella(head,cpin,g,dadi); /* chiamo la funzione tabella per stampare la tabella aggiornata */
                        
                        g=g->next; /* adesso tocca al giocatore successivo */
                        if(g==head) /* non appena gioca l'ultimo giocatore, salvo la lista giocatori e le casella della partita attuale (sovrascrivendo i file ogni volta) */
                        {
                        	strcpy(nome, "player");
                            salva_lista(nome,head);
                            strcpy(nome, "caselle");
                            salva_caselle(nome,cpin);
                        }
                        
                        if(n==1) /* nel caso in cui nella lista rimanesse un unico giocatore, quello e' il vincitore, quindi finisce la partita e i file di salvataggio (per un eventuale ripresa del gioco) vengono cancellati */
                        {
                                printf("%s ha vinto!\n", head->nome);
                                remove("player");
                                remove("caselle");
                        }                                    
                }
                break;                                
        }
}

void menu_riavvio()
{
	    	printf("\t\t ------------------------------------------- \n");
            printf("\t\t|             	  MONOPOLY                  |\n");
            printf("\t\t|  C'e' una partita in sospeso.             |\n");
            printf("\t\t|  Premi [s] per continuarla.               |\n");
            printf("\t\t|  Premi [INVIO] per aprire il menu'.       |\n");
            printf("\t\t ------------------------------------------- \n");
}
int main()
{
        int n, e;
        char ch;
        char nome[20];
        FILE *pfile;
        giocatore *head, *g, *temp;
        casella *cpin;
        char nc[40][20];
		int tc[40];
        head=NULL; /* inizializzo la lista giocatori a NULL */
        cpin=NULL; /* inizializzo la lista caselle a NULL */
        nome_caselle(nc, tc);
       
        pfile=fopen("player", "r+b"); /* apro il file player in lettura (binario) */
        if(pfile!=NULL) /* controllo se esiste il file */
        {
			menu_riavvio();
            scanf("%c", &ch);
            
            if(ch=='s') /* 's' per dire di 'si' */
            {
                e=1;
                n=1;
                char nome[20];
                strcpy(nome, "player");
				head=carica_lista(nome); /* carico la lista giocatori della scorsa partita interrotta */
                temp=head;
                
                do /* controllo il numero di giocatori */
                {
                   if(temp->next!=head)
                   {
                       n=n+1;
                       temp=temp->next;
                   }
                }
                while(temp->next!=head);
                g=head;
                strcpy(nome, "caselle");
                cpin=carica_caselle(nome); /* carico le caselle della scorsa partita interrotta */
            }
            else /* nel caso l'utente non volesse riprendere la scorsa partita, parte il menu' normalmente */
            {
                e=menu();
                if(e==1) /* se l'utente inserisce (1), inizia la partita */
                {
                    n=num_giocatori();
                    cpin=genera_casella(nc, tc); /* genero la lista caselle */
                    head=genera_giocatori(n, head); /* genero la lista giocatori */
                    g=head;
                }
            }
        }
        else /* nel caso in cui non ci fossero dei file presenti in memoria, il programma si avviera' normalmente */
        {
                e=menu();
                
                if(e==1) /* se l'utente inserisce (1), inizia la partita */
                {
                    n=num_giocatori();
                    cpin=genera_casella(nc, tc); /* genero la lista delle caselle */
                    head=genera_giocatori(n, head); /* genero la lista giocatori */
                    g=head;
                }
        }     
        play(e,n,head,cpin,g);
}


 


