#include <iostream>

int userDb[50] = {123};
int main() {

    int userAge = 0;
    int userId;
    int option;
    int index = 1;
    bool isLoggedIn = false;
    bool progressOfAuth = true;
    bool isAuthenticated = false;
    bool startTheGame = false;

    int userCoins = 100;
    int guessedNum;
    int numbers[5] = {23,43,16,18,33};
    //43,16,18,33

    // \

    printf("Welcome To New Game\n");
    printf("Enter Your Age: ");
    scanf("%d", &userAge);
    if (userAge > 17){
        srand(time(NULL));
        printf("you are old enough to play the game\n");
        printf("choose option 1 to Sign In, choose option 2 to Sign Up and 3 to Exit\n");
        printf("option- ");
        scanf(" %d", &option);
        while (isAuthenticated == false && progressOfAuth == true) {
            if (option == 1) {
                while (isLoggedIn == false ) {
                    printf("Enter your user ID: ");
                    scanf(" %d", &userId);
                    for (int i = 0; i < 50; ++i) {
                        if (userDb[i] == userId){
                            printf("you have account\n");
                            isLoggedIn = true;
                        }
                    }
                    if (isLoggedIn == true) {
                        isAuthenticated = true;
                        printf("Here is your balance: %d\n",userCoins);
                        startTheGame = true;
                    } else  {
                        printf("You have no account with this ID: %d\n", userId);
                        printf("choose option 1 to Enter your ID again or 2 to Sign Up\n");
                        printf("option- ");
                        scanf(" %d", &option);
                        if (option == 1) {
                            isLoggedIn = false;
                        }else if (option == 2) {
                            break;
                        }
                    }
                }
            }else if (option == 2){
                printf("create your ID: \n");
                printf("ID: ");
                scanf(" %d", &userId);
                for (int j = 0; j < 50; ++j) {
                    if (userDb[j] == userId) {
                        printf("this ID is already taken!\n");
                        break;
                    }
                    isLoggedIn = true;
                }
                if (isLoggedIn == true) {
                    userDb[index] = userId;
                    index ++;
                    isAuthenticated = true;
                    startTheGame = true;
                    printf("Here is your balance: %d\n",userCoins);
                }

            }else if (option == 3){
                progressOfAuth = false;
                break;
            }else   {
                printf("invalid option!");
            }
        }

        if (startTheGame == true) {
            printf("Game Rule:  Guss the Number between  23,43,16,18 and 33\n");

            while ( userCoins > 0) {
                int answer = numbers[rand() % 5];
                int bet = 0;
                printf("How many Coins do you want to bet? You have %d", userCoins);
                printf(" coins.\n");
                printf("bet 0 to exit!\n");
                printf("bet: ");
                scanf(" %d", &bet);
                if (bet == 0) {
                    break;
                }
                printf("Guess the number!\n");
                printf("your answer: ");
                scanf(" %d", &guessedNum);
                if (answer == guessedNum) {
                    printf("YOU WIN!!\n");
                    userCoins = userCoins + bet;

                }else {
                    printf("YOU LOST!\n");
                    userCoins =  userCoins - bet;
                }
            }
            if (userCoins < 0) {
                printf("Game Over!");
            }
        }

    } else {
        printf("You are not old enough");
    }


    return 0;
}
