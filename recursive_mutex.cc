#include <iostream>
#include <mutex>
#include <vector>

// Recursive mutex is necessary for recursive algorithms that need thread safety

class FileSystem {
    static inline std::recursive_mutex mtx;

    struct Node {
        std::string name;
        int size;
        std::vector<Node> children;
    };

    Node root;

public:
    FileSystem() {
        root = {"root", 0, {
            {"docs", 0, {
                {"readme.txt", 100, {}},
                {"notes.txt", 50, {}}
            }},
            {"src", 0, {
                {"main.cpp", 200, {}},
                {"lib", 0, {
                    {"util.cpp", 150, {}}
                }}
            }}
        }};
    }

    // Recursive function - locks at each level of recursion
    int getTotalSize(const Node& node) {
        std::lock_guard<std::recursive_mutex> lock(mtx);  // locks N times for N-deep tree

        int total = node.size;
        for (const auto& child : node.children) {
            total += getTotalSize(child);  // recursive call re-locks - needs recursive_mutex!
        }
        return total;
    }

    int getTotalSize() {
        return getTotalSize(root);
    }
};

int main() {
    FileSystem fs;
    std::cout << "Total size: " << fs.getTotalSize() << " bytes\n";
}
