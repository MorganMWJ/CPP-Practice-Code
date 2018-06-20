#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//revision of Recursion
int factorial(int x){
    if(x<0){
        x = x*(-1);
    }
    if(x==0){
        return 1;
    }
    else{
        return x * factorial(x-1);
    }
}

//c++ has Default Parameters
int defaultFactorial(int x = 0){
    return factorial(x);
}

int main()
{
    cout << "Enter an Integer:" << endl;
    int startNum;
    cin >> startNum;
    cout << "Factorial of Zero: ";
    cout << defaultFactorial() << endl;
    cout << "Factorial of your Int: ";
    cout << factorial(startNum) << endl;

    printf("\n");
    printf("////////////////////////////\n\n");

    //Pointer Revision
   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n", &var  );

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n", ip );

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );

    return 0;
}

