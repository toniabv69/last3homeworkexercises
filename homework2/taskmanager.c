#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VARIABLES
#include "processes.h"

extern Process processes[MAX_PROCESSES];
extern int processescount;

int main(void) {
    processescount = 0;
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = 0;
        strcpy(processes[i].name, "\0");
    }
    int lengthcheck = 1;
    int choice = 0;
    char newname[30] = "";
    int success = 0;
    int newid = 0;
    int kill_result = 0;
    while(choice != 4) {
        #if defined _WIN32
        system("cls");
        #elif defined __linux__
        system("clear");
        #endif
        printf("Task Manager\n\n");
        printf("1. Create a new process (Maximum processes : %d)\n", MAX_PROCESSES);
        printf("2. List all processes\n");
        printf("3. Kill a process\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                getchar();
                printf("Please input the name you want the new process to be called: ");
                scanf("%s", newname);
                for(int i = 0; newname[i] != '\0'; i++) {
                    lengthcheck = 0;
                    if(i > 30) {
                        lengthcheck = 1;
                        #if defined _WIN32
                        system("cls");
                        #elif defined __linux__
                        system("clear");
                        #endif
                        printf("The input name was too long. (max. 30 characters)\n");
                        printf("Press Enter to continue...\n");
                        getchar();
                        getchar();
                        break;
                    }
                }
                if(lengthcheck) break;
                for(int i = 0; newname[i] != '\0'; i++) {
                    if(newname[i] == '\n') newname[i] = '\0';
                }
                success = createnewprocess(newname);
                if(success == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("The process could not be created because there were too many processes running.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    getchar();
                } else if(success == -1) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("The process could not be created because there weren't any available process ids.\n");
                    printf("Please exit the program to create new processes.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    getchar();
                } else {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("The process was created successfully.\n");
                    printf("The id of the new process is %d.\n", success);
                    printf("Press Enter to continue...");
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
                getchar();
                for(int i = 0; i < MAX_PROCESSES; i++) {
                    printf("%-1d. %-10d %-30s\n", i + 1, processes[i].id, processes[i].name);
                }
                printf("Press Enter to continue...");
                getchar();
                break;
            case 3:
                #if defined _WIN32
                system("cls");
                #elif defined __linux__
                system("clear");
                #endif
                printf("Please input the id of the process you'd like to kill: ");
                scanf("%d", &newid);
                if(newid < 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("Invalid process id!\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                }
                kill_result = stopprocess(newid);
                if(kill_result == 0) {
                    #if defined _WIN32
                    system("cls");
                    #elif defined __linux__
                    system("clear");
                    #endif
                    printf("No process with input id was found!\n");
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
                    printf("Process killed successfully!\n");
                    printf("Press Enter to continue...\n");
                    getchar();
                    getchar();
                    break;
                }
                break;
            case 4:
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
    
}