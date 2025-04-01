# Monopoly game in C (Messina Edition)
Project for the Fundamentals of Computer Science course in the Bachelor's degree program at the University of Messina.

## Overview
This project is a **simplified Monopoly game** implemented in **C**. The game follows the core mechanics of Monopoly, allowing multiple players to roll dice, move across the board, buy properties, pay rent, and compete until only one player remains financially solvent.

## Features
- **Turn-based gameplay** with player interactions
- **Property management** (buying, selling, rent payments)
- **Dice rolling mechanics** for movement
- **Bankruptcy system** that eliminates players when they run out of money
- **Basic AI (if included)** for computer-controlled players
- **Simple console interface** using `printf` and `scanf`
- **Save and Load feature**

## Project Structure
The code is structured into different sections, each responsible for specific functionalities of the game:

### 1. **Header Files and Constants**
The program includes standard C libraries such as:
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
```
- `stdio.h` - Handles input and output.
- `stdlib.h` - Used for memory management and random number generation.
- `time.h` - Used to seed the random number generator for dice rolls.
- `string.h` - Used for handling strings (e.g., copying names).
- `unistd.h` - Provides access to the POSIX API (e.g., for sleep functions).

### 2. **Data Structures**
The game relies on `struct` definitions to represent key components:

#### **Casella Structure**
```c
typedef struct casella {
    char proprietario[20];
    int numero;
    int rendita;
    int valore;
    int tipo;
    char nome[20];
    struct casella *next;
} casella;
```
- `proprietario` - Stores the owner of the property.
- `numero` - Stores the position of the property on the board.
- `rendita` - Rent value for the property.
- `valore` - Purchase cost of the property.
- `tipo` - Type of property.
- `next` - Pointer to the next property in the list.

#### **Giocatore Structure**
```c
typedef struct giocatore {
    char nome[20];
    int saldo;
    int numero_casella;
    struct giocatore *next;
    struct casella *pinG;
} giocatore;
```
- `nome` - Stores the player’s name.
- `saldo` - Represents the player’s available money.
- `numero_casella` - Tracks the player’s position on the board.
- `next` - Pointer to the next player.
- `pinG` - Pointer to the property the player is currently on.

### 3. **Core Game Functions**

#### **Game Setup: nome_caselle()**
Initializes the names and types of all board spaces.
```c
void nome_caselle(char nc[][20], int tc[]) {
    strcpy(nc[0],"Start");
    tc[0] = 0;
    strcpy(nc[1],"Giampilieri");
    tc[1] = 1;
    strcpy(nc[2],"Pesca");
    tc[2] = 0;
    // Additional property setup continues...
}
```

#### **Menu Display: menu()**
Displays the game menu and gets user input.
```c
int menu() {
    int t;
    printf("\t\t ------------------------------------- \n");
    printf("\t\t|             MONOPOLY                |\n");
    printf("\t\t|  Premi [1] per iniziare la partita. |\n");
    printf("\t\t|  Premi [0] per uscire.              |\n");
    printf("\t\t ------------------------------------- \n");
    scanf("%d", &t);
    return t;
}
```

#### **Rolling the Dice: rand_dadi()**
Generates a dice roll result.
```c
int rand_dadi() {
    int p, s, c;
    srand(time(0));
    p = rand() % 6 + 1; /* First die */
    s = rand() % 6 + 1; /* Second die */
    c = p + s; /* Sum of the dice */
    printf("\nE' uscito il numero: %d\nPremi [ENTER] per continuare.", c);
    while(getchar() != '\n');
    return c;
}
```

#### **Random Game Events: rand_gioco()**
Handles random game events when a player lands on a special space.
```c
void rand_gioco(giocatore *g) {
    int a, i, s;
    // Implementation for game mechanics when landing on special spaces
}
```

## How to Compile and Run
To compile the program using `gcc`:
```sh
gcc monopoly.c -o monopoly
```
To run the game:
```sh
./monopoly
```

## Possible Improvements
- **Multiplayer Mode**: Implement network-based multiplayer.
- **GUI Version**: Convert the console-based game into a graphical version.
- **More Game Rules**: Add house/hotel upgrades, Chance & Community Chest cards.

## Conclusion
This project is a great demonstration of **structs, loops, conditionals, and basic game logic** in C. It provides a functional yet simplified version of Monopoly that can be further improved with additional features.

---
Feel free to contribute, improve, or modify the game!

