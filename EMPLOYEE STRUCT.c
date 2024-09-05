#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
    struct Date dateOfJoining;
};

enum Department {
    HOD,
    Clerical
};

float calculateExperience(struct Date dateOfJoining) {
    struct Date currentDate = {4, 9, 2024};
    int experience = currentDate.year - dateOfJoining.year;

    if (currentDate.month < dateOfJoining.month || 
        (currentDate.month == dateOfJoining.month && currentDate.day < dateOfJoining.day)) {
        experience--;
    }

    return experience;
}

float calculateHODRemuneration(int experience, float salary) {
    switch (experience) {
        case 0:
        case 1:
        case 2:
            return salary * 0.02;
        case 3:
        case 4:
        case 5:
            return salary * 0.05;
        default:
            return salary * 0.10;
    }
}

float calculateClericalRemuneration(int experience, float salary) {
    switch (experience) {
        case 0:
        case 1:
        case 2:
            return salary * 0.05;
        case 3:
        case 4:
        case 5:
            return salary * 0.10;
        default:
            return 0.0;
    }
}

float calculateRemuneration(struct Employee emp) {
    int experience = calculateExperience(emp.dateOfJoining);
    float (*remunerationFunc)(int, float) = NULL;

    if (strcmp(emp.designation, "HOD") == 0) {
        remunerationFunc = calculateHODRemuneration;
    } else if (strcmp(emp.designation, "Clerical") == 0) {
        remunerationFunc = calculateClericalRemuneration;
    }

    if (remunerationFunc != NULL) {
        return remunerationFunc(experience, emp.salary);
    } else {
        return 0.0;
    }
}

int main() {
    struct Employee emp;
    char temp[50];

    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Designation (HOD/Clerical): ");
    scanf("%s", temp);
    if (strcmp(temp, "HOD") == 0)
        strcpy(emp.designation, "HOD");
    else if (strcmp(temp, "Clerical") == 0)
        strcpy(emp.designation, "Clerical");
    else {
        printf("Invalid Designation\n");
        return 1;
    }

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    printf("Enter Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp.dateOfJoining.day, &emp.dateOfJoining.month, &emp.dateOfJoining.year);

    printf("Remuneration for %s: %.2f\n", emp.name, calculateRemuneration(emp));

    return 0;
}
