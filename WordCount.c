/**
 * WordCount Program
 *
 * @author van_fantasy
 * @link https://tigerxly.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

/**
 * Struct Name: result
 * Struct discirption: The result of the program
 */
struct result{
    char operator;
    int cnt;
};

/**
 * Judge function used to judge whether a char represents the end of a word
 *
 * @param char c The char to judge
 * @return bool True if the char represents the end of a word
 */
bool is_end_of_word(char c){
    return (c == ' ' || c == '\n' || c == ',' || c == '\t' || c == '\0');
}

/**
 * Function used to count the characters
 *
 * @param FILE* file The file pointer represents the file to operate
 * @return int cnt the number of characters
 */
int count_characters(FILE* file){
    char cur_char;
    int cnt = 0;
    while(~fscanf(file, "%c", &cur_char)){
        cnt++;
    }
    return cnt;
}

/**
 * Function used to count the words
 *
 * @param FILE* file The file pointer represents the file to operate
 * @return int cnt the number of words
 */
int count_words(FILE* file){
    char cur_char;
    int cnt = 0;
    bool is_between_two_words = true; //True if the program is iterating between two words or the at the end of the file
    while(~fscanf(file, "%c", &cur_char)){
        if(is_end_of_word(cur_char)){
            if(!is_between_two_words){
                cnt++;
                is_between_two_words = true;
            }
        }
        else{
            is_between_two_words = false;
        }
    }
    if(!is_end_of_word(cur_char)){ //End of file handler
        if(!is_between_two_words){
            cnt++;
        }
    }
    return cnt;
}

/**
 * The main function
 */
int main(int argc, char* argv[]){
    //Input infomation
    char file_input[128]; //File path inputed
    char file_path[128]; //The complete path of the file
    char operator; //The operator
    operator = argv[1][1];
    strcpy(file_input, argv[2]);

    if(operator != 'w' && operator != 'c'){
        printf("%c\n", operator);
        printf("ERROR: Invalid Operator!\n");
        exit(0);
    }

    //Get the directory where the file is located
    char* file_directory = strrchr(argv[0], '\\');
    *(file_directory + 1) = '\0';
    strcpy(file_path, argv[0]);

    if(file_input[2] == '\\' && file_input[1] == ':'){ //Inputed a complete path
        strcpy(file_path, file_input);
    }
    else{ //Inputed a file name
        strcat(file_path, file_input);
    }

    //freopen(file_path, "r", stdin);
    FILE* file = fopen(file_path, "r");
    if(file == NULL){ //File does not exist
        printf("ERROR: File Does Not Exist!\n");
        exit(0);
    }

    if(operator == 'w'){
        printf("单词数：%d\n", count_words(file));
    }
    else{
        printf("字符数：%d\n", count_characters(file));
    }

    fclose(file);

    return 0;
}

