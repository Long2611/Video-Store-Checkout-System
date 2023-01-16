#include <iostream>
#include <string>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class Node
{
    private:
        int numb_actors; 
        string movie, director, year, status, id, date;
        string actors[10]; 
        Node* next;
    public:
        Node(string movie, string director, string year,int numbActors, string actors[10], string status, string id, string date);
        Node* getNext();
        string getData(int choice);
        string* getActor();
        int getNumbActor();
        void setNext(Node* ptr);
        void setData(string movie, string director, string year, int numbActors, string actors[10], string status, string id, string date);
        void modifyDataIn(Node* ptr);//check in.
        void modifyDataOut(Node* ptr, string ID, string date);//check out.
};

class ArrayLinkedlist
{
    private:
        
    public:
        Node* movie[100];
        Node* actors[100];
        Node* head;
        int size_actor;
        ArrayLinkedlist();//constructor
        void add_node_at_tail(string movie, string director, string year,int numbActors, string actors[10], string status, string id, string date);
        string lower_case(string name);
        void search_movie_by_movie(string movie);
        void searchMovieByActors(string actors);
        void checkMissing();
        void checkIn(string movie, string ID);
        void checkOut(string movie, string ID, string data);
        int size();
        void get_movie();
        void search();
        void createArr();
        void createArrActors();
        void sortArr(int arrSize, int choice);
        void sortActor();
        void printSearch(int startIndex, int endIndex);
        int binarySearchFirst(int left, int right, string target, int choice);
        int binarySearchLast(int left, int right, string target, int choice);
};
class Array
{
    private:
    string movie[100];
    string director[100];
    string actor[100];
    string year[100];
    public:
    void arr_resize();
    void create_arr(int options);
    void sort_arr(string arr[]);
};



class Movie_service
{
    public:
    void run();
};
#endif
