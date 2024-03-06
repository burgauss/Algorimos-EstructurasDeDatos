// AplicationsCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    unsigned long long smallerElement;
    int lastIndex;
    int sizeOfArray = arr.size();
    for (int i = 0; i < sizeOfArray; i++) {
        smallerElement = arr[i];
        lastIndex = 0;
        for (int j = 0; j < sizeOfArray-i-1 ; j++)
        {
            if (smallerElement > arr[j + i + 1]) {
                smallerElement = arr[j + i + 1];
                lastIndex = j + i + 1;
            }
        }

        if (smallerElement != arr[i])
        {
            int temp = arr[i];
            arr[i] = smallerElement;
            arr[lastIndex] = temp;
        }
    }
    
    unsigned long long maximumSum = 0;
    unsigned long long mimimumSum = 0;
    for (int i = 0; i < 4; i++)
    {
        maximumSum += arr[i];
    }

    for (int i = 4; i >0; i--)
    {
        mimimumSum += arr[i];
    }

    cout << maximumSum << " " << mimimumSum << endl;



}

void miniMaxSum2(vector<int> arr)
{
    long min_num = INT_MAX;
    long max_num = INT_MIN;
    long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (min_num > arr[i]) min_num = arr[i];
        if (max_num < arr[i]) max_num = arr[i];
        sum += arr[i];
    }
    cout << (sum - max_num) << " " << (sum - min_num);
}


int main()
{

    //string arr_temp_temp;
    //getline(cin, arr_temp_temp);

    //vector<string> arr_temp = split(rtrim(arr_temp_temp));

    //vector<int> arr(5);

    //for (int i = 0; i < 5; i++) {
    //    int arr_item = stoi(arr_temp[i]);

    //    arr[i] = arr_item;
    //}

    vector<int> arr{ 5000,10000,23333,10000,20000 };

    miniMaxSum2(arr);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
