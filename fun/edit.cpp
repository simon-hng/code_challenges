//  class Example {
//          function outerFunction(a, b) {
//              return (function innerFunction(x, y) {
//                  if (x > y) {
//                      return (x + a) * (y - b);
//                  } else {
//                      return (x - y) + (a * b);
//                  }
//              })(a + 1, b - 1);
//          }

//          function run() {
//              result = outerFunction((randomValue1), (randomValue2));
//              print(result);
//          }
//      }

// def code_blocks(code):

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Editor {
  std::vector<std::string> code;
  std::vector<bool> activeLines;
  std::unordered_set<int> expandedBlocks;

  auto extractCodeBlocks(std::vector<std::string> code)
      -> std::unordered_map<int, int> {
    std::unordered_map<int, int> result{};
    std::vector<int> brackets{};

    for (int i{0}; i < code.size(); ++i) {
      for (auto &ch : code[i]) {
        if (ch == '{') {
          brackets.push_back(i);
        }
        if (ch == '}') {
          result[brackets.back()] = i;
          brackets.pop_back();
        }
      };
    }

    return result;
  }

  auto printCode() { std::cout << "test"; };

  auto toggle(int line) -> void {
    auto blocks = extractCodeBlocks(code);
    auto endLine = blocks[line];

    const auto isCollapsing = activeLines[line + 1];
    for (int i{line}; i < endLine; ++i) {
      activeLines[i] = !isCollapsing;
    }

    printCode()
  }
}

// # < class Example {
//     #     function outerFunction(a, b) {
//     # <        return (function innerFunction(x, y) {
//     #             if (x > y) {
//     #                 return (x + a) * (y - b);
//     # <            } else {
//     #                 return (x - y) + (a * b);
//     #             }
//     #         })(a + 1, b - 1);
//     #     }

//     # <    function run() {
//     #         result = outerFunction((randomValue1), (randomValue2));
//     #         print(result);
//     #     }

//     # >    function run() { ...
//           }
//     # }

// def printCode(self, code: List[str], activeLines: List[int]):
//         # assume that this works
//         pass
