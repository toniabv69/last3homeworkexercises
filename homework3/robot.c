#include <stdio.h>
#include <stdlib.h>
#include "bitstate.h"

int main(void) {
    int choice = 0;
    int bit_index = 0;
    int result = 0;
    unsigned int bit_state = 0;
    int binary[32] = {0};
    while(choice != 6) {
        #if defined _WIN32
        system("cls");
        #elif defined __linux__
        system("clear");
        #endif
        printf("Robot Menu\n\n");
        printf("1. Turn on diode\n");
        printf("2. Turn off diode\n");
        printf("3. Toggle state of diode\n");
        printf("4. Check state of diode\n");
        printf("5. Print state of all diodes\n");
        printf("6. Exit\n");
        printf("(Please note: The diodes are 32)\n\n");
        printf("Please make a selection: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Please put in the number of the diode you want to turn on: ");
                scanf("%d", &bit_index);
                result = setbit(bit_index - 1);
                if(result == -1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Invalid diode number!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                } 
                if(result == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Diode turned on successfully!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                }
                break;
            case 2:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Please put in the number of the diode you want to turn off: ");
                scanf("%d", &bit_index);
                result = unsetbit(bit_index - 1);
                if(result == -1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Invalid diode number!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                } 
                if(result == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Diode turned off successfully!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                }
                break;
            case 3:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Please put in the number of the diode you want to toggle: ");
                scanf("%d", &bit_index);
                result = togglebit(bit_index - 1);
                if(result == -1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Invalid diode number!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                } 
                if(result == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Diode toggled successfully!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                }
                break;
            case 4:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Please put in the number of the diode you want to check: ");
                scanf("%d", &bit_index);
                result = isbitset(bit_index - 1);
                if(result == -1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Invalid diode number!\n");
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                } 
                if(result == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Diode %d is off.\n", bit_index);
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                }
                if(result == 1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Diode %d is on.\n", bit_index);
                    printf("Press Enter to return to menu...");
                    getchar();
                    getchar();
                }
                break;
            case 5:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                for(int i = 0; i < 32; i++) binary[i] = 0;
                bit_state = getbitstate();
                for(int i = 0; bit_state > 0; i++) {
                    binary[i] += bit_state % 2;
                    bit_state /= 2;
                }
                printf("(1 is on, 0 is off): \n");
                for(int i = 0; i < 32; i++) {
                    printf("%d", binary[i]);
                }
                printf("\nPress Enter to return to menu...");
                getchar();
                getchar();
                break;
            case 6:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                break;
            default:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Invalid choice!\n");
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}
