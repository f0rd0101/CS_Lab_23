#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    char name[50];
    char airport[50];
    int passengers;
    float speed;
} Airliner;

int main() {
    
    Airliner airliners[MAX] = {
        {"Boeing 747", "Sumy", 416, 900.5},
        {"Airbus A320", "Lviv", 180, 840.0},
        {"Boeing 737", "Konotop", 215, 850.3},
        {"Embraer 190", "Odesa", 100, 820.2},
        {"Airbus A380", "Boryspil", 555, 950.6}
    };
    int count = 5; 

    char searchAirport[50];
    printf("Enter the name of the city to search: ");
    fgets(searchAirport, sizeof(searchAirport), stdin);
    searchAirport[strcspn(searchAirport, "\n")] = '\0';  

    FILE* file = fopen("results.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int found = 0;
    printf("\nAirliners registered at the airport \"%s\":\n", searchAirport);
    fprintf(file, "Airliners registered at the airport \"%s\":\n", searchAirport);

    for (int i = 0; i < count; i++) {
        if (strcmp(airliners[i].airport, searchAirport) == 0) {
            printf("----------------------------------------\n");
            printf("Name: %s\n", airliners[i].name);
            printf("Airport: %s\n", airliners[i].airport);
            printf("Number of passengers: %d\n", airliners[i].passengers);
            printf("Average speed: %.2f km/h\n", airliners[i].speed);

            fprintf(file, "----------------------------------------\n");
            fprintf(file, "Name: %s\n", airliners[i].name);
            fprintf(file, "Airport: %s\n", airliners[i].airport);
            fprintf(file, "Number of passengers: %d\n", airliners[i].passengers);
            fprintf(file, "Average speed: %.2f km/h\n", airliners[i].speed);
            found = 1;
        }
    }

    if (!found) {
        printf("No airliners registered at this airport.\n");
        fprintf(file, "No airliners registered at this airport.\n");
    }

    fclose(file);
    return 0;
}
