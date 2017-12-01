# ifndef ITEM_H
# define ITEM_H

template<typename T1, typename T2>
class Item{
public:
  T1 key;
  T2 value;
	Item();
  Item(T1 newKey, T2 newValue);
  T1 getKey();
  T2 getValue();
};

template<typename T1, typename T2>
Item<T1, T2>::Item(){

}

template<typename T1, typename T2>
Item<T1, T2>::Item(T1 newKey, T2 newValue){
  this->key = newKey;
  this->value = newValue;
}

template<typename T1, typename T2>
T1 Item<T1, T2>::getKey(){
  return this->key;
}

template<typename T1, typename T2>
T2 Item<T1, T2>::getValue(){
  return this->value;
}

# endif
