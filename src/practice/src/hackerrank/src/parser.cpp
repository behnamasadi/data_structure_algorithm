//https://codereview.stackexchange.com/questions/183609/hackerrank-attribute-parser-practice
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;
int main() {

    smatch result;
        int n,q;
        cin>> n >> q;

        string document;
        for (;n>-1;--n)
        {
            string line;
            getline(cin, line);
            document.append(line);
        }
        using Tag_name = string;
        using Attribute_name = string;
        unordered_map<Tag_name, unordered_map<Attribute_name, string>> tag_map;
        Tag_name tag_name{};

        regex tag_regex(R"(<[^>]*)");
        auto tag_matches_begin = sregex_iterator(document.begin(), document.end(), tag_regex);
        auto tag_matches_end = sregex_iterator();
        for (auto tag_it = tag_matches_begin; tag_it != tag_matches_end; ++tag_it) {
            smatch match = *tag_it;
            auto match_string = match.str();

            // if beginig of tag <tag ...
            if (regex_search(match_string, result, regex(R"(<\s*([^/]\w*))"))) {
                string new_tag_name = result[1].str();
                if (tag_name.empty()) {
                    tag_name = new_tag_name;
                } else {
                    tag_name = tag_name + "." + new_tag_name;
                }
                string search_string = match_string;
                while (regex_search(search_string, result, regex(R"re(([^=\s]*)\s*=\s*"([^"]*))re"))) {
                    string attribute_name = result[1].str();
                    string attribute_value = result[2].str();

                    tag_map[tag_name][attribute_name] = attribute_value;

                    search_string = result.suffix();
                }
            }
            // if end of tag  </tag>
            else if (regex_search(match_string, result, regex(R"(</\s*(\w*))"))) {
                string end_tag_name = result[1].str();
                tag_name = regex_replace(tag_name, regex(end_tag_name), "");
                tag_name = regex_replace(tag_name, regex(R"(\.$)"), "");
            }
        }
        vector<string> queries;
        for (;q>0;--q)
        {
            string line;
            getline(cin, line);

            regex_search(line, result, regex(R"((.*)~(.*))"));
            string tag_name = result[1].str();
            string attribute_name = result[2].str();
            if (tag_map[tag_name].count(attribute_name) > 0 )
            {
                queries.push_back(tag_map[tag_name][attribute_name] );
            }
            else
            {
                queries.push_back("Not Found!" );
            }
        }
        cout << flush;
        for(auto i:queries)
            cout << i << "\n";


    return 0;
}
