#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	ifstream in_file("MooCat.txt");
	ofstream out_file("MooCat_out.txt");
	string exclusion_word[26] = {
		"the", "and", "but", "that", "then", "are", "been",
		"can", "a", "could", "did", "for", "of",
		"had", "have", "him", "his", "her", "its", "is",
		"were", "which", "when", "with", "would" 
	};
	set<string> exclusion_set(exclusion_word, exclusion_word + 26);
	map<string, int> word_map;
	string tword;
	while (in_file >> tword)
	{
		if (exclusion_set.count(tword))
			continue;
		word_map[tword]++;
	}
	map<string, int>::iterator it = word_map.begin();
	for (; it != word_map.end(); it++)
		out_file << it->first << '('
				 << it->second <<')'<< endl;

}