#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    unordered_map<char, int> charIndexMap; // Map to store character indices
    int maxLength = 0;                     // Maximum length of substring without repeating characters
    int start = 0;                         // Start of the current substring

    for (int end = 0; end < n; end++)
    {
        char currentChar = s[end];

        // If the character is already in the map and its index is greater than or equal to the start,
        // update the start to the index of the repeated character + 1
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start)
        {
            start = charIndexMap[currentChar] + 1;
        }

        // Update the index of the current character in the map
        charIndexMap[currentChar] = end;

        // Update the maximum length if the current substring is longer
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main()
{
    string str;
    cin >> str;
    int result = lengthOfLongestSubstring(str);

    cout << result << endl;

    return 0;
}
