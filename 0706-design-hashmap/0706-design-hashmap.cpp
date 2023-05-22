class HashNode{
public:
    int key;
    int data;
    HashNode *next;


    HashNode(int key, int value){
        this->key = key;
        this->data = value;
        this->next= nullptr;
    }


};



class MyHashMap {

    HashNode** arr;
public:
    MyHashMap() {
        arr = new HashNode*[10007];
        for(int i=0;i<10007;i++){
            arr[i] = NULL;
        }
    }

    void put(int key, int value) {
        HashNode *node = new HashNode(key, value);
        int idx = key%10007;

        if(arr[idx]== nullptr)
            arr[idx]= node;
        else{
            HashNode *temp = arr[idx];
            while(temp->next!= nullptr)
                temp = temp->next;
            temp->next = node;
        }
    }

    int get(int key) {
        int idx = key%10007;

        if(arr[idx]== nullptr)
            return -1;
        else{
            HashNode *temp = arr[idx];
            int result=-1;
            while(temp){
                if(temp->key==key){
                    result=temp->data;
                }
                temp=temp->next;
            }
            return result;
        }
    }

    void remove(int key) {
      //first element removal:
      int idx = key%10007;
     HashNode *curr = arr[idx];
     HashNode *prev = arr[idx];

     while(curr) {
         if (curr == arr[idx]) {
             if (curr->key == key) {
                 arr[idx] = curr->next;
                 curr = arr[idx];
                 prev = curr;
             } else
                 curr = curr->next;
         } else {
             if (curr->key == key) {
                 prev->next = curr->next;
                 curr = curr->next;
             } else {
                 prev = curr;
                 curr = curr->next;
             }
         }
     }

    }
};