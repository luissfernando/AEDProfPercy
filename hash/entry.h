#ifndef ENTRY_H
#define ENTRY_H
struct Entry{
  int key;
  int value;
  Entry(int key,int value);
  Entry();
};
Entry::Entry(int _key,int _value){
  key = _key;
  value = _value;

}
Entry::Entry(){
  key=value=0;
}
#endif // !ENTRY_H
