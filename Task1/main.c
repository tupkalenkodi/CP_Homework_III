#include <stdio.h>

// Function that converts the floor from char format to an integer format.
int number_of_floor(char floor){
    if (floor == 'G'){
        return 0;
    }
    else if (floor == '1'){
        return 1;
    }
    else if (floor == '2'){
        return 2;
    }
    else if (floor == '3'){
        return 3;
    }
    else if (floor == '4'){
        return 4;
    }
    else if (floor == '5'){
        return 5;
    }
    else{
        return -4;
    }
}


//Function that returns floor number always in correct format.
char check(){
    //Creating and assigning two new variables, which represent floor in both formats.
    getchar();
    char floor;
    printf("Type the floor: ");
    scanf("%c\n", &floor);

    printf("%c\n", floor);
    int num;
    num = number_of_floor(floor);



    printf("%i\n", num);
    //Check if format is correct.
    if (num == -4){
        printf("Please, type the floor in the correct format(G, 1, 2, 3, 4, 5)\n");
        //Calling function recursively.
        check();
        return 1;
    }

    return floor;
}


char floor1 = 'G';
int num1 = 0;

int main() {
    //Ask if user wants to proceed.
    char general_answer = 'Y';
    printf("Do you want to proceed(Y, N):");
    getchar();
    scanf("%c\n", &general_answer);

    //Assigning two variables, which represents the floor where lift is now.
    char floor0 = floor1;
    int num0 = number_of_floor(floor0);

    while (general_answer == 'Y') {

        //Assigning two variables, which represents the floor where lift needs to get.
        floor1 = (char)check();
        num1 = number_of_floor(floor1);

        //Depending on type we have two possibilities.
        if (num0 >= num1) {
            for (int i = num0; i > num1; i--) {
                if (i == 0) {
                    printf("This is the first floor\n");
                    break;
                }
                printf("This is a floor number: %i\n", i);

                char answer;
                printf("Do you want to leave(Y, N): ");
                getchar();
                scanf("%c\n", &answer);

                if (answer == 'Y') {
                    break;
                }
                else if (answer == 'N') {
                    continue;
                }
            }
        }
        else if (num0 <= num1) {
            for (int i = num0; i <= num1; i++) {
                if (i == 5) {
                    printf("This is a last floor\n");
                    break;
                }
                printf("This is a floor number: %i\n", i);

                char answer;
                getchar();
                printf("Do you want to leave(Y, N): ");
                scanf("%c\n", &answer);

                if (answer == 'Y') {
                    break;
                }
                else if (answer == 'N') {
                    continue;
                }
            }
        }

        printf("Thank you, bye!");
        return 0;
    }
}

