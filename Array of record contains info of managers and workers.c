#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fptr;
    int i, n, empno;
    float bpay, allow, ded;
    char name[10];
    fptr = fopen("data.txt", "w");
    printf("Enter the number of employees : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the employee number : ");
        scanf("%d", &empno);
        printf("\nEnter the name : ");
        scanf("%s", name);
        printf("\nEnter the basic pay, allowances & deductions : ");
        scanf("%f %f %f", &bpay, &allow, &ded);
        fprintf(fptr, "%d %s %f %f %f \n", empno,name,bpay,allow,ded);
    }
	fclose(fptr);
	fptr = fopen("data.txt", "r");
	printf("\nEmp. No.Name\t\t Bpay\t\t Allow\t\t Ded\t\t Npay\n\n");
	for(i = 0; i < n; i++)
    {
    	fscanf(fptr,"%d%s%f%f%f\n", &empno,name,&bpay,&allow,&ded);
    	printf("%d \t %s \t %.2f \t %.2f \t %.2f \t %.2f \n", empno, name, bpay, allow, ded, bpay + allow - ded);
    }
    fclose(fptr);
    return 0;
}
