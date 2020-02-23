#include <bits/stdc++.h>
using namespace std;

const char MAX_CHAR = 26;

// Function to count frequency of each char in the
// string. freq[0] for 'a',...., freq[25] for 'z'
void countFreq(string str, int freq[], int len)
{
	for (int i=0; i<len; i++)
		freq[str.at(i) - 'a']++;
}

// Cases to check whether a palindr0mic
// string can be formed or not
bool canMakePalindrome(int freq[], int len)
{
	// count_odd to count no of
	// chars with odd frequency
	int count_odd = 0;
	for (int i=0; i<MAX_CHAR; i++)
		if (freq[i]%2 != 0)
			count_odd++;

	// For even length string
	// no odd freq character
	if (len%2 == 0)
	{
		if (count_odd > 0)
			return false;
		else
			return true;
	}

	// For odd length string
	// one odd freq character
	if (count_odd != 1)
		return false;

	return true;
}

// Function to find odd freq char and
// reducing its freq by 1returns "" if odd freq
// char is not present
string findOddAndRemoveItsFreq(int freq[])
{
	string odd_str = "";
	for (int i=0; i<MAX_CHAR; i++)
	{
		if (freq[i]%2 != 0)
		{
			freq[i]--;
			odd_str = odd_str + (char)(i+'a');
			return odd_str;
		}
	}
	return odd_str;
}

// To find lexicographically first palindromic
// string.
string findPalindromicString(string str)
{
	int len = str.length();

	int freq[MAX_CHAR] = {0};
	countFreq(str, freq, len);

	if (!canMakePalindrome(freq, len))
		return "No Palindromic String";

	// Assigning odd freq character if present
	// else empty string.
	string odd_str = findOddAndRemoveItsFreq(freq);

	string front_str = "", rear_str = " ";

	// Traverse characters in increasing order
	for (int i=0; i<MAX_CHAR; i++)
	{
		string temp = "";
		if (freq[i] != 0)
		{
			char ch = (char)(i + 'a');

			// Divide all occurrences into two
			// halves. Note that odd character
			// is removed by findOddAndRemoveItsFreq()
			for (int j=1; j<=freq[i]/2; j++)
				temp = temp + ch;

			// creating front string
			front_str = front_str + temp;

			// creating rear string
			rear_str = temp + rear_str;
		}
	}

	// Final palindromic string which is
	// lexicographically first
	return (front_str + odd_str + rear_str);
}

// Driver program
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string str;
	cin>>str;
	cout << findPalindromicString(str);
	return 0;
}
