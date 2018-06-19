#include <iostream>

using namespace std;

int sqrtInt(int x){
    int temp;
    for(int i=1;i<=x;i++){
        temp =x/i;
        if((temp*temp) == x){
            return temp;
        }
    }
    return -1; //returns -1 if cannot square root the integer
}

int main()
{
    cout << "Please Enter Integer to square root:" << endl;
    int integer;
    cin>>integer;
    int answer = sqrtInt(integer);
    if(answer==-1){
        cout << "Cannot square root that integer :-(" << endl;
    }
    else{
        cout << "SQRT: " << answer << endl;
    }
    return 0;
}
