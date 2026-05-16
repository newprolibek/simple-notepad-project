#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <cctype>
#include <set>
#include <string>
#include <vector>

class spell_checker {
private:
    std::set <std::string> words;
public:
    explicit spell_checker(const std::set<std::string>& words) : words(words) {}

    static std::string normalize_word(const std::string& word)
    {
        std::string result;
        for (char c : word) {
            if (std::isalpha(static_cast<unsigned char>(c))) {
                result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            }
        }
        return result;
    }

    std::vector<std::string> get_suggestions(const std::string& word)
    {
        std::vector<std::string> suggestions;
        std::string w = normalize_word(word);
        if (w.empty()) {
            return suggestions;
        }

        for (std::size_t i = 0; i < w.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                std::string candidate = w;
                candidate[i] = c;
                if (candidate != w && this->words.find(candidate) != this->words.end()) {
                    suggestions.push_back(candidate);
                    if (suggestions.size() >= 5) {
                        return suggestions;
                    }
                }
            }
        }

        for (std::size_t i = 0; i < w.size(); ++i) {
            std::string candidate = w.substr(0, i) + w.substr(i + 1);
            if (this->words.find(candidate) != this->words.end()) {
                suggestions.push_back(candidate);
                if (suggestions.size() >= 5) {
                    return suggestions;
                }
            }
        }

        for (std::size_t i = 0; i <= w.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                std::string candidate = w.substr(0, i) + c + w.substr(i);
                if (this->words.find(candidate) != this->words.end()) {
                    suggestions.push_back(candidate);
                    if (suggestions.size() >= 5) {
                        return suggestions;
                    }
                }
            }
        }

        return suggestions;
    }
};

#endif // SPELL_CHECKER_H
