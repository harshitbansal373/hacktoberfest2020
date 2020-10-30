// CPP program for encoding the string using classical cipher 

#include<bits/stdc++.h> 
using namespace std; 

// Function generates the encoded text 
string encoder(string key) 
{ 
	string encoded = ""; 
	// This array represents the 
	// 26 letters of alphabets 
	bool arr[26] = {0}; 

	// This loop inserts the keyword 
	// at the start of the encoded string 
	for (int i=0; i<key.size(); i++) 
	{ 
		if(key[i] >= 'A' && key[i] <= 'Z') 
		{ 
			// To check whether the character is inserted 
			// earlier in the encoded string or not 
			if (arr[key[i]-65] == 0) 
			{ 
				encoded += key[i]; 
				arr[key[i]-65] = 1; 
			} 
		} 
		else if (key[i] >= 'a' && key[i] <= 'z') 
		{ 
			if (arr[key[i]-97] == 0) 
			{ 
				encoded += key[i] - 32; 
				arr[key[i]-97] = 1; 
			} 
		} 
	} 

	// This loop inserts the remaining 
	// characters in the encoded string. 
	for (int i=0; i<26; i++) 
	{ 
		if(arr[i] == 0) 
		{ 
			arr[i]=1; 
			encoded += char(i + 65); 
		} 
	} 
	return encoded; 
} 

// Function that generates encodes(cipher) the message 
string cipheredIt(string msg, string encoded) 
{ 
	string cipher=""; 

	// This loop ciphered the message. 
	// Spaces, special characters and numbers remain same. 
	for (int i=0; i<msg.size(); i++) 
	{ 
		if (msg[i] >='a' && msg[i] <='z') 
		{ 
			int pos = msg[i] - 97; 
			cipher += encoded[pos]; 
		} 
		else if (msg[i] >='A' && msg[i] <='Z') 
		{ 
			int pos = msg[i] - 65; 
			cipher += encoded[pos]; 
		} 
		else
		{ 
			cipher += msg[i]; 
		} 
	} 
	return cipher; 
} 

// Driver code 
int main() 
{ 
	// Hold the Keyword 
	string key; 
	key = "Computer"; 
	cout << "Keyword : " <<key << endl; 

	// Function call to generate encoded text 
	string encoded = encoder(key); 

	// Message that need to encode 
	string message = "GeeksforGeeks"; 
	cout << "Message before Ciphering : " << message << endl; 

	// Function call to print ciphered text 
	cout << "Ciphered Text : " << cipheredIt(message,encoded) << endl; 

	return 0; 
} 
