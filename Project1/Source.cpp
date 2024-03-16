#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static int reg = 0;
static int cnt = 0; //static value
int id = 0;
float chargee(float);
float chargee(int);
class customer {
protected:
    char Fname[50];
    char c[2] = " ";
    char Lname[50];
    string Phno;
public:
    customer() {

    }
    void get_Cdetails() {
        reg++;
        cout << "\n\t\t\t";
        cout.fill('*');
        cout.width(64);
        cout << " \n";
        cout << "\t\t\tEnter First name : ";
        cin >> Fname;
        cout << "\t\t\tEnter Last name : ";
        cin >> Lname;
        strcat(Fname, c);
        strcat(Fname, Lname);
        cout << "\t\t\tEnter Phone No : ";
        cin >> Phno;
    }
    string put_name()
    {
        return Fname;
    }
    string put_no() {
        return Phno;
    }
};
class vehicle {
    string vehicleNo;
public:
    void Vdetail() {
        cout << "\t\t\tEnter Vehicle Number : ";
        cin >> vehicleNo;
    }
    string put_Vdetail() {
        return vehicleNo;
    }
};

template<class T>  //template
T Vtype(T n) {
    T type;
    type = n;
    return type;
}
class calculation {
    float charge;
    float duration;
public:
    calculation() {
        charge = 0;
        duration = 0;
    }
    void cal(int n) {

        cout << "\t\t\tEnter the amount of time you want to park your vehicle in HRs : ";
        cin >> duration;
        if (n == 2) {
            charge = chargee(2) * duration;
            //charge = (float)25 * duration;
        }
        else {
            charge = chargee(duration);
            // charge = 59.99 * duration;
        }
    }
    float put_charge() {
        return charge;
    }
    float  put_duration() {
        return duration;
    }

};
float chargee(int n) {
    float c;
    c = (float)25;
    return c;
}
float chargee(float duration) {
    float c;
    c = (float)59.99 * duration;
    return c;
}
class E_slip :public customer, public calculation, public vehicle  //multiple inheritance
{
public:
    E_slip() {};  //default constructor
    void displayBill();
};
void E_slip::displayBill() {
    cout << "\n\n";
    cout << "\t\t\t********************** CAR PARKING E_slip **********************";
    ++cnt;
    cout << "\n\n\t\t\tBill Number: " << cnt << endl;
    cout << "\t\t\tName: " << put_name() << endl;
    cout << "\t\t\tPh no: " << put_no();
    cout << "\n\t\t\tCar Number: " << put_Vdetail();
    cout << "\n\t\t\tcar parked for " << put_duration() << " hrs";
    cout << "\n\t\t\tTotal Charges: Rs. " << put_charge() << "/-";
    cout << "\n\t\t\tCurrent Status: PAID";
    cout << "\n\t\t\t***************************** END ******************************\n";
}
//class allvehicle : public E_slip
//{
//public:
//    void alldisplay() {
//        for (int i = 1; i <= id; i++) {
//
//            displayBill();
//        }
//    }
//};
class parkingspot
{
    int capacity_2W;
    int capacity_4W;
public:
    parkingspot() {
        capacity_2W = 40;
        capacity_4W = 60;
    }
    void operator--() //operator overloading 
    {
        --capacity_2W;
    }
    void operator--(int) {
        capacity_4W--;
    }
    void parkdetail_1() {
        cout << "\n\t\t\t2 Wheeler park Spot remaining : " << capacity_2W;
    }
    void parkdetail_2() {
        cout << "\n\t\t\t4 Wheeler park Spot remaining : " << capacity_4W;
    }

};


int main()
{
    int c;
    parkingspot p1, p2;
    while (1) {
        cout << "\n\t\t\t************************** MENU ******************************\n";
        cout << "\t\t\t\t\t\tEnter \n\t\t\t1 To Park\n\t\t\t2 To Check Remaining Slots\n\t\t\t3 To view all records";
        cout << "\n\t\t\tEnter Your Choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            int a = 2;
            float x = 4.0;
            E_slip E;
            E.get_Cdetails();
            E.Vdetail();
            int choice;
            cout << "\n\t\t\tEnter 2 for 2 wheeler\n\t\t\tEnter 4 for 4 wheeler  ";
            cout << "\n\t\t\tEnter your choice : ";
            cin >> choice;
            switch (choice) {
            case 2:
                int b;
                b = Vtype(a);
                break;
            case 4:
                float y;
                y = Vtype(x);
                break;
            }
            if (choice == 2) {
                E.cal(2);
                --p1;
                E.displayBill();
            }
            else if (choice == 4) {
                E.cal(4);
                p2--;
                E.displayBill();
            }
            else {
                cout << "\n\t\t\tInvalid choice\n";
            }
            break;
        }
        case 2:
        {
            cout << "\n\t\t\t\t\t\tThe Capacity Remaining ";
            p1.parkdetail_1();
            p2.parkdetail_2();
            break;
        }
        case 3:
        {
            E_slip E1;
            for (int i = 0; i < reg; i++)
                E1.displayBill();

            break;
        }
        default:
            cout << "\n\t\t\t\t\t\tEnter Valid Input \n";
            break;

        }


    }
    return 0;
}