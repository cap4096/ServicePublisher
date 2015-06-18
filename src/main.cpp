#include <iostream>
#include "DnsResolver.h"
using namespace std;

int main()
{
    for(auto e : DnsResolver::resolve("www.google.com", "http"))
    {

    }

    cout << "Hello, World!" << endl;
    return 0;
}