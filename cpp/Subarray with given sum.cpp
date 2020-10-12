int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        int curr_sum = arr[0], j = 0;
        bool found = false;
        for (int i = 1; i <= n; ++i)
        {
            while (curr_sum > s) curr_sum -= arr[j++];
            if (curr_sum == s)
            {
                cout << j+1 << " " << i << endl;
                found = true;
                break;
            }
            if (i < n) curr_sum += arr[i];
        }
        if (!found) cout << -1 << endl;
    }
    return 0;
}