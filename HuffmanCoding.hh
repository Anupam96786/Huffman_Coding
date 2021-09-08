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

class HuffmanCoding
{
private:
    HCNode *root;

public:
    HuffmanCoding()
    {
        root = new HCNode('\0');
    }

    ~HuffmanCoding()
    {
        queue<HCNode *> q;
        q.push(root);
        while (!q.empty())
        {
            HCNode *tempNode;
            tempNode = q.front();
            if (tempNode->zero)
                q.push(tempNode->zero);
            if (tempNode->one)
                q.push(tempNode->one);
            q.pop();
            delete tempNode;
        }
    }
};

