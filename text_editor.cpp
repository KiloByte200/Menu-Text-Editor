#include <iostream>
#include <vector>
#include <string>
#include <limits>
//function to delete a line
//function to clear all text
// option to quit program


void viewText(const std::vector<std::string> &buffer){
    for(int i = 0; i < buffer.size(); i++){
        std:: cout << i+1 << ". ";
        std::cout << buffer[i] << "\n";
    }
}

void clearAll(std::vector<std::string> &buffer){
    buffer.clear();
    std::cout << "[All text cleared]\n";
}

void deleteLine(std::vector<std::string> &buffer){
    if(buffer.empty()){
        std::cout << "[nothing to delete]\n";
        return;
    }

    std::cout << "Select which line you would like to delete: ";

    int choice;
    while(!(std::cin >> choice) || choice < 1 || choice > static_cast<int>(buffer.size())){
        std::cout << "\n[invalid input]";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    buffer.erase(buffer.begin() + choice - 1);
}

void appendLine(std::vector<std::string> &buffer){
    viewText(buffer);
    std::cout << "\n:";
    std::string text;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, text);
    buffer.push_back(text);
}
void printMenu(const std::vector<std::string> &buffer){
    std::cout << "Mini Text Editor\n";
    std::cout << "----------------\n";
    viewText(buffer);
    std::cout << "----------------\n";
    std::cout << "1. View text\n";
    std::cout << "2. Append line\n";
    std::cout << "3. Delete line\n";
    std::cout << "4. Clear all text\n";
    std::cout << "5. Quit\n";
    std::cout << "Choice:";
}


int main(){
    std::vector<std::string> buffer;
    bool running = true;
    int choice;
    while (running){
        printMenu(buffer);
        while (!(std::cin >> choice) || !(choice < 6 && choice > 0)){
            std::cout << "[invalid input]";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //std::cout << choice;
        }
        
        switch(choice){
            case 1:
                viewText(buffer);
                break;
            case 2:
                appendLine(buffer);
                break;
            case 3:
                deleteLine(buffer);
                break;
            case 4:
                clearAll(buffer);
                break;
            case 5:
                return 0;
            default:
                viewText(buffer);
                break;
        }
    }
    return 0;
}