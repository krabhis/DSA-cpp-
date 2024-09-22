/*
The expression ch - 'a' is used to convert a character into an index that corresponds to its position in the alphabet.

Character Representation: In C++, characters are represented by their ASCII values. For example, the character 'a' has an ASCII value of 97, and 'b' has a value of 98, and so on.
Indexing: When you subtract 'a' from another lowercase letter, it effectively gives you the 0-based index of that letter in the alphabet:
For example:
'a' - 'a' equals 0
'b' - 'a' equals 1
'c' - 'a' equals 2

*/

vector<int> freq(26, 0); // Frequency array for 'a' to 'z'

char ch = 'c';
freq[ch - 'a']++; // Increment the count for 'c'
