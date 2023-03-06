// Worked on by- Efrain, Jack, Kevin, Halit

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// giving all the values
class nodes
{

public:
    float ID;
    string name;
    double gpa;
    nodes *nxt;

nodes()
    {
        ID=0;
        name=" ";
        gpa=0;
        nxt=NULL;
    }

    nodes (float a, string b, double c)
    {
        ID = a;
        name = b;
        gpa = c;
    }
}
;

//addressing the heading of the linklist(the first link)
class linkList
{

public:
    nodes *heading;
    linkList()
    {
        heading = NULL;
    }
    linkList(nodes *n)
    {
        heading=n;
    }

    nodes *existingNode(float a)
    {
        nodes *temporary = NULL;
        nodes* pointer = heading;
        while(pointer!=NULL)
        {
            if(pointer->ID==a)
            {
                temporary = pointer;

            }
            pointer = pointer->nxt;

        }

        return temporary;
    }

//Adding a nodes
void addingNode(nodes *n)
    {

        if(existingNode(n->ID)!=NULL)
        {
            cout<<"-this ID already exist in file, try another ID-"<<endl;
        }
        else
        {
            if(heading == NULL)
            {
                heading = n;
                cout<<"  "<<endl;

            }
            else
            {
                nodes *pointer = heading;
                while(pointer->nxt!=NULL)
                {
                    pointer = pointer -> nxt;
                }
                pointer->nxt = n;
                cout<<"-ID has been added-"<<endl;

            }

        }

    }

// deleting a nodes by using its ID
void deletingNode(float a)
    {
        if(heading == NULL)
        {
            cout<<"-list is currently empty, add an ID.-"<<endl;

        }
        else if(heading!=NULL)
        {
            if(heading->ID==a)
            {
                heading = heading -> nxt;
                cout<<"-student with ID- "<<a<<"has been deleted.-"<<endl;

            }
            else
            {
                nodes *temporary = NULL;
                nodes *previousPtr = heading;
                nodes *currentPtr = heading -> nxt;
                while(currentPtr!=NULL)
                {
                    if(currentPtr -> ID == a)
                    {
                        temporary = currentPtr;
                        currentPtr = NULL;

                    }
                    else
                    {
                        previousPtr = previousPtr -> nxt;
                        currentPtr = currentPtr -> nxt;

                    }

                }
                if(temporary != NULL)
                {
                    previousPtr -> nxt = temporary -> nxt;
                    cout<<"-student deleted with ID: "<<a<<endl;

                }
                else
                {
                    cout<<"-no student exists with ID: "<<a<<endl;

                }

            }

        }

    }
//updating a nodes by using the ID
void updatingNode(float a, string b, double c)
    {
        nodes *pointer = existingNode(a);
        if(pointer!=NULL)
        {
            pointer->ID = a;
            pointer->name= b;
            pointer->gpa= c;
            cout<<"-individual student data has been updated-"<<endl;

        }
        else
        {
            cout<<"-student with ID: "<<a<<" doesn't exist, try another ID.-"<<endl;

        }

    }
//sorting the list by ID
void sortingList()
    {
        nodes *pointer, *currentPtr;
        float temporary;
        string abc;
        pointer = heading;
        while(pointer->nxt != NULL)
        {
            currentPtr = pointer -> nxt;
            while(currentPtr!=NULL)
            {
                if(pointer->ID>currentPtr->ID)
                {
                    temporary = pointer -> ID;
                    pointer -> ID = currentPtr -> ID;
                    currentPtr -> ID = temporary;
                    temporary = pointer -> gpa;
                    pointer ->gpa = currentPtr -> gpa;
                    currentPtr -> gpa = temporary;
                    abc = pointer -> name;
                    pointer ->name = currentPtr -> name;
                    currentPtr -> name = abc;

                }
                currentPtr = currentPtr -> nxt;

            }
            pointer = pointer -> nxt;

        }
    }
//displaying the entire linklist
void displayingList()
    {
        if(heading == NULL)
        {
            cout<<"-there is currently no data.-";

        }
        else
        {
            cout<<endl;
            cout<<"list of students on file: "<<endl;
            nodes *temporary = heading;
            while(temporary!=NULL)
            {
                cout<<" ID: "<<temporary->ID<<
                " Name: "<<temporary -> name<<
                " GPA: "<<temporary -> gpa<<endl;
                temporary = temporary -> nxt;

            }

        }

    }
// deleting the entire linklist
void purgingList()
    {
        nodes *temporary = heading;
        if(heading==NULL)
        {
            cout<<"-the list is currently empty-"<<endl;

        }
        else
        {
            while(temporary!=NULL)
            {
                temporary = temporary -> nxt;
                free(heading);
                heading = temporary;

            }
            cout<<"-data has been purged.-"<<endl;

        }

    }
//Showing a clean list either at the start or after purging
void cleanList()
        {
            nodes *temporary = heading;
            if(heading==NULL)
            {
                cout<<" ";

            }
            else
            {
                while(temporary!=NULL)
                {
                    temporary = temporary -> nxt;
                    free(heading);
                    heading = temporary;

                }
                cout<<" ";

            }
        }
//Display an individual student
void displayingIndividualStudent(int a)
    {
        nodes *temporary = heading;
        if(heading == NULL)
        {
            cout<<"-there is no data on file.-"<<endl;

        }
        else if(heading!=NULL)
        {
    if(heading->ID==a)
    {
        heading = heading -> nxt;
        cout<<"student with ID: "<<a<<" has this data: "<<endl;
        cout<<" Name: "<<temporary->name<<" GPA: "<<temporary -> gpa<<endl;

    }
            else
            {
                nodes *temporary = NULL;
                nodes *previousPtr = heading;
                nodes *currentPtr = heading -> nxt;
                while(currentPtr!=NULL)
                {
                    if(currentPtr -> ID == a)
                    {
                        temporary = currentPtr;
                        cout<<"student with ID: "<<a<<" has this data:"<<endl;
                        cout<<" Name: "<<temporary->name<<" GPA: "<<temporary-> gpa<<endl;
                        currentPtr = NULL;

                    }
                    else
                    {
                        previousPtr = previousPtr -> nxt;
                        currentPtr = currentPtr -> nxt;

                    }

                }

            }

        }

    }
//empty list
bool emptyList()
    {
        if(heading == NULL)
            return true;
        else
            return false;

    }

};


int main()
{
    linkList a;
    int userOptions;
    float ID1, inputByUser;
    double GPA1;
    string Name1;

    do
    {
        cout << "what would you like to do?" << endl;
        cout << "1. create list." << endl;
        cout << "2. add student." << endl;
        cout << "3. delete student." << endl;
        cout << "4. update/modify student data." << endl;
        cout << "5. search for an indivudual student."<<endl;
        cout << "6. display entire list." << endl;
        cout << "7. purge entire list." << endl;


        cin >> userOptions;
        nodes * nodes1 = new nodes();
        switch (userOptions)

        {
            case 0:
                break;
            case 1:
                cout<<"new list created."<<endl;
                a.cleanList();
                break;
            case 2:
                cout << " enter the ID of the student: " << endl;
                cin >> ID1;
                cout<<" enter the name of the student: "<<endl;
                cin>>Name1;
                cout<<" enter the GPA of the student: "<<endl;
                cin>>GPA1;
                nodes1 -> gpa = GPA1;
                nodes1 -> ID = ID1;
                nodes1 -> name = Name1;
                a.addingNode(nodes1);
                break;
            case 3:
                cout << " delete student By ID - \nenter ID of the student to be deleted: " << endl;
                cin >> inputByUser;
                a.deletingNode(inputByUser);
                break;
            case 4:
                cout << " update student By ID - \nenter the student ID to be updated:" << endl;
                cin >> ID1;
                cout<<" enter a new name: "<<endl;
                cin>>Name1;
                cout<<" enter a new GPA: "<<endl;
                cin >> GPA1;
                a.updatingNode(ID1, Name1, GPA1);
                break;
            case 5:
                cout<<" enter the ID of the student you would want to search for: "<<endl;
                cin>>inputByUser;
                a.displayingIndividualStudent(inputByUser);
                break;
            case 6:
            if(a.emptyList()==true)
            {
                a.displayingList();

            }
            else
            {
                a.sortingList();
                a.displayingList();

            }
            break;

            case 7:
            a.purgingList();
            break;
            default:
            cout << "-enter the right numbers above-" << endl;

        }
    }
    while (userOptions != 0);
    return 0;
}
