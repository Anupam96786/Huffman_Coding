// =========================================================
// Author: Anupam Samanta
// Create date: 08-09-2021
// Description: Huffman Coding Class
// =========================================================

#include <bits/stdc++.h>
using namespace std;

// Node class for huffman coding
class HCNode
{
public:
    char data;
    int charCount;
    HCNode *zero;
    HCNode *one;
    HCNode(char data, int count)
    {
        this->data = data;
        charCount = count;
        zero = NULL;
        one = NULL;
    }
};

// Main class for huffman coding
class HuffmanCoding
{
private:
    unordered_map<char, string> encodeTable;
    unordered_map<string, char> decodeTable;

    // class to compare HCNode charCount in priority queue
    class Compare
    {
    public:
        bool operator()(HCNode *parent, HCNode *child)
        {
            return parent->charCount > child->charCount;
        }
    };

    // function to delete the huffman tree or root
    void deleteTree(HCNode *root)
    {
        if (root == NULL)
            return;
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

    // function to join two HCNoe and will return a joint node of type HCNode
    HCNode *joinNode(HCNode *zero, HCNode *one)
    {
        HCNode *node = new HCNode('\0', zero->charCount + one->charCount);
        node->zero = zero;
        node->one = one;
        return node;
    }

    // temp function to generate encode and decode table
    // on which recursion will be called
    void generateEncodeDecodeTableTemp(HCNode *root, string encodedBit)
    {
        if (root == NULL)
            return;
        if (root->data != '\0')
        {
            encodeTable[root->data] = encodedBit;
            decodeTable[encodedBit] = root->data;
            return;
        }
        if (root->data == '\0')
        {
            generateEncodeDecodeTableTemp(root->zero, encodedBit + "0");
            generateEncodeDecodeTableTemp(root->one, encodedBit + "1");
        }
        return;
    }

    // function to generate encode and decode table
    void generateEncodeDecodeTable(HCNode *root)
    {
        generateEncodeDecodeTableTemp(root, "");
    }

public:
    // function to encode the given string
    // return a string of 0's and 1's
    string encode(string s)
    {
        string encodedString;
        if (s.size() == 0)
            return encodedString;
        unordered_map<char, int> charCount;
        for (int i = 0; i < s.size(); i++)
        {
            charCount[s[i]]++;
        }
        priority_queue<HCNode *, vector<HCNode *>, Compare> nodeQueue; // creating the min priority queue
        for (auto i : charCount)
        {
            // datatype of i is pair
            // i.first contains character
            // i.second contains count of that character
            nodeQueue.push(new HCNode(i.first, i.second));
        }

        // if the string has only one type of character then just return 0's according to the number of character
        if (nodeQueue.size() == 1)
        {
            for (int i = 0; i < nodeQueue.top()->charCount; i++)
                encodedString.append("0");
            HCNode *temp = nodeQueue.top();
            nodeQueue.pop();
            delete temp;
        }

        // if there is multiple types of character then
        // - create huffman tree
        // - generate encode and decode table
        else
        {
            while (nodeQueue.size() != 1)
            {
                HCNode *zero = nodeQueue.top();
                nodeQueue.pop();
                HCNode *one = nodeQueue.top();
                nodeQueue.pop();
                nodeQueue.push(joinNode(zero, one));
            }
            HCNode *root = nodeQueue.top();
            nodeQueue.pop();
            generateEncodeDecodeTable(root);
            deleteTree(root);
            for (int i = 0; i < s.size(); i++)
                encodedString.append(encodeTable[s[i]]);
        }
        return encodedString;
    }

    // function to decode the given string
    // return the decoded string
    string decode(string encodedString)
    {
        string decodedString;
        int size = 1;
        while (encodedString.size() != 0)
        {
            string substr = encodedString.substr(0, size);
            if (decodeTable.count(substr) > 0)
            {
                string s(1, decodeTable[substr]);
                decodedString.append(s);
                encodedString = encodedString.substr(size);
                size = 1;
            }
            else
            {
                size++;
            }
        }
        return decodedString;
    }
};
