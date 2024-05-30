#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
    int id;
    char stu_name[50], department[20];
    float university_current_result, university_overall_result;
    long long int stu_p_number, stu_fathers_p_number, stu_mothers_p_number;
    char present_address[200], permanent_address[200];
    char stu_fathers_name[50], stu_mothers_name[50];
    char stu_blood_group[7];
    char university_name[100], section[5], semester[5];
    char college_name[100], hsc_board[20];
    float hsc_gpa, ssc_gpa;
    int hsc_passing_year, ssc_passing_year;
    char school_name[100],ssc_board[20];
    char about_student_details[500];

    struct node *next;
    struct node *previous;
} *start = NULL, *end = NULL;


void create_students_record() {
    struct node *new_node, *current;
    int i, number_of_node;

    printf("\n\n\n\n\n\n\t\t\tEnter Number of Student's for Record: ");
    scanf("%d", &number_of_node);

    FILE *file = fopen("Student's Record.txt", "a+");
    if (file == NULL) {
        printf("File does not create.\n");
        exit(1);
    }

    for (i = 1; i <= number_of_node; i++) {
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("\nMemory Does Not Created.\n");
            exit(0);
        }

        printf("\n\n\t\t\tStudent's Details\n");
        fprintf(file, "\n\n\t\t\tStudent's Details\n");
        printf("\t\t_________________________________\n");
        fprintf(file, "\t\t_________________________________\n");

        printf("\n\n\tEnter Student Name: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->stu_name, sizeof(new_node->stu_name), stdin);
        new_node->stu_name[strcspn(new_node->stu_name, "\n")] = 0; // Remove newline character
        fprintf(file, "\n\tStudent Name: %s", new_node->stu_name);

        printf("\n\tID: ");
        scanf("%d", &new_node->id);
        fprintf(file, "\n\tID: %d", new_node->id);

        printf("\n\tSection: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->section, sizeof(new_node->section), stdin);
        new_node->section[strcspn(new_node->section, "\n")] = 0;
        fprintf(file, "\n\tSection: %s", new_node->section);

        printf("\n\tSemester: ");
        fgets(new_node->semester, sizeof(new_node->semester), stdin);
        new_node->semester[strcspn(new_node->semester, "\n")] = 0;
        fprintf(file, "\n\tSemester: %s", new_node->semester);

        printf("\n\tDepartment: ");
        fgets(new_node->department, sizeof(new_node->department), stdin);
        new_node->department[strcspn(new_node->department, "\n")] = 0;
        fprintf(file, "\n\tDepartment: %s", new_node->department);

        printf("\n\tUniversity Name: ");
        fgets(new_node->university_name, sizeof(new_node->university_name), stdin);
        new_node->university_name[strcspn(new_node->university_name, "\n")] = 0;
        fprintf(file, "\n\tUniversity Name: %s", new_node->university_name);

        printf("\n\tStudent Blood Group: ");
        fgets(new_node->stu_blood_group, sizeof(new_node->stu_blood_group), stdin);
        new_node->stu_blood_group[strcspn(new_node->stu_blood_group, "\n")] = 0;
        fprintf(file, "\n\tStudent Blood Group: %s", new_node->stu_blood_group);

        printf("\n\tUniversity Current Semester Result: ");
        scanf("%f", &new_node->university_current_result);
        fprintf(file, "\n\tUniversity Current Semester Result: %.2f", new_node->university_current_result);

        printf("\n\tUniversity Overall Result: ");
        scanf("%f", &new_node->university_overall_result);
        fprintf(file, "\n\tUniversity Overall Result: %.2f", new_node->university_overall_result);

        printf("\n\n\n\t\t\tStudent's Background\n");
        fprintf(file, "\n\n\n\t\t\tStudent's Background\n");
        printf("\t\t____________________________________\n");
        fprintf(file, "\t\t____________________________________\n");

        printf("\n\n\tCollege Name: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->college_name, sizeof(new_node->college_name), stdin);
        new_node->college_name[strcspn(new_node->college_name, "\n")] = 0;
        fprintf(file, "\n\n\tCollege Name: %s", new_node->college_name);

        printf("\n\tH.S.C Passing Year: ");
        scanf("%d", &new_node->hsc_passing_year);
        fprintf(file, "\n\tH.S.C Passing Year: %d", new_node->hsc_passing_year);

        printf("\n\tH.S.C Result in GPA: ");
        scanf("%f", &new_node->hsc_gpa);
        fprintf(file, "\n\tH.S.C Result in GPA: %.2f", new_node->hsc_gpa);

        printf("\n\n\tH.S.C Board: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->hsc_board, sizeof(new_node->hsc_board), stdin);
        new_node->hsc_board[strcspn(new_node->hsc_board, "\n")] = 0;
        fprintf(file, "\n\tH.S.C Board: %s", new_node->hsc_board);

        printf("\n\tSchool Name: ");
        fgets(new_node->school_name, sizeof(new_node->school_name), stdin);
        new_node->school_name[strcspn(new_node->school_name, "\n")] = 0;
        fprintf(file, "\n\tSchool Name: %s", new_node->school_name);

        printf("\n\tS.S.C Passing Year: ");
        scanf("%d", &new_node->ssc_passing_year);
        fprintf(file, "\n\tS.S.C Passing Year: %d", new_node->ssc_passing_year);

        printf("\n\tS.S.C Result in GPA: ");
        scanf("%f", &new_node->ssc_gpa);
        fprintf(file, "\n\tS.S.C Result in GPA: %.2f", new_node->ssc_gpa);

        printf("\n\n\tS.S.C Board: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->ssc_board, sizeof(new_node->ssc_board), stdin);
        new_node->ssc_board[strcspn(new_node->ssc_board, "\n")] = 0;
        fprintf(file, "\n\tS.S.C Board: %s", new_node->ssc_board);

        printf("\n\n\n\t\t\tStudent's Contact Information\n");
        fprintf(file, "\n\n\n\t\t\tStudent's Contact Information\n");
        printf("\t\t_____________________________________________\n");
        fprintf(file, "\t\t_____________________________________________\n");

        printf("\n\n\tStudent's Phone Number: ");
        scanf("%lld", &new_node->stu_p_number);
        fprintf(file, "\n\n\tStudent's Phone Number: %lld", new_node->stu_p_number);

        printf("\n\tFather's Name: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->stu_fathers_name, sizeof(new_node->stu_fathers_name), stdin);
        new_node->stu_fathers_name[strcspn(new_node->stu_fathers_name, "\n")] = 0;
        fprintf(file, "\n\tFather's Name: %s", new_node->stu_fathers_name);

        printf("\n\tMother's Name: ");
        fgets(new_node->stu_mothers_name, sizeof(new_node->stu_mothers_name), stdin);
        new_node->stu_mothers_name[strcspn(new_node->stu_mothers_name, "\n")] = 0;
        fprintf(file, "\n\tMother's Name: %s", new_node->stu_mothers_name);

        printf("\n\tFather's Phone Number: ");
        scanf("%lld", &new_node->stu_fathers_p_number);
        fprintf(file, "\n\tFather's Phone Number: %lld", new_node->stu_fathers_p_number);

        printf("\n\tMother's Phone Number: ");
        scanf("%lld", &new_node->stu_mothers_p_number);
        fprintf(file, "\n\tMother's Phone Number: %lld", new_node->stu_mothers_p_number);

        printf("\n\n\tPresent Address: ");
        getchar(); // Clear newline character from the buffer
        fgets(new_node->present_address, sizeof(new_node->present_address), stdin);
        new_node->present_address[strcspn(new_node->present_address, "\n")] = 0;
        fprintf(file, "\n\tPresent Address: %s", new_node->present_address);

        printf("\n\tPermanent Address: ");
        fgets(new_node->permanent_address, sizeof(new_node->permanent_address), stdin);
        new_node->permanent_address[strcspn(new_node->permanent_address, "\n")] = 0;
        fprintf(file, "\n\tPermanent Address: %s", new_node->permanent_address);

        printf("\n\tOther's Details and Comment: ");
        fgets(new_node->about_student_details, sizeof(new_node->about_student_details), stdin);
        new_node->about_student_details[strcspn(new_node->about_student_details, "\n")] = 0;
        fprintf(file, "\n\tOther's Details and Comment: %s", new_node->about_student_details);

        new_node->next = NULL;
        new_node->previous = NULL;

        if (start == NULL && end == NULL) {
            start = new_node;
            end = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            new_node->previous = current;
            current = new_node;
            end = new_node;
        }
    }

    fclose(file);
}



void add_student_record_at_first()
{
    struct node *new_node, *current;
    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory Does Not Created.\n");
        exit(0);
    }
    else
    {
        FILE *file = fopen("Student's Record.txt","a+");
        if(file == NULL)
        {
            printf("File does not create.\n");
        }
        else
        {
            printf("\n\n\t\t\tStudent's Details\n");
            fprintf(file,"\n\n\t\t\tStudent's Details\n");
            printf("\t\t_________________________________\n");
            fprintf(file,"\t\t_________________________________\n");

            printf("\n\n\tEnter Student Name: ");
            fflush(stdin);
            gets(new_node->stu_name);
            fprintf(file,"\n\tStudent Name: %s", new_node->stu_name);

            printf("\n\tID: ");
            scanf("%d", &new_node->id);
            fprintf(file,"\n\tID: %d",new_node->id);

            printf("\n\tSection: ");
            fflush(stdin);
            gets(new_node->section);
            fprintf(file,"\n\tSection: %s", new_node->section);

            printf("\n\tSemester: ");
            fflush(stdin);
            gets(new_node->semester);
            fprintf(file,"\n\tSemester: %s", new_node->semester);

            printf("\n\tDepartment: ");
            fflush(stdin);
            gets(new_node->department);
            fprintf(file,"\n\tDepartment: %s", new_node->department);

            printf("\n\tUniversity Name: ");
            fflush(stdin);
            gets(new_node->university_name);
            fprintf(file,"\n\tUniversity Name: %s", new_node->university_name);

            printf("\n\tStudent Blood Group: ");
            fflush(stdin);
            gets(new_node->stu_blood_group);
            fprintf(file,"\n\tStudent Blood Group: %s", new_node->stu_blood_group);

            printf("\n\tUniversity Current Semester Result: ");
            scanf("%f", &new_node->university_current_result);
            fprintf(file,"\n\tUniversity Current Semester Result: %0.2f",new_node->university_current_result);

            printf("\n\tUniversity Overall Result: ");
            scanf("%f", &new_node->university_overall_result);
            fprintf(file,"\n\tUniversity Overall Result: %0.2f",new_node->university_overall_result);

            printf("\n\n\n\t\t\tStudent's Background\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Background\n");
            printf("\t\t____________________________________");
            fprintf(file,"\t\t____________________________________");

            printf("\n\n\tCollege Name: ");
            fflush(stdin);
            gets(new_node->college_name);
            fprintf(file,"\n\n\tCollege Name: %s", new_node->college_name);

            printf("\n\tH.S.C Passing Year: ");
            scanf("%d", &new_node->hsc_passing_year);
            fprintf(file,"\n\tH.S.C Passing Year: %d",new_node->hsc_passing_year);

            printf("\n\tH.S.C Result in GPA: ");
            scanf("%f", &new_node->hsc_gpa);
            fprintf(file,"\n\tH.S.C Result in GPA: %0.2f",new_node->hsc_gpa);

            printf("\n\tH.S.C Board: ");
            fflush(stdin);
            gets(new_node->hsc_board);
            fprintf(file,"\n\tH.S.C Board: %s", new_node->hsc_board);

            printf("\n\tSchool Name: ");
            fflush(stdin);
            gets(new_node->school_name);
            fprintf(file,"\n\tSchool Name: %s", new_node->school_name);

            printf("\n\tS.S.C Passing Year: ");
            scanf("%d", &new_node->ssc_passing_year);
            fprintf(file,"\n\tS.S.C Passing Year: %d",new_node->ssc_passing_year);

            printf("\n\tS.S.C Result in GPA: ");
            scanf("%f", &new_node->ssc_gpa);
            fprintf(file,"\n\tS.S.C Result in GPA: %0.2f",new_node->ssc_gpa);

            printf("\n\tS.S.C Board: ");
            fflush(stdin);
            gets(new_node->ssc_board);
            fprintf(file,"\n\tS.S.C Board: %s", new_node->ssc_board);

            printf("\n\n\n\t\t\tStudent's Contract Information\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Contract Information\n");
            printf("\t\t_____________________________________________");
            fprintf(file,"\t\t_____________________________________________");

            printf("\n\n\tStudent's Phone Number: ");
            scanf("%lld", &new_node->stu_p_number);
            fprintf(file,"\n\n\tStudent's Phone Number: %lld",new_node->stu_p_number);

            printf("\n\tFather's Name: ");
            fflush(stdin);
            gets(new_node->stu_fathers_name);
            fprintf(file,"\n\tFather's Name: %s",new_node->stu_fathers_name);

            printf("\n\tMother's Name: ");
            fflush(stdin);
            gets(new_node->stu_mothers_name);
            fprintf(file,"\n\tMother's Name: %s",new_node->stu_mothers_name);

            printf("\n\tFather's Phone Number: ");
            scanf("%lld", &new_node->stu_fathers_p_number);
            fprintf(file,"\n\tFather's Phone Number: %lld",new_node->stu_fathers_p_number);

            printf("\n\tMother's Phone Number: ");
            scanf("%lld", &new_node->stu_mothers_p_number);
            fprintf(file,"\n\tMother's Phone Number: %lld",new_node->stu_mothers_p_number);

            printf("\n\tPresent Address: ");
            fflush(stdin);
            gets(new_node->present_address);
            fprintf(file,"\n\tPresent Address: %s",new_node->present_address);

            printf("\n\tPermanent Address: ");
            fflush(stdin);
            gets(new_node->permanent_address);
            fprintf(file,"\n\tPermanent Address: %s",new_node->permanent_address);

            printf("\n\tOther's Details and Comment: ");
            fflush(stdin);
            gets(new_node->about_student_details);
            fprintf(file,"\n\tOther's Details and Comment: %s",new_node->about_student_details);

            fclose(file);
        }
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    if (start != NULL) {
        current = start;
        new_node->next = current;
        current->previous = new_node;
    }
    start = new_node;
}



void add_student_record_at_last()
{
    struct node *new_node, *current;
    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory Does Not Created.\n");
        exit(0);
    }
    else
    {
        FILE *file = fopen("Student's Record.txt","a+");
        if(file == NULL)
        {
            printf("File does not create.\n");
        }
        else
        {
            printf("\n\n\t\t\tStudent's Details\n");
            fprintf(file,"\n\n\t\t\tStudent's Details\n");
            printf("\t\t_________________________________\n");
            fprintf(file,"\t\t_________________________________\n");

            printf("\n\n\tEnter Student Name: ");
            fflush(stdin);
            gets(new_node->stu_name);
            fprintf(file,"\n\tStudent Name: %s", new_node->stu_name);

            printf("\n\tID: ");
            scanf("%d", &new_node->id);
            fprintf(file,"\n\tID: %d",new_node->id);

            printf("\n\tSection: ");
            fflush(stdin);
            gets(new_node->section);
            fprintf(file,"\n\tSection: %s", new_node->section);

            printf("\n\tSemester: ");
            fflush(stdin);
            gets(new_node->semester);
            fprintf(file,"\n\tSemester: %s", new_node->semester);

            printf("\n\tDepartment: ");
            fflush(stdin);
            gets(new_node->department);
            fprintf(file,"\n\tDepartment: %s", new_node->department);

            printf("\n\tUniversity Name: ");
            fflush(stdin);
            gets(new_node->university_name);
            fprintf(file,"\n\tUniversity Name: %s", new_node->university_name);

            printf("\n\tStudent Blood Group: ");
            fflush(stdin);
            gets(new_node->stu_blood_group);
            fprintf(file,"\n\tStudent Blood Group: %s", new_node->stu_blood_group);

            printf("\n\tUniversity Current Semester Result: ");
            scanf("%f", &new_node->university_current_result);
            fprintf(file,"\n\tUniversity Current Semester Result: %0.2f",new_node->university_current_result);

            printf("\n\tUniversity Overall Result: ");
            scanf("%f", &new_node->university_overall_result);
            fprintf(file,"\n\tUniversity Overall Result: %0.2f",new_node->university_overall_result);

            printf("\n\n\n\t\t\tStudent's Background\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Background\n");
            printf("\t\t____________________________________");
            fprintf(file,"\t\t____________________________________");

            printf("\n\n\tCollege Name: ");
            fflush(stdin);
            gets(new_node->college_name);
            fprintf(file,"\n\n\tCollege Name: %s", new_node->college_name);

            printf("\n\tH.S.C Passing Year: ");
            scanf("%d", &new_node->hsc_passing_year);
            fprintf(file,"\n\tH.S.C Passing Year: %d",new_node->hsc_passing_year);

            printf("\n\tH.S.C Result in GPA: ");
            scanf("%f", &new_node->hsc_gpa);
            fprintf(file,"\n\tH.S.C Result in GPA: %0.2f",new_node->hsc_gpa);

            printf("\n\tH.S.C Board: ");
            fflush(stdin);
            gets(new_node->hsc_board);
            fprintf(file,"\n\tH.S.C Board: %s", new_node->hsc_board);

            printf("\n\tSchool Name: ");
            fflush(stdin);
            gets(new_node->school_name);
            fprintf(file,"\n\tSchool Name: %s", new_node->school_name);

            printf("\n\tS.S.C Passing Year: ");
            scanf("%d", &new_node->ssc_passing_year);
            fprintf(file,"\n\tS.S.C Passing Year: %d",new_node->ssc_passing_year);

            printf("\n\tS.S.C Result in GPA: ");
            scanf("%f", &new_node->ssc_gpa);
            fprintf(file,"\n\tS.S.C Result in GPA: %0.2f",new_node->ssc_gpa);

            printf("\n\tS.S.C Board: ");
            fflush(stdin);
            gets(new_node->ssc_board);
            fprintf(file,"\n\tS.S.C Board: %s", new_node->ssc_board);

            printf("\n\n\n\t\t\tStudent's Contract Information\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Contract Information\n");
            printf("\t\t_____________________________________________");
            fprintf(file,"\t\t_____________________________________________");

            printf("\n\n\tStudent's Phone Number: ");
            scanf("%lld", &new_node->stu_p_number);
            fprintf(file,"\n\n\tStudent's Phone Number: %lld",new_node->stu_p_number);

            printf("\n\tFather's Name: ");
            fflush(stdin);
            gets(new_node->stu_fathers_name);
            fprintf(file,"\n\tFather's Name: %s",new_node->stu_fathers_name);

            printf("\n\tMother's Name: ");
            fflush(stdin);
            gets(new_node->stu_mothers_name);
            fprintf(file,"\n\tMother's Name: %s",new_node->stu_mothers_name);

            printf("\n\tFather's Phone Number: ");
            scanf("%lld", &new_node->stu_fathers_p_number);
            fprintf(file,"\n\tFather's Phone Number: %lld",new_node->stu_fathers_p_number);

            printf("\n\tMother's Phone Number: ");
            scanf("%lld", &new_node->stu_mothers_p_number);
            fprintf(file,"\n\tMother's Phone Number: %lld",new_node->stu_mothers_p_number);

            printf("\n\tPresent Address: ");
            fflush(stdin);
            gets(new_node->present_address);
            fprintf(file,"\n\tPresent Address: %s",new_node->present_address);

            printf("\n\tPermanent Address: ");
            fflush(stdin);
            gets(new_node->permanent_address);
            fprintf(file,"\n\tPermanent Address: %s",new_node->permanent_address);

            printf("\n\tOther's Details and Comment: ");
            fflush(stdin);
            gets(new_node->about_student_details);
            fprintf(file,"\n\tOther's Details and Comment: %s",new_node->about_student_details);

            fclose(file);
        }
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    if (end != NULL) {
        current = end;
        current->next = new_node;
        new_node->previous = current;
    }
    end = new_node;
}



void add_student_record_at_middle()
{
    struct node *new_node, *current, *temp1, *temp2;
    int i,student_id,position;

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory Does Not Created.\n");
        exit(0);
    }
    else
    {
        FILE *file = fopen("Student's Record.txt","a+");
        if(file == NULL)
        {
            printf("File does not create.\n");
        }
        else
        {
            printf("\n\n\t\t\tStudent's Details\n");
            fprintf(file,"\n\n\t\t\tStudent's Details\n");
            printf("\t\t_________________________________\n");
            fprintf(file,"\t\t_________________________________\n");

            printf("\n\n\tEnter Student Name: ");
            fflush(stdin);
            gets(new_node->stu_name);
            fprintf(file,"\n\tStudent Name: %s", new_node->stu_name);

            printf("\n\tID: ");
            scanf("%d", &new_node->id);
            fprintf(file,"\n\tID: %d",new_node->id);

            printf("\n\tSection: ");
            fflush(stdin);
            gets(new_node->section);
            fprintf(file,"\n\tSection: %s", new_node->section);

            printf("\n\tSemester: ");
            fflush(stdin);
            gets(new_node->semester);
            fprintf(file,"\n\tSemester: %s", new_node->semester);

            printf("\n\tDepartment: ");
            fflush(stdin);
            gets(new_node->department);
            fprintf(file,"\n\tDepartment: %s", new_node->department);

            printf("\n\tUniversity Name: ");
            fflush(stdin);
            gets(new_node->university_name);
            fprintf(file,"\n\tUniversity Name: %s", new_node->university_name);

            printf("\n\tStudent Blood Group: ");
            fflush(stdin);
            gets(new_node->stu_blood_group);
            fprintf(file,"\n\tStudent Blood Group: %s", new_node->stu_blood_group);

            printf("\n\tUniversity Current Semester Result: ");
            scanf("%f", &new_node->university_current_result);
            fprintf(file,"\n\tUniversity Current Semester Result: %0.2f",new_node->university_current_result);

            printf("\n\tUniversity Overall Result: ");
            scanf("%f", &new_node->university_overall_result);
            fprintf(file,"\n\tUniversity Overall Result: %0.2f",new_node->university_overall_result);

            printf("\n\n\n\t\t\tStudent's Background\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Background\n");
            printf("\t\t____________________________________");
            fprintf(file,"\t\t____________________________________");

            printf("\n\n\tCollege Name: ");
            fflush(stdin);
            gets(new_node->college_name);
            fprintf(file,"\n\n\tCollege Name: %s", new_node->college_name);

            printf("\n\tH.S.C Passing Year: ");
            scanf("%d", &new_node->hsc_passing_year);
            fprintf(file,"\n\tH.S.C Passing Year: %d",new_node->hsc_passing_year);

            printf("\n\tH.S.C Result in GPA: ");
            scanf("%f", &new_node->hsc_gpa);
            fprintf(file,"\n\tH.S.C Result in GPA: %0.2f",new_node->hsc_gpa);

            printf("\n\tH.S.C Board: ");
            fflush(stdin);
            gets(new_node->hsc_board);
            fprintf(file,"\n\tH.S.C Board: %s", new_node->hsc_board);

            printf("\n\tSchool Name: ");
            fflush(stdin);
            gets(new_node->school_name);
            fprintf(file,"\n\tSchool Name: %s", new_node->school_name);

            printf("\n\tS.S.C Passing Year: ");
            scanf("%d", &new_node->ssc_passing_year);
            fprintf(file,"\n\tS.S.C Passing Year: %d",new_node->ssc_passing_year);

            printf("\n\tS.S.C Result in GPA: ");
            scanf("%f", &new_node->ssc_gpa);
            fprintf(file,"\n\tS.S.C Result in GPA: %0.2f",new_node->ssc_gpa);

            printf("\n\tS.S.C Board: ");
            fflush(stdin);
            gets(new_node->ssc_board);
            fprintf(file,"\n\tS.S.C Board: %s", new_node->ssc_board);

            printf("\n\n\n\t\t\tStudent's Contract Information\n");
            fprintf(file,"\n\n\n\t\t\tStudent's Contract Information\n");
            printf("\t\t_____________________________________________");
            fprintf(file,"\t\t_____________________________________________");

            printf("\n\n\tStudent's Phone Number: ");
            scanf("%lld", &new_node->stu_p_number);
            fprintf(file,"\n\n\tStudent's Phone Number: %lld",new_node->stu_p_number);

            printf("\n\tFather's Name: ");
            fflush(stdin);
            gets(new_node->stu_fathers_name);
            fprintf(file,"\n\tFather's Name: %s",new_node->stu_fathers_name);

            printf("\n\tMother's Name: ");
            fflush(stdin);
            gets(new_node->stu_mothers_name);
            fprintf(file,"\n\tMother's Name: %s",new_node->stu_mothers_name);

            printf("\n\tFather's Phone Number: ");
            scanf("%lld", &new_node->stu_fathers_p_number);
            fprintf(file,"\n\tFather's Phone Number: %lld",new_node->stu_fathers_p_number);

            printf("\n\tMother's Phone Number: ");
            scanf("%lld", &new_node->stu_mothers_p_number);
            fprintf(file,"\n\tMother's Phone Number: %lld",new_node->stu_mothers_p_number);

            printf("\n\tPresent Address: ");
            fflush(stdin);
            gets(new_node->present_address);
            fprintf(file,"\n\tPresent Address: %s",new_node->present_address);

            printf("\n\tPermanent Address: ");
            fflush(stdin);
            gets(new_node->permanent_address);
            fprintf(file,"\n\tPermanent Address: %s",new_node->permanent_address);

            printf("\n\tOther's Details and Comment: ");
            fflush(stdin);
            gets(new_node->about_student_details);
            fprintf(file,"\n\tOther's Details and Comment: %s",new_node->about_student_details);

            fclose(file);
        }
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    cls();

    printf("Enter ID before Insert Record: ");
    scanf("%d", &student_id);

    position = pos(student_id);

    current = start;
    for(i = 1; i <= (position - 1); i++)
    {
        current = current->next;
    }

    if (current != NULL) {
        temp2 = current;
        temp1 = current->previous;
        if (temp1 != NULL) {
            temp1->next = new_node;
        }
        new_node->previous = temp1;
        new_node->next = temp2;
        temp2->previous = new_node;
    }
}



void display_students_record_from_forward()
{
    FILE *file = fopen("Student's Record.txt", "r");
    char line[256];

    if (file == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\tThere Are No Record In The List.\n");
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
        fclose(file);
    }
}



void display_students_record_from_backward()
{
    FILE *file = fopen("Student's Record.txt", "r");
    char lines[1000][256];
    int num_lines = 0;

    if (file == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\tThere Are No Record In The List.\n");
    }
    else
    {
        while (fgets(lines[num_lines], sizeof(lines[num_lines]), file))
        {
            num_lines++;
        }
        fclose(file);

        for (int i = num_lines - 1; i >= 0; i--)
        {
            printf("%s", lines[i]);
        }
    }
}



int pos(int student_id)
{
    FILE *file = fopen("Student's Record.txt", "r");
    char line[256];
    int position = 0;
    int id;

    if (file == NULL)
    {
        return -1;
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%d", &id); // assuming ID is the first field in each line
            position++;
            if(student_id == id)
            {
                fclose(file);
                return position;
            }
        }
        fclose(file);
    }
    return -1;
}

int search_students_record(int student_id)
{
    FILE *file = fopen("Student's Record.txt", "r");
    char line[256];
    int position = 0;
    int id;

    if (file == NULL)
    {
        return -1;
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%d", &id); // assuming ID is the first field in each line
            position++;
            if(student_id == id)
            {
                printf("%s", line); // print the student's record
                fclose(file);
                return position;
            }
        }
        fclose(file);
    }
    return -1;
}



void delete_students_record()
{
    FILE *file = fopen("Student's Record.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");
    char line[256];
    int delet_id, id;

    printf("Enter ID for delete: ");
    scanf("%d", &delet_id);

    if (file == NULL || tempfile == NULL)
    {
        printf("\nError opening file.\n");
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%d", &id); // assuming ID is the first field in each line
            if(delet_id != id)
            {
                fputs(line, tempfile); // write the line to the temp file
            }
        }
        fclose(file);
        fclose(tempfile);

        // delete the original file and rename the temp file
        remove("Student's Record.txt");
        rename("temp.txt", "Student's Record.txt");

        printf("\nDelete Successfully.\n");
    }
}



void length_of_the_students_record()
{
    struct node *current;
    int count = 0;
    current = start;

    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("\n\n\n\n\n\n\n\t\t\tThere are %d number of Student's in the Record.", count);
    printf("\n                                     And the length is %d.\n",count);
}



void cls()
{
    system("cls");
}



int main()
{
    system("color A");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t|\tWelcome      |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
    getch();
    cls();
    int choice, position, student_id, insert_choice, display_choice;

    while(1)
    {
        printf("\n\t\t\t\t\tStudent's Record\n");
        printf("\t\t\t_______________________________________________");
        printf("\n\n");

        printf("------------------------------------------------------------------------------------------");
        printf("\n\n");
        printf("\t\t\t\t1. Create Record.\n");
        printf("\t\t\t\t2. Add Record.\n");
        printf("\t\t\t\t3. Display Record.\n");
        printf("\t\t\t\t4. Search Record.\n");
        printf("\t\t\t\t5. Delete Record.\n");
        printf("\t\t\t\t6. Length of the Record.\n");;
        printf("\t\t\t\t7. Exit.\n\n");
        printf("------------------------------------------------------------------------------------------");

        printf("\n\t\t\tPlease Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        cls();

        switch(choice)
        {
            case 1: create_students_record();
                    cls();
                    printf("\n\n\n\n\n\n\n\t\t\tRecord Created Successfully.");
                    getch();
                    cls();
                    break;

            case 2: while(1)
                    {
                        printf("\n\n\n\n\n");
                        printf("------------------------------------------------------------------------------------------");
                        printf("\n\n");
                        printf("\t\t\t\t1. Add Record At First.\n");
                        printf("\t\t\t\t2. Add Record At Last.\n");
                        printf("\t\t\t\t3. Add Record At Middle.\n");
                        printf("\t\t\t\t4. Back To Main Program.\n\n");
                        printf("------------------------------------------------------------------------------------------");

                        printf("\n\n\n\t\t\tPlease Enter your choice: ");
                        scanf("%d", &insert_choice);
                        printf("\n\n");
                        cls();

                        switch(insert_choice)
                        {
                            case 1: add_student_record_at_first();
                                    cls();
                                    printf("\n\n\n\n\n\n\n\t\t\tRecord Added successfully.");
                                    getch();
                                    cls();
                                    break;

                            case 2: add_student_record_at_last();
                                    cls();
                                    printf("\n\n\n\n\n\n\n\t\t\tRecord Added successfully.");
                                    getch();
                                    cls();
                                    break;

                            case 3: add_student_record_at_middle();
                                    cls();
                                    printf("\n\n\n\n\n\n\n\t\t\tRecord Added successfully.");
                                    getch();
                                    cls();
                                    break;

                            case 4: main();
                                    break;

                            default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                                    printf("\n\t\t\t\tOr Enter 4 to Main menu.\n");
                                    getch();
                                    cls();
                        }
                    }
                    getch();
                    cls();
                    break;

            case 3: while(1)
                    {
                        printf("\n\n\n\n\n");
                        printf("------------------------------------------------------------------------------------------");
                        printf("\n\n");
                        printf("\t\t\t\t1. Display From Forward.\n");
                        printf("\t\t\t\t2. Display From Backward.\n");
                        printf("\t\t\t\t3. Back To Main Program.\n\n");
                        printf("------------------------------------------------------------------------------------------");

                        printf("\n\n\n\t\t\tPlease Enter your choice: ");
                        scanf("%d", &display_choice);
                        printf("\n\n");

                        cls();

                        switch(display_choice)
                        {
                            case 1: display_students_record_from_forward();
                                    getch();
                                    cls();
                                    break;

                            case 2: display_students_record_from_backward();
                                    getch();
                                    cls();
                                    break;

                            case 3: main();
                                    break;

                            default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                                    printf("\n\t\t\t\tOr Enter 3 to Main menu.\n");
                                    getch();
                                    cls();
                        }
                    }
                    getch();
                    cls();
                    break;

            case 4: printf("\n\n\n\n\n\n\t\t\tEnter ID: ");
                    scanf("%d",&student_id);
                    cls();

                    position = search_students_record(student_id);
                    if(position == -1)
                    {
                        printf("\n\n\n\n\n\n\t\t\tThis ID is not in the Record.\n");
                        getch();
                        cls();
                    }
                    else
                    {
                        printf("\n\n\n\n\n\n\t\t\tThe Position of this Record is at Number %d.\n", position);
                        getch();
                        cls();
                    }
                    break;

            case 5: delete_students_record();
                    getch();
                    cls();
                    break;

            case 6: length_of_the_students_record();
                    getch();
                    cls();
                    break;

            case 7: exit(1);
                    break;

            default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                    printf("\n\t\t\t\tOr Enter 8 to Exit.\n");
                    getch();
                    cls();
        }
    }
}
