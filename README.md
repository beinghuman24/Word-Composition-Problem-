# Word Composition Problem
- Word Composition Problem is the problem that includes the Longest Compound Word , Second Longest Compound Word and the Time taken to process the input file.
- Compounded words are the words formed using one or more of the valid words only in the selected file.
- Since the files are already sorted, therefore the valid words that compose compounded words are bound to come before the compounded word itself.
- So, Compounded word can be thought of as the combination of some of the the words that have been already read i.e. -> prefix, and a suffix.
# Approach 
- I had Used Trie based Approach for solving this question.
- Trie class represents the trie data structure that contains methods to insert a word, check if a word exists, and get all prefixes of a given word.
- TrieNode class represents a node in the trie data structure that contains an unordered map to store child nodes and a boolean flag(end) to indicate if the current node represents the end of a word.
- Solution class contains the main logic of the program. It has a Trie object and a deque of pairs to store (word-suffix) pairs. It includes methods to build the trie from a file containing words and to find the longest and second-longest compound words.
- Repeat untill the queue is empty, POP the <word,suffix> pairs from the dequeue.
  * Check if the suffix of the word contains any valid word i.e. prefix from the trie and if length (word) > max_length , set second longest = longest , longest = word and max_length = length(word).
  * Else get all the prefixes of the current suffix of the word , and find the new suffixes w.r.t each and every prefix length. Append the new <word,suffix> pairs into the deque.
- This returns the longest and second longest words from the file.
  # Result
- Output for File: Input_01.txt :
<img width="253" alt="Screenshot 2024-03-06 093510" src="https://github.com/beinghuman24/Word-Composition-Problem-/assets/128249673/1af6767d-51e7-4ea6-acab-4ed7344647b2">
- Output for File: Input_02.txt :
<img width="343" alt="Screenshot 2024-03-06 093444" src="https://github.com/beinghuman24/Word-Composition-Problem-/assets/128249673/411116ca-1276-4947-bfe6-05d3a452ef70">


