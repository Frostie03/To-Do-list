/*this program using data structures stack queue and linked list to create a to-do list depending on how the user wants to organise the list the program 
will use the appropriate algorithm and also give the appropriate operations for the same algorithm */
#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node* next;
};

class Stack//data structure stores LIFO
{
    private:
        Node* top;

    public:
        Stack()
        {
            top = nullptr;
        }

        void push (string data)
        {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }

        void pop ()
        {
           if (top == nullptr)
           {
                cout << "List is empty!!!" << endl;
                return;
           } 
           
           Node* temp = top;
           top = top->next;
           delete temp;
        }

        void displayStack()
        {
            if (top ==nullptr)
            {
                cout << "List is empty!!!" << endl;
                return;
            }

            Node* temp = top;
            int i=1;
            while (temp != nullptr)
            {
                cout<<i<<". "<<temp->data<<endl;
                temp = temp ->next;
                i++;
            }
        }

};

class Queue//data structure stores FIFO
{
    private:
        Node* front;
        Node* rear;

    public:
        Queue()
        {
            front = nullptr;
            rear = nullptr;
        }

        void Enqueue(string data)
        {
            Node* newNode = new Node();
            newNode->data = data;
            if (rear == nullptr)
            {
                front = rear = newNode;
                return;
            }

            rear -> next = newNode;
            rear = newNode;
        }

        void Dequeue ()
        {
            if (front == nullptr)
            {
                cout<<"List is empty!!"<<endl;
                return;
            }

            front = front->next;
            if (front == nullptr)
            {
                rear = nullptr;
            }
        }

        void displayQueue()
        {
            if (front == nullptr)
            {
                cout<<"List is empty!!"<<endl;
                return;
            }

            Node* temp = front;
            int i=1;
            while (temp != nullptr)
            {
                cout<<i<<". "<<temp->data<<endl;
                temp = temp->next;
                i++; 
            }
        }

};

class LinkedList//data structure stores dynamically and dynamic accessing of data
{
    protected:
        Node* head;

    public:
        LinkedList ()
        {
            head = nullptr;
        }

        void InsertAtStart(string data)
        {
            Node* newNode = new Node();
            newNode -> data = data;
            newNode ->next = head;
            head = newNode;
        }

        void InsertionAtEnd(string data)
        {
            Node* newNode = new Node();
            newNode -> data = data;
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node* temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void InsertionAtLocation(string data, int position)
        {
            Node* newNode = new Node();
            newNode->data = data;
            if (position == 0)
            {
                InsertAtStart(data);
                return;
            }

            Node* temp = head;
            for (int i = 0; temp != nullptr && i < position - 1; i++)
            {
                temp = temp->next;
            }

            if (temp == nullptr)
            {
                cout<<"Position is out of bound!!!"<<endl;
                delete newNode;
                return;
            }

            newNode -> next = temp->next;
            temp->next = newNode;
        }
};

class Deletion : public LinkedList//derived class to perform deletion operations for linked List 
{
    public:
        void DeletionAtStart()
        {
            if (head == nullptr)
            {
                cout<<"List is empty!!!"<<endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void DeletionAtEnd()
        {
            if (head == nullptr)
            {
                cout<<"List is empty!!!"<<endl;
                return;
            }

            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;
        } 

        void DeletionAtLocation (int position)
        {
            if ( head == nullptr)
            {
                cout<<"List is empty!!!"<<endl;
                return;
            }

            if (position == 0)
            {
                DeletionAtStart();
                return;
            }

            Node* temp = head;
            for(int i = 0; temp != nullptr && i < position - 1; i++)
            {
                temp = temp->next;
            }

            if (temp == nullptr || temp->next == nullptr)
            {
                cout<<"Position is out of range!!!"<<endl;
                return;
            }

            Node* nodeToDeleted = temp -> next;
            temp->next = temp->next->next;
            delete nodeToDeleted;
        }

        void DisplayLinkedlist()
        {
            Node* temp = head;
            int i=1;
            while (temp != nullptr)
            {
                cout<<i<<". "<<temp->data<<endl;
                temp = temp->next;
                i++;
            }
            cout<<endl;
            
        }

};

int main()
{
    Stack obj1;
    Queue obj2;
    Deletion obj3;
    
    int choice, position, size, opp;
    string data;
    cout<<"Choose the order in which you will enter you tasks"<<endl;
    cout<<"1. First task is the last in the list"<<endl;
    cout<<"2. First task is the first in the list"<<endl;
    cout<<"3. Random order"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>choice;
    while (choice < 0 || choice > 5)
    {
        cout<<"Invalid choice!!!"<<endl;
        cout<<"Enter the valid input"<<endl;
        cin>>choice;
    }

    switch (choice)
    {
        case 1:
            cout<<"Enter the number of tasks: "<<endl;
            cin>>size;
            cout<<"Enter the task: "<<endl;
            for(int i = 0; i < size; i++)
            {
                cin>>data;
                obj1.push(data);
            }
            break;
        
        case 2:
            cout<<"Enter the number of tasks: "<<endl;
            cin>>size;
            cout<<"Enter the task: "<<endl;
            for(int i = 0; i < size; i++)
            {
                cin>>data;
                obj2.Enqueue(data);
            }
            break;

        case 3:
            cout<<"Enter the number of tasks: "<<endl;
            cin>>size;
            cout<<"Enter the task: "<<endl;
            for(int i = 0; i < size; i++)
            {
                cin>>data;
                obj3.InsertionAtEnd(data);
            }
            break;

        case 4: 
            cout<<"Exiting..."<<endl;
            break;
        
        default:
            cout<<"Invalid choice!!!"<<endl;
            break;
    }

    if (choice == 4)
    {
        return 0;
    }
    else
    {
        switch (choice)
        {
        case 1:
            do
            {
                cout<<"Do you want to: "<<endl;
                cout<<"1. Delete last task\n2. Insert new task\n3. Display list\n4. Exit"<<endl;
                cin>>opp;
                switch(opp)
                {
                    case 1:
                        obj1.pop();
                        break;
                        
                    case 2:
                        cout<<"Enter the task: "<<endl;
                        cin>>data;
                        obj1.push(data);
                        break;
                        
                    case 3:
                        obj1.displayStack();
                        break;

                    case 4: 
                        cout<<"Exiting..."<<endl;
                        return 0;

                    default:
                        cout<<"Invalid choice"<<endl;
                }
            }
            while (opp != 4);
            break;
        
        case 2: 
            do
            {
                cout<<"Do you want to: "<<endl;
                cout<<"1. Delete first task\n2. Insert new task\n3. Display list\n4. Exit"<<endl;
                cin>>opp;
                switch(opp)
                {
                    case 1:
                        obj2.Dequeue();
                        break;
                        
                    case 2:
                        cout<<"Enter the task: "<<endl;
                        cin>>data;
                        obj2.Enqueue(data);
                        break;
                        
                    case 3:
                        obj2.displayQueue();
                        break;

                    case 4:
                        cout<<"Exiting..."<<endl;
                        return 0;

                    default:
                        cout<<"Invalid choice"<<endl;
                }
            }
            while (opp != 4);

        case 3:
            do
            {
                cout<<"Do you want to: "<<endl;
                cout<<"1. Insert at the start\n2. Insert in the middle\n3. Insert at the end"<<endl;
                cout<<"4. Delete the first task\n5. Delete in the middle\n6. Delete at the end\n7. Display\n8. Exit"<<endl;
                cin>>opp;
                switch(opp)
                {
                    case 1:
                        cout<<"Enter the task to be inserted at the start: ";
                        cin>>data;
                        obj3.InsertAtStart(data);
                        break;
                        
                    case 2:
                        cout<<"Enter the position to insert the task: "<<endl;
                        cin>>position;
                        cout<<"Enter the task to be inserted in the middle: ";
                        cin>>data;
                        obj3.InsertionAtLocation(data, position);
                        break;
                        
                    case 3:
                        cout<<"Enter the task to be inserted at the end: ";
                        cin>>data;
                        obj3.InsertionAtEnd(data);
                        break;
                    
                    case 4:
                        obj3.DeletionAtStart();
                        break;
                    
                    case 5:
                        cout<<"Enter the position to delete the task: "<<endl;
                        cin>>position;
                        obj3.DeletionAtLocation(position);
                        break;

                    case 6:
                        obj3.DeletionAtEnd();
                        break;

                    case 7: 
                        obj3.DisplayLinkedlist();
                        break;

                    case 8:
                        cout<<"Exiting..."<<endl;
                        return 0;
                
                    default:
                        cout<<"Invalid choice"<<endl;
                }
            }
            while (opp != 8);
        default:
            cout<<"Inavalid opption!!!"<<endl;
            break;
        }
    }
    return 0;
}