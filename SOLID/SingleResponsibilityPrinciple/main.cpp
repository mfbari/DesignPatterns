#include <iostream>
#include <string>
#include <vector>

class Journal {
    std::string title;
    std::vector<std::string> entries;
public:
    Journal(const std::string& title, const std::vector<std::string>& entries) :
        title(title), entries(entries) {}
};

int main() {

    return 0;
}