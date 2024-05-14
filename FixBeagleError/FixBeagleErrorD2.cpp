#include <iostream>
#include <cstdio>
#include <string>
#include <filesystem>
#include "Windows.h"

using namespace std;

int main() {

    std::string answer;
    std::cout << "This will attempt to fix the BEAGLE error code in Destiny 2. It will modify AppData." << std::endl;
    std::cout << "Proceed [y/n]? ";
    std::cin >> answer;
    std::cout << "\n\n";

    if (answer == "y" || answer == "Y") {
        //set paths to the D2 folder in appdata
        std::filesystem::path oldDirName = std::filesystem::temp_directory_path() / "Destiny 2";
        std::filesystem::path newDirName = std::filesystem::temp_directory_path() / "Destiny 2_backup";

        //rename dir
        if (std::rename(oldDirName.string().c_str(), newDirName.string().c_str()) != 0) {
            std::perror("Error renaming directory, exiting.");
            system("PAUSE");
            return 1;
        }

        std::puts("Directory renamed successfully, exiting.");
        system("PAUSE");
        return 0;

    } else if (answer == "n" || answer == "N") {
        std::cout << "Aborting." << std::endl;
        system("PAUSE");
        return 0;
    } else {
        std::cout << "Unrecognized action, exiting." << std::endl;
        system("PAUSE");
        return 0;
    }

    return 0;
}