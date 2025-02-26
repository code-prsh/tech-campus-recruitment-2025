#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void extract_logs(const std::string& log_file, const std::string& date) {
    std::ifstream infile(log_file, std::ios::in);
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open log file: " << log_file << std::endl;
        return;
    }

    // Ensure output directory exists
    std::filesystem::create_directories("output");

    std::string output_file = "../output/output_" + date + ".txt";
    std::ofstream outfile(output_file, std::ios::out);
    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to create output file: " << output_file << std::endl;
        return;
    }

    std::string line;
    size_t count = 0;
    
    while (std::getline(infile, line)) {  // Read line by line
        if (line.rfind(date, 0) == 0) {  // Check if line starts with the given date
            outfile << line << "\n";
            count++;
        }
    }

    infile.close();
    outfile.close();

    std::cout << "Logs for " << date << " saved to " << output_file << " (" << count << " entries)" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: extract_logs.exe YYYY-MM-DD" << std::endl;
        return 1;
    }

    std::string log_date = argv[1];
    std::string log_file_path = "C:\\Users\\pranjal\\Downloads\\logs_2024.log (1)\\logs_2024.log";  // Update with actual path

    extract_logs(log_file_path, log_date);
    return 0;
}
