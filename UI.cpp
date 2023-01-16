#include "Linkedlist.h"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

void Movie_service::run()
{
    string file_name = "VideoDB1.txt";
    string words, movie, director, year, 
    actors, total_actors, status, id, date;
    int numb_actors;
    fstream file;
    file.open(file_name.c_str());
    int lines, numb;
    file >> lines >> numb;
    string totalActors[10];
    ArrayLinkedlist record;
    for (int i = 0; i < lines; i++)
    {
        movie = "";
        director = "";
        year = "";
        file >> movie >> director >> year >> numb_actors;
        // cout << movie << " " << director << " " << year << " " << numb_actors << endl;
        total_actors = "";
        // string totalActors[10];
        for (int i = 0; i < numb_actors; i++)
        {
            file >> actors;
            total_actors += actors + " ";
            totalActors[i] = actors;
        }
        // cout << total_actors << endl;
        file >> status;
        id = "";
        date = "";
        if(status == "out")
        {
            file >> id >> date;
        }
        record.add_node_at_tail(movie, director, year, numb_actors, totalActors, status, id, date);
    }
    record.add_node_at_tail(movie, director, year, numb_actors, totalActors, status, id, date);
    int size = record.size();
    while(true)
    {
        string choice; 
        cout << "1: for searching movie " << endl;
        cout << "2: for check missing movie " << endl;
        cout << "3: for check-in movie " << endl;
        cout << "4: for check-out movie " << endl;
        cout << "5: for exit the system " << endl;
        cout << "Your choice is: ";
        cin >> choice;
        if (choice == "5")
        {
            cout << "Thank you for using the system" << endl;
            break;
        } else if(choice == "1")
        {
            int searchChoice;
            cout << "Searching movie base on four types" << endl;
            cout << "1: for movie's title" << endl;
            cout << "2: for director of movie" << endl;
            cout << "3: for year made of movie" << endl;
            cout << "4: for actor in movie" << endl;
            cout << "Your choice is: ";
            cin >> searchChoice;
            string input; 
            int indexStart, indexEnd;
            switch (searchChoice)
            {
            case 1:
                cout << "Please enter movie name" << endl;
                cin >> input;
                record.createArr();
                record.sortArr(lines, 1);
                indexStart = record.binarySearchFirst(0,lines-1,input, 1);
                indexEnd = record.binarySearchLast(0,lines-1,input, 1);
                record.printSearch(indexStart, indexEnd);
                break;
            case 2:
                cout << "Please enter director's name of the movie" << endl;
                cin >> input;
                record.createArr();
                record.sortArr(lines, 2);
                indexStart = record.binarySearchFirst(0,lines-1,input, 2);
                indexEnd = record.binarySearchLast(0,lines-1,input, 2);
                record.printSearch(indexStart, indexEnd);
            case 3:
                cout << "Please enter year of the movie was made" << endl;
                cin >> input;
                record.createArr();
                record.sortArr(lines, 3);
                indexStart = record.binarySearchFirst(0,lines-1,input, 3);
                indexEnd = record.binarySearchLast(0,lines-1,input, 3);
                cout << indexStart << " " << indexEnd << endl;
                record.printSearch(indexStart, indexEnd);
            case 4:
                cout << "Please enter actor in the movie" << endl;
                cin >> input;
                record.createArr();
                record.sortArr(lines, 3);
                record.search_movie_by_actors(input);
            default:
                break;
            }
        }else if(choice == "2")
        {
            record.check_missing();
        }
        else if(choice == "3")
        {
            // 5432 
            // The-Wizard-of-Oz
            string input, movieIn;
            cout << "Please enter your full movie name: ";
            cin >> movieIn;
            cout << "Please enter your ID: ";
            cin >> input;
            record.check_in(movieIn, input);
        }
        else if(choice == "4")
        {
            int indexStart, indexEnd, amount;
            string input, id, date;
            cout << "What movie do you want to check out? " << endl;
            cout << "Please enter it with full movie name: ";
            cin >> input;
            cout << "Please enter your ID accout: ";
            cin >> id;
            cout << "Please enter today date with format mm-dd-yyyy: ";
            cin >> date;
            record.check_out(input, id, date);
            // Spider-Man  ("Spider-Man-2", "1235","12-2-2023"
            // break;
        }
        
    }

}
// g++ Project.cpp Linkedlist.cpp UI.cpp -o Final
// ./Final

// int choice = 3;
//     // cout << size << endl;
//     record.check_missing();
//     // cout << "\n";
//     record.createArr();
//     record.createArrActors();
//     record.sortArr(lines, choice);
//     // for (int i = 0; i < lines; i++)
//     // {
//     //     cout << record.movie[i]->getData(2) << endl;
//     // }
//     // record.get_movie();
//     string searchMovie = "2007";
//     int indexStart = record.binarySearchFirst(0,lines-1,searchMovie, choice);
//     int indexEnd = record.binarySearchLast(0,lines-1,searchMovie, choice);
//     cout << "Index Start: " << indexStart << endl;
//     cout << "Index End: " << indexEnd << endl;
//     record.printSearch(indexStart, indexEnd);
//     cout << "Program end" << endl;
//     record.search_movie_by_actors("Kir");