#include<iostream>
#include"../include/unicode2utf8.h"

using namespace std;

int main(int argc, char** argv)
{
    for(int i=1; i<argc; i++)
    {
        string t = unicode2utf8(argv[i]);
        cout<<t<<endl;
    }
    return 0;
}

