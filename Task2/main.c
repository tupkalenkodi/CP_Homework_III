#include <stdio.h>


//Function that returns length of the word
int length_calculate(char word[]){

    int i = 0;
    while (word[i] != ';'){
        i++;
    }
    return i;
}


int check_if_words_are_equal(char word1[], char word2[]){
    for (int j = 0; j < length_calculate(word1); j++){
        if (word1[j] != word2[j]){
            return 0;
        }
    }
    return 1;
}


int main (){
    //Hidden_word will be in format "....;"(With the semicolumn at the end).
    char hidden_word[20];

    //Assigning random value to hidden_word.
    char array_of_random_words[][20] = {"extreme;", "clarify;", "ton;", "compartment;", "rung;", "grimace;", "freshman;","command;", "ghostwriter;", "core;", "rack;", "beneficiary;", "hot;", "adoption;", "fun;", "myth;"};
    int random_number;
    printf("Choose some random number from 1 to 15:\n");
    scanf("%i", &random_number);

    printf("%s", array_of_random_words[random_number - 1]);

    //Variable that represent length of hidden_word.
    int size_of_hidden_word = length_calculate(hidden_word);

    //User's word.
    char guessed_word[size_of_hidden_word];

    //Filling guessed_word with underscores.
    for (int i = 0; i < size_of_hidden_word; i++){
        guessed_word[i] = '_';
        //printf("%c", guessed_word[i]);
    }

    //Number that corresponds quantity of possible guesses.
    int left_parts_of_figure = 6;

    //Printing the guessed word.
    for (int i = 0; i < size_of_hidden_word; i++){
        printf("%c", guessed_word[i]);
    }
    printf("\n");

    int result_of_comparison;
    
    while (left_parts_of_figure != 0){
        //If user won.
        result_of_comparison = check_if_words_are_equal(hidden_word, guessed_word);
        if (result_of_comparison == 1){
            printf("\n");
            printf("Congratulations, you won!");
            return 0;
        }
        else {
            //Ask for the letter and position.
            int position = 0;
            char users_letter;

            printf("Type me the position of the letter(Starting with 1):\n");
            scanf("%i", &position);
            getchar();
            printf("Type me the letter:\n");
            scanf("%c", &users_letter);
            getchar();

            //Now we have two possibilities.

            //If user guessed.
            if (hidden_word[position - 1] == users_letter) {
                guessed_word[position - 1] = users_letter;
            }

                //If user did not guess.
            else if (hidden_word[position - 1] != users_letter) {
                left_parts_of_figure--;
            }
            printf("\n");
            for (int i = 0; i < size_of_hidden_word; i++) {
                printf("%c", guessed_word[i]);
            }
            printf("\n");
            printf("You have %i tries left\n", left_parts_of_figure);
            printf("\n");
        }
    }
    //If user lost.
    printf("\n");
    printf("I am sorry, you lost\n");
    printf("Your word was: ");
    for (int i = 0; i < size_of_hidden_word; i++) {
        printf("%c", hidden_word[i]);
    }
    return 0;
}
