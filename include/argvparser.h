#ifndef ARGVPARSER_H
#define ARGVPARSER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <iomanip>

namespace argvparser {

    // Inicializace parseru s argc a argv
    void init(int argc, char** argv);

    // Ukončení parseru
    int end();

    // Definice argumentu s callbackem a popisem
    template<typename Func>
    void define_argument(const std::vector<std::string>& names, const Func lambda, const std::string description = "");

    // Získání argumentu podle indexu
    std::string get_argument(const int index, const std::string defaultValue = "");

    // Zkontroluje, zda existuje argument na indexu
    bool has_argument(const int index);

    // Získání argumentu následujícího po daném názvu argumentu
    std::string get_argument_after(const std::vector<std::string>& names, const std::string defaultValue = "");

    // Spuštění parseru argumentů
    int parser(int i = 1);

} // namespace argvparser

#include "../src/argvparser.inl" // šablony definované inline

#endif // ARGVPARSER_H
