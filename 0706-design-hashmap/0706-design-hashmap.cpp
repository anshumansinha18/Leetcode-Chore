class HashNode{
public: int data;
    HashNode *next;


    HashNode(int value){
        this->data = value;
        this->next= nullptr;
    }


};



class MyHashMap {

    HashNode** arr;
public:
    MyHashMap() {
        arr = new HashNode*[1000001];
        for(int i=0;i<1000001;i++){
            arr[i] = NULL;
        }
    }

    void put(int key, int value) {
        HashNode *node = new HashNode(value);

        arr[key] = node;
    }

    int get(int key) {

       if(arr[key]==NULL)
           return -1;
       else return arr[key]->data;
    }

    void remove(int key) {
  
      arr[key] = nullptr;
    }
};