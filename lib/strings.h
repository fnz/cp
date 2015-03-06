vector<int> zFunc (const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

vector<int> prefixFunc (const string& s) {
    int n = s.length();
    vector<int> p(n);
    for (int i=1; i<n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}