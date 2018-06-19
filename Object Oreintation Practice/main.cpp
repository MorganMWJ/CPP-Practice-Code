#include <iostream>
#include <sstream>

using namespace std;

class Employee{//Super Class (Base Class)

private://instance variables (called Data Members in c++)
    string name;
    double pay;

public://constructor(s)
    Employee(){
        name = "";
        pay = 0.0;
    }
    Employee(string startName, double startPay){
        name = startName;
        pay = startPay;
    }
    ~Employee() {};//destructor allows memory to be freed once object is deleted
    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
    void setPay(double p){
        pay = p;
    }
    double getPay(){
        return pay;
    }
    string toStirng(){
        // cannot concatenate string and double  (name + ": " + pay;)
        stringstream sStrObj;
        sStrObj << name << ": " << pay;//flow all info to combine in string stream object
        return sStrObj.str(); //.str method turns a stringstream into a string
    }
    //access modifier are called 'Access Specifiers' in c++
    //All above methods are public because they are all below 'public:' do not need to specify public for each individual method (differs from java in this respect)
};


class Manager : public Employee{ //sub class (derived class)

private:
    bool salaried;

public:
    Manager(string name,double payRate,bool isSalaried)
    : Employee(name,payRate)
    {
        salaried = isSalaried;
    }
    ~Manager() {};
    bool getSalaried(){
        return salaried;
    }

};

int main()
{
    //There is no 'new' keyword to create an object in c++ (differs from java in that respect)
    Employee e1("Morgan", 70000);
    Employee e2("Joshua", 50000);
    cout << e1.toStirng() << endl;
    cout << e2.toStirng() << endl;
    /////////////////
    Manager m1("Martyn", 100000.00, true);
    cout << m1.toStirng() << endl;
    if(m1.getSalaried()){
        cout << "Manager is on a Standard salary" << endl;
    }
    else{
        cout << "Manager is on a non-standard salary" << endl;
    }
    return 0;
}
