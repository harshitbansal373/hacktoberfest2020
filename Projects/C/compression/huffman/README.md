compression algorithms
1) hoffman coding
    * read file and count the freq of each char
    * create tree of each char and add it in heap with pseudo eof as well
    * create a whole tree form taking 2 tree from heap continuously until we remain   with one tree in heap
    * create hash table from tree
    * write compressed file

2) lzw