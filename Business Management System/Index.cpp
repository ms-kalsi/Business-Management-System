#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class business_management{

    public:
    void meetings(void);
    void projects(void);
    void expenses(void);
};


class project:public business_management{
    public:
    void add_project(void);
};

class meeting:public business_management{
    public:
    void add_meet(void);
};

class expense:public business_management{
    public:
    void dexpense(void);
    void mexpense(void);
};


void meeting::add_meet(void){
    cout << "------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";
    cout <<"\nEnter Day\n";
    string day;
    int point = -1;
    int i = 0;
    string days[] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
    cin >> day;
    for(i = 0 ; i < 7 ; i++){
        if(day == days[i]){
            point = i;
            break;
        }
    }
    if(point == -1){
        cout << "\nWrong Day!!!\nEnter Appropriate Day\n\n";
        return;
    }
    string stt;
    fstream meet, temp;
    string str;
    int count = 0;
    meet.open("Meetings.txt", ios::out|ios::in);
    temp.open("temp.txt", ios::out|ios::in);
    if(!meet&&!temp){
        cout << "Unexpected error!!!\n";
    }else{
        string st;
        getline(meet, st);
        for(int j = 0; j < i ; j++){
            temp << st << endl;
            getline(meet, st);
        }
        if(st == "  N/A."){
            cout << "Note:- To add a meeting, write in the following format\n       <Meeting name> <double space> <time> <Double space> <Place>\n\n";
            getline(cin, stt);
            getline(cin, stt);
            stt = "  " + stt;
            temp << stt << endl;
            getline(meet, st);
            for(int j = 0; j < 6-i ; j++){
                if(j == 5-i)
                temp << st ;
                else
                temp << st << endl;
                getline(meet, st);
            }
            cout << "\nMeeting successfully scheduled!!["<< (char)251 <<"]\n";
            count++;
        }else{
            cout<<"\nDay is already Booked\n\n";
        }
    }
    cout << "------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";
    meet.close();
    temp.close();
    if(count == 1){
        meet.open("Meetings.txt", ios::out|ios::in);
        temp.open("temp.txt", ios::out|ios::in);
        if(!meet&&!temp){
            cout<<"Unexpected Error";
        }else{
            for(int j = 0 ; j < 7 ; j++){
                getline(temp, str);
                if(j == 6)
                meet << str;
                else
                meet << str << endl;
            }
        }
    }
}
void business_management::meetings(void){
    meeting meet1;
    cout << "------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";

    string days[] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
    int t = 7;
    int cc = 0;
    fstream meet;
    meet.open("Meetings.txt", ios::in|ios::out);
    if(!meet){
        cout << "Unexpected error!!!" << endl;
    }else{
        string st;
        while(!meet.eof()){
            getline(meet, st);
            int l = st.length();
            int count = 0;
            cout<<days[cc]<<endl;
            cc++;
            while(count < l){
                if(st[count]== ' ' && st[count+1] == ' ')
                cout << "\n";
                cout<<st[count];
                count++;
            }
            cout << "\n\n";
        }
        meet.close();
    }
    
    while(true){
        cout << "1. Schedule Meeting\n0. Back\n\n";
        int n;
        cin >> n;
        switch(n){
            case 1:
            meet1.add_meet();
            break;
        }
        if(n==0)
        break;
    }
    cout << "------------------------------------------------------------\n\n";
}


void project::add_project(void){
    cout << "------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";
    int c = 0, count = 0;
    fstream proj, temp;
    string stt;
    getline(cin, stt);
    cout << "\nEnter The project\n";
    getline(cin, stt);
    proj.open("Projects.txt", ios::out|ios::in);
    temp.open("temp.txt", ios::out|ios::in);
    if(!proj&&!temp){
        cout << "Unexpected error!!!\n";
    }else{
        string st;
        while(!proj.eof()){
            getline(proj, st);
            if(st == "UPCOMING"){
                temp << st << endl;
                while(!proj.eof()){
                    c++;
                    getline(proj, st);
                    temp << st << endl;
                }
                c++;
            }else{
                temp << st << endl;
            }
        }
        temp << "  " << c << ". " << stt ;
    }
    proj.close();
    temp.close();
    temp.open("temp.txt", ios::out|ios::in);
    if(!temp){
        cout << "Unexpecteed error!!!";
    }else{
        string st;
        while(!temp.eof()){
            count++;
            getline(temp, st);
        }
    }
    temp.close();
    proj.open("Projects.txt", ios::out|ios::in);
    temp.open("temp.txt", ios::out|ios::in);
    if(!proj&&!temp){
        cout << "Unexpected error!!!\n";
    }else{
        string st;
        for(int j = 0 ; j < count ; j++){
            getline(temp, st);
            if(j == count-1)
            proj << st;
            else
            proj << st << endl;
        }
    }
    proj.close();
    temp.close();
    cout << "\n------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";
}
void business_management::projects(void){
    project pro;
    cout << "-------------Ongoing Projects----------------\n";
    fstream proj;
    proj.open("Projects.txt", ios::out|ios::in);
    if(!proj){
        cout << "unexpected Error!!!";
    }else{
        while(!proj.eof()){
            string st;
            getline(proj, st);
            if(st == "ONGOING"){
                getline(proj, st);
                while(st != "NULL"){
                    cout << st << endl;
                    getline(proj, st);
                }
            }
            cout << endl;
            if(st == "UPCOMING")
            break;
        }
        proj.close();
    }
    cout << "-------------Upcoming Projects----------------\n";
    proj.open("Projects.txt", ios::out|ios::in);
    if(!proj){
        cout << "unexpected Error!!!";
    }else{
        while(!proj.eof()){
            string st;
            getline(proj, st);
            if(st == "UPCOMING"){
                getline(proj, st);
                while(!proj.eof()){
                    cout << st << endl;
                    getline(proj, st);
                }
                cout << st << endl;
            }
        }
        proj.close();
        cout << endl;
    }
    while(true){
        cout << "1. Add Project\n0. Back\n\n";
        int n;
        cin >> n;
        switch(n){
            case 1:
            pro.add_project();
            break;
        }
        if(n==0)
        break;
    }
    cout << "------------------------------------------------------------\n\n";

}


void expense::dexpense(void){
    cout << "\n-------------Daily Expenses----------------\n";
    fstream exp;
    int sum = 0;
    exp.open("Daily_Expenses.txt", ios::out|ios::in);
    if(!exp){
        cout << "Unexpected Error!!!";
    }else{
        string st;
        while(!exp.eof()){
            getline(exp, st);
            cout<<st<<endl;
        }
    }
    exp.close();
    exp.open("Daily_Expenses.txt", ios::out|ios::in);
    if(!exp){
        cout << "Unexpected Error!!!";
    }else{
        int i = 0;
        int temp = 0;
        string st;
        while(!exp.eof()){
            getline(exp, st);
            temp = 0;
            i=0;
            while(i<st.length()){
                char c = st[i];
                if(c>='0'&&c<='9'){
                    temp = temp*10 + c-'0';
                }
                i++;
            }
            sum+=temp;
        }
    }
    exp.close();
    cout << "\nTotal Expenses       : " << sum << endl;
    cout << endl;
}
void expense::mexpense(void){
    cout << "\n-------------Monthly Expenses----------------\n";
    fstream exp;
    int sum = 0;
    exp.open("Monthly_Expenses.txt", ios::out|ios::in);
    if(!exp){
        cout << "Unexpected Error!!!";
    }else{
        while(!exp.eof()){
            string st;
            getline(exp, st);
            cout<<st<<endl;
        }
    }
    exp.close();
    exp.open("Monthly_Expenses.txt", ios::out|ios::in);
    if(!exp){
        cout << "Unexpected Error!!!";
    }else{
        int i = 0;
        int temp = 0;
        string st;
        while(!exp.eof()){
            getline(exp, st);
            temp = 0;
            i=0;
            while(i<st.length()){
                char c = st[i];
                if(c>='0'&&c<='9'){
                    temp = temp*10 + c-'0';
                }
                i++;
            }
            sum+=temp;
        }
    }
    exp.close();
    cout << "\nTotal Expenses       : " << sum << endl;
    cout<<endl;     
}
void business_management::expenses(void){
    expense exp;
    cout << "------------------------------------------------------------\n\n";
    cout << "------------------------------------------------------------\n";

    while (true){
        int n1;
        cout << "1. Daily expenses" << endl
             << "2. Monthly expenses" << endl
             << "0. back\n" << endl;

        cin >> n1;
        switch (n1){
            case 1:
            exp.dexpense();
            break;

            case 2:
            exp.mexpense();
            break;

            case 0:
            break;

            default:
            cout << "\nPlease Enter the Appropriate number to Access the details\n\n";
            break;
        }
        if (n1 == 0)
        {
            break;
        }
    }
    cout << "------------------------------------------------------------\n\n";
}


int main(void){
    meeting meet;
    project proj;
    expense exp;
    cout << "-------------BUSINESS MANAGEMENT APPLICATION----------------\n";
    cout << "NOTE:- Please enter the appropriate Integer to access the required request\n\n";
    while(true){
        cout << "------------------------------------------------------------\n";
        cout << "1. Meetings\n2. Projects\n3. Expenses\n0. Exit\n\n";
        int n;
        cin >> n;
        switch(n){
            case 1:
            meet.meetings();
            break;
            case 2:
            proj.projects();
            break;
            case 3:
            exp.expenses();
            break;
            case 0:
            break;
            default:
            cout << "\nPlease Enter the Appropriate number to Access the details\n\n";
            break;
        }
        if(n==0)
        break;
    }
    cout << "------------------------------------------------------------\n\n";
    cout<<"APPLICATION EXITED\n\n";
    return 0;
}
