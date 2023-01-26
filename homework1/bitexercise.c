#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned char rooms = '\0';
    int choice = 0;
    int room_choice = 0;
    while (choice != 3) {
        #if defined _WIN32
        system("cls");
        #elif defined __linux__
        system("clear");
        #endif
        printf("House Lights Control Menu\n");
        printf("1. Switch Lights\n");
        printf("2. Print State\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            #if defined _WIN32
            system("cls");
            #elif defined __linux__
            system("clear");
            #endif
            printf("Please select the room you want to switch the lights in: ");
            scanf("%d", &room_choice);
            if (room_choice < 1 || room_choice > 8) {
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
            } else {
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                rooms ^= (1 << (room_choice - 1));
                printf("Lights switched!\n");
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            }
            break;
        case 2:
            #if defined _WIN32
            system("cls");
            #elif defined __linux__
            system("clear");
            #endif
            printf("%d\n", rooms);
            printf("Printing Lit Room Numbers:\n");
            for(int i = 0; i < 8; i++) {
                if((rooms & (1 << i)) == (1 << i)) printf("%d\n", i + 1);
            }
            printf("Press Enter to continue...");
            getchar();
            getchar();
            break;
        case 3:
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
