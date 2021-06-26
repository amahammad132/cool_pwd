#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <unistd.h>

namespace fs = std::filesystem;
using std::cout, std::endl;

std::string colorize(std::string inp) {
    return "\033[38;2;102;217;239m" + inp + "\033[0;10m";
}

int main(int argc, char* argv[]) {
    fs::path pathname = fs::current_path();
    if (argc > 1) {
        // -P option should show absolute path
        if (((std::string) argv[1]).compare("-P") == 0) {
            cout << "-P option used" << endl;
            cout << (std::string) pathname << endl;
            return 0;
        } else {
            cout << "unsupported option " << argv[1] << endl;
            return 1;
        }
    }

    // Check if the program is being piped into another program
    // If it is, print out the current directory normally
    if (!isatty(STDOUT_FILENO)) {
        cout << (std::string) pathname << endl;
        return 0;
    }

    // Make fs::path into vector of strings
    std::vector<std::string> dirs;
    for (auto& itm : pathname) {
        dirs.push_back((std::string) itm);
    }

    // Remove first element which is '/'
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
