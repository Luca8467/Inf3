#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <random>
#include <iostream>

auto main(int argc, char **argv) -> int
{
    int count = 20;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 100);
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Anzahl der Wiederholungen")->default_val(count);
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    fmt::print("Count is set to: {}\n", count);

    std::vector<int> vec(count);  // Vektor mit 5 Elementen, die auf 0 initialisiert sind

    // Ausgabe der Elemente
    for (int i = 0; i < vec.size(); ++i) {
        vec[i]=distrib(gen);
    }
    return 0; /* exit gracefully*/
}
