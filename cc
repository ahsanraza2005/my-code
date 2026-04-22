
//(TAC – Quadruples & Triples)//


#include <stdio.h>
#include <string.h>

struct quad {
    char op[5], arg1[5], arg2[5], res[5];
};

struct triple {
    char op[5], arg1[5], arg2[5];
};

int main() {
    int n, i;

    printf("Enter number of TAC instructions: ");
    scanf("%d", &n);

    struct quad q[n];
    struct triple t[n];

    for(i = 0; i < n; i++) {
        printf("\nInstruction %d:\n", i+1);
        printf("Operator: ");
        scanf("%s", q[i].op);
        printf("Arg1: ");
        scanf("%s", q[i].arg1);
        printf("Arg2: ");
        scanf("%s", q[i].arg2);
        printf("Result: ");
        scanf("%s", q[i].res);

        // copy to triple
        strcpy(t[i].op, q[i].op);
        strcpy(t[i].arg1, q[i].arg1);
        strcpy(t[i].arg2, q[i].arg2);
    }

    printf("\n--- Quadruple Representation ---\n");
    printf("Op\tArg1\tArg2\tResult\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%s\n", q[i].op, q[i].arg1, q[i].arg2, q[i].res);
    }

    printf("\n--- Triple Representation ---\n");
    printf("Index\tOp\tArg1\tArg2\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%s\n", i, t[i].op, t[i].arg1, t[i].arg2);
    }

    return 0;
}





//C Program (LL(1) Parsing)//
#include <stdio.h>
#include <string.h>

char input[20];
int i = 0;

void E();
void T();
void F();

void E() {
    T();
    while(input[i] == '+') {
        i++;
        T();
    }
}

void T() {
    F();
    while(input[i] == '*') {
        i++;
        F();
    }
}

void F() {
    if(input[i] == '(') {
        i++;
        E();
        if(input[i] == ')')
            i++;
        else
            printf("Error: Missing )\n");
    }
    else if(input[i] == 'i') { // id = i
        i++;
    }
    else {
        printf("Error\n");
    }
}

int main() {
    printf("Enter string: ");
    scanf("%s", input);

    E();

    if(input[i] == '\0')
        printf("String accepted\n");
    else
        printf("String rejected\n");

    return 0;
}




LALR Bottom-Up Parser

#include <stdio.h>
#include <string.h>

char stack[20], input[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void display() {
    for(int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

int main() {
    int i = 0;
    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while(input[i] != '\0') {
        push(input[i]);
        printf("\n");
        display();
        printf("\t%s\tShift", input+i+1);
        i++;

        // Reduce rules
        if(stack[top] == 'i') {
            stack[top] = 'E';
            printf("\nReduce: i -> E");
        }
    }

    if(stack[0] == 'E' && top == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}


 // program for symbol table |


#include<stdio.h> 
#include<conio.h> 
#include<malloc.h> 
#include<ctype.h> 
void main() 
{  
int i=0,j=0,x=0,n,flag=0;  
void *p,*add[15];  
char ch,srch,b[15],d[15],c;  
clrscr();  
printf("expression terminated by $:");  
while((c=getchar())!='$')  
{     
b[i]=c;     
i++;  
}
n=i-1;  
printf("\ngiven expression:");  
i=0;  
while(i<=n)  
{   
printf("%c",b[i]);   
i++;  
}
printf("\n symbol table\n");  
printf("\n symbol\taddr\ttype\n");   
while(j<=n)  
{        
c=b[j];         
if(isalpha(toascii(c)))        
{       
if(j==n)       
{   	 
p=malloc(c);    
add[x]=p;    
d[x]=c;    
printf("%c\t%d\tidentifier\n",c,p);       
}       
else       
{    
ch=b[j+1];    
if(ch=='/'||ch=='+'||ch=='-'||ch=='*'||ch=='=')    
{         
p=malloc(c);         
add[x]=p;         
d[x]=c;         
printf("%c\t%d\tidentifier\n",c,p);         
x++;    
}       
}    
}   
j++;  
}  
printf("Enter the identifier to be searched\n");  
srch=getch();  
for(i=0;i<=x;i++)  
{     
if(srch==d[i])     
{     
printf("symbol found\n");     
printf("%c @Adrress %d \n",srch,add[i]);     
flag=1;     
}  
}
if(flag==0)   
printf("symbol not found\n");  
getch(); 
}





