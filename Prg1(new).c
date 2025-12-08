#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char* day_name;
    int date;
    char* activity;
};

struct Day* createDay(const char* name, int date, const char* activity) {
    struct Day* newDay = (struct Day*)malloc(sizeof(struct Day));
    if (newDay == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newDay->day_name = strdup(name);
    newDay->date = date;
    newDay->activity = strdup(activity);
    return newDay;
}

void freeDay(struct Day* day) {
    free(day->day_name);
    free(day->activity);
    free(day);
}

int main() {
    struct Day* calendar[7];

    calendar[0] = createDay("Monday", 1, "Working on project A");
    calendar[1] = createDay("Tuesday", 2, "Meetings with team");
    calendar[2] = createDay("Wednesday", 3, "Preparing presentation");
    calendar[3] = createDay("Thursday", 4, "Workshops on new technology");
    calendar[4] = createDay("Friday", 5, "Finishing report");
    calendar[5] = createDay("Saturday", 6, "Family's outing");
    calendar[6] = createDay("Sunday", 7, "Relaxing and unwind");

    for (int i = 0; i < 7; i++) {
        printf("Day %s (Date %d):\n", calendar[i]->day_name, calendar[i]->date);
        printf("Activity: %s\n", calendar[i]->activity);
        printf("\n");
    }

    for (int i = 0; i < 7; i++) {
        freeDay(calendar[i]);
    }

    return 0;
}
