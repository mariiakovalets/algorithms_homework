#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BrowserHistory {
    vector<string> history;
    int cur;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }

    void visit(string url) {
        history.resize(cur + 1);
        history.push_back(url);
        cur++;
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }

    string forward(int steps) {
        cur = min((int)history.size() - 1, cur + steps);
        return history[cur];
    }
};