#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
    HuffmanNode(char data, int freq, HuffmanNode* left, HuffmanNode* right)
        : data(data), freq(freq), left(left), right(right) {}
};

struct compare 
{
    bool operator()(HuffmanNode* l, HuffmanNode* r) 
	{ 
		return l->freq > r->freq; 
	}
};

void buildCodes(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode) 
{
    if (!root) return;
    if (!root->left && !root->right) huffmanCode[root->data] = str;
    buildCodes(root->left, str + "0", huffmanCode);
    buildCodes(root->right, str + "1", huffmanCode);
}

unordered_map<char, string> huffmanEncoding(const string& s) 
{
    unordered_map<char, int> freqMap;
    for (char ch : s) freqMap[ch]++;
    
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;
    for (auto& p : freqMap) minHeap.push(new HuffmanNode(p.first, p.second));

    while (minHeap.size() > 1) 
	{
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        minHeap.push(new HuffmanNode('$', left->freq + right->freq, left, right));
    }

    unordered_map<char, string> huffmanCode;
    buildCodes(minHeap.top(), "", huffmanCode);
    return huffmanCode;
}

int main() 
{
    string s;
    cout << "Enter the string to encode: ";
    getline(cin, s);
    if (s.empty()) 
	{
        cout << "Input string is empty. Exiting program." << endl;
        return 0;
    }

    auto huffman = huffmanEncoding(s);
    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffman) cout << pair.first << " : " << pair.second << endl;

    cout << "\nEncoded String: ";
    for (char ch : s) cout << huffman[ch];
    cout << endl;

    return 0;
}

