#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
// #include <sys/resource.h>
#include <bits/stdc++.h>

using namespace std;

string str, ptn;
int res, m, n, len, len1, i, j, k, table[1000];

void shift(const string &p) {
    len = p.length();
    for (i = 0; i < 1000; i++)
        table[i] = len;
    for (j = 0; j <= len - 2; j++)
        table[p[j]] = len - 1 - j;
}

int horspool(const string &p, const string &t) {
    shift(p);
    m = p.length();
    n = t.length();
    i = m - 1;
    while (i <= n - 1) {
        k = 0;
        while (k <= m - 1 && (p[m - 1 - k] == t[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i = i + table[t[i]];
    }
    return -1;
}

int main() {
    struct timeval tv1, tv2;
    // struct rusage r_usage;

    cout << "Enter the text: ";
    getline(cin, str);

    cout << "Enter the pattern to be found: ";
    getline(cin, ptn);

    // gettimeofday(&tv1, NULL);
    res = horspool(ptn, str);
    // gettimeofday(&tv2, NULL);

    if (res == -1)
        cout << "\nPattern not found\n";
    else
        cout << "Pattern found at " << res + 1 << " position\n";

    // double elapsedTime = (double)(tv2.tv_usec - tv1.tv_usec);
    // cout << "Time of Horsepool's Algorithm = " << elapsedTime << " microseconds\n";

    // getrusage(RUSAGE_SELF, &r_usage);
    // cout << "Memory usage: " << r_usage.ru_maxrss << " kilobytes\n";

    return 0;
}
