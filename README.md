## Sublime-Text Snippets - Getting the most out of the repository
Copy the files inside `sublime-snippets` directory to `C:\Users\{username}\AppData\Roaming\Sublime Text 3\Packages\User` to enable tab triggers in Sublime-Text.

![](gif/sublime_snippet.gif)

## Tab triggers to be used

### Number Theory
* __modular__: Handling modular integers
* __matrix__: Matrix with binary exponentiation utility
* __monoid__: Storing floating points in `p/q` format
* __totient__: Euler totient function (for given integer only)
* __totient_sieve__: Computing totient function for `1, 2, ..., n`
* __spf__: Sieve of smallest prime factors
* __primes__: Getting all the primes number within given upper bound


### Data structures
* __dsu__: Disjoint union-find data structure
* __pbds__: Priority-based data structures
* __fenwick__: Fenwick tree for prefix sums
* __sparse_table__: Sparse table
* #### Advanced Queues
  * __min_queue__: Get minimum in queue in constant time
  * __max_queue__: Get maximum in queue in constant time
* #### Segment Tree
  * __segtree__: Segment tree (without lazy propagation)
  * __lazy_segtree__: Segment tree (with lazy propagation)
* #### Sqrt Decomposition
  * __mo1__: Query structure for Mo's algorithm
  * __mo2__: For updating range to current query
  
### String Algorithms
* __z_function__: Computing Z-values
* __prefix_function__: Computing prefix function
* __string_hash__: Rabin-karp hashing
* #### Trie
  * __trie__: Trie of strings
  * __trie_bit__: Trie of bits


### Graph Theory
* __centroid__: Centroid of each subtree in a tree
* __diameter__: Diameter of a tree
* __scc__: Kosaraju' algorithm for strongly connected components
* __digraph__: Directed graphs with edges over a range (See [this](https://codeforces.com/contest/786/problem/B))
* #### LCA
  * __lca__: Computing lca using rmq
  * __lca_binarylift__: Computing lca using binary lift
  * __lca_seg__: Computing lca using segment tree
* #### Heavy-light decomposition
  * __hld_point__: HLD decomposition considering _point_ updates
  * __hld_range__: HLD decomposition considering _range_ updates
  
### Geometry
* __point__: 2d points
* __line_int__: 2d straight lines
* __line_double__: 2d straight lines
* __dynamic_hull__: Finding optimal `ax + b` for given `x` using _convex hull trick_

### Debugging
* __debug__: Debugging utility (except `__int128` integers and static arrays)
* __pr__: Debugging utility for `__int128` integers and static arrays


## Other References for Competitive Programming
* [tourist's templates](https://github.com/utkarsh512/gennady-korotkevich-implementions)
* [Everything for CP](https://github.com/utkarsh512/Everything-for-CP)
* [Benq Codes](https://github.com/bqi343/USACO)
* [KTH Resources](https://github.com/kth-competitive-programming/kactl)
