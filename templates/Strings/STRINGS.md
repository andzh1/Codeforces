## List of all algorithms

### AhoCorasick (occurrences of few strings in given text in linear lime complexity)
- **Usage**
```c++
std::vector<std::string> substrings;
std::string text;
auto positions = numberOfSubstringEntries(substrings, text);
```
- **Result**
```c++
positions[i] - all occurencies of i-th substrings in text
```
- **Complexity** - `O(text.size() + substrings[i].size())`

---

### Substring occurrences
- **Usage**
```c++
std::string text = "aababab";
std::string substr = "a";
std::vector<int> result = getSubstringOccurrences(text, substr); // [0, 1, 3, 5]
```
- **Result** - all occurrences indices of substr in text
- **Complexity** - `O(text.size() + substr.size())`

---

