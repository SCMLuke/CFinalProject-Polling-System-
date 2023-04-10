#include <stdio.h>
#include <intrin.h>

struct userInfo {
    int voteChoice;
    char *userName;
    char *userPassword;
};

struct adminInfo {
    char *adminUserName;
    char *adminPassword;
};
struct candidateInfo {
    char *candidateFirstName;
    char *candidateLastName;
    int voteCount;
};

int main() {
    int exitValue = 0;
    int menuChoice;

    struct candidateInfo arr_candidate[2];  //Array of candidates in the pole.
    arr_candidate[0].candidateFirstName = "John";
    arr_candidate[0].candidateLastName = "President";
    arr_candidate[0].voteCount = 0;

    arr_candidate[1].candidateFirstName = "Primem";
    arr_candidate[1].candidateLastName = "Inister";
    arr_candidate[1].voteCount = 0;


    struct userInfo arr_user[1];    //Amount of voters in the pole. One for the test.
    arr_user[0].userName = "BobbyHill";
    arr_user[0].userPassword = "123";
    arr_user[0].voteChoice = 0;

    struct adminInfo testAdmin;
    testAdmin.adminUserName = "TestAdmin";
    testAdmin.adminPassword = "123";

    while (exitValue == 0) {
        printf("Polling System\n1 = User Voting\n2 = Admin Panel\n3 = Close Program\nEnter Choice: ");
        scanf("%d",&menuChoice);
        if(menuChoice == 1) {


            char userNameInput[30];
            char userPasswordInput[30];
            printf("\nUser Panel\nPlease enter your username/password.\nusername: ");
            scanf("%s",&userNameInput);
            printf("\nPassword: ");
            scanf("%s",&userPasswordInput);
            if(strcmp(userNameInput,arr_user[0].userName)==0 && strcmp(userPasswordInput,arr_user[0].userPassword)==0) {
                int userMenuChoice;
                printf("User Profile of: %s",arr_user[0].userName);
                printf("\n---------------\n");
                printf("1 = Cast Vote\n2 = Logout/Return to menu\n");
                scanf("%d",&userMenuChoice);
                if (userMenuChoice == 1) {
                    int userPresidentChoice;
                    printf("Who do you want to vote for?\n");
                    printf("1 = %s",arr_candidate[0].candidateLastName);
                    printf("\n2 = %s",arr_candidate[1].candidateLastName);
                    printf("\n");
                    scanf("%d",&userPresidentChoice);
                    if (userPresidentChoice == 1 && arr_user[0].voteChoice == 0) {
                        arr_candidate[0].voteCount++;
                        arr_user[0].voteChoice = 1;
                    } else if (userPresidentChoice == 2 && arr_user[0].voteChoice == 0) {
                        arr_candidate[1].voteCount++;
                        arr_user[0].voteChoice = 2;
                    } else {
                        printf("You have either selected an invalid candidate option, or have already voted.\n");
                    }
                } else if (userMenuChoice == 2) {
                    printf("\nReturning to Main Menu...\n");
                }
            } else {
                printf("Please enter valid user data!");
            }


        } else if (menuChoice == 2) {

            char adminUserNameInput[30];
            char adminPasswordInput[30];
            printf("\nAdmin Panel for polling officers.\nPlease enter your username/password.\nusername: ");
            scanf("%s",&adminUserNameInput);
            printf("\nPassword: ");
            scanf("%s",&adminPasswordInput);
            if (strcmp(adminUserNameInput,testAdmin.adminUserName)==0 && strcmp(adminPasswordInput,testAdmin.adminPassword)==0) {
                int loopValue = 0;
                while (loopValue == 0) {
                    int adminMenuChoice;
                    printf("Admin Panel");
                    printf("\n---------------\n");
                    printf("1 = Count Votes\n2 = Edit User Info\n3 = Logout/Return to menu\n");
                    scanf("%d", &adminMenuChoice);
                    if (adminMenuChoice == 1) {
                        printf("\nCandidate Name  -  Vote Amount\n");
                        printf("%s", arr_candidate[0].candidateLastName);
                        printf("  -  ");
                        printf("%d", arr_candidate[0].voteCount);
                        printf("\n");
                        printf("%s", arr_candidate[1].candidateLastName);
                        printf("  -  ");
                        printf("%d", arr_candidate[1].voteCount);
                        printf("\n\n");
                    } else if (adminMenuChoice == 2) {
                        int i;
                        int editChoice;
                        printf("\nSelect user to edit\n");
                        for (i = 0; i < 1; i++) {   //Condition for executing is i < voter array size.
                            printf("\n%d",i+1);
                            printf(" %s",arr_user[i].userName);
                            printf("\n\n");
                        }
                        scanf("%d",&editChoice);
                        int editLoop = 0;
                        switch (editChoice) {   //Switch case for each user. Add more for each user partaking.
                            case 1:
                                while (editLoop == 0) {
                                    int editSelection;
                                    printf("\nSelect what to edit (user/pass)\n1. Username\n2. Password\n");
                                    scanf("%d", &editSelection);
                                    if (editSelection == 1) {
                                        char newUserName[30];
                                        printf("\nEnter new Username:\n");
                                        scanf("%s", &newUserName);
                                        arr_user[editSelection-1].userName = newUserName;
                                        printf("\nNew Username: %s",arr_user[editSelection-1].userName);
                                        printf("\n");
                                        editLoop = 1;
                                    } else if (editSelection == 2) {
                                        char newUserPassword[30];
                                        printf("\nEnter new Password:\n");
                                        scanf("%s", &newUserPassword);
                                        arr_user[editSelection-2].userPassword = newUserPassword;
                                        printf("\nNew Password: %s",arr_user[editSelection-2].userPassword);
                                        printf("\n");
                                        editLoop = 1;
                                    } else {
                                        printf("\nPlease select a valid option\n");
                                        editLoop = 1;
                                    }
                                }
                                break;
                        }
                    } else if (adminMenuChoice == 3) {
                        printf("\nReturning to Main Menu...\n");
                        loopValue = 1;
                    } else {
                        printf("\nNot a valid option!\n");
                    }
                }
            } else {
                printf("Please enter valid admin data!");
            }

        } else if (menuChoice == 3) {
            return 0;
        }

    }

}
