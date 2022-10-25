// Function Description

// Complete the insertionSort1 function in the editor below.

// insertionSort1 has the following parameter(s):

// n: an integer, the size of
// arr: an array of integers to sort
// Returns

// None: Print the interim and final arrays, each on a new line. No return value is expected.
// Input Format

// The first line contains the integer , the size of the array .
// The next line contains  space-separated integers .

// Constraints

// Output Format

// Print the array as a row of space-separated integers each time there is a shift or insertion.

// Sample Input

// 5
// 2 4 6 8 3
// Sample Output

// 2 4 6 8 8
// 2 4 6 6 8
// 2 4 4 6 8
// 2 3 4 6 8

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void insertionSort1(int n, vector<int> arr)
{
    int y = 0, t;

    for (int i = 0; i < n; i++)
    {
        t = arr[i];
        for (y = i - 1; (y >= 0 && arr[y] > t); y--)
        {
            arr[y + 1] = arr[y];
            for (int x : arr)
                cout << x << " ";
            cout << endl;
        }
        arr[y + 1] = t;
    }
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
