#include <iostream>
#include <string.h>
#include "Linkedlist.h"

using namespace std;

Node::Node(string movie, string director, string year, int numb_actors, string actors[], string status,  string id, string date)
{
    this->movie = movie;
    this->director = director;
    this->year = year; 
    this->numb_actors = numb_actors;
    // this->actors = actors;
    this->status = status;
    this->id = id;
    this->date = date;
    for (int i = 0; i < numb_actors; i++)
    {
        this->actors[i] = actors[i];
    }
    next = NULL;
}

Node* Node::getNext()
{
    return next;
}

string Node::getData(int choice) //get movie variable
{
    string result;
    switch (choice)
    {
    case 1:
        result = this->movie;
        return result;
    case 2:
        result = this->director;
        return result;
    case 3:
        result = this->year;
        return result;
    case 4:
        result = this->numb_actors;
        return result;
    case 5:
        for (int i = 0; i < this->numb_actors; i++)
        {
            result = result + actors[i] + " ";
        }
        // result = this->actors;
        return result;
    case 6:
        result = this->status;
        return result;
    case 7:
        result = this->id;
        return result;
    case 8:
        result = this->date;
        return result;
    default:
        return result = -1;
        break;
    }
    
}

int Node::getNumbActor()
{
    int result = this->numb_actors;
    return result;
}

string* Node::getActor()
{
    string * result = actors;
    return result;
}


void Node::setData(string movie, string director, string year, int numb_actors, string actors[], string status, string id, string date)
{
    this->movie = movie;
    this->director = director;
    this->year = year; 
    this->numb_actors = numb_actors; 
    // this->actors = actors;
    this->status = status;
    this->id = id;
    this->date = date;
    for (int i = 0; i < numb_actors; i++)
    {
        this->actors[i] = actors[i];
    }
}

void Node::setNext(Node *newPointer)
{
    next = newPointer;
}

void Node::modifyDataIn(Node* ptr)
{
    ptr->status = "in";
    ptr->id = "";
    ptr->date = "";
}

void Node::modifyDataOut(Node* ptr, string ID, string date)
{
    ptr->status = "out";
    ptr->id = ID;
    ptr->date = date;
}

ArrayLinkedlist::ArrayLinkedlist()
{
    head = NULL; 
}

// function will receive a string and return a same
// string with all lowercase to void case sensitive
string ArrayLinkedlist::lower_case(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    return name;
}

// void ArrayLinkedlist::add_node(string movie, string director, string year, string actors, string status, string id, string date)
// {
//     Node* new_node = new Node(movie, director, year, actors, status, id, date);
//     new_node->setNext(head);
//     head = new_node;
// }

void ArrayLinkedlist::add_node_at_tail(string movie, string director, string year, int numb_actors, string actors[], string status, string id, string date)
{
    Node* newNode = new Node(movie, director, year, numb_actors, actors, status, id, date);
    newNode->setNext(NULL);
    if(head == NULL)
    {
        head = newNode;
        return;
    } else {
        Node* currNode = head;
        while(currNode->getNext() != NULL)
        {
            currNode = currNode->getNext();
        }
        currNode->setNext(newNode);
    }
}

int ArrayLinkedlist::size()
{
    Node* currNode = head;
    int result = 0;
    while(currNode->getNext() != NULL)
    {
        result += 1;
        currNode = currNode->getNext();
    }
    return result;
}

void ArrayLinkedlist::get_movie()
{
    Node* curr_node = head;
    while(curr_node->getNext() != NULL)
    {
        // cout << curr_node->get_data() << endl;
        curr_node = curr_node->getNext();
    }

}

void ArrayLinkedlist::searchMovieByActors(string actors)
{
    Node* currNode = head;
    string search;
    int leng = actors.size();
    actors = lower_case(actors);
    while(currNode->getNext() != NULL)
    {
        string act = currNode->getData(5);
        act = lower_case(act);
    
        string temp = act.substr(0,leng);
        if (temp == actors)
        {
            cout << currNode->getData(1) << " " <<
            currNode->getData(2) << " " <<
            currNode->getData(3) << " " <<
            currNode->getData(4) << " " <<
            currNode->getData(5) << " " <<
            currNode->getData(6)<< endl;
        } 
        currNode = currNode->getNext();
    }
}

void ArrayLinkedlist::checkMissing()
{
    Node* currNode = head;
    while(currNode->getNext() != NULL)
    {
        string status = currNode->getData(6);
        string result;
        if (status == "out")
        {
            result = currNode->getData(1) + " " +
            currNode->getData(2) + " " +
            currNode->getData(3) + " " +
            currNode->getData(6) + " " +
            currNode->getData(7);
            cout << result << endl;
        }
        currNode = currNode->getNext();
    }
}

void ArrayLinkedlist::checkIn(string movie, string ID)
{
    Node* currNode = head;
    string searchingMovie, searchingID;
    while(currNode->getNext() != NULL)
    {
        searchingMovie = currNode->getData(1);
        searchingID = currNode->getData(7);
        if (searchingID == ID && searchingMovie == movie)
        {
            currNode->modifyDataIn(currNode);
            cout << "check-in successfully" << endl;
            break;
        } else {
            cout << "Your ID is not in the system" << endl;
            break;
        }
        currNode = currNode->getNext();
    }
}

void ArrayLinkedlist::checkOut(string movieSearch, string ID, string date)
{
    Node* currNode = head;
    int indexStart, indexEnd, amount;
    string checkStatus;
    createArr();
    sortArr(size(), 1);
    indexStart = binarySearchFirst(0,size()-1,movieSearch,1);
    indexEnd = binarySearchLast(0,size()-1,movieSearch,1);
    if(indexStart == indexEnd)
    {
        cout << "We don't have the movie" << endl;
    }else{

        amount = (indexEnd - indexStart) + 1;
        for (int i = indexStart; i <= indexEnd; i++)  
        {
            checkStatus = movie[i]->getData(6);
            if (checkStatus == "in")
            {
                movie[i]->modifyDataOut(movie[i], ID, date);
                cout << movie[i]->getData(1) << " " <<
                movie[i]->getData(2) << " " <<
                movie[i]->getData(3) << " " <<
                movie[i]->getData(7) << " " <<
                movie[i]->getData(8) << " " << endl;
                break;
            } else if(checkStatus == "out" && i == indexEnd)
            {
                cout << "Movie you want is currently unavaiable due to out of stock" <<endl;
            }
        }
    }
}

void ArrayLinkedlist::createArr()
{
    Node* currNode = head;
    int i = 0;
    while(currNode->getNext() != NULL)
    {
        movie[i] = currNode;
        i++;
        currNode = currNode->getNext();
    }
}

void ArrayLinkedlist::createArrActors()
{
    Node* currNode = head;
    int j = 0;
    size_actor = 0;
    while(currNode->getNext() != NULL)
    {
        int numb_act = currNode->getNumbActor();
        for(int i = 0; i < numb_act; i++)
        {
            actors[j+i] = currNode;
        }
        j++;
        currNode = currNode->getNext();
        size_actor += numb_act;
    }
    cout << size_actor << endl;
}

void ArrayLinkedlist::sortArr(int size, int choice)
{
    switch (choice)
    {
    case 1: //Sort to movie title 
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (size - i - 1); j++)
            {
                string name1 = movie[j]->getData(1) ;
                name1 = lower_case(name1);
                string name2 = movie[j+1]->getData(1) ;
                name2 = lower_case(name2);
                if(name1 > name2)
                {
                    Node *temp = movie[j];
                    movie[j] = movie[j+1];
                    movie[j+1] = temp;
                }
            }
        }
        break;
    case 2: //Sort to director 
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (size - i - 1); j++)
            {
                string name1 = movie[j]->getData(2) ;
                name1 = lower_case(name1);
                string name2 = movie[j+1]->getData(2) ;
                name2 = lower_case(name2);
                if(name1 > name2)
                {
                    Node *temp = movie[j];
                    movie[j] = movie[j+1];
                    movie[j+1] = temp;
                }
            }
        }
        break;
    case 3: //Sort to year made.
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (size - i - 1); j++)
            {
                string name1 = movie[j]->getData(3) ;
                name1 = lower_case(name1);
                string name2 = movie[j+1]->getData(3) ;
                name2 = lower_case(name2);
                if(name1 > name2)
                {
                    Node *temp = movie[j];
                    movie[j] = movie[j+1];
                    movie[j+1] = temp;
                }
            }
        }
        break;
    default:
        break;
    }
    
}

void ArrayLinkedlist::sortActor()
{
    for (int i = 0; i < size_actor; i++)
    {
        for (int j = 0; j < size_actor - i - 1; j++)
        {
            string * arr = actors[j]->getActor();
            string name1, name2;
            for (int k = 0; k < actors[j]->getNumbActor(); k++)
            {
                name1 = arr[k];
                name2 = arr[k+1];
            }
        }
    }
}


int ArrayLinkedlist::binarySearchFirst(int left, int right, string target, int choice)
{
    int targetLength = target.size();
    // cout << targetLength << endl;
    switch (choice)
    {
    case 1: // Search for movie by movie.
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            string str1 = movie[mid]->getData(1).substr(0,targetLength);
            // string str2 = movie[mid-1]->getData(1).substr(0,targetLength);
            if (mid == 0 || movie[mid-1]->getData(1).substr(0,targetLength) < target && str1 == target) 
            {
                return mid;
            }
            else if (target > str1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    case 2: // Search for movie by director.
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            string str1 = movie[mid]->getData(2).substr(0,targetLength);
            // string str2 = movie[mid-1]->getData(1).substr(0,targetLength);
            if (mid == 0 || movie[mid-1]->getData(2).substr(0,targetLength) < target && str1 == target) 
            {
                return mid;
            }
            else if (target > str1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    case 3: // Search for movie by year made.
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            string str1 = movie[mid]->getData(3).substr(0,targetLength);
            // string str2 = movie[mid-1]->getData(1).substr(0,targetLength);
            if (mid == 0 || movie[mid-1]->getData(3).substr(0,targetLength) < target && str1 == target) 
            {
                return mid;
            }
            else if (target > str1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    default:
        return -1;
        break;
    }
    return -1;
    // while (left <= right)
    // {
    //     int mid = left + (right - left)/2; 
    //     string str1 = movie[mid]->getData(1).substr(0,targetLength);
    //     // string str2 = movie[mid-1]->getData(1).substr(0,targetLength);
    //     if (mid == 0 || movie[mid-1]->getData(1).substr(0,targetLength) < target && str1 == target) 
    //     {
    //         return mid;
    //     }
    //     else if (target > str1) {
    //         left = mid + 1;
    //     }
    //     else {
    //         right = mid - 1;
    //     }
    // }
    // cout << "First done" << endl;
    // return -1;
}

int ArrayLinkedlist::binarySearchLast(int left, int right, string target, int choice)
{
    int targetLength = target.size();
    // cout << targetLength << endl;
    int size = right+1;
    switch (choice)
    {
    case 1:
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            // cout << target << " vs " << movie[mid]->getData(1) << endl;
            string str1 = movie[mid]->getData(1).substr(0,targetLength);
            // string str2 = movie[mid+1]->getData(1).substr(0,targetLength);
            if (mid == right || movie[mid+1]->getData(1).substr(0,targetLength) > target && str1 == target) 
            {
                return mid;
            }
            else if (target < str1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
        break;
    case 2:
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            // cout << target << " vs " << movie[mid]->getData(1) << endl;
            string str1 = movie[mid]->getData(2).substr(0,targetLength);
            // string str2 = movie[mid+1]->getData(1).substr(0,targetLength);
            if (mid == right || movie[mid+1]->getData(2).substr(0,targetLength) > target && str1 == target) 
            {
                return mid;
            }
            else if (target < str1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
        break;
    case 3: 
        while (left <= right)
        {
            int mid = left + (right - left)/2; 
            // cout << target << " vs " << movie[mid]->getData(1) << endl;
            string str1 = movie[mid]->getData(3).substr(0,targetLength);
            // string str2 = movie[mid+1]->getData(1).substr(0,targetLength);
            if (mid == right || movie[mid+1]->getData(3).substr(0,targetLength) > target && str1 == target) 
            {
                return mid;
            }
            else if (target < str1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
        break;
    default:
        return -1;
        break;
    }
    
    cout << "Last done" << endl;

    // return -1;
}
void ArrayLinkedlist::printSearch(int startIndex, int endIndex)
{
    if (startIndex == -1 || endIndex == -1 ||startIndex==endIndex)
    {
        cout << "Movie does noot found, we might does not have it right now." << endl;
        return;
    }
    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << movie[i]->getData(1) << " " <<
        movie[i]->getData(2) << " " <<
        movie[i]->getData(3) << " " <<
        movie[i]->getData(4) << " " <<
        movie[i]->getData(5) << " " <<
        movie[i]->getData(6)<< endl;
    }
}

//g++ Homework5.cpp Phonebook.cpp Node.cpp -o Phonebook
