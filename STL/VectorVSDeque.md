| Vector                                                            | Deque                                                                     |
| ----------------------------------------------------------------- | ------------------------------------------------------------------------- |
| Provides insertion and deletion methods at middle and end         | Provides insertion and deletion methods at middle, end, beginning         |
| Bad performance for insertion and deletion at the front           | Good performance for insertion and deletion at the front                  |
| Stores elements contiguously                                      | It contains lists of memory chunks where elements are stored contiguously |
| Good performance for addition and deletion of elements at the end | Good performance for addition and deletion of elements at the end         |
| It is stored in <vector> header file in C++                       | It is stored in <deque> in C++                                            |
| Its time complexity of insertion in front or in middle is O(N)    | Its time complexity of insertion in front and end is O(1)                 |
| Its time complexityof deletion is O(N)                            | Its time complexity of deletion is O(1)                                   |
