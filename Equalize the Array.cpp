#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalizeArray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int equalizeArray(vector<int> arr)
{
    std::map<int, int> mp;

    for (auto n : arr)
    {
        mp[n]++;
    }
    
    auto max = *max_element(mp.begin(), mp.end(), 
        [](const auto& lhs, const auto& rhs)
        {
            return lhs.second < rhs.second;
        }
    );

    return arr.size() - max.second;
}

int equalizeArray1(vector<int> arr)
{
    std::map<int, int> mp;
    int max = 0;

    for (const auto n : arr)
    {
        const auto ret = mp.insert({ n, 1 });
        if (ret.second == false)
        {
            ret.first->second++;
        }
        
        if (max < ret.first->second)
        {
            max = ret.first->second;
        }
    }
    
    return arr.size() - max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = equalizeArray(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}


