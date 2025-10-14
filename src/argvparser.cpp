#include "../include/argvparser.h"

namespace argvparser {

std::unordered_map<std::string, std::function<void()>> definedArguments;
std::unordered_map<std::string, std::string> descriptionsArguments;
int argc_ = 0;
char** argv_ = nullptr;

namespace {

bool starts_with(const std::string& text, const std::string& prefix) {
    return text.rfind(prefix, 0) == 0;
}

void help() {
    int maxKeyLength = 0;
    for (const auto& [key, val] : descriptionsArguments)
        if (key.length() > maxKeyLength)
            maxKeyLength = key.length();

    std::cout << "Available arguments:\n";
    for (const auto& [key, val] : descriptionsArguments)
        std::cout << std::setw(maxKeyLength + 2) << std::left << key
                  << " - " << val << "\n";
}

} // anonymous namespace

void init(int argc, char** argv) {
    argc_ = argc;
    argv_ = argv;

    definedArguments["--help"] = [](){ help(); std::exit(0); };
    definedArguments["-h"] = [](){ help(); std::exit(0); };
    descriptionsArguments["--help"] = "show this help message and exit";
    descriptionsArguments["-h"] = "show this help message and exit";
}

int parser(int start) {
    if (argc_ <= 1) {
        init(argc_, argv_);
        return 0;
    }
    for (int i = start; i < argc_; ++i) {
        std::string arg = argv_[i];
        if (definedArguments.find(arg) != definedArguments.end()) {
            definedArguments[arg]();
        } else if (starts_with(arg, "-")) {
            std::cerr << "\033[1;91munknown argument:\033[0m " << arg << "\n";
            return 1;
        }
    }
    return 0;
}

std::string get_argument(const int index, const std::string defaultValue) {
    if (index < 0 || index >= argc_) return defaultValue;
    return std::string(argv_[index]);
}

bool has_argument(const int index) {
    return index >= 0 && index < argc_ && argv_[index] != nullptr;
}

std::string get_argument_after(const std::vector<std::string>& names, const std::string defaultValue) {
    for (int i = 0; i < argc_; ++i) {
        for (const auto& name : names) {
            if (std::string(argv_[i]) == name && i + 1 < argc_) {
                return std::string(argv_[i + 1]);
            }
        }
    }
    return defaultValue;
}

} // namespace argvparser
