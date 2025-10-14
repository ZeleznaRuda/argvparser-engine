namespace argvparser {

template<typename Func>
void define_argument(const std::vector<std::string>& names, const Func lambda, const std::string description) {
    for (const auto& name : names) {
        definedArguments[name] = lambda;
        descriptionsArguments[name] = description;
    }
}

} // namespace argvparser
