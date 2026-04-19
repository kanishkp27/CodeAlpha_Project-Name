// Add Student
// Display Records
// Search Student
// Update Student
// Delete Student
// Uses structures + file handling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float marks;
};

void add() {
    FILE *fp = fopen("student.txt", "ab");
    struct student s;

    printf("Enter ID Name Marks: ");
    scanf("%d %s %f", &s.id, s.name, &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record Added!\n");
}

void display() {
    FILE *fp = fopen("student.txt", "rb");
    struct student s;

    printf("\nID\tName\tMarks\n");
    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}

void search() {
    FILE *fp = fopen("student.txt", "rb");
    struct student s;
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id == id) {
            printf("Found: %d %s %.2f\n", s.id, s.name, s.marks);
            found = 1;
        }
    }
    if(!found) printf("Record not found!\n");
    fclose(fp);
}

void update() {
    FILE *fp = fopen("student.txt", "rb+");
    struct student s;
    int id;

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id == id) {
            printf("Enter new Name and Marks: ");
            scanf("%s %f", s.name, &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            printf("Updated!\n");
            break;
        }
    }
    fclose(fp);
}

void deleteRecord() {
    FILE *fp = fopen("student.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    struct student s;
    int id;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    printf("Record Deleted!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteRecord(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}