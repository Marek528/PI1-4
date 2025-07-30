#include <iostream>
#include <string>
#include <vector>

using namespace std;

string applyTransformation(const string& message, const string& pattern, const string& replacement)
{
    string result = "";
    int messageLength = message.length();
    int patternLength = pattern.length();
    
    if (patternLength == 0)
    {
        return message;
    }
    
    vector<bool> isPartOfMatch(messageLength, false);
    
    int i = 0;
    while (i < messageLength)
    {
        if (i + patternLength <= messageLength && message.substr(i, patternLength) == pattern)
        {
            for (int j = 0; j < patternLength; j++)
            {
                isPartOfMatch[i + j] = true;
            }
            i += patternLength;
        }
        else
        {
            i++;
        }
    }
    
    i = 0;
    while (i < messageLength)
    {
        if (isPartOfMatch[i])
        {
            result += replacement;
            while (i < messageLength && isPartOfMatch[i])
            {
                i++;
            }
        }
        else
        {
            result += message[i];
            i++;
        }
    }
    
    return result;
}

int main()
{
    string encryptedMessage;
    cin >> encryptedMessage;
    
    int numTransformations;
    cin >> numTransformations;
    
    for (int i = 0; i < numTransformations; i++)
    {
        string pattern, replacement;
        cin >> pattern >> replacement;
        
        encryptedMessage = applyTransformation(encryptedMessage, pattern, replacement);
    }

    cout << endl << encryptedMessage;

    return 0;
}