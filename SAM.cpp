#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#define null NULL

class student
{
    private:
        friend class studentMessage;
        student *next; //Node pointer
        string name; //student name
        int age; //age
        int id; //student ID
        double score[3]; //Three subjects
        double total; //Total score
        double average; //average score
    public:
        student(string _name,int _age,int _id,double *_score)
        {
            name = _name;
            age = _age;
            id = _id;
            score[0] = _score[0];
            score[1] = _score[1];
            score[2] = _score[2];
            total = score[0]+score[1]+score[2];
            average = total/3;
            next = NULL;
        }
        student() //To initialize the header node for studentMessage
        {
            name = "null";
            age = 0;
            id = 0;
            score[0]=score[1]=score[2]=0;
            total = 0;
            average = 0;
            next = NULL;
        }
        ~student(){}
        void swap(student*);
};


void student::swap(student *q)
{
    string _name;
    int _age,_id;
    double _score[3],_total,_average;

    _name = name;
    name = q->name;
    q->name = _name;

    _age = age;
    age = q->age;
    q->age = _age;

    _id = id;
    id = q->id;
    q->id = _id;

    _score[0] = score[0];
    score[0] = q->score[0];
    q->score[0] = _score[0];

    _score[1] = score[1];
    score[1] = q->score[1];
    q->score[1] = _score[1];

    _score[2] = score[2];
    score[2] = q->score[2];
    q->score[2] = _score[2];

    _total = total;
    total = q->total;
    q->total = _total;

    _average = average;
    average = q->average;
    q->average = _average;
}






class studentMessage
{
    private:
      student *first; //Head pointer
      int num; //Number of students in the message
    public:
        studentMessage()
        {
            num = 0; //Initialize the number of students to 0
            first = new student;  //Initialize the head node
        }
        ~studentMessage(){delete first;}

        /*Management system routine operation*/
        void Insert(void); //insert
        void Display(void); //display
        void Delete(void); //delete
        void Search(void); //search for
        void Change(void); //change
        void sortByLesson1(void); //Sort by grade
        void sortByLesson2(void); //Sort by grade two
        void sortByLesson3(void); //Sort by grade three
        void sortByTotal(void); //Sort by total score
        void SearchByid(void); //Find by student number
        void SearchByname(void); //Find by name
        int menu(void); //Initial menu
        void clear(void); //clear the list
};


int studentMessage::menu(void)
{
    int ch;
    cout<<"\t\t======================================================================"<<endl;
    cout<<"\t\t**************** Student Achievement Management System ***************"<<endl;cout<<endl;
    cout<<"\t\t 1. Show all student results"<<endl;
    cout<<"\t\t 2. Add student information"<<endl;
    cout<<"\t\t 3. Query student information"<<endl;
    cout<<"\t\t 4. Modify student information"<<endl;
    cout<<"\t\t 5. Delete the last student information"<<endl;
    cout<<"\t\t 6. Delete all information"<<endl;
    cout<<"\t\t 0. Exit the system"<<endl;cout<<endl;
    cout<<"\t\t======================================================================"<<endl;
    cout<<"\t\t Select your Option(1-6)"<<endl;
    cout<<"\t\t Press 0 to Exit"<<endl;
    cin >> ch;
    cout<<"\n\n\n"<<endl;

    return ch;
}



//insert
void studentMessage::Insert(void)
{
    string name;
    int age;
    int id;
    double score[3];
    cout<<"Please enter student name: ";
    cin>>name;
    cout<<"Please enter student age: ";
    cin>>age;
    cout<<"Please enter student ID: ";
    cin>>id;
    cout<<"Please enter the student's three course grades below: ";
    cout<<endl;
    cout<<"Please enter the grade of the first course: ";cin>>score[0];
    cout<<"Please enter the score of the second course: ";cin>>score[1];
    cout<<"Please enter the grade of the third course: ";cin>>score[2];
    cout<<endl;


    student *newstu = new student(name,age,id,score);
    student *p = first;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = newstu;
    newstu->next = null;
    num++;
}



void studentMessage::Display(void)
{
    if(num == 0)
    {
        cout<<"There are no students in the current record..."<<endl;
    }

    else
    {
        student *p = first->next;
        while(p != null)
        {
            cout<<"Name:"<<p->name<<"  ";
            cout<<"age:"<<p->age<<"  ";
            cout<<"student ID:"<<p->id<<"  ";
            cout<<"Three course results: "<<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<"  ";
            cout<<"Total score:"<<p->total<<"  ";
            cout<<"The average score:"<<p->average<<endl;
            p = p->next;
        }
    }
}


void studentMessage::Delete(void)
{
    student *p = first;
    student *pre = first;
    while(p->next != NULL)
    {
        pre = p;
        p = p->next;
    }
    pre->next = NULL;
    delete p;
    num--;
}


void studentMessage::Search(void)
{
    int temp = 0;
    cout<<"Please enter the search criteria, there are the following options..."<<endl;
    cout<<"Search by student ID (please enter [1]) Search by name (please enter [2])"<<endl;
    cin>>temp;
    switch(temp)
    {
        case 1: SearchByid(); break;
        case 2: SearchByname(); break;
        default: cout<<"Input error..."<<endl;
    }
}

void studentMessage::SearchByid(void)
{
    int _id;
    int flag = 0;
    cout<<"Please enter the student ID of the student to be searched:";
    cin >> _id;
    student *p = first->next;
    while(p != null)
    {
        if(p->id == _id)
        {
            flag = 1;
            cout<<"The following is the search result:"<<endl;
            cout<<"Name:"<<p->name<<"  ";
            cout<<"age:"<<p->age<<"  ";
            cout<<"student ID:"<<p->id<<"  ";
            cout<<"Three course results: "<<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<"  ";
            cout<<"Total score:"<<p->total<<"  ";
            cout<<"The average score:"<<p->average<<endl;
        }
        p = p->next;
    }
    if(flag == 0)
    {
        cout<<"Sorry, no matches were found in the record..."<<endl;
    }
}

void studentMessage::SearchByname(void)
{
    string _name;
    int flag = 0;
    cout<<"Please enter the name of the student to be searched: ";
    cin >> _name;
    student *p = first->next;
    while(p != null)
    {
        if(p->name == _name)
        {
            flag = 1;
            cout<<"The following is the search result:"<<endl;
            cout<<"Name:"<<p->name<<"  ";
            cout<<"age:"<<p->age<<"  ";
            cout<<"student ID:"<<p->id<<"  ";
            cout<<"Three course results: "<<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<"  ";
            cout<<"Total score:"<<p->total<<"  ";
            cout<<"The average score:"<<p->average<<endl;
        }
        p = p->next;
    }

    if(flag == 0)
    {
        cout<<"Sorry, no matches were found in the record..."<<endl;
    }
}



void studentMessage::Change(void)
{
    string _name;
    int flag = 0,temp;
    int _id,_age;
    int course = 0;
    cout<<"Please enter the name of the student whose information needs to be changed: ";
    cin >> _name;
    student *p = first->next;
    while(p != null)
    {
        if(p->name == _name)
        {
            flag = 1;
            cout<<"The current information of the student is as follows:"<<endl;
            cout<<"Name:"<<p->name<<"  ";
            cout<<"age:"<<p->age<<"  ";
            cout<<"student ID:"<<p->id<<"  ";
            cout<<"Three course results: "<<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<"  ";
            cout<<"Total score:"<<p->total<<"  ";
            cout<<"The average score:"<<p->average<<endl;
            cout<<"Please specify which item needs to be modified..."<<endl;
            cout<<"Modify student ID (input [1]) Modify age (input [2]) Modify grades (input [3])"<<endl;
            cin >> temp;
            switch(temp)
            {
                case 1:
                    {
                        cout<<"Please enter a new student ID:";cin>>_id;
                        p->id = _id;
                    }
                    break;
                case 2:
                    {
                        cout<<"Please enter a new age:";cin>>_age;
                        p->age = _age;
                    }
                    break;
                case 3:
                    {
                        cout<<"Please follow the instructions to modify the course grade..."<<endl;
                        cout<<"Do I need to modify the first course grade? (Need to enter [1], do not need to enter [0])"<<endl;
                        cin >> course;
                        if(course == 1)
                        {
                            cout<<"Please enter the revised grade of the first course:"; cin >> p->score[0];
                        }
                        course = 0;

                        cout<<"Do I need to modify the grades of the second course? (Need to enter [1], do not need to enter [0])"<<endl;
                        cin >> course;
                        if(course == 1)
                        {
                            cout<<"Please enter the revised grade of the second course:"; cin >> p->score[1];
                        }
                        course = 0;

                        cout<<"Do I need to modify the grades of the third course? (Need to enter [1], do not need to enter [0])"<<endl;
                        cin >> course;
                        if(course == 1)
                        {
                            cout<<"Please enter the revised grade of the third course:"; cin >> p->score[2];
                        }
                        course = 0;

                        p->total = p->score[0]+p->score[1]+p->score[2];
                        p->average = p->total/3;

                        cout<<"The revised information is as follows: "<<endl;
                        cout<<"Name:"<<p->name<<"  ";
                        cout<<"age:"<<p->age<<"  ";
                        cout<<"student ID:"<<p->id<<"  ";
                        cout<<"Three course results: "<<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<"  ";
                        cout<<"Total score:"<<p->total<<"  ";
                        cout<<"The average score:"<<p->average<<endl;
                    }
                    break;
                default:  cout<<"Input error..."<<endl;
            }
        }
        p = p->next;
    }
    if(flag == 0)
        cout<<"There is no secondary student in the current record..."<<endl;
}

/*I use the bubble sorting method for sorting, sorting from small to large*/


//Sort by subject one
void studentMessage::sortByLesson1(void)
{
    student *p = first->next;
    while(p->next != null)
    {
        student *q = p->next;
        while(q != null)
        {
            if(p->score[0] > q->score[0])
            {
                p->swap(q);
            }
            q = q->next;
        }
        p = p->next;
    }
}

//Sort by subject two
void studentMessage::sortByLesson2(void)
{
    student *p = first->next;
    while(p->next != null)
    {
        student *q = p->next;
        while(q != null)
        {
            if(p->score[1] > q->score[1])
            {
                p->swap(q);
            }
            q = q->next;
        }
        p = p->next;
    }
}

//Sort by subject three
void studentMessage::sortByLesson3(void)
{
    student *p = first->next;
    while(p->next != null)
    {
        student *q = p->next;
        while(q != null)
        {
            if(p->score[2] > q->score[2])
            {
                p->swap(q);
            }
            q = q->next;
        }
        p = p->next;
    }
}

//Sort by total score
void studentMessage::sortByTotal(void)
{
    student *p = first->next;
    while(p->next != null)
    {
        student *q = p->next;
        while(q != null)
        {
            if(p->total > q->total)
            {
                p->swap(q);
            }
            q = q->next;
        }
        p = p->next;
    }
}

void studentMessage::clear(void)
{
    student *p = first->next;
    while(p != null)
    {
        first->next = p->next;
        p->next = null;
        delete p;
        p = first->next;
    }
}
void intro()
{
	cout<<"\n\n\n\t    STUDENT ACHIEVEMENT";
	cout<<"\n\n\t\tMANAGEMENT";
	cout<<"\n\n\t \t SYSTEM";
	cout<<"\n\n\n\nMADE BY : LAGHZAOUI ISMAIL ";
	cout<<"\n\nStudent Number: 204490014";
	cin.get();
}


int main()
{
    studentMessage stulist;
    int ch;
    intro();
    system("cls");
    while(ch = stulist.menu())
    {
        switch(ch)
        {
            case 1:
            system("cls");
               stulist.Display();
            break;

            case 2:
            system("cls");
               stulist.Insert();
            system("cls");
            break;

            case 3:
            system("cls");
                stulist.Search();
            break;

            case 4:
            system("cls");
                stulist.Change();
            system("cls");
            break;
            case 5:
            system("cls");
                stulist.Delete();
            break;
            case 6:
            system("cls");
                stulist.clear();
            break;
            default: cout<<"Please enter as required..."<<endl;
        }
    }
    return 0;
}
