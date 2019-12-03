#include<bits/stdc++.h>

using namespace std;

class node
{
public:

    int id;
    string name;
    node *next;
    node *prev;

    node(int x, string s)
    {
        id = x;
        name = s;
        next = NULL;
        prev = NULL;
    }

};

void print(node *head)
{
    if(head==NULL)
    {
        cout<<"\nList Empty";
        return;
    }

    node *t;
    cout<<endl;

    for(t=head;t;t=t->next)
    {
        cout<<t->id<<" , "<<t->name<<endl;
    }


}

void ins_begin(node *&head)
{
    int id;
    string name;

    cout<<"\nEnter Employee id  -   ";
    cin>>id;

    cout<<"\nEnter Employee name  -   ";
    cin>>name;

    node *x = new node(id, name);
    if(head==NULL)
    {
        head = x;
        print(head);
    }

    else
    {
        head->prev = x;
        x->next = head;
        head = x;
        print(head);
    }
}

void del_end(node *&head)
{
    if(head==NULL)
    {
        cout<<"\nList Empty";
        return;
    }

    node *t = head;

    while(t->next!=NULL)
        t=t->next;

    t->prev->next= NULL;
    delete(t);

    cout<<"\nElement deleted";

    print(head);
}

int main()
{
    node *head = NULL;
    int n;

    while(1)
    {
        cout<<"\nEnter 1 to insert at beg";
        cout<<"\nEnter 2 to delete at end";
        cout<<"\nEnter 3 to traverse";
        cout<<"\nEnter 4 to exit    -   ";
        cin>>n;

        switch(n)
        {
                case 1: ins_begin(head);
                        break;

                case 2: del_end(head);
                        break;

                case 3: print(head);
                        break;

                case 4: exit(0);
        }
    }

    return 0;

}

