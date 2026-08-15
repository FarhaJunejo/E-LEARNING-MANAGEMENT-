#include <iostream>
#include <string>
using namespace std;

// Data
string teacherUser=" ", teacherPass="";
string studentUser=" ", studentPass="";
string adminUser="ali", adminPass="123";

// Simple course list
string courses[8] = {"C++", "Web development", "maths","science","English","management skill","ICT","biology"};

// Payment
void payment()
{
    int c;
    cout<<"\nPayment:\n1.Card 2.EasyPaisa 3.JazzCash\nChoice: ";
    cin>>c;

    if(c==1) cout<<"Paid by Card\n";
    else if(c==2) cout<<"Paid by EasyPaisa\n";
    else if(c==3) cout<<"Paid by JazzCash\n";
    else cout<<"Invalid\n";
}

// Student Menu
void studentMenu()
{
    int c;
    do{
        cout<<"\n---Student---\n1.View Courses\n2.Enroll\n3.Logout\nChoice: ";
        cin>>c;

        if(c==1)
        {
            for(int i=0;i<3;i++)
                cout<<i+1<<"."<<courses[i]<<endl;
        }

        else if(c==2)
        {
            int x;
            cout<<"Select Course (1-3): ";
            cin>>x;

            if(x>=1 && x<=3)
            {
                cout<<"Enrolled in "<<courses[x-1]<<endl;
                payment();
            }
            else
                cout<<"Invalid Course\n";
        }

    }while(c!=3);
}

// Teacher Menu
void teacherMenu()
{
    int c;
    do{
        cout<<"\n---Teacher---\n1.Add Course\n2.View Students\n3.Logout\nChoice: ";
        cin>>c;

        if(c==1)
        {
            string newCourse;
            cout<<"Enter new course: ";
            cin>>newCourse;
            cout<<"Course "<<newCourse<<" Added\n";
        }

        else if(c==2)
        {
            cout<<"Students List:\n";
            if(studentUser!="")
                cout<<"- "<<studentUser<<endl;
            else
                cout<<"No students\n";
        }

    }while(c!=3);
}

// Admin Menu
void adminMenu()
{
    int c;
    do{
        cout<<"\n---Admin---\n1.View Teachers\n2.View Students\n3.Add Course\n4.Delet course\n5.Logout\nChoice: ";
        cin>>c;

        if(c==1)
        {
            if(teacherUser!="")
                cout<<"Teacher: "<<teacherUser<<endl;
            else
                cout<<"No teacher\n";
        }

        else if(c==2)
        {
            if(studentUser!="")
                cout<<"Student: "<<studentUser<<endl;
            else
                cout<<"No student\n";
        }

        else if(c==3)
        {
            string newCourse;
            cout<<"Enter course: ";
            cin>>newCourse;
            cout<<"Course "<<newCourse<<" Added\n";
        }
        

    }while(c!=4);
}


int main()
{
	
	cout << "====================================\n";
    cout << " Welcome to E-Learning Management\n";
    cout << "====================================\n";

    int type, op;
    string u,p;

    cout<<"1.Teacher   2.Student    3.Admin\nChoose: ";
    cin>>type;

    cout<<"1.Login 2.Register\nChoose: ";
    cin>>op;

    // Teacher
    if(type==1)
    {
        if(op==2)
        {
            cout<<"Create Username: ";
            cin>>teacherUser;
            cout<<"Create Password: ";
            cin>>teacherPass;
        }

        cout<<"Login Username: ";
        cin>>u;
        cout<<"Password: ";
        cin>>p;

        if(u==teacherUser || p==teacherPass)
        {
            cout<<"Teacher Login\n";
            teacherMenu();
        }
        else cout<<"Wrong Login\n";
    }

    // Student
    else if(type==2)
    {
        if(op==2)
        {
            cout<<"Create Username: ";
            cin>>studentUser;
            cout<<"Create Password: ";
            cin>>studentPass;
        }

        cout<<"Login Username: ";
        cin>>u;
        cout<<"Password: ";
        cin>>p;

        if(u==studentUser || p==studentPass)
        {
            cout<<"Student Login\n";
            studentMenu();
        }
        else cout<<"Wrong Login\n";
    }

    // Admin
    else if(type==3)
    {
        cout<<"Username: ";
        cin>>u;
        cout<<"Password: ";
        cin>>p;

        if(u==adminUser || p==adminPass)
        {
            cout<<"Admin Login\n";
            adminMenu();
        }
        else cout<<"Wrong Admin Login\n";
    }

    else
        cout<<"Invalid Choice\n";

    return 0;
}
