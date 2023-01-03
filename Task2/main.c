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
    printf("You need to guess the word, moreover the length of it is given, however, you have 6 tries. \nIf you don't guess the letter the number of tries will decrease by 1, otherwise, the number of tries will stay the same.\n");
    //Hidden_word will be in format "....;"(With the semicolon at the end).
    char hidden_word[20];

    //Choosing some random word.
    char array_of_random_words[15][20] = {"extreme;", "clarify;", "ton;", "compartment;", "rung;", "grimace;", "freshman;","command;", "ghostwriter;", "core;", "rack;", "beneficiary;", "hot;", "adoption;", "fun"};
    int random_number;
    printf("Choose some random number from 1 to 15:\n");
    scanf("%i", &random_number);
    if (random_number != 1 && random_number != 2 && random_number != 3 && random_number != 4 && random_number != 5 && random_number != 6 && random_number != 7 && random_number != 8 && random_number != 9 && random_number != 10 && random_number != 11 && random_number != 12 && random_number != 13 && random_number != 14 && random_number != 15){
        printf("\n");
        printf("Provide me with correct number.\n");
        scanf("%i", &random_number);
        printf("\n");
    }

    //Assigning this word to hidden_word.
    for (int j = 0; j <= length_calculate(array_of_random_words[random_number - 1]); j++) {
        hidden_word[j] = array_of_random_words[random_number - 1][j];
    }

    //Variable that represent length of hidden_word.
    int size_of_hidden_word = length_calculate(hidden_word);

    //User's word.
    char guessed_word[size_of_hidden_word];

    //Filling guessed_word with underscores.
    int counter = 0;
    for (int i = 0; i < size_of_hidden_word; i++){
        guessed_word[i] = '_';
        printf("%c", guessed_word[i]);
        counter++;
    }
    guessed_word[counter] = ';';
    printf("\n");

    //Number that corresponds quantity of tries left.
    int left_parts_of_figure = 6;

    int result_of_comparison;
    while (left_parts_of_figure != 0){
        //If user won.
        result_of_comparison = check_if_words_are_equal(hidden_word, guessed_word);
        if (result_of_comparison == 1){
            printf("Congratulations, you won!");
            printf("\n");
            return 0;
        }
        else {
            //Ask for the letter.
            char users_letter;
            getchar();
            printf("Type me the letter:\n");
            scanf("%c", &users_letter);

            //Assign one additional variable, for case when user doesn't guess.
            char guessed_word_0[20];
            for (int n = 0; n <= length_calculate(hidden_word); n++) {
                guessed_word_0[n] = guessed_word[n];
            }

            //Now I check if user's letter contained in hidden_word.
            for (int k = 0; k <= length_calculate(hidden_word); k++) {
                //If user guessed.
                if (hidden_word[k] == users_letter) {
                    guessed_word[k] = users_letter;
                }
            }

            //If user haven't guessed.
            int comparison_result = check_if_words_are_equal(guessed_word_0, guessed_word);
            if (comparison_result == 1){
                left_parts_of_figure--;
            }

            //Print the modified word.
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
