vector`<int>` maxCombinations(int N, int K, vector`<int>` &A, vector`<int>` &B)
{
    sort(rbegin(A), rend(A));
    sort(rbegin(B), rend(B));
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    st.insert({0, 0});
    pq.push({A[0] + B[0], {0, 0}});
    vector`<int>` ans;
    while (K--)
    {
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.first);
        int i = it.second.first;
        int j = it.second.second;
        if (i + 1 < N && st.find({i + 1, j}) == st.end())
        {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                st.insert({i + 1, j});

    }
        if (j + 1 < N && st.find({i, j + 1}) == st.end())
        {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
        }
    }
    return ans;
}
