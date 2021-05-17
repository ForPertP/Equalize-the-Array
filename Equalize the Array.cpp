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
