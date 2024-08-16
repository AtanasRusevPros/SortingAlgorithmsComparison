# SortingAlgorithmsComparison

While the project is effective and works as planned, the idea in it is a bit obsolete. Simply put, after my latest Linux tests on many of the algorithms - results vary on multiple factors. FYI - the C++ STL stable sort has a great smart sorting implementation and is from the best ones. You can reach up to 30% improvement on it with some crazy tweaks, but it will not be stable.
Thus, it is quite a lot more important to consider your application and data structure design, then to make extremely smart sort. Sorry, the STL sort is already quite great. Even though, if you want to read - see what I have done a few years ago :). It is fun :).

This is my attempt to make better implementations of some algorithms. In addition I wanted to write something new and good, but also to look for one already existing implementation which would be the best on average level.

Currently all implementations sort arrays of int numbers.

The project will go along with a paper in which I make description of some ideas - how one can write in general faster and better code (starting from the O notation, discussing shortly caches, cyclic operations, alignment and others). It can serve as a guide to junior developers as well. First draft is available in the main directory of the project.

For the moment all code shall be platform independent, but as I work under Windows (after working for quite a while with QtCreator and I love it for years) - I have switched completely to MSVC 2019 for various reasons. The two solutions can simply be downloaded and will compile for x64 - I've tested it already.

The License is LGPL 3.0 - https://www.gnu.org/licenses/lgpl-3.0.html

BASIC TEST IDEA:
The purpose of the project is to test any given algorithm with a big amount of different static arrays of numbers, so that when the final results are averaged we know which algo is better. We have several categories:

SORTED

REVERSE_SORTED

SORTED_WITH_SOME_ZEROES_INSERTED

RAND_WITH_REPEATING_NUMBERS

RAND_NO_REPEAT_SHUFFLED

ONE_NUMBER  // only integer 123

ONLY_ZEROES // necessary as some implementations may make use of the 0, and such test data will reveal potential issues

The arrays sizes are from these classes, I currently use only the first 3: 

enum class TestDataSizeType {

    SMALL_32_2050,
    
    BIG_32768_524288,
    
    SUPER_BIG_2096128,
    
    GIGA_BIG_2147483648,    // not yet used 
    
    TERA_BIG_1099511627776, // not yet used 
};

Currently the total number of the arrays used for sorting is 23*7=154 arrays - combined between the sizes and types.
All arrays have as well an aligned version.

The project goes along with a second small project which generates the data files for the test arrays. Though it is not the best, I've put some effort to make it sufficient, and to generate the files exactly as they should be copied to the main project together with the structure, parameters, etc.

IMPORTANT TEST STRATEGY POINTS:
I use the C++11 std::chrono::high_resolution_clock with precision std::chrono::nanoseconds. 
All averaged results are checked for too big deviations.
There is a "basic timeout" strategy to rule out the slow algorithms, it might need to be adjusted on some platforms - it is in the main.cpp - I use several singleRunLimit_XXXXXXX constants, and the values are based on the execution on my workstation "Intel_Xeon2630_3_Ghz_6_Core_64bit_15MB_L3_Cache_Bit_24_GB_RAM_DDR3_ECC_1333".
So - as few of my implementations and some of the external algorithms are slow - I break their execution and continue with the next one.


GENERIC TEST POINTS:
The algorithm processes the data from temporary containers (also with aligned and not aligned version). 
At the end it makes averages of all results in a single .csv file. 
As execution varies on a regular PC - dependign on the code, code optimizations and compiler optimizations one may get between +-3 and up to +-12% of fluctuations. 
So the full test is executed many times (currently I test with 20), and then the results are averaged.
Apart from this for each algorithm a log file is generated with the detailed listing of all executions, so that one can check if he wants some particular timings.

In order to compare I have included sources from other GitHub repositories, all of them metioned in the corresponding header comment in the beginning of the file.

When I'm ready I will publish also here which algorithms were taken into consideration, results from different persepectives, which is the best on average so far, etc. I will also summarize all points I have found so far, which can lead to improvement.

THIS PROJECT IS STILL IN DEVELOPMENT! Please consider this when downloading it. Hence I haven't announced it on any social platform or website. I just don't have enough time to go faster with my work and life :).

PENDING POINTS:
    - I still have to implement one final point for comparison of the data with standard sorted data! Currently the result is checked only for whether it is sorted, and not whether e.g. some array numbers have been replaced (and still in a sorted fashion).
    - Finish the documentation (38 pages and counting... I need more time...)
    - Build under Linux, test on different platforms.
    - Add more external algorithms.
    - Add explicit 64 bit support from point of view of the code - there are points I shall triple check, and make some additional review. The subject is long.


