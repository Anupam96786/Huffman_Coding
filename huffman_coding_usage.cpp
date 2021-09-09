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
    // creating two HuffmanCoding class
    HuffmanCoding hc1, hc2;

    // encoding "appddd" and storing the encoded string into 'encodedString' variable
    string encodedString =  hc1.encode("appddd");
    cout << encodedString << endl;

    // getting the decode table and storing it in 'dt' variable of DecodeTable datatype
    DecodeTable dt =  hc1.getDecodeTable();

    // using the 'encodedString' and 'dt' (decode table) to decode the encoded string using another HuffmanCoding object
    cout << hc2.decode(encodedString, dt);
    return 0;
}
