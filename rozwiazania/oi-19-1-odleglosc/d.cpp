template<typename T> void dout(string name, T arg) {
  cerr << name << " = " << arg << endl;
}

template<typename T1, typename... T2> void dout(string names, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " = " << arg << " | ";
  dout(names.substr(names.find(',') + 2), args...);
}

#ifdef LOCAL
  #define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...) 42
#endif