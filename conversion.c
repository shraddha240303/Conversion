// Conversion

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototype

int *dec_bin(int inp_num1);
int *dec_oct(int inp_num1);
int *dec_hexadec(int inp_num1);
int *bin_dec(int inp_num1);
int *bin_oct(int inp_num1);
int *bin_hexadec(int inp_num1);
int *oct_bin(int inp_num1);
int *oct_dec(int inp_num1);
int *oct_hexadec(int inp_num1);


int main(){

    int cho_num, inp_num, *ret;
    char rep;
    char inp_hexnum[100];
    int arr[100], i=0, j, sum=0, k;

    repeat: 

    printf ("\n\nChoose the operation, you want to be executed: \n\n");
    printf ("1. Decimal to Binary        2. Decimal to Octal          3. Decimal to Hexadecimal\n");
    printf ("4. Binary to Decimal        5. Binary to Octal           6. Binary to Hexadecimal\n");
    printf ("7. Octal to Binary          8. Octal to Decimal          9. Octal to Hexadecimal\n");
    printf ("10. Hexadecimal to Binary   11. Hexadecimal to Octal     12. Hexadecimal to Decimal");

    printf ("\nEnter your choose: ");       
    scanf ("%d", &cho_num);                                             // cho_num var for taking the choose 
    if ((cho_num >= 1) && (cho_num <= 9)){
        printf ("Enter number ");       
        scanf ("%d", &inp_num);                                         // inp_num var for taking the number
    }
    else if ((cho_num >= 10) && (cho_num <= 12)){
        printf ("Enter number ");       
        scanf ("%s", inp_hexnum);                                      // inp_num var for taking the hexa number

        // converting strhexa in inthexa
        while (inp_hexnum[i] != '\0'){
            switch (inp_hexnum[i]){
                case '0': arr[i] = 0; break;
                case '1': arr[i] = 1; break;
                case '2': arr[i] = 2; break;
                case '3': arr[i] = 3; break;
                case '4': arr[i] = 4; break;
                case '5': arr[i] = 5; break;
                case '6': arr[i] = 6; break;
                case '7': arr[i] = 7; break;
                case '8': arr[i] = 8; break;
                case '9': arr[i] = 9; break;
                case 'A': arr[i] = 10; break;
                case 'B': arr[i] = 11; break;
                case 'C': arr[i] = 12; break;
                case 'D': arr[i] = 13; break;
                case 'E': arr[i] = 14; break;
                case 'F': arr[i] = 15; break;
                default: printf ("Enter the valid number in range!!"); exit(0);
            }
            i++;
        } 

        // converting inthexa into decimal
        for (j=i-1, k=0; j>=0, k<i; j--, k++){
            sum += (arr[j]*pow(16,k));
        }
        inp_num = sum;
    }
    else{
        printf ("Enter the valid choice!!");
        exit(0);
    }
    
    switch (cho_num){
        case 1: ret = dec_bin(inp_num); break;
        case 2: ret = dec_oct(inp_num); break;
        case 3: ret = dec_hexadec(inp_num); break;
        case 4: ret = bin_dec(inp_num); break;
        case 5: ret = bin_oct(inp_num); break;
        case 6: ret = bin_hexadec(inp_num); break;
        case 7: ret = oct_bin(inp_num); break;
        case 8: ret = oct_dec(inp_num); break;
        case 9: ret = oct_hexadec(inp_num); break;
        case 10: ret = dec_bin(inp_num); break;
        case 11: ret = dec_oct(inp_num); break;
        case 12: printf ("%d", inp_num); break;                     // print decimal number
    }  

    printf ("\nWould you like to do again this thing (Y/N) : ");
    scanf ("%c", &rep); 

    if ((rep == 'Y') || (rep == 'y')){
        goto repeat;
    } 
    else{
        exit (0);
    }                            
    
    return (0);
}

// function definition

// decimal to binary
int *dec_bin(int inp_num1){

    int arr[100];
    static int arr1[100];                                   // arr[] for storing binary number in reverse manner & arr1[] for storing binary number in correct format
    int rem, i=0, j, k;

    while (1){
        rem = inp_num1 % 2;                                 // rem for storing last digit (234%2 = 0)          
        inp_num1 = inp_num1 / 2;                            // inp_num1 for storing next iteration number (234/2 = 127) 
        arr[i] = rem;                                       // assigning the value in arr[]
        i++;                             
        if (inp_num1 <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                  // for printing the binary number
        printf("%d",arr[j]);
        arr1[k] = arr[j];
    }
    
    return (arr1);
}

// decimal to octal
int *dec_oct(int inp_num1){

    int arr[100];                                           // for storing octal number
    int rem, i=0, j, k;
    static int arr1[100];

    while (1){
        rem = inp_num1 % 8;                                 // rem for storing last digit (234%8 = 2)
        inp_num1 = inp_num1 / 8;                            // inp_num1 for storing next iteration number (234/8 = 29)
        arr[i] = rem;
        i++;
        if (inp_num1 <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                  // for printing the octal number
        printf("%d",arr[j]);
        arr1[k] = arr[j];
    }
    
    return (arr1);
}

// decimal to hexadecimal
int *dec_hexadec(int inp_num1){

    int arr[100];                                         // for storing the hexadecimal number
    int rem, i=0, j, k;
    static int arr1[100];

    while (1){
        rem = inp_num1 % 16;                              // rem for storing last digit (234%16 = 10)
        inp_num1 = inp_num1 / 16;                         // inp_num1 for storing next iteration number (234/16 = 14)
        arr[i] = rem;
        i++;
        if (inp_num1 <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                // for printing the hexadecimal number
        if (arr[j] >= 10){
            switch (arr[j]){
                case 10: printf("A"); break;
                case 11: printf("B"); break;
                case 12: printf("C"); break;
                case 13: printf("D"); break;
                case 14: printf("E"); break;
                case 15: printf("F"); break;
                default: exit(0);
            }
        }
        else{
            printf("%d",arr[j]);
        }
        arr1[k] = arr[j];
    }

    return (arr1);    
}

// binary to decimal
int *bin_dec(int inp_num1){

    int rem, sum=0, i=0;                                   // sum for storing decimal value
    static int arr1[0];
    while (1){
        rem = inp_num1 % 10;                               // for storing the last digit number (234%10 = 4)
        inp_num1 = inp_num1 / 10;                          // for storing next iteration number (234/10 = 23)
        sum += (rem*pow(2,i));
        i++;
        if (inp_num1 <= 0){
            break;
        }
    }
    printf ("%d", sum);                                   // for printing the decimal number
    arr1[0] = sum;
    
    return (arr1);    
}

// binary to octal
int *bin_oct(int inp_num1){

    int arr[100];                                           // for storing octal number
    int rem1, i=0, j, k;
    int rem, sum=0, l=0;                                   // sum for storing decimal value
    static int arr1[100];

    // converting binary to decimal
    while (1){
        rem = inp_num1 % 10;                               // for storing the last digit number (234%10 = 4)
        inp_num1 = inp_num1 / 10;                          // for storing next iteration number (234/10 = 23)
        sum += (rem*pow(2,l));
        l++;
        if (inp_num1 <= 0){
            break;
        }
    }

    // converting decimal to octal
    while (1){
        rem1 = sum % 8;                                   // rem for storing last digit (234%8 = 2)
        sum = sum / 8;                                    // inp_num1 for storing next iteration number (234/8 = 29)
        arr[i] = rem1;
        i++;
        if (sum <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                  // for printing the octal number
        printf("%d",arr[j]);
        arr1[k] = arr[j];
    }

    return (arr1);
}

// binary to hexadecimal
int *bin_hexadec(int inp_num1){

    int rem1, i=0, j, k;
    int rem, sum=0, l=0;                                   // sum for storing decimal value
    int arr[100];                                          // for storing the hexadecimal number
    static int arr1[100];

    // binary to decimal
    while (1){
        rem = inp_num1 % 10;                               // for storing the last digit number (234%10 = 4)
        inp_num1 = inp_num1 / 10;                          // for storing next iteration number (234/10 = 23)
        sum += (rem*pow(2,l));
        l++;
        if (inp_num1 <= 0){
            break;
        }
    }

    //decimal to hexadecimal
    while (1){
        rem1 = sum % 16;                              // rem for storing last digit (234%16 = 10)
        sum = sum / 16;                         // inp_num1 for storing next iteration number (234/16 = 14)
        arr[i] = rem1;
        i++;
        if (sum <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                // for printing the hexadecimal number
        if (arr[j] >= 10){
            switch (arr[j]){
                case 10: printf("A"); break;
                case 11: printf("B"); break;
                case 12: printf("C"); break;
                case 13: printf("D"); break;
                case 14: printf("E"); break;
                case 15: printf("F"); break;
                default: exit(0);
            }
        }
        else{
            printf("%d",arr[j]);
        }
        arr1[k] = arr[j];
    }

    return (arr1);      
}

//  octal to binary
int *oct_bin(int inp_num1){

    int rem1, i=0, j, k;
    int arr[100];
    int rem, sum=0, l=0;                                            // sum for storing decimal value
    static int arr1[100];

    // octal to decimal
    while (1){
        rem = inp_num1 % 10;                                        // for storing the last digit 
        inp_num1 = inp_num1 / 10;                                   // for storing the next iteration number
        if ((rem < 9) && (rem >= 0)){
            sum += (rem*pow(8,l));
            l++;        
        }
        else{
            printf ("Enter the value in range!!");
            exit (0);
        }
        if (inp_num1 <= 0){                                         // for stoping the loop
            break;
        }
    }
     
    // decimal to binary
    while (1){
        rem1 = sum % 2;                                            // rem for storing last digit (234%2 = 0)          
        sum = sum / 2;                                             // inp_num1 for storing next iteration number (234/2 = 127) 
        arr[i] = rem1;                                             // assigning the value in arr[]
        i++;                             
        if (sum <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                  // for printing the binary number
        printf("%d",arr[j]);
        arr1[k] = arr[j];
    }
    
    return (arr1);    
}

// octal to decimal
int *oct_dec(int inp_num1){

    int rem, sum=0, i=0;                                            // sum for storing decimal value
    static int arr1[0];
    while (1){
        rem = inp_num1 % 10;                                        // for storing the last digit 
        inp_num1 = inp_num1 / 10;                                   // for storing the next iteration number
        if ((rem < 9) && (rem >= 0)){
            sum += (rem*pow(8,i));
            i++;        
        }
        else{
            printf ("Enter the value in range!!");
            exit (0);
        }
        if (inp_num1 <= 0){                                         // for stoping the loop
            break;
        }
    }
    printf ("%d", sum);                                             // for printing the decimal number
    arr1[0] = sum;

    return (arr1);       
}

// octal to hexadecimal
int *oct_hexadec(int inp_num1){

    int arr[100];                                                   // for storing the hexadecimal number
    int rem, sum=0, l=0;                                            // sum for storing decimal value
    int rem1, i=0, j, k;
    static int arr1[100];

    // octal to decimal
    while (1){
        rem = inp_num1 % 10;                                        // for storing the last digit 
        inp_num1 = inp_num1 / 10;                                   // for storing the next iteration number
        if ((rem < 9) && (rem >= 0)){
            sum += (rem*pow(8,l));
            l++;        
        }
        else{
            printf ("Enter the value in range!!");
            exit (0);
        }
        if (inp_num1 <= 0){                                         // for stoping the loop
            break;
        }
    }  

    // decimal to hexadecimal 
    while (1){
        rem1 = sum % 16;                              // rem for storing last digit (234%16 = 10)
        sum = sum / 16;                         // inp_num1 for storing next iteration number (234/16 = 14)
        arr[i] = rem1;
        i++;
        if (sum <= 0){
            break;
        }
    }

    for (j=i-1, k=0; j>=0, k<i; j--, k++){                // for printing the hexadecimal number
        if (arr[j] >= 10){
            switch (arr[j]){
                case 10: printf("A"); break;
                case 11: printf("B"); break;
                case 12: printf("C"); break;
                case 13: printf("D"); break;
                case 14: printf("E"); break;
                case 15: printf("F"); break;
                default: exit(0);
            }
        }
        else{
            printf("%d",arr[j]);
        }
        arr1[k] = arr[j];
    }

    return (arr1);        
}
