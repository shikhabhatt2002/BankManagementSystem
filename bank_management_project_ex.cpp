#include <iostream>
#include <iomanip>
#include <time.h>    //for random account number
#include <windows.h> //sleep()

using namespace std;

class customer
{
public:
    char fname[10], lname[10];
    string phone;
    string dob;

    customer()
    {
        phone = '\0';
        dob = '\0';
    }
    ~customer()
    {
    }
};

class Account : public customer
{

public:
    int accountNumber;
    int passcode;
    int balance;
    string type; //for account type
    int total_account = 0;
    static int count;

    Account()
    {
        accountNumber = 0;
        balance = 0;
        passcode = 0;
    }
    ~Account() {} 

    
    void CurrentBalance(int);       //bal chack
    void createAccount();           //functionv for openning new account
    void searchDetails(int, int);   //function to search details of perticular user
    void update_details(int, int);  //function for updating record
    void add(int, int, int);        //Add Money
    void withdrawal(int, int, int); //Deduct Money
};

void Account ::createAccount()
{
    count++;
    cout << "\n\t---------------------";
    cout << "\n\tEnter First name of " << count << " user :";
    cin >> fname;
    cin.ignore();

    cout << "\n\tEnter Last name of " << count << " user:";
    cin >> lname;

    string temp_phone;
    cout << "\n\tEnter phone number of " << count << " user:";
    cin >> temp_phone;

    if (temp_phone.length() == 10)
    {
        phone = temp_phone;
    }
    else
    {
        while (temp_phone.length() != 10)
        {
            cout << "\n\t----Phone number must be 10 digit----\n";
            cout << "\n\tInput your phone number again:";
            cin >> temp_phone;
            phone = temp_phone;
        }
    }

    cout << "\n\tEnter Date of Birth in this format (03/32/1897) of " << count << " user: ";
    cin >> dob;

    char atype;
    cout << "\n\tSelect Account Type(Savings S/Other O) of " << count << " user :";
    cin >> atype;
    if (tolower(atype) == 's') //to lower coverts character into small letter
    {
        type = "SAVINGS";
    }
    else
    {
        type = "OTHER";
    }

    srand(time(NULL));
    int n = rand() % 1000;
    accountNumber = n; //autogenerate account number

    cout << "\n\tYour Account Number is :" << accountNumber << endl;

    cout << "\n\tEnter 4 digit Passcode ::";
    cin >> passcode;

    cout << "\n\tEnter Primary Balance :";
    cin >> balance;
}

void Account ::CurrentBalance(int a_no)
{
    if (a_no == accountNumber)
    {

        cout << "\n\tCurrent Balance : " << balance << "/-RS.";
        cout << "\n\n\n";
    }
}

void Account ::searchDetails(int a_no, int pascode)
{

    if ((a_no == accountNumber) && (pascode == passcode))
    {
        cout << "\n\tAccount Number is :" << accountNumber;
        cout << "\n\tName              :" << fname << " " << lname;
        cout << "\n\tPhone             :" << phone;
        cout << "\n\tDate of birth     :" << dob;
        cout << "\n\tAccount Type      :" << type;
        cout << "\n\tBalance           :" << balance << "/-RS.";
        cout << "\n\n\n";
    }
}

void Account ::add(int a_no, int pascode, int amt)
{

    if ((a_no == accountNumber) && (pascode == passcode))
    {
        balance = balance + amt;
    }
    cout << "\n\tDone ! Amount Added\n";
}

void Account ::withdrawal(int a_no, int pascode, int amt)
{
    char tr_date[9];

    int flag = 0;

    if ((a_no == accountNumber) && (pascode == passcode))
    {
        if (balance != 0 && balance > amt)
        {

            balance = balance - amt;

            flag = 1;
        }
        else
        {
            cout << "\n\tyour transection can not be completed balance is Zero or Less than wuthdrawal amount\n! " << endl;
        }
    }

    if (flag == 1)
    {
        cout << "\n\tDone ! Amount Deducted\n";
    }
}

void Account ::update_details(int a_no, int pascode)
{
    int flag = 0;

    if ((a_no == accountNumber) && (pascode == passcode))
    {
        searchDetails(a_no, pascode);
        cout << "\n\tFill up Details with new records: \n";
        cout << "\n\tNew First name: ";

        cin >> fname;
        cin.clear();

        cout << "\n\tNew Last name: ";
        cin >> lname;
        cin.clear();

        cout << "\n\tNew  phone: ";
        cin >> phone;
        cin.clear();

        cout << "\n\tNew Dob in this format (02/32/1765): ";
        cin >> dob;
        cin.clear();

        cout << "\n\tCurrent Account Type: " << type;
        cout << "\n\tChange Type (Saving S/Other O) otherwiese press (N) :";
        char ans;
        cin >> ans;
        cin.clear();
        if (tolower(ans) == 'n')
        {
            cout << "\n\tOk !account type is not changed !\n ";
        }
        else if (tolower(ans) == 's')
        {
            type = "SAVING";
        }
        else
        {
            type = "OTHER";
        }

        cout << "\n\tDONE ! Details Updated THANK YOU.\n";
        flag = 1;
    }

    if (flag != 1)
    {
        cout << "\n\tNo record found\n\n";
    }
}

void choice(void)
{
    system("cls");
    cout << "\n\t---------------------";
    cout << "\n\t1.Create Account." << endl;
    cout << "\n\t2.View Your Account." << endl;
    cout << "\n\t3.Update Your Details." << endl;
    cout << "\n\t4.Withdraw your Money" << endl;
    cout << "\n\t5.Add Money." << endl;
    cout << "\n\t6.Show all Details." << endl;
    cout << "\n\t7.Check Current Balance." << endl;
    cout << "\n\t8.Exit." << endl;
    cout << "\n\t---------------------";
}

void showdata(void)
{
    char arrshow[] = {'B', 'A', 'N', 'K', ' ', 'M', 'A', 'N', 'A', 'G', 'E', 'M', 'E', 'N', 'T', ' ', 'S', 'Y', 'S', 'T', 'E', 'M'};
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << arrshow[i];
        Sleep(200);
    }
    system("CLS");
}

int Account::count; //for maintaining the count of account

int main()
{

    showdata();

    int ch;
    int amount = 0, i = 1;
    Account  a[20];
    int t_account;
    int j = 0;

    cout << "\n\n\tWelcome Sir/Ma'am!!!\n";
    Sleep(2000);

    do
    {
        choice();

        cout << "\n\tEnter your Choice (1-8):: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            system("cls");
            cout << "\n\tHow many accounts do you want to create: ";
            cin >> t_account;
            for (i = 1; i <= t_account; i++)
            {
                a[1].total_account = a[1].total_account + t_account;
                a[j + 1].createAccount();
                j++;
            }
            break;
        }
        case 2:
        {
            system("cls");
            int a_no, pascode = 0;

            if (a[1].total_account == 0)
            {
                cout << "\n\tNo data is present:\n";
                break;
            }
            else
            {
                cout << "\n\tEnter your account number and passcode:";
                cin >> a_no >> pascode;
                for (i = 1; i <= a[1].total_account; i++)
                {
                    if ((a_no == a[i].accountNumber) && (pascode == a[i].passcode))
                    {
                        a[i].searchDetails(a_no, pascode);
                        break;
                    }
                }
                if ((a_no != a[i].accountNumber) && (pascode != a[i].passcode))
                    cout << "\n\tAccount number or Passcode entered is WRONG!!\n";
                break;
            }
        }
        case 3:
        {
            system("cls");
            int a_no, pascode = 0;

            cout << "\n\tEnter your account number and passcode:";
            cin >> a_no >> pascode;
            for (i = 1; i <= a[1].total_account; i++)
            {
                if ((a_no == a[i].accountNumber) && (pascode == a[i].passcode))
                {
                    a[i].update_details(a_no, pascode);
                    break;
                }
            }
            if ((a_no != a[i].accountNumber) && (pascode != a[i].passcode))
                cout << "\n\tAccount number or Passcode entered is WRONG!!\n";

            break;
        }
        case 4:
        {
            system("cls");
            int a_no, pascode = 0, amount;
            cout << "\n\tEnter your account number and passcode:";
            cin >> a_no >> pascode;

            for (i = 1; i <= a[1].total_account; i++)
            {
                if ((a_no == a[i].accountNumber) && (pascode == a[i].passcode))
                {
                    cout << "\n\tEnter Amount to withdraw : ";
                    cin >> amount;
                    a[i].withdrawal(a_no, pascode, amount);
                    a[i].CurrentBalance(a_no);
                    break;
                }
            }
            if ((a_no != a[i].accountNumber) && (pascode != a[i].passcode))
                cout << "\n\tAccount number or Passcode entered is WRONG!!\n";
            break;
        }
        case 5:
        {
            system("cls");
            int a_no, pascode = 0, amount;
            cout << "\n\tEnter your account number and passcode:";
            cin >> a_no >> pascode;

            for (i = 1; i <= a[1].total_account; i++)
            {
                if ((a_no == a[i].accountNumber) && (pascode == a[i].passcode))
                {
                    cout << "\n\tEnter Amount to Add := ";
                    cin >> amount;
                    a[i].add(a_no, pascode, amount);
                    a[i].CurrentBalance(a_no);
                    break;
                }
            }
            if ((a_no != a[i].accountNumber) && (pascode != a[i].passcode))
                cout << "\n\tAccount number or Passcode entered is WRONG!!\n";
            break;
        }
        case 6:
        {
            system("cls");
            for (i = 1; i <= a[1].total_account; i++)
            {
                cout << "\n\tAccount Number is :" << a[i].accountNumber;
                cout << "\n\tName              :" << a[i].fname << " " << a[i].lname;
                cout << "\n\tPhone             :" << a[i].phone;
                cout << "\n\tDate of birth     :" << a[i].dob;
                cout << "\n\tAccount Type      :" << a[i].type;
                cout << "\n\tBalance           :" << a[i].balance << "/-RS.";
                cout << "\n\n\n";
            }
            break;
        }
        case 7:
        {
            int a_no;
            cout << "\n\tEnter the account number whose balance is to be checked: ";
            cin >> a_no;
            for (i = 1; i <= a[1].total_account; i++)
            {
                if (a_no == a[i].accountNumber)
                {
                    a[i].CurrentBalance(a_no);
                    break;
                }
            }
            if (a_no != a[i].accountNumber)
            {
                cout << "\n\tYour Account Number is WRONG!!!\n";
            }
            break;
        }
        case 8:
        {
            cout << "\n\t****THANK YOU****!!" << endl;
            exit(0);
        }
        default:
        {
            cout << "Wrong Choice \n"
                 << endl;
            break;
        }
        }
        cout << "\n\tpress 1 to continue\n\tpress 0 to leave = ";
        cin >> ch;
    } while (ch == 1);

    return 1;
}