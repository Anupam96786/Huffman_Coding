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
    HuffmanCoding hc1, hc2;
    string encodedString =  hc1.encode("appddd");
    cout << encodedString << endl;
    DecodeTable dt =  hc1.getDecodeTable();
    cout << hc2.decode(encodedString, dt);
    return 0;
}
