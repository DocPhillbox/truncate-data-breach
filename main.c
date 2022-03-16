#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 255

char filename[MAX_BUFFER];
char destination_folder[MAX_BUFFER];
char user_out_filename[MAX_BUFFER] = "user-";
char pass_out_filename[MAX_BUFFER] = "pass-";
char seperator[MAX_BUFFER];

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
    char line[MAX_BUFFER];

    printf("Enter the filename to split: ");
    if (strlen(fgets(filename, MAX_BUFFER, stdin)) == 1)
        return 0;
    printf("Enter the seperator (default :;)");
    if (strlen(fgets(seperator, MAX_BUFFER, stdin)) == 1)
        strcpy(seperator, ":;");
    
    filename[strcspn(filename, "\n")] = 0;
    seperator[strcspn(seperator, "\n")] = 0;
    
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

    while (fgets(line, MAX_BUFFER, breach_file) != NULL) {
        split_line_and_truncate(line, user_file, pass_file);
    }

    fclose(user_file);
    fclose(pass_file);
    
    return 0;
}