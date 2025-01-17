#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>

using namespace std;

//create bank class to declear attributes and function.

class bank{
    private:
        string user_Id;
        string password;
        string name;
        string address;
        long int account;
        double balance;
        string mobile;
    public:

        //create function is use to  take user details to  create account.

       void create(){
            system("cls");
            cout<<"***********Create Account**************"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"Enter Your Name : ";
            cin>>name;
            cout<<"Enter Your Address : ";
            cin>>address;
            cout<<"Enter Your Mobile no. : "; cin>>mobile;
            cout<<"Enter Account No. : "; cin>>account;
            cout<<"Enter Initial Funding Ammount : "; cin>>balance;
            cout<<"Enter User Id : "; cin>>user_Id;
            cout<<"Enter Password: "; cin>>password;
            fstream myfile;
            myfile.open("Details_Store.dat", ios::binary | ios::out | ios::app);

            if (!myfile){
                cout<<"File is not open!"<<endl;
                exit(0);
            }
            else{
                myfile.write((char *)&user_Id, sizeof(user_Id));
                myfile.write((char *)&password, sizeof(password));
                cout<<"***************************************"<<endl;
                cout<<"User Id and Passsword is Set Succesfully!"<<endl;
                cout<<"Presss Enter!"<<endl;
                cout<<"***************************************"<<endl;
                getch();

            }
            myfile.close();
        }

        //login function is use to user can login account after the account create.

        void login(){
            bank user;
            int a = 3;
            do{
                
                string user_Id1;
                string password1;
                system("cls");
                cout<<"************Login Account**************"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"Enter User Id : "; cin>>user_Id1;
                cout<<"Enter Password: "; cin>>password1;
                fstream myfile;
                myfile.open("Details_Store.dat", ios::binary | ios::in);
                if (!myfile){
                    cout<<"File is not open!"<<endl;
                    exit(0);
                }
                else{
                    while((myfile.read((char *)&user_Id, sizeof(user_Id))) && (myfile.read((char *)&password, sizeof(password)))){
                        if((user_Id.compare(user_Id1)==0) && (password.compare(password1)==0)){
                            user.sub_interface();
                        }
                                     
                    }
                }
                cout<<"***************************************"<<endl;
                cout<<"Wrong user id and password. Try again !"<<endl;
                cout<<"Presss Enter!"<<endl;
                cout<<"***************************************"<<endl;
                getch();
                myfile.close();
            }while(--a);
            cout<<"***************************************"<<endl;
            cout<<"You Enter three invalid input try after some time!"<<endl;
            cout<<"Presss Enter!"<<endl;
            cout<<"***************************************"<<endl;
            getch();

        }

        //update function is use to use can update the user id and password.

        void update() {
            bank user;
            string user_Id1, password1;
            system("cls");
            cout<<"************Update Account**************"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"Enter Current User id and Password"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"Enter User Id : "; cin>>user_Id1;
            cout<<"Enter Password: "; cin>>password1;
            fstream myfile;
            myfile.open("Details_Store.dat", ios::binary | ios::in | ios::out | ios::ate);
            myfile.seekg(0);
            if (!myfile){
                cout<<"File is not open!"<<endl;
                exit(0);
            }
            else{
                while((myfile.read((char *)&user_Id, sizeof(user_Id))) && (myfile.read((char *)&password, sizeof(password)))){   
                    if((user_Id.compare(user_Id1)==0) && (password.compare(password1)==0)){
                        string user_Id2, password2;
                        cout<<"***************************************"<<endl;
                        cout<<"Enter New User id and Password"<<endl;
                        cout<<"***************************************"<<endl;
                        cout<<"Enter User Id : "; cin>>user_Id2;
                        cout<<"Enter Password: "; cin>>password2;
                        myfile.seekg(-sizeof(user_Id), ios::cur);
                        myfile.seekg(-sizeof(password), ios::cur);
                        myfile.write((char *)&user_Id2, sizeof(user_Id2));
                        myfile.write((char *)&password2, sizeof(password2));
                        cout<<"***************************************"<<endl;
                        cout<<"Update User Id and Passsword is Set Succesfully!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                        user.main_intrface();
                    }                
                }
                cout<<"***************************************"<<endl;
                cout<<"Wrong User id and Password. try again !"<<endl;
                cout<<"***************************************"<<endl;
            }
            myfile.close();
            getch();
        }

        //delete function is use to delete the account that user is created.

       void Delete(){
            system("cls");
            string user_Id1;
            string password1;
            system("cls");
            cout<<"************Delete Account**************"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"Enter User Id : "; cin>>user_Id1;
            cout<<"Enter Password: "; cin>>password1;
            fstream myfile, tempf;
            myfile.open("Details_Store.dat", ios::binary | ios::in);
            tempf.open("temp.dat",ios::binary | ios::out);
            if (!myfile && !tempf){
                cout<<"File is not open!"<<endl;
                exit(0);
            }
            else{
                while((myfile.read((char *)&user_Id, sizeof(user_Id))) && (myfile.read((char *)&password, sizeof(password)))){
                    if((!user_Id.compare(user_Id1)==0) && (!password.compare(password1)==0)){
                        tempf.write((char *)&user_Id, sizeof(user_Id));
                        tempf.write((char *)&password, sizeof(password));
                        
                    }
                }
            }

            myfile.close();
            tempf.close();
            remove("Details_Store.dat");
            rename("temp.dat", "Details_Store.dat");
            cout<<"***************************************"<<endl;
            cout<<"User Id and Passsword is Delete Succesfully!"<<endl;
            cout<<"Presss Enter!"<<endl;
            cout<<"***************************************"<<endl;
            getch();
       }

        //main_interface function is use to show the user and option to select them.

       void main_intrface(){
            bank user;
            do{
                system("cls");
                cout<<"**********Welcome to The ATM***********"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"1 Create Account "<<endl;
                cout<<"2 Login Account"<<endl;
                cout<<"3 Delete Account"<<endl;
                cout<<"4 Update Account"<<endl;
                cout<<"5 Exit"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"Choose the Option"<<endl;
                cout<<"Enter the no. : ";
                int cho;
                cin>>cho;
                switch(cho){
                    case 1 :
                        user.create();
                        break;
                    case 2 :
                        user.login();
                        break;
                    case 3 :
                        user.Delete();
                        break;
                    case 4 :
                        user.update();
                        break;
                    case 5: 
                        exit(0);
                    default :
                        cout<<"***************************************"<<endl;
                        cout<<"Invalid input!. Try again!"<<endl;
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                }
            }while(1);
         }

        //sub_interface function is use to show the user many option after the account login.

       void sub_interface(){
            do {
                system("cls");
                double amount;
                cout<<"**********Welcome "<<name<<"***********"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"1 My Profile "<<endl;
                cout<<"2 Check Balance "<<endl;
                cout<<"3 Withdrawl Money "<<endl;
                cout<<"4 Deposite Money "<<endl;
                cout<<"5 Exit"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"Choose the Option"<<endl;
                cout<<"Enter the no. : ";
                int cho;
                cin>>cho;
                switch(cho){
                    case 1 :
                        system("cls");
                        cout<<"***************************************"<<endl;
                        cout<<"Name : "<<name<<endl;
                        cout<<"Address : "<<address<<endl;
                        cout<<"Mobile No. : "<<mobile<<endl;
                        cout<<"Account No. : "<<account<<endl;
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                        break;
                    case 2 :
                        system("cls");
                        cout<<"***************************************"<<endl;
                        cout<<"Available Balance : RS "<<balance<<endl;
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                        break;
                    case 3 :
                        system("cls");
                        cout<<"***************************************"<<endl;
                        cout<<"Enter Amount to Withdrawl : RS"; cin>>amount;
                        if (amount>balance){
                            cout<<"***************************************"<<endl;
                            cout<<"Insuficient Balance!"<<endl;
                        }
                        else if (amount<=balance){
                            balance-=amount;
                            cout<<"***************************************"<<endl;
                            cout<<"Withdrawl Money Successfully!"<<endl;
                        }
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                        break;
                    case 4 :
                        system("cls");
                        cout<<"***************************************"<<endl;
                        cout<<"Enter Amount to Deposite : RS"; cin>>amount;
                        balance+=amount;
                        cout<<"***************************************"<<endl;
                        cout<<"Deposite Money Successfully!"<<endl;
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                        break;
                    case 5: 
                        exit(0);
                    default :
                        cout<<"***************************************"<<endl;
                        cout<<"Invalid input!. Try again!"<<endl;
                        cout<<"Presss Enter!"<<endl;
                        cout<<"***************************************"<<endl;
                        getch();
                }
            }while(1);
        }
};

// main function is use to call the bank class and it's function.

int main (){
    bank user;

    user.main_intrface();
    
    return 0;
}
