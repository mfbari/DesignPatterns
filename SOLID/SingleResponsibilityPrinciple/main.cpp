#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Journal {
    std::string title;
    std::vector<std::string> entries;
public:
    Journal(const std::string& title) : title(title) {}
    void AddEntry(std::string entry) {
        entries.push_back(entry);
    }
    std::vector<std::string> GetEntries() const {
        return entries;
    }
};

/*
 * In the Journal we should to add the functionality to save the jouranl to
 * a file. This task should be separated into a new class that will take on
 * the responsibility to save a journal to the filesystem. or it can also
 * save it to another location, like to a cloud service. Now, if we added a 
 * save function to the Journal class and then needed to save a journal on 
 * different devices/services we would endup with different versions of the 
 * save function in the Journal class that does not have anything to do with
 * a Journal. The primary responsibility of the Journal class is to store the
 * Journal entries. Maybe return them when needed. 
 */

class PersistenceManager {
public:
    static void SaveJournalToFile(const Journal& journal,
            const std::string& filename) {
        std::ofstream ofs(filename);
        for (auto& entry : journal.GetEntries()) {
            ofs << entry << std::endl;
        }
    }
};

int main() {
    Journal journal("FB's Journal");
    journal.AddEntry("I cleaned the room today");
    journal.AddEntry("I ate chichen");

    PersistenceManager::SaveJournalToFile(journal, "fb_journal.txt");
    return 0;
}