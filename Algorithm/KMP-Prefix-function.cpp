//KMP Algorithm uses the prefix_function vector for computation
// String matching is one of the most wide application of it.

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// This is an online algorithm, i.e. it processes the data as it arrives - 
// for example, you can read the string characters one by one and process them immediately, 
// finding the value of prefix function for each next character.
