#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> splitall(string& pathname) {
    string delim = "/";
    vector<string> res {};

    size_t pos = 0;
    string token;
    while ((pos = pathname.find(delim)) != string::npos) {
        token = pathname.substr(0, pos);
        res.push_back(token);
        pathname.erase(0, pos + delim.length());
    }
    res.push_back(pathname);
    return res;
}

string colorize(string inp) {
    return "\033[38;2;102;217;239m" + inp + "\033[0;10m";
}

int main(int argc, char* argv[]) {
    string pwd = argv[1];

    vector<string> dirs = splitall(pwd);
    dirs.erase(dirs.begin());

    int dirs_size = dirs.size();
    cout << colorize("/");
    for (int i = 0; i < dirs_size - 1; i++) {
        cout << colorize(dirs[i]) << endl;
        for (int j = 0; j < (4 * i); j++) {
            cout << ' ';
        }
        cout << "└── ";
    }

    cout << colorize(dirs[dirs_size - 1]) << endl;
}
