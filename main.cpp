#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <cstdlib>
#include "util.h"

using namespace std;

int main()
{
    generateMenu();
    cout << "Terima kasih telah menggunakan program ini" << endl;
    _getch();
    closegraph();
    return 0;
}
