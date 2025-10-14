#ifndef ARGVPARSER_H
#define ARGVPARSER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <iomanip>
#include <cstdlib>

namespace argvparser {

extern std::unordered_map<std::string, std::function<void()>> definedArguments;
extern std::unordered_map<std::string, std::string> descriptionsArguments;
extern int argc_;
extern char** argv_;

void init(int argc, char** argv);
int parser(int start = 1);
std::string get_argument(const int index, const std::string defaultValue = "");
bool has_argument(const int index);
std::string get_argument_after(const std::vector<std::string>& names, const std::string defaultValue = "");

template<typename Func>
void define_argument(const std::vector<std::string>& names, Func lambda, std::string description);

} // namespace argvparser

#include "../src/argvparser.inl"  

#endif // ARGVPARSER_H
