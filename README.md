# SortingAlgorithmsComparison

This is my attempt to make better implementations of some algorithms. In addition I wanted to write something new and good, but also to look for one already existing implementation which would be the best on average level.

In addition I'm writing a paper in which I make description of some ideas - how one can write in general faster and better code (starting frmo the O notation, discussing shortly caches, cyclic operations, alignment and others). It can serve as a guide to junior developers as well.

The purpose of the project is to test any given algorithm with a big static arrays of numbers. We have several categories:
SORTED
REVERSE_SORTED
SORTED_WITH_SOME_ZEROES_INSERTED
RAND_WITH_REPEATING_NUMBERS
RAND_NO_REPEAT_SHUFFLED
ONE_NUMBER
ONLY_ZEROES

The arrays sizes are from these classes, I currently use only the first 3: 
enum class TestDataSizeType {
    SMALL_32_2050,
    BIG_32768_524288,
    SUPER_BIG_2096128,
    GIGA_BIG_2147483648,
    TERA_BIG_1099511627776,
};

Currently the total number of the arrays used for sorting is 23*7=154 arrays - combined between the sizes and types. All of them have as well an aligned version.

The project goes along with a second project which generates the data files for the test arrays. Though it is not the best, I've put some effort to make it sufficient, and to generate the files exactly as they should be pasted in the main project together with the structure, parameters, and to do this automatically.

The algorithm processes the data from temporary containers (also with aligned and not aligned version). At the end it makes averages of all results in a single .csv file. As execution varies on a regular PC - dependign on the code, code optimizations and compiler optimizations one may get between +-3 and up to +-12% of fluctuations. So the full test is executed many times (currently I test with 20), and then the results are averaged.

In order to compare I have included sources from other GitHub repositories, all of them metioned in the corresponding header comment in the beginning of the file.

When I'm ready I will publish also here which algorithms were taken into consideration, results from different persepectives, which is the best on average so far, etc. I will also summarize all points I have found so far, which can lead to improvement.

THIS PROJECT IS STILL IN DEVELOPMENT!

PENDING POINTS:
Build under Linux, test on different platforms.
Add more external algorithms.
Add explicit 64 bit support from point of view of the code - there are points I shall triple check, and make some additional review. The subject is long.


