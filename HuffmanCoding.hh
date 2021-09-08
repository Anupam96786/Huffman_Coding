// =========================================================
// Author: Anupam Samanta
// Create date: 08-09-2021
// Description: Huffman Coding Class
// =========================================================

#include <bits/stdc++.h>
using namespace std;

class HCNode
{
public:
    char data;
    int charCount;
    HCNode *zero;
    HCNode *one;
    HCNode(char data)
    {
        this->data = data;
        charCount = 0;
        zero = NULL;
        one = NULL;
    }
};
