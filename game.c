#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

bool finish = false;
int checks = 0;
char winner;

int showStats(char map[]) {
    printf("#################################################################\n");
    printf("#\033[1;36m         XXX    XXX         OOOOOOO         XXX    XXX         \033[1;0m#\n");
    printf("#\033[1;36m         XXX    XXX       OOO     OOO       XXX    XXX         \033[1;0m#\n");
    printf("#\033[1;36m           XX  XX        OO         OO        XX  XX           \033[1;0m#\n");
    printf("#\033[1;36m            XXXX         OO         OO         XXXX            \033[1;0m#\n");
    printf("#\033[1;36m            XXXX         OO         OO         XXXX            \033[1;0m#\n");
    printf("#\033[1;36m           XX  XX        OO         OO        XX  XX           \033[1;0m#\n");
    printf("#\033[1;36m         XXX    XXX       OOO     OOO       XXX    XXX         \033[1;0m#\n");
    printf("#\033[1;36m         XXX    XXX         OOOOOOO         XXX    XXX         \033[1;0m#\n");
    printf("#################################################################\n");
    printf("---------------\n");
    printf(" ############# \n");
    printf(" # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \n", map[0], map[1], map[2]);
    printf(" ############# \n");
    printf(" # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \n", map[3], map[4], map[5]);
    printf(" ############# \n");
    printf(" # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \033[1;32m%c\033[1;0m # \n", map[6], map[7], map[8]);
    printf(" ############# \n");
    printf("---------------\n");
    return 0;
}

bool isGameOver(char map[]) {
    if (map[0] == map[1] && map[0] == map[2]) {
        winner = map[0];
        return true;
    } else if (map[3] == map[4] && map[3] == map[5]) {
        winner = map[3];
        return true;
    } else if (map[6] == map[7] && map[6] == map[8]) {
        winner = map[6];
        return true;
    }
    if (map[0] == map[3] && map[0] == map[6]) {
        winner = map[0];
        return true;
    } else if (map[1] == map[4] && map[1] == map[7]) {
        winner = map[1];
        return true;
    } else if (map[2] == map[5] && map[2] == map[8]) {
        winner = map[2];
        return true;
    }
    if (map[0] == map[4] && map[0] == map[8]) {
        winner = map[0];
        return true;
    } else if (map[6] == map[4] && map[6] == map[2]) {
        winner = map[6];
        return true;
    } else if (checks == 9) {
        winner = 'N';
        return true;
    }
    return false;
}

int main() {
    char turn = 'X';
    int choice;
    char map[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

    while (!finish) {
        checks++;
        system("cls");
        showStats(map);
        printf("Turn: %c\nChoose location: ", turn);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && map[choice - 1] != 'X' && map[choice - 1] != 'O') {
            map[choice - 1] = turn;
        } else {
            checks--;
            printf("\033[1;33mInvalid move. Try again.\033[1;0m\n");
            Sleep(1000);
            printf("- 1 -\n");
            Sleep(1000);
            printf("- 2 -\n");
            Sleep(1000);
            printf("- 3 -\n");
            Sleep(500);
            continue;
        }

        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }

        finish = isGameOver(map);
        if (finish)
        {
            system("cls");
            showStats(map);
            switch (winner)
            {
            case 'X':
                printf("#################################################################\n");
                printf("\033[1;32m   XXX    XXX        XX             XX    XX    XXXX     XX     \n");
                printf("   XXX    XXX        XX             XX    XX    XXXX     XX     \n");
                printf("     XX  XX          XX             XX          XX XX    XX     \n");
                printf("      XXXX           XX     XXX     XX    XX    XX  XX   XX     \n");
                printf("      XXXX            XX   XX XX   XX     XX    XX   XX  XX     \n");
                printf("     XX  XX            XX  XX XX  XX      XX    XX    XX XX     \n");
                printf("   XXX    XXX           XXXX   XXXX       XX    XX     XXXX     \n");
                printf("   XXX    XXX           XXXX   XXXX       XX    XX     XXXX     \033[1;0m\n");
                printf("#################################################################\n");
                break;
            case 'O':
                printf("#################################################################\n");
                printf("\033[1;32m      OOOOOOO         OO             OO    OO    OOOO     OO     \n");
                printf("    OOO     OOO       OO             OO    OO    OOOO     OO     \n");
                printf("   OO         OO      OO             OO          OO OO    OO     \n");
                printf("   OO         OO      OO     OOO     OO    OO    OO  OO   OO     \n");
                printf("   OO         OO       OO   OO OO   OO     OO    OO   OO  OO     \n");
                printf("   OO         OO        OO  OO OO  OO      OO    OO    OO OO     \n");
                printf("    OOO     OOO          OOOO   OOOO       OO    OO     OOOO     \n");
                printf("      OOOOOOO            OOOO   OOOO       OO    OO     OOOO     \033[1;0m\n");
                printf("#################################################################\n");
                break;
            
            default:
                printf("#################################################################\n");
                printf("\033[1;34m          XXX    XXX                        OOOOOOO              \n");
                printf("          XXX    XXX   ###############    OOO     OOO            \n");
                printf("            XX  XX     ###############   OO         OO           \n");
                printf("             XXXX                        OO         OO           \n");
                printf("             XXXX                        OO         OO           \n");
                printf("            XX  XX     ###############   OO         OO           \n");
                printf("          XXX    XXX   ###############    OOO     OOO            \n");
                printf("          XXX    XXX                        OOOOOOO              \033[1;0m\n");
                printf("#################################################################\n");
                break;
            }
        }
        
    }

    return 0;
}
