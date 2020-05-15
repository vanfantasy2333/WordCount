#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

int main(int argc, char* argv[]){
    //文件名与标识符读取
    char file_name[100];
    char file_direct[100];
    char prm[10];
    strcpy(prm, argv[1]);
    strcpy(file_name, argv[2]);
    char* direct_end = strrchr(argv[0], '\\');
    *(direct_end + 1) = '\0';
    strcpy(file_direct, argv[0]);
    if(file_name[2] == '\\' && file_name[1] == ':'){
        strcpy(file_direct, file_name);
    }
    else{
        strcat(file_direct, file_name);
    }
    //统计
    freopen(file_direct, "r", stdin);
    char cur_char;
    bool is_between_two_words = true;
    int char_cnt = 0;
    int word_cnt = 0;
    while(~scanf("%c", &cur_char)){
        char_cnt++;
        if(cur_char == ' ' || cur_char == '\n' || cur_char == ',' || cur_char == '\t' || cur_char == '\0'){
            if(!is_between_two_words){
                word_cnt++;
                is_between_two_words = true;
            }
        }
        else{
            is_between_two_words = false;
        }
    }
    if(!(cur_char == ' ' || cur_char == '\n' || cur_char == ',' || cur_char == '\t' || cur_char == '\0')){
        if(!is_between_two_words){
            word_cnt++;
        }
    }
    fclose(stdin);

    //输出结果
    if(prm[1] == 'c'){
        printf("字符数：%d\n", char_cnt);
    }
    if(prm[1] == 'w'){
        printf("单词数：%d\n", word_cnt);
    }

    return 0;
}

