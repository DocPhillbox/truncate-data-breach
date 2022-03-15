#include <stdio.h>
#include <string.h>

char filename[255];
char destination_folder[255];
char user_out_filename[255] = "user-";
char pass_out_filename[255] = "pass-";
char seperator[255];

void write_user(char *user, FILE *user_file) {
    fprintf(user_file, strcat(user, "\n"));
}

void write_pass(char *pass, FILE *pass_file) {
    fprintf(pass_file, strcat(pass, "\n"));
}

char *split_line_and_truncate(char *line, FILE *user_file, FILE *pass_file) {
    char *user = strtok(line, seperator);
    char *pass = strtok(strtok(NULL, ":;"), "\n");
    write_user(user, user_file);
    write_pass(pass, pass_file);
}

int main() {
    FILE *breach_file;
    const long line_size = 255;
    char line[line_size];

    printf("Enter the filename to split: ");
    gets(filename);
    printf("Enter destination folder: ");
    gets(destination_folder);
    printf("Enter separator (default: :;): ");
    gets(seperator);
    if (seperator[0] == NULL) {
        printf("okkdhfruhjbr");
        strcpy(seperator, ":;");
    }

    strcat(user_out_filename, filename);
    strcat(pass_out_filename, filename);

    breach_file = fopen(filename, "r");
    if (breach_file == NULL) {
        printf("File not found...\n");
        return 0;
    }

    fopen(user_out_filename, "w");
    fopen(pass_out_filename, "w");

    FILE *user_file = fopen(user_out_filename, "a");
    FILE *pass_file = fopen(pass_out_filename, "a");

    while (fgets(line, line_size, breach_file) != NULL) {
        split_line_and_truncate(line, user_file, pass_file);
    }

    fclose(user_file);
    fclose(pass_file);
    
    return 0;
}