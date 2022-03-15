#include <stdio.h>
#include <string.h>

char *filename = "data-breach.txt";
char user_out_filename[100] = "user-";
char pass_out_filename[100] = "pass-";
char *seperator = ":;";

void write_user(char *user) {
    FILE *user_file = fopen(user_out_filename, "a");
    fprintf(user_file, strcat(user, "\n"));
    fclose(user_file);
}

void write_pass(char *pass) {
    FILE *pass_file = fopen(pass_out_filename, "a");
    fprintf(pass_file, strcat(pass, "\n"));
    fclose(pass_file);
}

char *split_line_and_truncate(char *line) {
    char *user = strtok(line, seperator);
    char *pass = strtok(strtok(NULL, ":;"), "\n");
    write_user(user);
    write_pass(pass);
}

int main() {
    FILE *breach_file;
    const long line_size = 255;
    char line[line_size];

    strcat(user_out_filename, filename);
    strcat(pass_out_filename, filename);

    breach_file = fopen(filename, "r");
    if (breach_file == NULL) {
        printf("File not found...\n");
        return 0;
    }

    fopen(user_out_filename, "w");
    fopen(pass_out_filename, "w");

    while (fgets(line, line_size, breach_file) != NULL) {
        split_line_and_truncate(line);
    }
    
    return 0;
}