#ifndef HASHTABLE_H
#define HASHTABLE_H
template <class T, class F, class S, unsigned int m>
class HashTable {
  private:
    S* table;
    F hash;
  public:
    HashTable() {
      table = new S[m];
    }
    ~HashTable() {
      delete[] table;
    }
    void insert( T& data) {
      int idx = hash(data) % m;
      table[idx].insert(data);
    }
    void remove(const T& data) {
      int idx = hash(data) % m;
      table[idx].remove(data);
    }
    bool find(const T& data) {
      int idx = hash(data) % m;
      return table[idx].find(data);
    }

    S& operator[](int index) {
      return table[index];
    }
};
#endif
