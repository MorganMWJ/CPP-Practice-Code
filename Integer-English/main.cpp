#include <iostream>

using namespace std;

string convert(long x){
    //exception
    if(x==0){
        return "zero";
    }
    //
    string numbers[] = {"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
    string teens[] = {"","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
    string tens[] = {"","ten ","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};

    string result = "";

    const long million = 1000000;
    const long thousand = 1000;
    const long hundred = 100;
    const long twenty = 20;
    const long ten = 10;

    unsigned int numberOfMill=0;
    unsigned int numberOfThous=0;
    unsigned int numberOfHunds=0;
    unsigned int numberOfTens=0;
    unsigned int numberOfUnits=0;

    if(x>=million){
        numberOfMill = int((x - (x%million))/million);
        if(numberOfMill>9){//if number needs to be built by multiple strings call !recursively!
            result = result + convert(numberOfMill) + "million ";
        }
        else{//use base number between 1 and 9
            result = result + numbers[numberOfMill] + "million ";
        }
        x = x%million;
    }
    if(x>=thousand){
        numberOfThous = int((x - (x%thousand))/thousand);
        if(numberOfThous>9){//if number needs to be built by multiple strings call !recursively!
            result = result + convert(numberOfThous) + "thousand ";
        }
        else{//use base number between 1 and 9
            result = result + numbers[numberOfThous] + "thousand ";
        }
        x = x%thousand;
    }
    if(x>=hundred){
        numberOfHunds = int((x - (x%hundred))/hundred);
        result = result + numbers[numberOfHunds] + "hundred ";
        x = x%hundred;
    }
    if((x>ten) && (x<twenty)){//last two digits between 10-20(teens) then use other method
        result = result + teens[x-10];
        return result;
    }
    else{//get the last 2 digits names by regular method
        if(x>=ten){
            numberOfTens = int((x - (x%ten))/ten);
            result = result + tens[numberOfTens];
            x = x%ten;
        }
        numberOfUnits = x;
        result = result + numbers[numberOfUnits];
        return result;
    }
}

int main()
{
    long int input;
    string result;
    cout << "Enter an integer: " << endl;
    cin >> input;

    if(input<0){
        result = "minus " + convert(input*-1);
    }
    else{
        result = convert(input);
    }
    cout << result << endl;
    return 0;
}
