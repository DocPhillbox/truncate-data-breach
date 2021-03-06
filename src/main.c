#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define MAX_BUFFER 255

char filename[MAX_BUFFER];
char destination_folder[MAX_BUFFER];
char user_out_filename[MAX_BUFFER] = "user-";
char pass_out_filename[MAX_BUFFER] = "pass-";
char seperator[MAX_BUFFER];

/**
 * @brief Write user into destination file
 * 
 * @param user Username to write in destination
 * @param user_file User destination file
 */
void write_user(char *user, FILE *user_file) {
    fprintf(user_file, strcat(user, "\n"));
}

/**
 * @brief Write password into destination file
 * 
 * @param pass Password to write in destination
 * @param pass_file Password destination file
 */
void write_pass(char *pass, FILE *pass_file) {
    fprintf(pass_file, strcat(pass, "\n"));
}

/**
 * @brief Split line and truncate username and password into two different files
 * 
 * @param line Line of the file to truncate
 * @param user_file User destination file
 * @param pass_file Password destination file
 */
void split_line_and_truncate(char *line, FILE *user_file, FILE *pass_file) {
    char *user = strtok(line, seperator);
    char *pass = strtok(strtok(NULL, ":;"), "\n");
    write_user(user, user_file);
    write_pass(pass, pass_file);
}

/**
 * @brief Difference between start and end time in milliseconds
 * 
 * @param t0 Start time
 * @param t1 End time
 * @return float Difference in milliseconds
 */
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

/**
 * @brief 
 * 
 * @return int 1 file not found
 *             2 breach file not provided
 */
int main() {
    FILE *breach_file;
    char line[MAX_BUFFER];
    struct timeval t_start;
    struct timeval t_end;
    float elapsed_time_in_milliseconds;

    printf("Enter the filename to split: ");
    if (strlen(fgets(filename, MAX_BUFFER, stdin)) == 1) {
        return 2;
    }

    printf("Enter the seperator (default :;): ");
    if (strlen(fgets(seperator, MAX_BUFFER, stdin)) == 1) {
        strcpy(seperator, ":;");
    }
    
    filename[strcspn(filename, "\n")] = 0;
    seperator[strcspn(seperator, "\n")] = 0;
    
    strcat(user_out_filename, filename);
    strcat(pass_out_filename, filename);

    breach_file = fopen(filename, "r");
    if (breach_file == NULL) {
        printf("File not found...\n");
        return 1;
    }

    printf("Start truncat %s\n", filename);

    fopen(user_out_filename, "w");
    fopen(pass_out_filename, "w");

    FILE *user_file = fopen(user_out_filename, "a");
    FILE *pass_file = fopen(pass_out_filename, "a");

    gettimeofday(&t_start, 0);
    int num_line = 0;
    while (fgets(line, MAX_BUFFER, breach_file) != NULL) {
        split_line_and_truncate(line, user_file, pass_file);
        ++num_line;
    }
    gettimeofday(&t_end, 0);
    elapsed_time_in_milliseconds = timedifference_msec(t_start, t_end);
    printf("Truncate %d lines in %f milliseconds\n", num_line, elapsed_time_in_milliseconds);

    fclose(user_file);
    fclose(pass_file);
    fclose(breach_file);
    
    return 0;
}