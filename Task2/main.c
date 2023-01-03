#include <stdio.h>


//Function that returns length of the word
int length_calculate(char word[]){

    int i = 0;
    while (word[i] != ';'){
        i++;
    }
    return i;
}


int main (){

    //Hidden_word will be in format "....;"(With the semicolumn at the end).
    char hidden_word[] = "oleg;";

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


    while (left_parts_of_figure != 0){
        //Ask for the letter and position.
        int position = 0;
        char users_letter;

        printf("Type me the position of the letter:\n");
        getchar();
        scanf("%i", &position);

        printf("Type me the letter:\n");
        getchar();
        scanf("%c", &users_letter);

        //Now we have two possibilities.

        //If user guessed.
        if (hidden_word[position] == users_letter){
           guessed_word[position] = users_letter;
        }

        //If user did not guess.
        else if (hidden_word[position] != users_letter){
            left_parts_of_figure--;
        }
        for (int i = 0; i < size_of_hidden_word; i++){
            printf("%c", guessed_word[i]);
        }
        printf("\n");
        printf("You have %i tries left\n", left_parts_of_figure);
    }
}
