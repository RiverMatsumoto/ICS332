#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // open file
    FILE* f = fopen("request_times.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    int num_requests = 0;
    double sum = 0;
    double prev = 0;
    int first_flag = 1;
    while (1)
    {
        // read times
        char line[100];
        fgets(line, 100, f);
        if (feof(f)) break;

        if (first_flag)
        {
            prev = atof(line);
            first_flag = 0;
            continue;
        }

        double current = atof(line);
        sum += current - prev;
        prev = current;
        num_requests++;
    }
    double total = sum / num_requests;
    printf("Total requests: %d\n", num_requests);
    printf("Average time between requests: %f\n", sum / num_requests);

    return 0;
}