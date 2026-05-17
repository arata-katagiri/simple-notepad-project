//
// Created by abdil on 5/17/2026.
//

#ifndef SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_H
#define SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_H
#include <algorithm>
#include <fstream>
#include <set>
#include <string>
#include <vector>

class spell_checker {
public:
    spell_checker() {
        const std::string filename = "data/words.txt";

        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            dict.insert(line);
        }
    }

    static std::string normalize(const std::string& word) {
        std::string transformed_word = word;

        std::erase_if(transformed_word, [](const unsigned char c) {
            return !std::isalpha(c);
        });

        std::ranges::transform(transformed_word, transformed_word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        return transformed_word;
    }

    [[nodiscard]] bool is_correct(const std::string& word) const {
        const std::string transformed_word = normalize(word);

        return dict.contains(transformed_word);
    }

    [[nodiscard]] std::vector<std::string> suggestions(const std::string& word) const {
        const std::string transformed_word = normalize(word);

        std::vector<std::string> s;

        for (int i = 0; i < transformed_word.length(); i++) {
            std::string temp = transformed_word;

            temp.erase(i);

            if (dict.contains(temp)) s.push_back(temp);

            if (s.size() == 5) break;
        }

        return s;
    }

private:
    std::set<std::string> dict;
};

#endif //SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_H