#include <iostream>
#include <string.h>
#include <fstream>
#include "Linkedlist.h"
using namespace std;

int main()
{
    Movie_service *shop = new Movie_service();
    shop->run();
    delete shop;
}