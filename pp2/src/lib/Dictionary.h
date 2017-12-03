# ifndef ITEM_H
# define ITEM_H

template<typename T1, typename T2>
class Dictionary{
private:
  T1 key;
  T2 value;
  
public:
	Dictionary();
	Dictionary(T1 newKey, T2 newValue);
	T1 getKey();
	T2 getValue();
 
};

template<typename T1, typename T2>
Dictionary<T1, T2>::Dictionary(){

}

template<typename T1, typename T2>
Dictionary<T1, T2>::Dictionary(T1 newKey, T2 newValue){
  this->key = newKey;
  this->value = newValue;
}

template<typename T1, typename T2>
T1 Dictionary<T1, T2>::getKey(){
  return this->key;
}

template<typename T1, typename T2>
T2 Dictionary<T1, T2>::getValue(){
  return this->value;
}

# endif
