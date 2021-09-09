// =========================================================
// Author: Anupam Samanta
// Create date: 08-09-2021
// Description: Huffman Coding
// =========================================================

#include <bits/stdc++.h>
#include "HuffmanCoding.hh"
using namespace std;

int main(int argc, char const *argv[])
{
    HuffmanCoding hc;
    string encodedString =  hc.encode("appddd");
    cout << encodedString << endl;
    cout << hc.decode(encodedString);
    return 0;
}
